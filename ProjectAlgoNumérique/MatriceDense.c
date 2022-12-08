#include"Vecteur.h"
#include"MatriceSup.h"
#include <stdio.h>
#include <stdlib.h>

int** MatriceDense(int* n){
    int i,j;

    printf("Donner Valeur de n\n");
    scanf("%d",n);
    int ** v = (int**)malloc((*n)*sizeof(int*));
    for(i=0;i<*n;i++){
        v[i] = (int *)calloc((*n),sizeof(int));
    }
    for (i=0;i<*n;i++){
        for (j=0;j<*n;j++){
            scanf("%d",&v[i][j]);
        }
    }
    return v;
}
void AffichageMatriceDense (int** matrice,int n){
    int i,j;
    printf("%d",n);
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("Matrice[%d][%d]: %d \t",i+1,j+1,matrice[i][j]);
        }
        printf("\n");
    }
}
int * MultiplicationMatVect (int** matrice,int n,int* Vecteur){
    int i,j,sum=0;
    int* rez = (int *) calloc(n,sizeof(int));
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
           rez[i]=rez[i]+(matrice[i][j]*Vecteur[j]);
        }

    }
    return rez;
}
int ** MultiplicationMat (int** matrice,int n,int** matrice2){
    int i,j,x,sum=0;
    int** rez = (int **) malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        rez[i] = (int *)calloc(n,sizeof(int));
    }
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            for(x=0;x<n;x++){
                rez[i][j]=rez[i][j]+matrice[i][x]*matrice2[x][j];
            }
        }

    }
    return rez;
}
int ** MultiplicationMatCar (int** matrice,int n){
    int i,j,x,sum=0;
    int** rez = (int **) malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        rez[i] = (int *)calloc(n,sizeof(int));
    }
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            for(x=0;x<n;x++){
                rez[i][j]=rez[i][j]+matrice[i][x]*matrice[x][j];
            }
        }

    }
    return rez;
}
int ** MultiplicationMatTransp (int** matrice,int n){
    int i,j,x,sum=0;
    int** rez = (int **) malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        rez[i] = (int *)calloc(n,sizeof(int));
    }
    for (i=0;i<n;i++){
        rez[i]=MultiplicationMatVect(matrice,n,matrice[i]);
        AffichageVecteur(rez[i],n);
    }
    return rez;
}


int ** MultiplicationMatinf(int **a,int n,int **b)
{
    int i,j,z;
    int** c=(int**)malloc(n*sizeof(int *));
    for (int i=0;i<n;i++)
{
    c[i]=(int*)calloc(n,sizeof(int));
}
    for(i=0;i<n;i++)
    {
        for(j=0;j<i+1;j++)
        {
            for(z=j;z<i+1;z++)
            {
                c[i][j]=c[i][j]+a[i][z]*b[z][j];
            }
        }
    }
    return c;
}
int ** MultiplicationMatSup(int **a,int n,int **b)
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
            for(z=i;z<j;z++)
            {
                c[i][j]=c[i][j]+a[i][z]*b[z][j];
            }
        }
    }
    return c;
}
void LU(int **mat, int ***L, int ***U,int dim){
int i,j,k;
for(i=0;i<dim;i++)
{
(*L)[i][i]=1;
for(j=0;j<=i-1;j++)
{
(*L)[i][j]=mat[i][j];
for(k=0;k<=j-1;k++)
{
(*L)[i][j]-=(*L)[i][k]*(*U)[k][j];
}
(*L)[i][j]/=(*U)[j][j];
}
for(j=i;j<dim;j++)
{
(*U)[i][j]=mat[i][j];
for(k=0;k<=i-1;k++)
{
(*U)[i][j]-=(*L)[i][k]*(*U)[k][j];
}
}}
void Cholesky(int **mat, int ***L,int dim){
int i,j,k;
for (j= 0; j<dim; j++)
{
    (*L)[j][j]=mat[j][j];
    for (int k = 0;  k<j-1;k++)
    {
        *(L)[j][j]=L[j][j]-(*L)[j][k]*(*L)[j][k];
    }
    (*L)[j][j]=sqrt((*L)[j][j]);
    for (int i = j+1; i<=dim; i++)
    {
        (*L)[i][j]=mat[i][j];
        for (int k=0; k <= j-1; k++)
        {
            (*L)[i][j]=(*L)[i][j]-(*L)[i][k]*(*L)[j][k];
        }
        (*L)[i][j]=(*L)[i][j]/(*L)[j][j];
    }

}

}
}
void GaussAvecVecteur(float **M, float *b, float *x, int n)
{{
int i,j,k;
for(k=0;k<n-1;k++)
{
for(i=k+1;i<n;i++)
{
M[i][k]/=M[k][k];
for(j=k+1;j<n;j++)
{
M[i][j]-=M[i][k]*M[k][j];
}
b[i]-=M[i][k]*b[k];
}
}
resolution_sup_vect(M,x,b,n);
}

}
void Gauss_Jordan_vecteur(float **M, float *b, float **x, int n)
{
int i,j,k;
for(i=0;i<n;i++)
(*x)[i]=b[i];
for(k=0;k<n;k++)
{
for(j=k+1;j<n;j++)
{
M[k][j]/=M[k][k];
}
(*x)[k]/=M[k][k];
for(i=0;i<=k-1;i++)
{
for(j=k+1;j<n;j++)
{
M[i][j]-=M[i][k]*M[k][j];
}
(*x)[i]-=M[i][k]*(*x)[k];
}
for(i=k+1;i<n;i++)
{
for(j=k+1;j<n;j++)
{
M[i][j]-=M[i][k]*M[k][j];
}
(*x)[i]-=M[i][k]*(*x)[k];
}
}
AffichageVecteur(x,n);
}
