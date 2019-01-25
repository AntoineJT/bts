#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <windows.h> // Inclut avec wincmd.h mais par soucis de clart�, le laisser ici ne pose pas de probl�me gr�ce � l'include guard mis en place dans wincmd.h
#include "wincmd.h"
// Bool�ens
typedef uint8_t boolean; // uint8_t est �gal � unsigned char

#ifdef FALSE
	#undef FALSE
#endif // FALSE
#ifdef TRUE
	#undef TRUE
#endif // TRUE
#define FALSE 0
#define TRUE 1
// Autres defines
// Permet de remettre la couleur d'origine
#define CMDRESETCOLOR WINCMDSETCOLOR(WINCMD_COLOR_LIGHTGREY,WINCMD_COLOR_BLACK)

// Il est possible de mettre tout le contenu de ce define sur une seule ligne, mais par soucis de clart� il vaut mieux retourner � la ligne gr�ce � '\'
// Affiche une erreur en rouge et la fait sortir via le stderr (sortie standard des erreurs) afin de pouvoir les enregistrer dans un fichier si besoin
#define PRINTERROR(_MESSAGE_) \
	WINCMDSETCOLOR(WINCMD_COLOR_WHITE,WINCMD_COLOR_BLACK) \
	fprintf(stderr,"\nErreur : "); \
	WINCMDSETCOLOR(WINCMD_COLOR_RED,WINCMD_COLOR_BLACK) \
	fprintf(stderr,_MESSAGE_); \
	CMDRESETCOLOR

// Message d'erreur affich� quand le choix est invalide
#define PRINTINVALIDCHOICE PRINTERROR("Cela n'est pas un choix valide !\n")

// Affiche un titre de sous-menu en couleurs
#define PRINTSUBMENUTTL(_TTL_) \
	WINCMDSETCOLOR(WINCMD_COLOR_PINK,WINCMD_COLOR_BLACK) \
	printf(_TTL_); \
	CMDRESETCOLOR

// Demande � l'utilisateur de s�lectionner une option et lui montre la liste d'options disponibles
#define MENUCHOICE(_MESSAGE_) \
	WINCMDSETCOLOR(WINCMD_COLOR_BLUEGREY,WINCMD_COLOR_BLACK) \
	printf("\nS�lectionnez une option"); \
	CMDRESETCOLOR \
	printf(_MESSAGE_); \
	SCANF("%d",&choice)

// Permet de faire un scanf de fa�on s�curis�e de sorte que le programme ne se comporte pas de mani�re impr�vue si on entre un flottant � la place d'un entier non sign� par exemple
#define SCANF(_FORMAT_,_POINTER_) \
	if (!scanf(_FORMAT_,_POINTER_)){ \
		PRINTERROR("Vous avez entr� une valeur non conforme et avez fait planter le programme!\nFermeture...") \
		Sleep(5000); \
		exit(EXIT_FAILURE); \
	}

