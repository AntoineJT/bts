/*
    Ce fichier est utile afin de regrouper diverses macros permettant de manipuler la console Windows
*/
#ifndef WINCMD_H_ // Macro de type "Include Guard"
    #define WINCMD_H_
    #include <windows.h>

    // Define
    // Couleurs
    #define WINCMD_COLOR_BLACK 0
    #define WINCMD_COLOR_DARKBLUE 1
    #define WINCMD_COLOR_GREEN 2
    #define WINCMD_COLOR_BLUEGREY 3
    #define WINCMD_COLOR_BROWN 4
    #define WINCMD_COLOR_PURPLE 5
    #define WINCMD_COLOR_KHAKI 6
    #define WINCMD_COLOR_LIGHTGREY 7
    #define WINCMD_COLOR_GREY 8
    #define WINCMD_COLOR_BLUE 9
    #define WINCMD_COLOR_LIGHTGREEN 10
    #define WINCMD_COLOR_TURQUOISE 11
    #define WINCMD_COLOR_RED 12
    #define WINCMD_COLOR_PINK 13
    #define WINCMD_COLOR_YELLOW 14
    #define WINCMD_COLOR_WHITE 15

    // Macros
    // _TXT_ indique la couleur du texte ; _BG_ indique la couleur du fond
    #define WINCMDSETCOLOR(_TXT_,_BG_) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),_BG_*16+_TXT_);
#endif
