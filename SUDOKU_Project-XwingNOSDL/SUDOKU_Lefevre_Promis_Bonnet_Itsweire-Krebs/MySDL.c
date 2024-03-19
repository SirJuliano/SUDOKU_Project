//
// Created by nono on 28/02/24.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "Resolution.h"
#include "MySDL.h"

#define SCREEN_WIDTH  900
#define SCREEN_HEIGHT 600
#define GRID_SIZE     9

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
TTF_Font* font = NULL;

//teste si les coordonnées sont dans un rectangle donné en paramètre
bool pointInsideRect(int x, int y, const SDL_Rect *rect) {
    return x >= rect->x && x <= rect->x + rect->w && y >= rect->y && y <= rect->y + rect->h;
}

//initialisation de l'affichage
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

    window = SDL_CreateWindow("Grille de Sudoku", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
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

    font = TTF_OpenFont("Fonts/LiberationSans-Bold.ttf", 36);  // Remplacez par le chemin de votre police TTF
    if (!font) {
        fprintf(stderr, "Erreur lors du chargement de la police : %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        exit(EXIT_FAILURE);
    }


}

//libération des ressources utilisées pour l'affichage
void quitterSDL() {
    SDL_StopTextInput();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void printnote(SDL_Rect* grille,int value, int x, int y){
    char chiffre[2];
    sprintf(chiffre, "%d", value);
    int coordX;
    int coordY;

    SDL_Surface* surface = TTF_RenderText_Solid(font, chiffre, (SDL_Color){0, 0, 0, 255});
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (value == 1) {
        coordX = grille->x + x * 50 + 5;
        coordY = grille->y + y * 50 + 5;
    } else if(value == 2) {
        coordX = grille->x + x * 50 + 20;
        coordY = grille->y + y * 50 + 5;
    } else if(value == 3){
        coordX = grille->x + x * 50 + 35;
        coordY = grille->y + y * 50 + 5;
    } else if(value == 4){
        coordX = grille->x + x * 50 + 5;
        coordY = grille->y + y * 50 + 20;
    } else if(value == 5){
        coordX = grille->x + x * 50 + 20;
        coordY = grille->y + y * 50 + 20;
    } else if(value == 6){
        coordX = grille->x + x * 50 + 35;
        coordY = grille->y + y * 50 + 20;
    } else if(value == 7){
        coordX = grille->x + x * 50 + 5;
        coordY = grille->y + y * 50 + 35;
    } else if(value == 8){
        coordX = grille->x + x * 50 + 20;
        coordY = grille->y + y * 50 + 35;
    } else if(value == 9){
        coordX = grille->x + x * 50 + 35;
        coordY = grille->y + y * 50 + 35;
    }

    SDL_Rect rect = {
            coordX,
            coordY,
            10,
            10
    };

    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void setselected(SDL_Rect* grille, int x, int y){
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);  // Couleur de fond (blanc)
    SDL_Rect rect = {
            grille->x + x * 50+1,
            grille->y + y * 50+1,
            50-1,
            50-1
    };

    SDL_RenderFillRect(renderer, &rect);
}


//réalise l'affichage (grille et boutons)
void dessinerGrille(SDL_Rect* grille, T_grid* grid, Button* tab, bool shownote, bool textimput, int coordX, int coordY) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Couleur de fond (blanc)
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Couleur des lignes de la grille (noir)


    SDL_RenderDrawRect(renderer, grille);

    // Dessiner les lignes verticales de la grille
    for (int i = 0; i <= GRID_SIZE; ++i) {
        if(i == 0 || i == GRID_SIZE){
            int x = grille->x + i * (grille->w/ 9);
            SDL_Rect lineRect = {x, grille->y, 3, grille->h + 3};
            SDL_RenderFillRect(renderer, &lineRect);
        }  else if(i%NBSQRT == 0 ){
            int x = grille->x + i * (grille->w/ 9);
            SDL_Rect lineRect = {x, grille->y, 3, grille->h};
            SDL_RenderFillRect(renderer, &lineRect);
        } else {
            int x = grille->x + i * (grille->w/ 9);
            SDL_RenderDrawLine(renderer, x, grille->y, x, grille->y + grille->h);
        }
    }

    // Dessiner les lignes horizontales de la grille
    for (int j = 0; j <= GRID_SIZE; ++j) {
        if(j == 0 || j == GRID_SIZE){
            int y = grille->y + j * (grille->h / 9);
            SDL_Rect lineRect = {grille->x, y, grille->w +3 , 3};
            SDL_RenderFillRect(renderer, &lineRect);
        } else if(j%NBSQRT == 0){
            int y = grille->y + j * (grille->h / 9);
            SDL_Rect lineRect = {grille->x, y, grille->w, 3};
            SDL_RenderFillRect(renderer, &lineRect);
        } else {
            int y = grille->y + j * (grille->h / 9);
            SDL_RenderDrawLine(renderer, grille->x, y, grille->x + grille->w, y);
        }
    }

    // Dessiner le contour de la grille
    SDL_RenderDrawRect(renderer, grille);

    if(textimput){
        setselected(grille, coordX, coordY);
    }
    // Dessiner les chiffres de chaques cases
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Couleur des chiffres (noir)
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            if (getVal(*grid, i, j) != 0) {
                char chiffre[2];
                sprintf(chiffre, "%d", getVal(*grid, i, j));

                SDL_Surface* surface = TTF_RenderText_Solid(font, chiffre, (SDL_Color){0, 0, 0, 255});
                SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

                SDL_Rect rect = {
                        15 + (j+1) * 50,
                        5 + (i+1) * 50,
                        surface->w,
                        surface->h
                };

                SDL_RenderCopy(renderer, texture, NULL, &rect);
                SDL_DestroyTexture(texture);
                SDL_FreeSurface(surface);
            }
        }
    }

    // Tableau contenant les textes des boutons
    char text[14][20] = {
            "Reset",
            "Solve",
            "Show notes",
            "Rules 1/3",
            "Rule 2",
            "Rules 5 to 10",
            "Rules 11/12",
            "delete",
            "Rules X_wing",
            "Facile",
            "Moyen",
            "Difficile",
            "Extreme",
            "Impossible"
    };

    // Dessiner les boutons
    for(int i = 0 ; i<14; i++){
        SDL_SetRenderDrawColor(renderer, tab[i].color.r, tab[i].color.g, tab[i].color.b, tab[i].color.a);
        SDL_RenderFillRect(renderer, &tab[i].rect);
        SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
        SDL_RenderDrawRect(renderer, &tab[i].rect);

        SDL_Surface* surface_b1 = TTF_RenderText_Blended(font, text[i], (SDL_Color){0, 0, 0, 255});
        SDL_Texture* texture_b1 = SDL_CreateTextureFromSurface(renderer, surface_b1);
        SDL_RenderCopy(renderer, texture_b1, NULL, &tab[i].textfield);
        SDL_DestroyTexture(texture_b1);
        SDL_FreeSurface(surface_b1);
    }

    //Dessiner la ligne de séparation des boutons et le label pour les grilles préchargées
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect lineRect = {694, 75,  2 , 400};
    SDL_RenderFillRect(renderer, &lineRect);

    char texte[25] = "Grilles";

    SDL_Surface* surface = TTF_RenderText_Solid(font, texte, (SDL_Color){0, 0, 0, 255});
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect rect = {
            720,
            75,
            120,
            50
    };

    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect lineRect2 = {694, 75,  2 , 400};
    SDL_RenderFillRect(renderer, &lineRect2);

    char texte2[25] = "Regles";

    SDL_Surface* surface2 = TTF_RenderText_Solid(font, texte2, (SDL_Color){0, 0, 0, 255});
    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, surface2);

    SDL_Rect rect2 = {
            550,
            75,
            120,
            50
    };

    SDL_RenderCopy(renderer, texture2, NULL, &rect2);
    SDL_DestroyTexture(texture2);
    SDL_FreeSurface(surface2);

    if(shownote == true){
        for(int i = 0; i<LENGTH; i++){
            for(int y = 0; y <LENGTH; y++){

                int note = getNote(*grid, i, y);
                for(int n = 1 ; n <= 9; n++){
                    if(note != 0){
                        if(note%2 == 1){
                            printnote(grille,n, y, i);
                            note = note / 2;
                        } else {
                            note = note / 2;
                        }
                    }

                }
            }
        }
    }




    SDL_RenderPresent(renderer);
}


