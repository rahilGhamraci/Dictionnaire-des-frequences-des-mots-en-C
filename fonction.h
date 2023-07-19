#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include<stdio.h>


typedef struct Liste Liste;
struct Liste
{ char mot[50] ;
 Liste *svt;
};
typedef struct Liste* listeMots;

typedef struct noeud1 * listeFreq;
  typedef struct noeud1{
        char *mot;
        int   freq;
        listeFreq svt;
  }noeud1;

   typedef struct noeud2 * dictContexte;
    typedef struct noeud2{
      char*mot;
      listeFreq cont;
      dictContexte svt;
    } noeud2;

char* creationChaine ();
long taille(FILE *);
listeMots mots(char* );
listeMots motsDe(char* );
int frequences(listeMots ,char * );
listeFreq min(listeFreq );
listeFreq frequencesDe(char* );
listeFreq max(listeFreq );
listeFreq contexte(char * , char * );
listeFreq contexte1(listeMots , char * );
dictContexte creerDict( listeMots  ,listeMots );
char *maxContexte(dictContexte , char* ) ;
int freqCont(dictContexte ,char *, char*);
char * random(dictContexte );
void genererText(dictContexte , int );
// les procedures d'affichage
void afficherListeMots(listeMots );
void afficherListeFreq(listeFreq );
void afficherContexte(listeFreq );
void affichermaxContexte(char*  , char* );
void afficherfreqCont(char* , char* , int);
void afficherDict(dictContexte );


#endif // FONCTION_H_INCLUDED
