#include <stdio.h>
#include <stdlib.h>
#include "MatriceDense.h"
#include "MatriceBande.h"
#include "MatriceInf.h"
#include "MatriceSup.h"
#include "Vecteur.h"
void menuMatriceBande(int *** Matrice,int* n,int *s,int *r){
        int choix=-1;

    while (choix!=2){
   do
    printf("/******* SAISIE VOTRE CHOIX *******/\n");
    printf("SASIE 0 POUR CREATION MATRICE Bande\n");
    printf("SASIE 1 POUR Affichage MATRICE\n");
    printf("SASIE 2 POUR SORTIR\n");
    scanf("%d",&choix);
   }while (choix<0 && choix>2);

   switch (choix)
   {
   case 0:
    *Matrice=MatriceBande(n,s,r);
    break;
    case 1:
    AffichageMatriceDense(*Matrice,*n);
    break;
    case 2:
    choix=2;
    break;
   }
   }

}
void menuMatriceDense(int ***MatDense,int*** MatInf,int*** MatSup,int*** L,int*** U,int* Vect
                      ,int** b,int* n){
                          int choix=-1;
    while (choix!=12){

   do{
    printf("/******* SAISIE VOTRE CHOIX *******/\n");
    printf("SASIE 0 POUR CREATION MATRICE\n");
    printf("SASIE 1 POUR AFFICHAGE MATRICE\n");
    printf("SASIE 2 POUR Multiplication MATRICE Avec VECTEUR\n");
    printf("SASIE 3 POUR Multiplication MATRICE Avec MATRICE DENSE\n");
    printf("SASIE 4 POUR Multiplication MATRICE Au Carréé\n");
    printf("SASIE 5 POUR Multiplication MATRICE Avec Transposéé\n");
    printf("SASIE 6 POUR Multiplication MATRICE Avec Matrice Inf\n");
    printf("SASIE 7 POUR Multiplication MATRICE Avec Matrice Sup\n");
    printf("SASIE 8 POUR Décomposition LU\n");
    printf("SASIE 9 POUR Décomposition Cholesky\n");
    printf("SASIE 10 POUR Gauss Avec Vecteur\n");
    printf("SASIE 11 POUR Gauss Jordan Vecteur\n");
    printf("SASIE 12 POUR SORTIR\n");
    scanf("%d",&choix);
   }while (choix<0 && choix>12);

   switch (choix)
   {
   case 0:
    (*MatDense)=MatriceDense(n);
    break;
    case 1:
    AffichageMatriceDense(*MatDense,*n);
    break;
    case 2:
    *Vect=MultiplicationMatVect(*MatDense,*n,*Vect);
    break;
    case 3:
    *MatDense=MultiplicationMat(*MatDense,*n,MatriceDense(*n));
    break;
    case 4:
    *MatDense=MultiplicationMatCar(*MatDense,*n);
    break;
    case 5:
    *MatDense=MultiplicationMatTransp(*MatDense,*n);
    break;
    case 6:
    *MatDense=MultiplicationMatinf(*MatDense,*n,*MatInf);
    break;
    case 7:
    *MatDense=MultiplicationMatinf(*MatDense,*n,*MatSup);
    break;
    case 8:
    LU(*MatDense,L,U,*n);
    break;
    case 9:
    //
    break;
    case 10:
    GaussAvecVecteur(*MatDense,*b,Vect,*n);
    break;
    case 11:
    Gauss_Jordan_vecteur(*MatDense,*b,Vect,*n);
    break;
    case 12:
    choix=12;
   }
   }
}
void menuMatriceInf(int*** MatInf,int*** MatInf2,int*** MatDense,int*** MatSup,int** Vect,int** b,int *n){
    while (1){
    int choix=-1;
    do{
    printf("/******* SAISIE VOTRE CHOIX *******/\n");
    printf("SASIE 0 POUR CREATION MATRICE\n");
    printf("SASIE 1 POUR AFFICHAGE MATRICE\n");
    printf("SASIE 2 POUR Multiplication MATRICE Avec Matrice DENSE\n");
    printf("SASIE 3 POUR Multiplication MATRICE Avec MATRICE INF\n");
    printf("SASIE 4 POUR Multiplication MATRICE Avec MATRICE SUP\n");
    printf("SASIE 5 POUR Résolution Matrice Inf ou diag l = 1\n");
    printf("SASIE 6 POUR SORTIR\n");
    scanf("%d",&choix);
   }while (choix<0 && choix>6;

   switch (choix)
   {
   case 0:
    *MatInf=MatriceTriangulaireInf(n);
    break;
    case 1:
    AffichageMatriceInf(*MatInf,*n);
    break;
    case 2:
    MatDense=MultMatriceInfxDense(*MatInf,*n,*MatDense);
    break;
    case 3:
    MatDense=MultMatriceInfxInf(*MatInf,*n,*MatInf2);
    break;
    case 4:
    MatDense=MultiplicationMatInfxSup(*MatInf,*n,*MatSup);
    break;
    case 5:
    resolution_inf_1(*MatInf,*Vect,*b,*n);
    break;
    case 6:
    choix=6;
   }
   }
}
void menuMatriceSup(int*** MatInf,int*** MatSup2,int*** MatDense,int*** MatSup,int** Vect,int** b,int *n){
while (1){
    int choix=-1;
    do{
    printf("/******* SAISIE VOTRE CHOIX *******/\n");
    printf("SASIE 0 POUR CREATION MATRICE\n");
    printf("SASIE 1 POUR AFFICHAGE MATRICE\n");
    printf("SASIE 2 POUR Multiplication MATRICE Avec Matrice DENSE\n");
    printf("SASIE 3 POUR Multiplication MATRICE Avec MATRICE INF\n");
    printf("SASIE 4 POUR Multiplication MATRICE Avec MATRICE SUP\n");
    printf("SASIE 5 POUR Résolution Matrice Inf ou diag l = 1\n");
    printf("SASIE 6 POUR SORTIR\n");
    scanf("%d",&choix);
   }while (choix<0 && choix>6);

   switch (choix)
   {
   case 0:
    *MatSup=MatriceTriangulaireSup(n);
    break;
    case 1:
    AffichageMatriceSup(*MatSup,*n);
    break;
    case 2:
    *MatDense=MultMatriceSupxDense(*MatSup,*n,*MatDense);
    break;
    case 3:
    *MatDense=MultiplicationMatSupxInf(*MatSup,*n,*MatInf);
    break;
    case 4:
    *MatDense=MultiplicationMatSupxSup(*MatSup,*n,*MatSup2);
    break;
    case 5:
    resolution_sup_vect(*MatSup,*Vect,*b,*n);
    break;
    case 6:
    choix=6;
    break;
   }
}}
void menuVecteur(int** Vect,int *n){
while (1){
    int choix=-1;
    do{
    printf("/******* SAISIE VOTRE CHOIX *******/\n");
    printf("SASIE 0 POUR CREATION Vecteur\n");
    printf("SASIE 1 POUR AFFICHAGE Vecteur\n");
    printf("SASIE 2 POUR SORTIR\n");
    scanf("%d",&choix);
   }while (choix<0 && choix>2);

   switch (choix)
   {
   case 0:
    *Vect=Vecteur(n);
    break;
    case 1:
    AffichageVecteur(*Vect,*n);
    break;
    case 2:
    choix=2;
    break;
   }
}}
int main()
{
while (1){
    int choix=-1;
    int ** MatDense,**MatInf,**MatInf2,**MatSup,**MatSup2,**MatBande,**L,**U;
    int *b,*Vect;
    int n,r,s;
    do{
    printf("/******* SAISIE VOTRE CHOIX *******/\n");
    printf("SASIE 0 POUR  Choisir Menu Matrice Bande \n");
    printf("SASIE 1 POUR  Choisir Menu Matrice Dense\n");
    printf("SASIE 2 POUR  Choisir Menu Matrice Inf\n");
    printf("SASIE 3 POUR  Choisir Menu Matrice Sup\n");
    printf("SASIE 4 POUR  Choisir Menu Vecteur Sup\n");
    printf("SASIE 5 POUR SORTIR\n");
    scanf("%d",&choix);
   }while (choix<0 && choix>5);
   switch (choix)
   {
   case 0:
    menuMatriceBande(&MatDense,&n,&s,&r);
    break;
    case 1:
    menuMatriceDense(&MatDense,&MatInf,&MatSup,&L,&U,&Vect,&b,&n);
    break;
    case 2:
    menuMatriceInf(&MatInf,&MatInf2,&MatDense,&MatSup,&Vect,&b,&n);
    break;
    case 3:
    menuMatriceSup(&MatInf,&MatSup2,&MatDense,&MatSup,&Vect,&b,&n);
    break;
    case 4:
    menuVecteur(&Vect,&n);
    break;
    case 5:
    exit(-1);
}
}}
