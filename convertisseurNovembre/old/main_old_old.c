#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "wincmd.h"
//#include <windows.h> // Inutile car d�j� inclus dans le wincmd.h : gr�ce � l'include guard utilis� dans windows.h, cela ne produirait pas d'erreur, mais serait inutile car n'inclurait rien
// Bool�ens
#define BFALSE 0
#define BTRUE 1
typedef struct {
	uint8_t i : 1; // Le bool�en est stock� sur 1 bit : il a donc 2 valeurs possibles � savoir 0 et 1, faux ou vrai
} Boolean; // Boolean est plus propre que bool_ ou boolean_ (boolean, bool, BOOL, BOOLEAN... sont d�j� d�finis)

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
	scanf("%d",&choice);


int main(void)
{
	SetConsoleOutputCP(1252); // Permet d'afficher les accents
	SetConsoleTitleA("Convertisseur Novembre - fait par : Antoine Tournepiche et Florian Mayeux-Gudina");
	WINCMDSETCOLOR(WINCMD_COLOR_TURQUOISE,WINCMD_COLOR_BLACK)
	printf("Convertisseur (travail � faire pendant les vacances d'Octobre)\n");
	WINCMDSETCOLOR(WINCMD_COLOR_YELLOW,WINCMD_COLOR_BLACK)
	printf("fait par le bin�me : Antoine Tournepiche et Florian Mayeux-Gudi�a\n");
	CMDRESETCOLOR
	Boolean stay; // Bool�en qui indique si l'on veut continuer d'ex�cuter le programme
	stay.i=BTRUE; // Vrai : l'utilisateur veut continuer � utiliser le programme (stay -> rester)
	int choice; // choice est utilis� pour diff�rents choix (�conomie de RAM) : afin d'optimiser la vitesse, il s'agit d'un int normal et non d'un int non sign� sur 3 bits
	while(stay.i){
		MENUCHOICE("\n1: Conversion Celsius/Fahrenheit\n2: Conversion Miles/Km\n3: Conversion Litres/Gallons\n4: Conversion Centim�tres/Pouces\n5: Conversion Horaire/Secondes\n0: Sortir du programme\n\nChoix : ")
		switch(choice){
			case 0 :
				stay.i=BFALSE; // L'utilisateur veut quitter le programme
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
							scanf("%f",&temp);
							temp=temp*1.8+32; // Conversion en Fahrenheit
							printf("Valeur en degr�s Fahrenheit : %.2f�F\n",temp);
							break;
						case 2:
							printf("\nValeur en degr�s Fahrenheit : ");
							scanf("%f",&temp);
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
							printf("\nValeur en Miles : ");
							scanf("%f",&dist);
							dist=dist*1.609344; // Conversion en Kilom�tres
							printf("Valeur en Kilom�tres : %.2fkm\n",dist);
							break;
						case 2:
							printf("\nValeur en Kilom�tres : ");
							scanf("%f",&dist);
							dist=dist/1.609344; // Conversion en Miles
							printf("Valeur en Miles : %.2fmi\n",dist);
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
							printf("\nValeur en Litres : ");
							scanf("%f",&vol);
							vol=vol/3.785411784; // Conversion en Gallons US
							printf("Valeur en Gallons US : %.2fgal US\n",vol);
							break;
						case 2:
							printf("\nValeur en Litres : ");
							scanf("%f",&vol);
							vol=vol/4.54609; // Conversion en Gallons UK / Imp�riaux
							printf("Valeur en Gallons Imp�riaux : %.2fgal Imp\n",vol);
							break;
						case 3:
							printf("\nValeur en Gallons US : ");
							scanf("%f",&vol);
							vol=vol*3.785411784; // Conversion en Litres
							printf("Valeur en Litres : %.2fL\n",vol);
							break;
						case 4:
							printf("\nValeur en Gallons Imp�riaux : ");
							scanf("%f",&vol);
							vol=vol*4.54609; // Conversion en Litres
							printf("Valeur en Litres : %.2fL\n",vol);
							break;
						case 5:
							printf("\nValeur en Gallons Imp�riaux : ");
							scanf("%f",&vol);
							vol=vol*4.54609/3.785411784; // Conversion en Gallons US (4.54609/3.785411784)
							printf("Valeur en Gallons US : %.2fgal US\n",vol);
							break;
						case 6:
							printf("\nValeur en Gallons US : ");
							scanf("%f",&vol);
							vol=vol*3.785411784/4.54609; // Conversion en Gallons Imp�riaux (3.785411784/4.54609)
							printf("Valeur en Gallons Imp�riaux : %.2fgal Imp\n",vol);
							break;
						default:
							PRINTINVALIDCHOICE
							break;
					}
				}
				break;
		   case 4 :
				while(choice!=0){
					PRINTSUBMENUTTL("\nConversion Miles/Km\n")
					MENUCHOICE("\n1: Convertir Centim�tres en Pouces\n2: Convertir Pouces en Centim�tres\n0: Retour au menu principal\n\nChoix : ")
					float size; // taille en cm ou pouces
					switch(choice){
						case 0: break; // N'affiche pas que quitter le menu est un choix invalide
						case 1:
							printf("\nValeur en Centim�tres : ");
							scanf("%f",&size);
							size=size/2.54; // Conversion en Centim�tres
							printf("Valeur en Pouces : %.3fpo\n",size);
							break;
						case 2:
							printf("\nValeur en Pouces : ");
							scanf("%f",&size);
							size=size*2.54; // Conversion en Centim�tres
							printf("Valeur en Centim�tres : %.2fcm\n",size);
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
					uint32_t sec;
					unsigned int buff; // buffer permettant de remplir la structure d�finie plus haut
					struct {
						unsigned int
							hh : 5, // 0 � 31 : valeurs utilis�es : 0 � 23
							mm : 6; // 0 � 63 : valeurs utilis�es : 0 � 59
					} clock; // Permet d'�conomiser de la RAM
					switch(choice){
						case 0: break; // N'affiche pas que quitter le menu est un choix invalide
						case 1:
							printf("\n");
							do {
								printf("Nombre d'heures : ");
								scanf("%ud",&buff);
								if (buff>23){
									PRINTERROR("Le nombre d'heure est trop grand!\n\n");
								}
							} while(buff>23);
							sec=buff*3600;
							do {
								printf("Nombre de minutes : ");
								scanf("%ud",&buff);
								if (buff>59){
									PRINTERROR("Le nombre de minutes est trop grand!\n\n");
								}
							} while(buff>59);
							sec+=buff*60;
							do {
								printf("Nombre de secondes : ");
								scanf("%ud",&buff);
								if (buff>59){
									PRINTERROR("Le nombre de secondes est trop grand!\n\n");
								}
							} while(buff>59);
							sec+=buff;
							printf("\nValeur en Secondes : %" SCNu32 "s\n",sec);
							break;
					   case 2:
							do {
								printf("\nValeur en Secondes : ");
								scanf("%" SCNu32,&sec);
								if (sec>86399){
									PRINTERROR("Le nombre de secondes est trop grand pour �tre converti en horaire!\n\n");
								}
							} while(sec>86399);
							buff=0;
							while(sec>=3600){
								sec-=3600;
								buff++;
							}
							clock.hh=buff;
							buff=0;
							while(sec>=60){
								sec-=60;
								buff++;
							}
							clock.mm=buff;
							printf("Valeur Horaire : %uh%um%us\n",clock.hh,clock.mm,sec);
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