void initButtons(Button* tab){
    Button reset = {{75, 520, 100, 50}, false, {192, 192, 192, 255}, {95, 530, 60, 30}};
    Button solve = {{225, 520, 100, 50}, false, {192, 192, 192, 255}, {245, 530, 60, 30}};
    Button notes = {{375, 520, 100, 50}, false, {192, 192, 192, 255}, {380, 530, 90, 30}};
    Button rules1_3 = {{550, 145, 120, 50}, false, {192, 192, 192, 255}, {560, 155, 100, 30}};
    Button rule2 = {{550, 215, 120, 50}, false, {192, 192, 192, 255}, {580, 225, 60, 30}};
    Button rules5_10 = {{550, 285, 120, 50}, false, {192, 192, 192, 255}, {560, 295, 100, 30}};
    Button rules11_12 = {{550, 355, 120, 50}, false, {192, 192, 192, 255}, {560, 365, 100, 30}};
    Button delete = {{550, 520, 120, 50}, false, {192, 192, 192, 255}, {560, 530, 100, 30}};
    Button X_wing = {{550, 425, 120, 50}, false, {192, 192, 192, 255}, {560, 435, 100, 30}};

    Button facile = {{720, 145, 120, 50}, false, {192, 192, 192, 255}, {750, 155, 60, 30}};
    Button moyen = {{720, 215, 120, 50}, false, {192, 192, 192, 255}, {750, 225, 60, 30}};
    Button difficile = {{720, 285, 120, 50}, false, {192, 192, 192, 255}, {740, 295, 80, 30}};
    Button extreme = {{720, 355, 120, 50}, false, {192, 192, 192, 255}, {740, 365, 80, 30}};
    Button impossible = {{720, 425, 120, 50}, false, {192, 192, 192, 255}, {730, 435, 100, 30}};

    tab[0] = reset;
    tab[1] = solve;
    tab[2] = notes;
    tab[3] = rules1_3;
    tab[4] = rule2;
    tab[5] = rules5_10;
    tab[6] = rules11_12;
    tab[7] = delete;
    tab[8] = X_wing;

    tab[9] = facile;
    tab[10] = moyen;
    tab[11] = difficile;
    tab[12] = extreme;
    tab[13] = impossible;
}

