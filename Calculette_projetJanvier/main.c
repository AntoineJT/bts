#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "boolean.h"
#include "calc.h"
#include "conv.h"
#include "input.h"

int main(void){
    // Variables
    unsigned int choice;
    boolean stay=true;
    boolean stay_sm; // sm -> submenu
    // Code
    SetConsoleOutputCP(1252);
    while(stay) {
        puts("Menu Principal\n\n1. Calculette\n2. Convertisseur\n0. Quitter\n");
        input_choice(&choice,3);
        switch(choice){
            case 0: // Dans ce cas on quitte le programme
                stay=false;
                break;
            case 1:
                do {
                    puts("\nMenu Calculette\n\n1. Addition\n2. Soustraction\n3. Multiplication\n4. Division\n0. Retour au menu principal\n");
                    input_choice(&choice,5);
                    stay_sm=choice!=0;
                    if(stay_sm)
                        calc(choice);
                } while(stay_sm);
                break;
            case 2:
                do {
                    puts("\nMenu Convertisseur\n\n1. Conversion Horaire (HHMMSS) en durée (en s)\n2. Conversion durée (en s) en Horaire (HHMMSS)\n0. Retour au menu principal\n");
                    input_choice(&choice,3);
                    stay_sm=choice!=0;
                    if(stay_sm)
                        conv(choice);
                } while(stay_sm);
                break;
            default:break;  // Dans ce cas (qui ne peut normalement pas se produire), il n'y a rien à faire
        }
    }
    return EXIT_SUCCESS;
}
