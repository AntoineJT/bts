#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __WIN32
#include <windows.h>
#endif

#define FLUSHSTDIN while(getchar()!='\n');

int main(void)
{
    #ifdef __WIN32
    SetConsoleOutputCP(1252);
    #endif
    char* word=malloc(100*sizeof(char)); // 99 chars
    printf("Entrez un mot � faire deviner � votre adversaire : ");
    scanf("%s",word); // TODO Faire en sorte que plante pas si sup�rieur � mem allou�e
    FLUSHSTDIN
    #ifdef __WIN32
    system("cls");
    #endif // __WIN32
    unsigned int len=strlen(word);
    char* arr=malloc((len+1)*sizeof(char));
    memset(arr,'_',len);
    *(arr+len)='\0'; // stupid hack
    char buff;
    unsigned int trials=5;
    while(trials!=0){ // jnz
        printf("Mot : %s\nEntrez une lettre : ",arr);
        scanf("%1c",&buff);
        FLUSHSTDIN
        /* Searching method */
        // TODO To Improve
        char* cPtr=strchr(word,buff); // first occurence
        if (cPtr==NULL){
            trials--;
            printf("Ce caract�re n'est pas dans le mot.\nIl vous reste %u essais.\n",trials);
        } else {
            #if 0
            unsigned int pos1=cPtr-arr-32; // fonctionne juste pour 'test' // needs to better understand that shitty thing
            printf("%u",pos1);
            *(arr+pos1)=buff;
            cPtr=strrchr(word,buff);
            if (cPtr!=NULL){ // if NULL, no more things to change
                unsigned int pos2=cPtr-arr-32; // fonctionne juste pour 'test'
                *(arr+pos2)=buff;
                // TODO Copier la cha�ne de caract�re entre pos1 et pos2 et parcourir l'ensemble pour v�rifier si contenu dedans
            }
            #endif
            #if 0
            do {
                cPtr=strchr(word+1,buff);
                printf("%d\n",cPtr-arr+1);
            } while(cPtr!=NULL);
            #endif
        }
        if (!strcmp(arr,word)){
            printf("Gagn�!\nLe mot �tait effectivement %s.\nIl restait encore %u essais.\n",word,trials);
            break;
        }
    }

    return EXIT_SUCCESS;
}
