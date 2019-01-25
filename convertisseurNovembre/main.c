#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <windows.h> // Inclut avec wincmd.h mais par soucis de clarté, le laisser ici ne pose pas de problème grâce à l'include guard mis en place dans wincmd.h
#include "wincmd.h"
// Booléens
typedef uint8_t boolean; // uint8_t est égal à unsigned char

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

// Il est possible de mettre tout le contenu de ce define sur une seule ligne, mais par soucis de clarté il vaut mieux retourner à la ligne grâce à '\'
// Affiche une erreur en rouge et la fait sortir via le stderr (sortie standard des erreurs) afin de pouvoir les enregistrer dans un fichier si besoin
#define PRINTERROR(_MESSAGE_) \
	WINCMDSETCOLOR(WINCMD_COLOR_WHITE,WINCMD_COLOR_BLACK) \
	fprintf(stderr,"\nErreur : "); \
	WINCMDSETCOLOR(WINCMD_COLOR_RED,WINCMD_COLOR_BLACK) \
	fprintf(stderr,_MESSAGE_); \
	CMDRESETCOLOR

// Message d'erreur affiché quand le choix est invalide
#define PRINTINVALIDCHOICE PRINTERROR("Cela n'est pas un choix valide !\n")

// Affiche un titre de sous-menu en couleurs
#define PRINTSUBMENUTTL(_TTL_) \
	WINCMDSETCOLOR(WINCMD_COLOR_PINK,WINCMD_COLOR_BLACK) \
	printf(_TTL_); \
	CMDRESETCOLOR

// Demande à l'utilisateur de sélectionner une option et lui montre la liste d'options disponibles
#define MENUCHOICE(_MESSAGE_) \
	WINCMDSETCOLOR(WINCMD_COLOR_BLUEGREY,WINCMD_COLOR_BLACK) \
	printf("\nSélectionnez une option"); \
	CMDRESETCOLOR \
	printf(_MESSAGE_); \
	SCANF("%d",&choice)

// Permet de faire un scanf de façon sécurisée de sorte que le programme ne se comporte pas de manière imprévue si on entre un flottant à la place d'un entier non signé par exemple
#define SCANF(_FORMAT_,_POINTER_) \
	if (!scanf(_FORMAT_,_POINTER_)){ \
		PRINTERROR("Vous avez entré une valeur non conforme et avez fait planter le programme!\nFermeture...") \
		Sleep(5000); \
		exit(EXIT_FAILURE); \
	}

