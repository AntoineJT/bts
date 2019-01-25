#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// NUM_EXO -> 1, 2 ou 3
#define NUM_EXO     1

int main(void)
{
    SetConsoleOutputCP(1252);
    const float classe[20][5]={{10,15,20,4,2},{4,7,2,1.5,19.75}};
    float somme;
    #if NUM_EXO==1
    puts("Ce programme calcule la moyenne de chaque élève de la classe (20 élèves)");
    for(unsigned int i=0;i<20;i++){
        somme=0;
        for (unsigned int j=0;j<5;j++)
            somme+=classe[i][j];
        printf("Moyenne de l'élève n°%u = %.2f\n",i+1,somme/5);
    }
    #elif NUM_EXO==2
    puts("Ce programme calcule la moyenne de chaque devoir en fonction des notes des élèves de la classe (20 élèves)");
    for(unsigned int i=0;i<5;i++){
        somme=0;
        for(unsigned int j=0;j<20;j++)
            somme+=classe[j][i];
        printf("Moyenne des élèves au devoir n°%u = %.2f\n",i+1,somme/20);
    }
    #elif NUM_EXO==3
    somme=0;
    float notemax=0;
    unsigned int eleve;
    printf("Ce programme affiche les 5 notes d'un étudiant choisi par l'utilisateur, sa meilleure note et sa moyenne\nElève (de 1 à 20) n°");
    scanf("%u",&eleve); // on récupère le numéro de l'élève (indice+1)
    eleve--; // on récupère l'indice
    float note;
    for(unsigned int i=0;i<5;i++){
        note=classe[eleve][i];
        printf("Note n°%u = %.2f\n",i+1,note);
        somme+=note;
        if(note>notemax)
            notemax=note;
    }
    printf("Meilleure note : %.2f\nMoyenne : %.2f",notemax,somme/5);
    #else
    #pragma GCC diagnostic ignored "-Wunused-variable" // on s'en fout que les variables/constantes déclarées ne soient pas utilisées
    #error "Cet exercice n'existe pas"
    #endif
    return EXIT_SUCCESS;
}