int main(void)
{
	SetConsoleOutputCP(1252); // Permet d'afficher les accents
	SetConsoleTitleA("Convertisseur Novembre - fait par : Antoine Tournepiche et Florian Mayeux-Gudina");
	WINCMDSETCOLOR(WINCMD_COLOR_TURQUOISE,WINCMD_COLOR_BLACK)
	printf("Convertisseur (travail � faire pendant les vacances d'Octobre)\n");
	WINCMDSETCOLOR(WINCMD_COLOR_YELLOW,WINCMD_COLOR_BLACK)
	printf("fait par le bin�me : Antoine Tournepiche et Florian Mayeux-Gudi�a\n");
	CMDRESETCOLOR
	boolean stay; // Bool�en qui indique si l'on veut continuer d'ex�cuter le programme
	stay=TRUE; // Vrai : l'utilisateur veut continuer � utiliser le programme (stay -> rester)
	int choice; // choice est utilis� pour diff�rents choix (�conomie de RAM) : afin d'optimiser la vitesse, il s'agit d'un int normal et non d'un int non sign�
	while(stay){
		MENUCHOICE("\n1: Conversion Celsius/Fahrenheit\n2: Conversion Miles/Km\n3: Conversion Litres/Gallons\n4: Conversion Centim�tres/Pouces\n5: Conversion Horaire/Secondes\n0: Sortir du programme\n\nChoix : ")
		switch(choice){
			case 0 :
				stay=FALSE; // L'utilisateur veut quitter le programme
				break;
			case 1 :
				while(choice!=0){
					PRINTSUBMENUTTL("\nConversion Celsius/Fahrenheit\n")
					MENUCHOICE("\n1: Convertir Celsius en Fahrenheit\n2: Convertir Fahrenheit en Celsius\n0: Retour au menu principal\n\nChoix : ")
					float temp; // temp�rature
					switch(choice){
						case 0: break; // N'affiche pas que quitter le menu est un choix invalide
						case 1:
							printf("\nValeur en degr�s Celsius : ");
							SCANF("%f",&temp)
							temp=temp*1.8+32; // Conversion en Fahrenheit
							printf("Valeur en degr�s Fahrenheit : %.2f�F\n",temp);
							break;
						case 2:
							printf("\nValeur en degr�s Fahrenheit : ");
							SCANF("%f",&temp)
							temp=(temp-32)/1.8; // Conversion en Celsius
							printf("Valeur en degr�s Celsius : %.2f�C\n",temp);
							break;
						default:
							PRINTINVALIDCHOICE
							break;
					}
				}
				break;
			case 2 :
				while (choice!=0){
					PRINTSUBMENUTTL("\nConversion Miles/Km\n")
					MENUCHOICE("\n1: Convertir Miles en Kilom�tres\n2: Convertir Kilom�tres en Miles\n0: Retour au menu principal\n\nChoix : ")
					float dist; // distance
					switch(choice){
						case 0: break; // N'affiche pas que quitter le menu est un choix invalide
						case 1:
						    do {
                                printf("\nValeur en Miles : ");
                                SCANF("%f",&dist)
                                if (dist<0){
                                    PRINTERROR("Une distance ne peut �tre n�gative!\n")
                                }
						    } while(dist<0);
                            dist=dist*1.609344; // Conversion en Kilom�tres
							printf("Valeur en Kilom�tres : %.5fkm\n",dist);
							break;
						case 2:
						    do {
                                printf("\nValeur en Kilom�tres : ");
                                SCANF("%f",&dist)
                                if (dist<0){
                                    PRINTERROR("Une distance ne peut �tre n�gative!\n")
                                }
						    } while (dist<0);
							dist=dist/1.609344; // Conversion en Miles
							printf("Valeur en Miles : %.5fmi\n",dist);
							break;
						default:
							PRINTINVALIDCHOICE
							break;
					}
				}
				break;
			case 3 :
				while(choice!=0){
					PRINTSUBMENUTTL("\nConversion Litres/Gallons\n")
					MENUCHOICE("\n1: Convertir Litres en Gallons US\n2: Convertir Litres en Gallons Imp�riaux\n3: Convertir Gallons US en Litres\n4: Convertir Gallons Imp�riaux en Litres\n5: Convertir Gallons Imp�riaux en Gallons US\n6: Convertir Gallons US en Gallons Imp�riaux\n0: Retour au menu principal\n\nChoix : ")
					float vol; // volume
					switch(choice){
						case 0: break; // N'affiche pas que quitter le menu est un choix invalide
						case 1:
                            do {
                                printf("\nValeur en Litres : ");
                                SCANF("%f",&vol)
                                if (vol<0){
                                    PRINTERROR("Un volume ne peut �tre n�gatif!\n")
                                }
						    } while (vol<0);
							vol=vol/3.785411784; // Conversion en Gallons US
							printf("Valeur en Gallons US : %.6fgal US\n",vol);
							break;
						case 2:
						    do {
                                printf("\nValeur en Litres : ");
                                SCANF("%f",&vol)
                                if (vol<0){
                                    PRINTERROR("Un volume ne peut �tre n�gatif!\n")
                                }
						    } while (vol<0);
							vol=vol/4.54609; // Conversion en Gallons UK / Imp�riaux
							printf("Valeur en Gallons Imp�riaux : %.6fgal Imp\n",vol);
							break;
						case 3:
                            do {
                                printf("\nValeur en Gallons US : ");
                                SCANF("%f",&vol)
							    if (vol<0){
                                    PRINTERROR("Un volume ne peut �tre n�gatif!\n")
                                }
						    } while (vol<0);
							vol=vol*3.785411784; // Conversion en Litres
							printf("Valeur en Litres : %.6fL\n",vol);
							break;
						case 4:
						    do {
                                printf("\nValeur en Gallons Imp�riaux : ");
                                SCANF("%f",&vol)
							    if (vol<0){
                                    PRINTERROR("Un volume ne peut �tre n�gatif!\n")
                                }
						    } while (vol<0);
							vol=vol*4.54609; // Conversion en Litres
							printf("Valeur en Litres : %.6fL\n",vol);
							break;
						case 5:
						    do {
                                printf("\nValeur en Gallons Imp�riaux : ");
                                SCANF("%f",&vol)
							    if (vol<0){
                                    PRINTERROR("Un volume ne peut �tre n�gatif!\n")
                                }
						    } while (vol<0);
							vol=vol*4.54609/3.785411784; // Conversion en Gallons US (4.54609/3.785411784)
							printf("Valeur en Gallons US : %.6fgal US\n",vol);
							break;
						case 6:
						    do {
                                printf("\nValeur en Gallons US : ");
                                SCANF("%f",&vol)
							    if (vol<0){
                                    PRINTERROR("Un volume ne peut �tre n�gatif!\n")
                                }
						    } while (vol<0);
							vol=vol*3.785411784/4.54609; // Conversion en Gallons Imp�riaux (3.785411784/4.54609)
							printf("Valeur en Gallons Imp�riaux : %.6fgal Imp\n",vol);
							break;
						default:
							PRINTINVALIDCHOICE
							break;
					}
				}
				break;
		   case 4 :
				while(choice!=0){
					PRINTSUBMENUTTL("\nConversion Centim�tres/Pouces\n")
					MENUCHOICE("\n1: Convertir Centim�tres en Pouces\n2: Convertir Pouces en Centim�tres\n0: Retour au menu principal\n\nChoix : ")
					float size; // taille en cm ou pouces
					switch(choice){
						case 0: break; // N'affiche pas que quitter le menu est un choix invalide
						case 1:
						    do {
                                printf("\nValeur en Centim�tres : ");
                                SCANF("%f",&size)
							    if (size<0){
                                    PRINTERROR("Une taille ne peut �tre n�gative!\n")
                                }
						    } while (size<0);
							size=size/2.54; // Conversion en Centim�tres
							printf("Valeur en Pouces : %.6fpo\n",size);
							break;
						case 2:
						    do {
                                printf("\nValeur en Pouces : ");
                                SCANF("%f",&size)
							    if (size<0){
                                    PRINTERROR("Une taille ne peut �tre n�gative!\n")
                                }
						    } while (size<0);
							size=size*2.54; // Conversion en Centim�tres
							printf("Valeur en Centim�tres : %.6fcm\n",size);
							break;
						default:
							PRINTINVALIDCHOICE
							break;
					}
				}
				break;
			case 5:
				while(choice!=0){
					PRINTSUBMENUTTL("\nConversion Horaire/Secondes\n")
					MENUCHOICE("\n1: Convertir Horaire en Secondes\n2: Convertir Secondes en Horaire\n0: Retour au menu principal\n\nChoix : ")
					// Les variables locales sont d�clar�es ici car on ne peut le faire dans une boucle switch directement
					uint32_t sec;
					unsigned int hour=0;
					unsigned int minute=0;
					switch(choice){
						case 0: break; // N'affiche pas que quitter le menu est un choix invalide
						case 1:
							printf("\nPour rappel : Un horaire est de la forme HHMMSS\nAinsi, il est interdit d'entrer des valeurs n�gatives ou sup�rieures � 59 pour les secondes et minutes ou � 23 pour les heures!\n\n");
							do {
								printf("Nombre d'heures : ");
								SCANF("%u",&hour)
								if (hour>23){
									PRINTERROR("Le nombre d'heure est trop grand!\n\n");
								}
							} while(hour>23);
							do {
								printf("Nombre de minutes : ");
								SCANF("%u",&minute)
								if (minute>59){
									PRINTERROR("Le nombre de minutes est trop grand!\n\n");
								}
							} while(minute>59);
							do {
								printf("Nombre de secondes : ");
								SCANF("%u",&sec)
								if (sec>59){
									PRINTERROR("Le nombre de secondes est trop grand!\n\n");
								}
							} while(sec>59);
							sec+=hour*3600+minute*60;
							printf("\nValeur en Secondes : %us\n",sec);
							break;
					   case 2:
							printf("\nAttention : le nombre de secondes ne peut �tre sup�rieur � 86399, sinon il ne s'agit pas d'un horaire\n\n");
							do {
								printf("Valeur en Secondes : ");
								SCANF("%u",&sec)
								if (sec>86399){
									PRINTERROR("Le nombre de secondes est trop grand pour �tre converti en horaire!\n\n");
								}
							} while(sec>86399);
							/*  Le code suivant peut �tre remplac� par une seule ligne :
                                    printf("Valeur Horaire : %.0fh%.0fm%ds\n",(float)(sec/3600),(float)((sec/60)%60),sec%60);
                                        (fa�on totalement g�r�e par le d�veloppeur)
                                        En effet, "%.0f" permet de ne pas afficher la virgule flottante et donc de
                                        ne pas avoir � utiliser la fonction floor de la lib standard math.h
                                OU encore sur une seule ligne :
                                    printf("Valeur Horaire : %dh%dm%ds\n",sec/3600,(sec/60)%60,sec%60);
                                        (fa�on se basant sur la concatenation des flottants en entier via suppression de la partie flottante,
                                         et pas en arrondissant [sinon m�thode �choue])
                                OU encore sur plusieurs lignes en utilisant les r�sultats calcul�s les uns apr�s les autres :
                                    hour=sec/3600;
                                    minute=(sec-hour*3600)/60;
                                    sec=sec-hour*3600-minute*60;
                                    printf("Valeur Horaire : %uh%um%us\n",hour,minute,sec);
                                        (fa�on se basant sur la concat�nation des flottants en entier via suppression de la partie flottante,
                                        et pas en arrondissant [sinon m�thode �choue])
							*/
							while(sec>=3600){
								sec-=3600;
								hour++;
							}
							while(sec>=60){
								sec-=60;
								minute++;
							}
							printf("Valeur Horaire : %uh%um%us\n",hour,minute,sec);
							break;
						default:
							PRINTINVALIDCHOICE
							break;
					}
				}
				break;
			default :
				PRINTINVALIDCHOICE
				break;
		}
	}
	return EXIT_SUCCESS;
}