int main(void)
{
	SetConsoleOutputCP(1252); // Permet d'afficher les accents
	SetConsoleTitleA("Convertisseur Novembre - fait par : Antoine Tournepiche et Florian Mayeux-Gudina");
	WINCMDSETCOLOR(WINCMD_COLOR_TURQUOISE,WINCMD_COLOR_BLACK)
	printf("Convertisseur (travail à faire pendant les vacances d'Octobre)\n");
	WINCMDSETCOLOR(WINCMD_COLOR_YELLOW,WINCMD_COLOR_BLACK)
	printf("fait par le binôme : Antoine Tournepiche et Florian Mayeux-Gudiña\n");
	CMDRESETCOLOR
	boolean stay; // Booléen qui indique si l'on veut continuer d'exécuter le programme
	stay=TRUE; // Vrai : l'utilisateur veut continuer à utiliser le programme (stay -> rester)
	int choice; // choice est utilisé pour différents choix (économie de RAM) : afin d'optimiser la vitesse, il s'agit d'un int normal et non d'un int non signé
	while(stay){
		MENUCHOICE("\n1: Conversion Celsius/Fahrenheit\n2: Conversion Miles/Km\n3: Conversion Litres/Gallons\n4: Conversion Centimètres/Pouces\n5: Conversion Horaire/Secondes\n0: Sortir du programme\n\nChoix : ")
		switch(choice){
			case 0 :
				stay=FALSE; // L'utilisateur veut quitter le programme
				break;
			case 1 :
				while(choice!=0){
					PRINTSUBMENUTTL("\nConversion Celsius/Fahrenheit\n")
					MENUCHOICE("\n1: Convertir Celsius en Fahrenheit\n2: Convertir Fahrenheit en Celsius\n0: Retour au menu principal\n\nChoix : ")
					float temp; // température
					switch(choice){
						case 0: break; // N'affiche pas que quitter le menu est un choix invalide
						case 1:
							printf("\nValeur en degrés Celsius : ");
							SCANF("%f",&temp)
							temp=temp*1.8+32; // Conversion en Fahrenheit
							printf("Valeur en degrés Fahrenheit : %.2f°F\n",temp);
							break;
						case 2:
							printf("\nValeur en degrés Fahrenheit : ");
							SCANF("%f",&temp)
							temp=(temp-32)/1.8; // Conversion en Celsius
							printf("Valeur en degrés Celsius : %.2f°C\n",temp);
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
					MENUCHOICE("\n1: Convertir Miles en Kilomètres\n2: Convertir Kilomètres en Miles\n0: Retour au menu principal\n\nChoix : ")
					float dist; // distance
					switch(choice){
						case 0: break; // N'affiche pas que quitter le menu est un choix invalide
						case 1:
						    do {
                                printf("\nValeur en Miles : ");
                                SCANF("%f",&dist)
                                if (dist<0){
                                    PRINTERROR("Une distance ne peut être négative!\n")
                                }
						    } while(dist<0);
                            dist=dist*1.609344; // Conversion en Kilomètres
							printf("Valeur en Kilomètres : %.5fkm\n",dist);
							break;
						case 2:
						    do {
                                printf("\nValeur en Kilomètres : ");
                                SCANF("%f",&dist)
                                if (dist<0){
                                    PRINTERROR("Une distance ne peut être négative!\n")
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
					MENUCHOICE("\n1: Convertir Litres en Gallons US\n2: Convertir Litres en Gallons Impériaux\n3: Convertir Gallons US en Litres\n4: Convertir Gallons Impériaux en Litres\n5: Convertir Gallons Impériaux en Gallons US\n6: Convertir Gallons US en Gallons Impériaux\n0: Retour au menu principal\n\nChoix : ")
					float vol; // volume
					switch(choice){
						case 0: break; // N'affiche pas que quitter le menu est un choix invalide
						case 1:
                            do {
                                printf("\nValeur en Litres : ");
                                SCANF("%f",&vol)
                                if (vol<0){
                                    PRINTERROR("Un volume ne peut être négatif!\n")
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
                                    PRINTERROR("Un volume ne peut être négatif!\n")
                                }
						    } while (vol<0);
							vol=vol/4.54609; // Conversion en Gallons UK / Impériaux
							printf("Valeur en Gallons Impériaux : %.6fgal Imp\n",vol);
							break;
						case 3:
                            do {
                                printf("\nValeur en Gallons US : ");
                                SCANF("%f",&vol)
							    if (vol<0){
                                    PRINTERROR("Un volume ne peut être négatif!\n")
                                }
						    } while (vol<0);
							vol=vol*3.785411784; // Conversion en Litres
							printf("Valeur en Litres : %.6fL\n",vol);
							break;
						case 4:
						    do {
                                printf("\nValeur en Gallons Impériaux : ");
                                SCANF("%f",&vol)
							    if (vol<0){
                                    PRINTERROR("Un volume ne peut être négatif!\n")
                                }
						    } while (vol<0);
							vol=vol*4.54609; // Conversion en Litres
							printf("Valeur en Litres : %.6fL\n",vol);
							break;
						case 5:
						    do {
                                printf("\nValeur en Gallons Impériaux : ");
                                SCANF("%f",&vol)
							    if (vol<0){
                                    PRINTERROR("Un volume ne peut être négatif!\n")
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
                                    PRINTERROR("Un volume ne peut être négatif!\n")
                                }
						    } while (vol<0);
							vol=vol*3.785411784/4.54609; // Conversion en Gallons Impériaux (3.785411784/4.54609)
							printf("Valeur en Gallons Impériaux : %.6fgal Imp\n",vol);
							break;
						default:
							PRINTINVALIDCHOICE
							break;
					}
				}
				break;
		   case 4 :
				while(choice!=0){
					PRINTSUBMENUTTL("\nConversion Centimètres/Pouces\n")
					MENUCHOICE("\n1: Convertir Centimètres en Pouces\n2: Convertir Pouces en Centimètres\n0: Retour au menu principal\n\nChoix : ")
					float size; // taille en cm ou pouces
					switch(choice){
						case 0: break; // N'affiche pas que quitter le menu est un choix invalide
						case 1:
						    do {
                                printf("\nValeur en Centimètres : ");
                                SCANF("%f",&size)
							    if (size<0){
                                    PRINTERROR("Une taille ne peut être négative!\n")
                                }
						    } while (size<0);
							size=size/2.54; // Conversion en Centimètres
							printf("Valeur en Pouces : %.6fpo\n",size);
							break;
						case 2:
						    do {
                                printf("\nValeur en Pouces : ");
                                SCANF("%f",&size)
							    if (size<0){
                                    PRINTERROR("Une taille ne peut être négative!\n")
                                }
						    } while (size<0);
							size=size*2.54; // Conversion en Centimètres
							printf("Valeur en Centimètres : %.6fcm\n",size);
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
					// Les variables locales sont déclarées ici car on ne peut le faire dans une boucle switch directement
					uint32_t sec;
					unsigned int hour=0;
					unsigned int minute=0;
					switch(choice){
						case 0: break; // N'affiche pas que quitter le menu est un choix invalide
						case 1:
							printf("\nPour rappel : Un horaire est de la forme HHMMSS\nAinsi, il est interdit d'entrer des valeurs négatives ou supérieures à 59 pour les secondes et minutes ou à 23 pour les heures!\n\n");
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
							printf("\nAttention : le nombre de secondes ne peut être supérieur à 86399, sinon il ne s'agit pas d'un horaire\n\n");
							do {
								printf("Valeur en Secondes : ");
								SCANF("%u",&sec)
								if (sec>86399){
									PRINTERROR("Le nombre de secondes est trop grand pour être converti en horaire!\n\n");
								}
							} while(sec>86399);
							/*  Le code suivant peut être remplacé par une seule ligne :
                                    printf("Valeur Horaire : %.0fh%.0fm%ds\n",(float)(sec/3600),(float)((sec/60)%60),sec%60);
                                        (façon totalement gérée par le développeur)
                                        En effet, "%.0f" permet de ne pas afficher la virgule flottante et donc de
                                        ne pas avoir à utiliser la fonction floor de la lib standard math.h
                                OU encore sur une seule ligne :
                                    printf("Valeur Horaire : %dh%dm%ds\n",sec/3600,(sec/60)%60,sec%60);
                                        (façon se basant sur la concatenation des flottants en entier via suppression de la partie flottante,
                                         et pas en arrondissant [sinon méthode échoue])
                                OU encore sur plusieurs lignes en utilisant les résultats calculés les uns après les autres :
                                    hour=sec/3600;
                                    minute=(sec-hour*3600)/60;
                                    sec=sec-hour*3600-minute*60;
                                    printf("Valeur Horaire : %uh%um%us\n",hour,minute,sec);
                                        (façon se basant sur la concaténation des flottants en entier via suppression de la partie flottante,
                                        et pas en arrondissant [sinon méthode échoue])
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