void grillefacile(T_grid grid){
    grid = add_Value(grid, 0, 4, 3);
    grid = add_Value(grid, 0, 5, 4);
    grid = add_Value(grid, 0, 6, 9);
    grid = add_Value(grid, 0, 7, 2);
    grid = add_Value(grid, 1, 0, 9);
    grid = add_Value(grid, 1, 2, 3);
    grid = add_Value(grid, 1, 5, 2);
    grid = add_Value(grid, 1, 7, 5);
    grid = add_Value(grid, 1, 8, 1);
    grid = add_Value(grid, 2, 1, 5);
    grid = add_Value(grid, 2, 3, 1);
    grid = add_Value(grid, 2, 4, 8);
    grid = add_Value(grid, 2, 8, 3);
    grid = add_Value(grid, 3, 0, 2);
    grid = add_Value(grid, 3, 4, 4);
    grid = add_Value(grid, 3, 5, 7);
    grid = add_Value(grid, 3, 6, 6);
    grid = add_Value(grid, 3, 8, 5);
    grid = add_Value(grid, 4, 5, 6);
    grid = add_Value(grid, 4, 6, 7);
    grid = add_Value(grid, 4, 7, 3);
    grid = add_Value(grid, 4, 8, 4);
    grid = add_Value(grid, 5, 0, 4);
    grid = add_Value(grid, 5, 4, 5);
    grid = add_Value(grid, 5, 6, 2);
    grid = add_Value(grid, 6, 0, 7);
    grid = add_Value(grid, 6, 3, 3);
    grid = add_Value(grid, 6, 5, 1);
    grid = add_Value(grid, 6, 8, 8);
    grid = add_Value(grid, 7, 4, 6);
    grid = add_Value(grid, 7, 6, 3);
    grid = add_Value(grid, 7, 7, 4);
    grid = add_Value(grid, 7, 8, 2);
    grid = add_Value(grid, 8, 0, 3);
    grid = add_Value(grid, 8, 1, 8);
    grid = add_Value(grid, 8, 2, 6);
    grid = add_Value(grid, 8, 3, 4);
    grid = add_Value(grid, 8, 6, 1);
}

