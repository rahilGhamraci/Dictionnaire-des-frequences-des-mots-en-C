#include "fonction.h"

//..................................creation motsDe ..........................................................

listeMots motsDe(char* t ){

	listeMots lmot,listmot,p,pred;

	listmot=mots(t);

	lmot=listmot;
	while (lmot != NULL){

		p=(*lmot).svt;
		pred=lmot;
			while(p!=NULL){

				if(!strcmp((*lmot).mot,(*p).mot )){

					(*pred).svt=(*p).svt;
					free(p);
					p=(*pred).svt;

				}else {
					p=(*p).svt;
					pred=(*pred).svt;
				}

			}
			lmot=(*lmot).svt;

	}

	return listmot;
}

//------
listeMots mots(char *t ) {

int i,j,j1,n;
 listeMots P; char *m=(char*)malloc(50+1); m[0]='\0';char *m1=(char*)malloc(50+1); m1[0]='\0';
listeMots L; int n0=0;

n=strlen(t);
t[n+1]='\0';

 i=0;
 while(t[i]!= '\0'){
	j=0;j1=0;
    while(t[i]!=' ' && t[i]!='\0' && t[i]!='\n' && ((t[i]>='A' && t[i]<='Z') || (t[i]>='a' && t[i]<='z')) ){
		m[j]=tolower(t[i]);
        j++;
        i++;
		}
		if (m[0]!='\0'){
		if(n0==0){  P = (Liste *)malloc(10*sizeof(Liste)); //remplissage du 1er élément
 				(*P).svt = NULL;
 				 L=P; n0++; } else { (*P).svt=(Liste *)malloc(10*sizeof(Liste)); P=(*P).svt; (*P).svt=NULL;}
		m[j]='\0';
       strcpy((*P).mot ,m);
        m[0]='\0';
    }


		while(t[i]!=' ' && t[i]!='\0'&& t[i]!='\n' && (t[i]<'A' || (t[i]<'a' && t[i]>'Z'))) {
			m1[j1]=t[i]; j1++; break;
		}


    if (m1[0]!='\0'){
    	if(n0==0){  P = (Liste *)malloc(10*sizeof(Liste)); //remplissage du 1er élément
 				(*P).svt = NULL;
 				 L=P; n0++; } else { (*P).svt=(Liste *)malloc(10*sizeof(Liste)); P=(*P).svt; (*P).svt=NULL;}

		m1[j1]='\0';
       strcpy((*P).mot ,m1);
        m1[0]='\0';
    }

    i++;
 }

 free(m);free(m1);
 return L;

}




//....................................creation fichier........................................................................
long taille(FILE *fichier){
    fseek(fichier,0,SEEK_END);

    return ftell(fichier);
}

//------
char* creationChaine (){
	FILE* fichier = NULL; char*nomFich=(char*)malloc(100+1);

	printf("	<<Donner le nom de votre fichier>>: ");
	gets(nomFich);
	fichier = fopen(nomFich, "r");
	if(fichier==NULL){
		do{
			printf("	//Nous n'avons pas trouver votre fichier, \n	//Si votre fichier ne trouve pas au meme dossier que votre programme\n	//Donner le chemin absolu: ");
			gets(nomFich);
			fichier = fopen(nomFich, "r");
		}while(fichier==NULL);
	}
//-------apres la recuperation du fichier
	long lg = taille(fichier);
    char *chaine1=(char*)malloc(lg+1);chaine1[0]='\0'; char *chaine3=(char*)malloc(lg+1); chaine3[0]='\0'; char m;

    rewind(fichier);
 	m=fgetc(fichier);
 		while (!feof(fichier)){

 		if(m!= '\n'){
 			fseek(fichier, -1, SEEK_CUR);
 			fgets(chaine1, lg, fichier);

 			strcat(chaine3,chaine1);
 			strcat(chaine3," ");
		 }
		 m=fgetc(fichier);
		 }

        fclose(fichier);

        free(chaine1);free(nomFich);

        return chaine3 ;
}







//...........................................fonction freqencesDe.............................................................................
int frequences(listeMots L,char * m){

    listeMots p,pred,t;
    int n=0;
    p=L;
    pred=p;

    while(p!=NULL){

        if(strcmp(p->mot,m)==0){
            n++;


            pred->svt=p->svt;/*suppresion de l'occurence trouvée  -- INC pred */
            t=p;
            p=p->svt;
            free(t);


            }else{
            pred=p;
           p=p->svt;}
    }

    return n;
    }

//------
listeFreq min(listeFreq l){

      listeFreq  pmin=l,p=l->svt;
      while(p!=NULL){
      if(pmin->freq > p->freq){
      pmin=p;
}p=p->svt;

}
return pmin; }

