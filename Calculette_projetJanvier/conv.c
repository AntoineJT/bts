#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "conv.h"
#include "input.h"

/* ----------------------------------------------------- */

inline unsigned int conv_hms2sec(const unsigned int h,const unsigned int m,const unsigned int s){
    return h*3600+m*60+s;
}

void conv_sec2hms(unsigned int *h,unsigned int *m,unsigned int *s){
    unsigned int buff; // cette variable permet de mettre un calcul en ram afin de ne pas le faire 2 fois
    *h=*s/3600;
    buff=*h*3600; // on ne calcule pas 2 fois cette valeur
    *m=(*s-buff)/60;
    *s-=buff+*m*60;
}

/* ----------------------------------------------------- */
// 0x30 est une constante permettant de récupérer la valeur d'un chiffre dans la table ASCII afin de récupérer le caractère correspondant
static char* to2numf(unsigned int num){ // f -> format : utile pour formater les horaires
    char *res=malloc(2*sizeof(char));
    /*
    if(num>99){
        return (void*)NULL;
    }
    */ // Ce morceau de code a été enlevé car cette fonction est 'static' donc "privée" et qu'ainsi il suffit de l'utiliser correctement dans ce fichier source
    if(num<10){
        *res='0';
        *(res+1)=(char)num+0x30;
    } else
    if(num<100){
        unsigned int buff=num/10;
        *res=(char)buff+0x30;
        *(res+1)=(char)num-buff*10+0x30;
    }
    *(res+2)='\0';
    return res;
}

void conv(const conv_enum sel){
	unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
    switch(sel){
        case HMS2S:
            puts("\nPour rappel : Un horaire est de la forme HHMMSS\nAinsi, il est interdit d'entrer des valeurs négatives ou supérieures à 59 pour les secondes et minutes ou à 23 pour les heures!\n");
			input_uint_mv("Nombre d'heures : ",&hours,23,"Le nombre d'heure est invalide!\n");
			input_uint_mv("Nombre de minutes : ",&minutes,59,"Le nombre de minutes est invalide!\n");
			input_uint_mv("Nombre de secondes : ",&seconds,59,"Le nombre de secondes est invalide!\n");
			printf("\nValeur en Secondes : %us\n",conv_hms2sec(hours,minutes,seconds));
            break;
        case S2HMS:
            puts("\nAttention : le nombre de secondes ne peut être supérieur à 86399, sinon il ne s'agit pas d'un horaire\n");
			input_uint_mv("Valeur en Secondes : ",&seconds,86399,"Le nombre de secondes spécifié ne peut être converti en horaire!\n");
			conv_sec2hms(&hours,&minutes,&seconds);
			printf("Valeur Horaire : %sh%sm%ss\n",to2numf(hours),to2numf(minutes),to2numf(seconds));
            break;
        default:break;
    }
}