void grillemoyenne(T_grid grid){
    grid = add_Value(grid, 0, 0, 5);
    grid = add_Value(grid, 0, 2, 1);
    grid = add_Value(grid, 0, 6, 6);
    grid = add_Value(grid, 1, 1, 4);
    grid = add_Value(grid, 1, 2, 9);
    grid = add_Value(grid, 1, 4, 5);
    grid = add_Value(grid, 1, 5, 7);
    grid = add_Value(grid, 1, 8, 1);
    grid = add_Value(grid, 2, 0, 8);
    grid = add_Value(grid, 2, 1, 2);
    grid = add_Value(grid, 2, 3, 6);
    grid = add_Value(grid, 2, 7, 4);
    grid = add_Value(grid, 3, 2, 8);
    grid = add_Value(grid, 3, 3, 7);
    grid = add_Value(grid, 3, 5, 5);
    grid = add_Value(grid, 4, 1, 9);
    grid = add_Value(grid, 4, 7, 5);
    grid = add_Value(grid, 4, 8, 7);
    grid = add_Value(grid, 5, 5, 6);
    grid = add_Value(grid, 5, 8, 4);
    grid = add_Value(grid, 6, 0, 3);
    grid = add_Value(grid, 6, 2, 4);
    grid = add_Value(grid, 6, 7, 2);
    grid = add_Value(grid, 6, 8, 8);
    grid = add_Value(grid, 7, 1, 8);
    grid = add_Value(grid, 7, 2, 5);
    grid = add_Value(grid, 7, 5, 9);
    grid = add_Value(grid, 8, 1, 6);
    grid = add_Value(grid, 8, 2, 2);
    grid = add_Value(grid, 8, 8, 5);
}

void grilledifficile(T_grid grid){
    grid = add_Value(grid, 0, 2, 1);
    grid = add_Value(grid, 0, 5, 3);
    grid = add_Value(grid, 0, 7, 2);
    grid = add_Value(grid, 1, 0, 9);
    grid = add_Value(grid, 1, 3, 5);
    grid = add_Value(grid, 1, 7, 7);
    grid = add_Value(grid, 3, 0, 5);
    grid = add_Value(grid, 3, 4, 3);
    grid = add_Value(grid, 3, 6, 2);
    grid = add_Value(grid, 3, 7, 4);
    grid = add_Value(grid, 4, 0, 4);
    grid = add_Value(grid, 4, 5, 6);
    grid = add_Value(grid, 5, 0, 2);
    grid = add_Value(grid, 5, 5, 1);
    grid = add_Value(grid, 5, 7, 9);
    grid = add_Value(grid, 6, 2, 9);
    grid = add_Value(grid, 6, 4, 6);
    grid = add_Value(grid, 6, 8, 7);
    grid = add_Value(grid, 7, 2, 8);
    grid = add_Value(grid, 7, 5, 7);
    grid = add_Value(grid, 7, 7, 3);
    grid = add_Value(grid, 8, 6, 6);
    grid = add_Value(grid, 8, 8, 4);
}

void grilleextreme(T_grid grid) {
    grid = add_Value(grid, 0, 6, 5);
    grid = add_Value(grid, 1, 1, 2);
    grid = add_Value(grid, 1, 5, 4);
    grid = add_Value(grid, 1, 6, 1);
    grid = add_Value(grid, 2, 1, 1);
    grid = add_Value(grid, 2, 2, 5);
    grid = add_Value(grid, 2, 8, 7);
    grid = add_Value(grid, 3, 2, 7);
    grid = add_Value(grid, 3, 5, 8);
    grid = add_Value(grid, 4, 0, 4);
    grid = add_Value(grid, 4, 4, 2);
    grid = add_Value(grid, 5, 0, 9);
    grid = add_Value(grid, 5, 7, 6);
    grid = add_Value(grid, 5, 8, 8);
    grid = add_Value(grid, 6, 3, 4);
    grid = add_Value(grid, 6, 6, 9);
    grid = add_Value(grid, 6, 7, 7);
    grid = add_Value(grid, 7, 3, 7);
    grid = add_Value(grid, 7, 7, 3);
    grid = add_Value(grid, 8, 3, 1);
    grid = add_Value(grid, 8, 4, 5);
    grid = add_Value(grid, 8, 5, 2);
}

void grilleimpossible(T_grid grid){
    grid = add_Value(grid, 0, 0, 1);
    grid = add_Value(grid, 0, 3, 4);
    grid = add_Value(grid, 0, 4, 3);
    grid = add_Value(grid, 0, 7, 5);
    grid = add_Value(grid, 1, 2, 5);
    grid = add_Value(grid, 1, 6, 9);
    grid = add_Value(grid, 2, 4, 2);
    grid = add_Value(grid, 3, 5, 6);
    grid = add_Value(grid, 4, 1, 8);
    grid = add_Value(grid, 4, 8, 7);
    grid = add_Value(grid, 5, 0, 3);
    grid = add_Value(grid, 5, 3, 1);
    grid = add_Value(grid, 5, 4, 5);
    grid = add_Value(grid, 5, 7, 9);
    grid = add_Value(grid, 6, 1, 3);
    grid = add_Value(grid, 6, 3, 6);
    grid = add_Value(grid, 6, 4, 4);
    grid = add_Value(grid, 6, 6, 8);
    grid = add_Value(grid, 7, 5, 2);
    grid = add_Value(grid, 7, 7, 4);
    grid = add_Value(grid, 8, 0, 6);
    grid = add_Value(grid, 8, 5, 9);
}