//------
listeFreq frequencesDe(char* t){
    listeFreq L,r,pred,pmin;int x; char *s=(char*)malloc(50+1);if(s==NULL){  printf("erreur allocation");exit(-1);	}
    listeMots l,p;

    l=mots(t);
    p=l;

   listeFreq q=( listeFreq)malloc(sizeof(noeud1));/*creation du premier element de listeFreq*/
// if(q==NULL){  printf("erreur allocation");exit(-1);	}

   q->mot=p->mot;

   q->svt=NULL;
   L=q;
   q->freq=frequences(p,p->mot); // l modifier supp des occ des mots


    p=p->svt;/*pointer sur le deuxieme  mot de l*/

    while(p!=NULL){
        q->svt=( listeFreq)malloc(sizeof(noeud1));
        q=q->svt;
   		q->mot=p->mot;

  		q->svt=NULL;
   		q->freq=frequences(p,p->mot);
    	p=p->svt;

    }


//     /* le trie de la liste*/
 r=L;
    pred=r;
  while(r!=NULL){
   pmin=min(pred);
   if(pmin->freq != pred->freq){
   	strcpy( s,pred->mot);
   strcpy(pred->mot,pmin->mot);
   strcpy(pmin->mot,s);
    x=pred->freq;
    pred->freq=pmin->freq;
    pmin->freq=x;
   }


    pred=r;
    r=r->svt;
  }

    free(s);
      return L;
    }

//.................................fonction contexte.................................
listeFreq max(listeFreq l){

      listeFreq  pmax=l,p=l->svt;
      while(p!=NULL){
      if(pmax->freq < p->freq){
      pmax=p;}

	  p=p->svt; }

	return pmax;
}

//------
listeFreq contexte(char * T, char * m){
listeFreq q1,q2; int n=0,h=0,x;
     listeFreq q=NULL,r,pred,pmax; char *s=(char*)malloc(50+1);
    listeMots p,Pcontexte;

   q1=q;
   p=mots(T);

while (p!=NULL){

	if (strcmp((*p).mot,m)==0){
		if (p->svt!=NULL){Pcontexte = (*p).svt;}else{h=1;break;}

		if(q==NULL){ q=( listeFreq)malloc(sizeof(noeud1)); (*q).mot=Pcontexte->mot ;(*q).freq=1 ;(*q).svt=NULL;   q1=q;q2=q;	}
		else{
			while(q2!=NULL){
				if(!strcmp((*q2).mot,Pcontexte->mot)){
					q2->freq++;n=1;
				}
				q2=q2->svt;
			}

	if(n==0){q1->svt=( listeFreq)malloc(sizeof(noeud1)); q1=q1->svt; (*q1).mot=Pcontexte->mot ;(*q1).freq=1 ;(*q1).svt=NULL;}

			}
			}

p=(*p).svt;q2=q;n=0;
}
if(q==NULL && h==1){
	q=( listeFreq)malloc(sizeof(noeud1)); (*q).mot=" " ;(*q).freq=0 ;(*q).svt=NULL;
}


/*le trie ..........................*/

if(q!=NULL && (*q).mot!=" " ){
	     r=q;
    pred=q;


  while(r!=NULL){

   pmax=max(pred);

   strcpy( s,pred->mot);
   strcpy(pred->mot,pmax->mot);
   strcpy(pmax->mot,s);
    x=pred->freq;
    pred->freq=pmax->freq;
    pmax->freq=x;

    pred=r;
    r=r->svt;
  }
}

free(s);
return q;
   }
//...............................................creation du dictionnaire................................
listeFreq contexte1(listeMots p, char * m){
listeFreq L,q1,q2; int n=0,h=0,x;
      listeFreq q=NULL,r,q5,pred,pmax; char *s=(char*)malloc(100+1);s[0]='\0';
    listeMots p1,Pcontexte;

  q1=q;

while (p!=NULL){

	if (strcmp((*p).mot,m)==0){
		if (p->svt!=NULL){Pcontexte = (*p).svt;}else{h=1;break;}

		if(q==NULL){ q=( listeFreq)malloc(sizeof(noeud1)); (*q).mot=Pcontexte->mot ;(*q).freq=1 ;(*q).svt=NULL;   q1=q;q2=q;	}
		else{
			while(q2!=NULL){
				if(!strcmp((*q2).mot,Pcontexte->mot)){
					q2->freq++;n=1;
				}
				q2=q2->svt;
			}

	if(n==0){q1->svt=( listeFreq)malloc(sizeof(noeud1)); q1=q1->svt; (*q1).mot=Pcontexte->mot ;(*q1).freq=1 ;(*q1).svt=NULL;}

			}
			}

p=(*p).svt;q2=q;n=0;
}
if(q==NULL && h==1){
	q=( listeFreq)malloc(sizeof(noeud1)); (*q).mot=" " ;(*q).freq=0 ;(*q).svt=NULL;
}

/*le trie .........................*/

if(q!=NULL && (*q).mot!=" " ){
	     r=q->svt;
    pred=q;


  while(r!=NULL){

   pmax=max(pred);
if(pmax!=pred){
    s=pred->mot;
   pred->mot=pmax->mot;
   pmax->mot=s;
    x=pred->freq;
    pred->freq=pmax->freq;
    pmax->freq=x;
	pred=r;
    r=r->svt;
 }else{
	break;
	}

  }
}

free(s);
return q;
   }

