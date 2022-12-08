#include"stdio.h"
int* Vecteur(int *n){
    int i;
    printf("Donner Valeur de n\n");
    scanf("%d",n);
    int* vect=(int * )malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        printf("Donner la case %d\n",i+1);
        scanf("%d",&vect[i]);
    }
    return vect;
}
void AffichageVecteur (int* Vecteur,int n){
    int i;
    for (i=0;i<n;i++){
        printf("Vecteur[%d]: %f \t",i,Vecteur[i]);
    }
    printf("\n");
}
