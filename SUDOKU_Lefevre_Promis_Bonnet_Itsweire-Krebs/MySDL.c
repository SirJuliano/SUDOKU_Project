#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define GRID_SIZE 9
#define GRID_CELL_SIZE 50
#define GRID_MARGIN 20
#define GRID_WIDTH 3

void drawGrid(SDL_Renderer* renderer) {
    // Dessiner la bordure
    SDL_Rect outerRect = {GRID_MARGIN, GRID_MARGIN, GRID_CELL_SIZE * GRID_SIZE + GRID_WIDTH * (GRID_SIZE - 1) + 2 , GRID_CELL_SIZE * GRID_SIZE + GRID_WIDTH * (GRID_SIZE - 1) + 2 };
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &outerRect);

    // Dessiner les lignes horizontales
    for (int i = 1; i < GRID_SIZE; ++i) {
        if(i%3 == 0){
            int y = GRID_MARGIN + i * (GRID_CELL_SIZE + GRID_WIDTH) - GRID_WIDTH / 2;
            SDL_Rect lineRect = {GRID_MARGIN, y, outerRect.w, GRID_WIDTH};
            SDL_RenderFillRect(renderer, &lineRect);
        } else {
            int y = GRID_MARGIN + i * (GRID_CELL_SIZE + GRID_WIDTH) - GRID_WIDTH / 2;
            SDL_Rect lineRect = {GRID_MARGIN, y, outerRect.w, 1};
            SDL_RenderFillRect(renderer, &lineRect);
        }
    }

    // Dessiner les lignes verticales
    for (int i = 1; i < GRID_SIZE; ++i) {
        if(i%3 == 0){
            int x = GRID_MARGIN + i * (GRID_CELL_SIZE + GRID_WIDTH) - GRID_WIDTH / 2;
            SDL_Rect lineRect = {x, GRID_MARGIN, GRID_WIDTH, outerRect.h};
            SDL_RenderFillRect(renderer, &lineRect);
        } else {
            int x = GRID_MARGIN + i * (GRID_CELL_SIZE + GRID_WIDTH) - GRID_WIDTH / 2;
            SDL_Rect lineRect = {x, GRID_MARGIN, 1, outerRect.h};
            SDL_RenderFillRect(renderer, &lineRect);
        }

    }
}

