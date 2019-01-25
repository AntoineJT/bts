#include <stdio.h>
#include "boolean.h"
#include "input.h"

void input_uint_mv(const char* str_lbl,unsigned int *val,const unsigned int valmax,const char* str_err){ // mv -> max value
    boolean valid;
    do {
        printf(str_lbl);
        valid=scanf("%u",val)&&*val<=valmax;
        if(!valid){
            while(getchar()!='\n');
            puts(str_err);
        }
    } while(!valid);
}

void input_choice(unsigned int *choice,const unsigned int nb_elem){
    boolean valid;
    do {
        printf("Choix: ");
        valid=scanf("%u",choice)&&*choice<nb_elem;    // Vérifie que la saisie est valide et que le choix est défini : si c'est inférieur à nb_elem, alors il n'est pas défini!
        if(!valid){
            while(getchar()!='\n');
            puts("Ce choix est invalide!");
        }
    } while(!valid);
}

void input_float(const char* label,float *nb){
    boolean valid;
    do {
        printf(label);
        valid=scanf("%f",nb);
        if(!valid){
            while(getchar()!='\n');
            puts("Ceci n'est pas un nombre valide!");
        }
    } while(!valid);
}