void mysdl(T_grid grid) {


    initialiserSDL(); //initialistaion et allocation en mémoire de l'affichage
    int x, y;
    int continuer = 1;


    SDL_Event event;
    bool textImput = false;
    SDL_Rect grille = {50,50,450,450};
    Button tab[14];
    initButtons(tab);
    bool shownote = false;


    SDL_StartTextInput();

    while (continuer) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                continuer = 0;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                // Déterminer la position du clic
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if(pointInsideRect(mouseX, mouseY, &grille)){ //vérifie que leclick de souris était sur une case de la grille
                    x = mouseX / (50); //détermine la coordonnée x de la case de la grille qui a été cliquée
                    y = mouseY / (50); //détermine la coordonnée y de la case de la grille qui a été cliquée
                    textImput = true;
                } else if (pointInsideRect(mouseX, mouseY, &tab[0].rect)){ // bouton reset
                    initGrid(grid, LENGTH);
                } else if (pointInsideRect(mouseX, mouseY, &tab[1].rect)){ // bouton solve
                    run_rules(grid, LENGTH);
                } else if (pointInsideRect(mouseX, mouseY, &tab[2].rect)){ // bouton show notes
                    if(shownote == false){
                        shownote = true;
                    }
                    else{
                        shownote = false;
                    }
                } else if (pointInsideRect(mouseX, mouseY, &tab[3].rect)){ // bouton règles 1 et 3
                    rule_1and3(grid, LENGTH);
                } else if (pointInsideRect(mouseX, mouseY, &tab[4].rect)){ // bouton règle 2
                    rule_2(grid, LENGTH);
                } else if (pointInsideRect(mouseX, mouseY, &tab[5].rect)){ // bouton règle de 5 à 10
                    rules_610(grid);
                } else if (pointInsideRect(mouseX, mouseY, &tab[6].rect)){ // bouton règle 11 et 12
                    rules_1112_launch(grid);
                } else if (pointInsideRect(mouseX, mouseY, &tab[7].rect)){ // bouton delete value
                    grid = deleteAvalue(grid, y-1, x-1);
                } else if (pointInsideRect(mouseX, mouseY, &tab[8].rect)){ // bouton règle x_wing
                    x_wing_rules(grid);
                } else if (pointInsideRect(mouseX, mouseY, &tab[9].rect)){ // bouton grille facile
                    initGrid(grid, LENGTH);
                    grillefacile(grid);
                } else if (pointInsideRect(mouseX, mouseY, &tab[10].rect)){ // bouton grille moyenne
                    initGrid(grid, LENGTH);
                    grillemoyenne(grid);
                } else if (pointInsideRect(mouseX, mouseY, &tab[11].rect)){ // bouton grille difficile
                    initGrid(grid, LENGTH);
                    grilledifficile(grid);
                } else if (pointInsideRect(mouseX, mouseY, &tab[12].rect)){ // bouton grille extreme
                    initGrid(grid, LENGTH);
                    grilleextreme(grid);
                } else if (pointInsideRect(mouseX, mouseY, &tab[13].rect)){ // bouton grille impossible
                    initGrid(grid, LENGTH);
                    grilleimpossible(grid);
                }

            } else if (event.type == SDL_TEXTINPUT && textImput && x != -1 && y != -1) { //si on essaie de taper une valeur au clavier, la saisie est autorisée et que x et y on été initalisé
                char c = event.text.text[0]; //on récupère le texte tapé au clavier
                if (c > '0' && c <= '9') { // si il s'agit d'un chiffre entre 1 et 9
                    deleteAvalue(grid, y-1, x-1);
                    add_Value(grid, y-1,x-1, c - '0'); //on ajoute le chiffre converti en int dans la case (x,y)
                }
                textImput = false;
            }
        }
        dessinerGrille(&grille, &grid, tab, shownote, textImput, x-1, y-1); //mise à jour de l'affichage
    }

    quitterSDL(); //libération de la mémoire utilisée pour l'affichage

}