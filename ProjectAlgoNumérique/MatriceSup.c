#include"Vecteur.h"
#include <stdio.h>
#include <stdlib.h>
int** MatriceTriangulaireSup(int *n){
    int i,j;
    printf("Donner Valeur de n\n");
    scanf("%d",n);
    int ** v = (int**)malloc(*n*sizeof(int*));
    for(i=0;i<*n;i++){
        v[i] = (int *)calloc(*n,sizeof(int));
    }
    for (i=0;i<*n;i++){
        for (j=i;j<*n;j++){
            printf("Donner la case %d de la ligne %d\n",j+1,i+1);
            scanf("%d",&v[i][j]);
        }
    }
    return v;
}
void AffichageMatriceSup (int** matrice,int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("Matrice[%d][%d]: %d \t",i+1,j+1,matrice[i][j]);
        }
        printf("\n");
    }
}
int ** MultMatriceSupxDense(int **a,int n,int **b){
    int i,j,z;
    int** c=(int**)malloc(n*sizeof(int *));
    for (int i=0;i<n;i++)
{
    c[i]=(int*)calloc(n,sizeof(int));
}
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(z=i;z<n;z++)
            {
                c[i][j]=c[i][j]+a[i][z]*b[z][j];
            }
        }
    }
    return c;
}
int ** MultiplicationMatSupxInf(int **a,int n,int **b){
    int i,j,z,y;
    int** c=(int**)malloc(n*sizeof(int *));
    for (int i=0;i<n;i++)
{
    c[i]=(int*)calloc(n,sizeof(int));
}
    for(i=0;i<n;i++)
    {   y=i;
        for(j=0;j<n;j++)
        {
            if(j>i){
                y++;
            }
            for(z=y;z<n;z++)
            {
                c[i][j]=c[i][j]+a[i][z]*b[z][j];
            }

        }


    }
    return c;
}
int ** MultiplicationMatSupxSup(int **a,int n,int **b)
{
    int i,j,z;
    int** c=(int**)malloc(n*sizeof(int *));
    for (int i=0;i<n;i++)
{
    c[i]=(int*)calloc(n,sizeof(int));
}
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            for(z=i;z<j+1;z++)
            {
                c[i][j]=c[i][j]+a[i][z]*b[z][j];
            }
        }
    }
    return c;
}
void resolution_sup_vect(int **M, int *x, int *b, int n)
{
int i,j;
for(i=n-1;i>=0;i--)
{
x[i]=b[i];
for(j=i+1;j<n;j++)
{
x[i]-=M[i][j]*x[j];
}
x[i]=x[i]/M[i][i];
}
AffichageVecteur(x,n);
}

