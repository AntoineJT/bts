#include <stdio.h>
#include "boolean.h"
#include "calc.h"
#include "input.h"

/* ----------------------------------------------------- */
/* Fonctions de calcul */
inline float calc_add(const float f1,const float f2){
    return f1+f2;
}

inline float calc_sub(const float f1,const float f2){
    return f1-f2;
}

inline float calc_mult(const float f1,const float f2){
    return f1*f2;
}

float calc_div(const float f1,const float f2){
	float res;
	if(f2!=0)
		res=f1/f2;
	else
		res=0;
	return res;
}

// Cette fonction est implémentée, mais non utilisée dans le code
float calc_abs(const float f1,const float f2){
	float res;
    if(f1>f2)
        res=f1-f2;
    else
        res=f2-f1;
	return res;
}

/* ----------------------------------------------------- */
/* Procédures */
void calc(const calc_enum sel){
    float nb1;
    float nb2;
    float res;
    char symbol;
    switch(sel){
        case ADD:
            puts("\nAddition");
            break;
        case SUB:
            puts("\nSoustraction");
            break;
        case MULT:
            puts("\nMultiplication");
            break;
        case DIV:
            puts("\nDivision");
            break;
        default:break;
    }
    input_float("Entrez un premier nombre: ",&nb1);
    input_float("Entrez un deuxième nombre: ",&nb2);
    switch(sel){
        case ADD:
            symbol='+';
            res=calc_add(nb1,nb2);
            break;
        case SUB:
            symbol='-';
            res=calc_sub(nb1,nb2);
            break;
        case MULT:
            symbol='*';
            res=calc_mult(nb1,nb2);
            break;
        case DIV:
            symbol='/';
            res=calc_div(nb1,nb2);
        default:break;
    }
	if(sel==DIV&&nb2==0)
		puts("\nErreur : Division par 0!");
	else {
        puts("\nRésultats");
		printf("%f%c%f=%f\n",nb1,symbol,nb2,res);
	}
}

/* ----------------------------------------------------- */