int main(int argc, char* args[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    int quit = 0;
    SDL_Event event;

    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Création de la fenêtre
    window = SDL_CreateWindow("Grid Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Création du renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Boucle principale
    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Dessiner la grille
        drawGrid(renderer);

        SDL_Surface* image = SDL_LoadBMP("images_sudoku/Chiffre1");

        // Mettre à jour l'écran
        SDL_RenderPresent(renderer);
    }

    // Libérer les ressources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}








//CHATGPT
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600
#define GRID_SIZE     9

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
TTF_Font* font = NULL;

int grille[GRID_SIZE][GRID_SIZE] = {0};  // Initialisation de la grille avec des zéros

void initialiserSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (TTF_Init() < 0) {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("Grille de Sudoku", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Erreur lors de la création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    font = TTF_OpenFont("chemin/vers/votre/police.ttf", 36);  // Remplacez par le chemin de votre police TTF
    if (!font) {
        fprintf(stderr, "Erreur lors du chargement de la police : %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

void quitterSDL() {
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void dessinerGrille() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Couleur de fond (blanc)
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Couleur des lignes de la grille (noir)

    // Dessiner les lignes verticales
    for (int i = 1; i < GRID_SIZE; ++i) {
        SDL_RenderDrawLine(renderer, i * SCREEN_WIDTH / GRID_SIZE, 0, i * SCREEN_WIDTH / GRID_SIZE, SCREEN_HEIGHT);
    }

    // Dessiner les lignes horizontales
    for (int j = 1; j < GRID_SIZE; ++j) {
        SDL_RenderDrawLine(renderer, 0, j * SCREEN_HEIGHT / GRID_SIZE, SCREEN_WIDTH, j * SCREEN_HEIGHT / GRID_SIZE);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Couleur des chiffres (noir)

    // Dessiner les chiffres dans les cases non vides
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (grille[i][j] != 0) {
                char chiffre[2];
                sprintf(chiffre, "%d", grille[i][j]);

                SDL_Surface* surface = TTF_RenderText_Solid(font, chiffre, (SDL_Color){0, 0, 0, 255});
                SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

                SDL_Rect rect = {
                    j * SCREEN_WIDTH / GRID_SIZE + (SCREEN_WIDTH / GRID_SIZE - surface->w) / 2,
                    i * SCREEN_HEIGHT / GRID_SIZE + (SCREEN_HEIGHT / GRID_SIZE - surface->h) / 2,
                    surface->w,
                    surface->h
                };

                SDL_RenderCopy(renderer, texture, NULL, &rect);

                SDL_DestroyTexture(texture);
                SDL_FreeSurface(surface);
            }
        }
    }

    SDL_RenderPresent(renderer);
}

void gererClicSouris(int x, int y) {
    int caseX = x / (SCREEN_WIDTH / GRID_SIZE);
    int caseY = y / (SCREEN_HEIGHT / GRID_SIZE);

    // Ajouter un chiffre dans la case (si elle est vide)
    if (grille[caseY][caseX] == 0) {
        int chiffre;  // Chiffre à ajouter (ici, 1 par défaut)
        scanf("%d",&chiffre);
        grille[caseY][caseX] = chiffre;
    }

    dessinerGrille();  // Mettre à jour l'affichage
}

int main() {
    initialiserSDL();

    int continuer = 1;
    SDL_Event event;

    while (continuer) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    continuer = 0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    gererClicSouris(event.button.x, event.button.y);
                    break;
            }
        }

        dessinerGrille();
    }

    quitterSDL();

    return 0;
}





//CODE PERSO
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600
#define GRID_SIZE     9

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
TTF_Font* font = NULL;

int grille[GRID_SIZE][GRID_SIZE] = {0};  // Initialisation de la grille avec des zéros

void initialiserSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (TTF_Init() < 0) {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("Grille de Sudoku", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Erreur lors de la création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    font = TTF_OpenFont("Fonts/FreeSansOblique.ttf", 36);  // Remplacez par le chemin de votre police TTF
    if (!font) {
        fprintf(stderr, "Erreur lors du chargement de la police : %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

void quitterSDL() {
    SDL_StopTextInput();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void dessinerGrille() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Couleur de fond (blanc)
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Couleur des lignes de la grille (noir)

    // Dessiner les lignes verticales
    for (int i = 1; i < GRID_SIZE; ++i) {
        SDL_RenderDrawLine(renderer, i * SCREEN_WIDTH / GRID_SIZE, 0, i * SCREEN_WIDTH / GRID_SIZE, SCREEN_HEIGHT);
    }

    // Dessiner les lignes horizontales
    for (int j = 1; j < GRID_SIZE; ++j) {
        SDL_RenderDrawLine(renderer, 0, j * SCREEN_HEIGHT / GRID_SIZE, SCREEN_WIDTH, j * SCREEN_HEIGHT / GRID_SIZE);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Couleur des chiffres (noir)

    // Dessiner les chiffres dans les cases non vides
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (grille[i][j] != 0) {
                char chiffre[2];
                sprintf(chiffre, "%d", grille[i][j]);

                SDL_Surface* surface = TTF_RenderText_Solid(font, chiffre, (SDL_Color){0, 0, 0, 255});
                SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

                SDL_Rect rect = {
                        j * SCREEN_WIDTH / GRID_SIZE + (SCREEN_WIDTH / GRID_SIZE - surface->w) / 2,
                        i * SCREEN_HEIGHT / GRID_SIZE + (SCREEN_HEIGHT / GRID_SIZE - surface->h) / 2,
                        surface->w,
                        surface->h
                };

                SDL_RenderCopy(renderer, texture, NULL, &rect);

                SDL_DestroyTexture(texture);
                SDL_FreeSurface(surface);
            }
        }
    }

    SDL_RenderPresent(renderer);
}

int main() {
    initialiserSDL();
    int x, y;
    int continuer = 1;
    SDL_Event event;
    bool textImput = false;

    SDL_StartTextInput();

    while (continuer) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                continuer = 0;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                // Déterminer la position du clic
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                // Déterminer la cellule cliquée
                x = mouseX / (600/9);
                y = mouseY / (600/9);
                textImput = true;
            } else if (event.type == SDL_TEXTINPUT && textImput && x != -1 && y != -1) {
                // Filtrez les événements pour n'accepter que les caractères numériques
                char c = event.text.text[0];
                if (c >= '0' && c <= '9') {
                    // Stockez la valeur dans la cellule sélectionnée
                    grille[y][x] = c - '0';
                }
                textImput = false;
            }
        }

        dessinerGrille();
    }



    quitterSDL();

    return 0;
}