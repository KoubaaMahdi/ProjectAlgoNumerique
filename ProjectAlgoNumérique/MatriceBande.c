#include <stdio.h>
#include <stdlib.h>
int** MatriceBande(int *n,int *s,int* r){
    int i,j,x;
    printf("Donner Valeur de n,s,r\n");
    scanf("%d %d %d",n,s,r);
    int ** v = (int**)malloc(*n*sizeof(int*));
    for(i=0;i<*n;i++){
        v[i] = (int *)calloc(*n,sizeof(int));
    }
    for(i=0;i<*r;i++){
        for(j=0;j<*s+i;j++){
            printf("Donner la case %d de la ligne %d\n",j+1,i+1);
            scanf("%d",&v[i][j]);
        }
    }
    for(i=*r;i<*n;i++){
            x=i-(*r-1);
        for(j=x;j<x+*s;j++){
            printf("Donner la case %d de la ligne %d\n",j+1,i+1);
            scanf("%d",&v[i][j]);
        }
    }
    return v;
}
void AffichageMatriceBande (int** matrice,int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("Matrice[%d][%d]: %d \t",i+1,j+1,matrice[i][j]);
        }
        printf("\n");
    }
}
