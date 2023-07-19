#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int main(int argc, char *argv[]){
char *chaine; char *m1=(char*)malloc(100+1); int i,nbr,nbr1; char n[10],cmpt[10];  char *m2 ; char *m3=(char*)malloc(50+1);
 listeMots listmot1,pop; listeFreq Lf,Lc,q; dictContexte Ld;


  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~<< Bienvenue dans notre programme >>~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

//printf("- Donner un texte: ");
//gets(chaine);
chaine = creationChaine(); pop=mots(chaine); listmot1=motsDe(chaine); Lf=frequencesDe(chaine);

Ld=creerDict(pop,listmot1);


do{
srand(time(0));
printf("------------------------------- Menu -------------------------------\n");
printf("1- La fonction motsDe\n");
printf("2- La fonction frequencesDe\n");
printf("3- La fonction Contexte\n");
printf("4- La fonction Dictionnaire\n");
printf("5- La fonction maxContexte\n");
printf("6- La fonction freqContexte\n");
printf("7- La fonction genererTexte\n");
printf("------------------------------- <<o>> ------------------------------\n\n");

	do{
	printf("- veuillez choisir le numero la fonction que vous voullez executer: "); gets(n);
	} while(n[0]<'1' || n[0]>'7' || n[1]!= '\0') ;

 switch (n[0])
  {
    case '1':
       afficherListeMots(listmot1);
       break;
    case '2':
       afficherListeFreq(Lf);
       break;
    case '3':
        fflush(stdin);printf("\n  vous voulez le contexte de: "); gets(m1);i=0;while(m1[i]!= '\0'){ m1[i]=tolower(m1[i]);i++;}
		Lc=contexte(chaine,m1); afficherContexte(Lc);
       break;
    case '4':
      afficherDict(Ld);
       break;
    case '5':
       printf("\n  vous voulez le max de contexte de: "); gets(m1);i=0;while(m1[i]!= '\0'){ m1[i]=tolower(m1[i]);i++;}
       m2=maxContexte(Ld,m1); affichermaxContexte(m2,m1);
       break;
    case '6':
        printf("\n  Donner un mot: "); gets(m3); printf("  vous voulez le nbr d'app du mot %s dans contexte de: ",m3) ;
  		gets(m1);i=0;while(m1[i]!= '\0'){ m1[i]=tolower(m1[i]);i++;} nbr=freqCont(Ld,m1,m3);afficherfreqCont(m3 ,m1,nbr);
       break;
    case '7':
       printf("\n  Donner le nbr de la sequence: "); scanf("%d",&nbr1);genererText(Ld,nbr1);

       break;

  }


 //*************************************reexecution******************************
  printf("\n- Voulez vous reexecuter le programme? ");
	do{
	printf("oui ou non? ");
	fflush(stdin);
  	gets(cmpt);
	} while(strcmp(cmpt,"oui") && strcmp(cmpt,"non"));


  } while(!strcmp(cmpt,"oui"));

  free(m1);free(m3);
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~<< Merci d'avoir utiliser notre programme >>~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

return 0;
}
