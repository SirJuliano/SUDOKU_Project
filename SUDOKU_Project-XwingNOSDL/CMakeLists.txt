cmake_minimum_required(VERSION 3.27)
project(SUDOKU_Project_XwingNOSDL C)

set(CMAKE_C_STANDARD 11)

include_directories(SUDOKU_Lefevre_Promis_Bonnet_Itsweire-Krebs)

add_executable(SUDOKU_Project_XwingNOSDL
        SUDOKU_Lefevre_Promis_Bonnet_Itsweire-Krebs/Grille.c
        SUDOKU_Lefevre_Promis_Bonnet_Itsweire-Krebs/Grille.h
        SUDOKU_Lefevre_Promis_Bonnet_Itsweire-Krebs/main.c
        SUDOKU_Lefevre_Promis_Bonnet_Itsweire-Krebs/MySDL.c
        SUDOKU_Lefevre_Promis_Bonnet_Itsweire-Krebs/Notes.c
        SUDOKU_Lefevre_Promis_Bonnet_Itsweire-Krebs/Notes.h
        SUDOKU_Lefevre_Promis_Bonnet_Itsweire-Krebs/Resolution.c
        SUDOKU_Lefevre_Promis_Bonnet_Itsweire-Krebs/Resolution.h
        SUDOKU_Lefevre_Promis_Bonnet_Itsweire-Krebs/MySDL.h)