//------
dictContexte creerDict(listeMots p, listeMots p1){ // p1 mayt3awdouch

  dictContexte q=NULL,q1;

  while (p1!=NULL){

  		if(q==NULL){ q=(dictContexte)malloc(sizeof(noeud2));  q->cont = contexte1(p,p1->mot);  ; (*q).mot=p1->mot; (*q).svt=NULL;   q1=q;	}

		else{
				q1->svt=(dictContexte)malloc(sizeof(noeud2)); q1=q1->svt; q1->cont = contexte1(p,p1->mot); ;(*q1).mot=p1->mot  ;(*q1).svt=NULL;
			}

  	p1=p1->svt;
  }

     return q;

  }
//........................................fonction maxContexte.........................................
char * maxContexte(dictContexte d, char* m){
    int n=0;
     dictContexte p;
     listeFreq q=NULL; char *L=(char*)malloc(10+1); if(L==NULL){  printf("erreur allocation");exit(-1);	}
	 L[0]='\0';

	p=d;
     while(p!=NULL && n==0){

        if(strcmp(p->mot,m)==0){ // chercher le mot dans dictcontexte
            q=p->cont;	//q la liste des contextes
            n=1;
        }
       p=p->svt;}


if(q!=NULL ){ return (*q).mot;} else{ return L; }

			}
//..........................................fonction freqCont...............................................
int freqCont(dictContexte d,char *m, char*n){
     dictContexte p;
     listeFreq q,q1;
      p=d;

      while(p!=NULL){
        if(strcmp(p->mot,m)==0){
            q=p->cont;
            while(q!=NULL){
                if(strcmp(q->mot,n)==0) {return q->freq; }
            q=q->svt;
            }
        }
       p=p->svt;
      }

    }
//.........................................fonction genererText....................................................
char * random(dictContexte d){
int alt,i ;
dictContexte q;
  alt=rand();
 do{
    i=0;
    q=d;
    while(q!=NULL && i!=alt){
        q=q->svt;
        i++;						// O(n) n nbr d'element
    }
 if(q==NULL) {
 	alt=rand()%i;
 }
 }while(q==NULL);


  return q->mot;
}
//------
void genererText(dictContexte d, int n){
    char*m;int i;

    m=random(d);
    printf("|");

    for(i=1;i<=n;i++){
    if(strcmp(m," ")){
    	printf("%s|",m);
        m=maxContexte(d,m);

	}else{
	printf("\n  Le dernier mot n'a pas de contexte");
	break; }

    }
	printf("\n");

  }



// les procedures d'affichage ----------------------------------------------------------
void afficherListeMots(listeMots L){
    listeMots  p=L;
   printf("\n  La fonction motsDe: \n");

   while (p != NULL){
   printf("[%s] \n",(*p).mot);
   p = (*p).svt;}

   }
//-----------
void afficherListeFreq(listeFreq L){
	listeFreq q=L;

	printf("\n  La fonction frequencesDe: \n");
  while (q != NULL){
	printf("|%s| %d \n",(*q).mot,(*q).freq);
	q = (*q).svt;}
  }
//-----------
void afficherContexte(listeFreq L){
   listeFreq  q=L;
  if(q!=NULL ){

  if(q->mot ==" "){ printf("  Le mot n'a pas de contexte\n");}else {
	while (q != 0){
 		printf("|%s| %d \n",(*q).mot,(*q).freq);
 		q = (*q).svt;}	}

  } else { printf("  Le mot que vous avez entrer n'existe pas\n");  }
}
//-----------
void affichermaxContexte(char* m2 , char* m1){

	if(m2[0]!='\0'){

if(!strcmp(m2," ")){
printf("  Le mot %s n'a pas de contexte\n",m1);
}else{
printf("  Le contexte max : %s\n",m2);
}
}else {printf("  Le mot %s n'existe pas dans votre texte\n",m1); }
}

void afficherfreqCont(char* m3 , char* m1, int nbr){
	printf("  Le nbr d'app du mot %s dans le contexte de %s est: %d\n",m3,m1,nbr);
}


void afficherDict(dictContexte d){
listeFreq q;
  printf("\n L'affichage de dictionnaire \n");
  while(d!=0){
    printf("[%s]\n",(*d).mot);
    q=d->cont;
 printf("{");
 while (q != 0){
 printf(" |%s| %d ",(*q).mot,(*q).freq);
    q = (*q).svt;
 }  printf("}");
  printf("\n\n");
   d=(*d).svt;
  }
}
