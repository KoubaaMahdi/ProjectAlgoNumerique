#include <stdio.h>
#include <stdlib.h>
int** MatriceTriangulaireInf(int *n){
    int i,j;
    printf("Donner Valeur de n\n");
    scanf("%d",n);
    int ** v = (int**)malloc(*n*sizeof(int*));
    for(i=0;i<n;i++){
        v[i] = (int *)calloc(*n,sizeof(int));
    }
    for (i=*n-1;i>=0;i--){
        for (j=i;j>=0;j--){
            printf("Donner la case %d de la ligne %d\n",j+1,i+1);
            scanf("%d",&v[i][j]);
        }
    }
    return v;
}
void AffichageMatriceInf (int** matrice,int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("Matrice[%d][%d]: %d \t",i+1,j+1,matrice[i][j]);
        }
        printf("\n");
    }
}
int ** MultMatriceInfxDense(int **a,int n,int **b){
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
            for(z=0;z<i+1;z++)
            {
                c[i][j]=c[i][j]+a[i][z]*b[z][j];
            }
        }
    }
    return c;
}
int ** MultMatriceInfxInf(int **a,int n,int **b){
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
int ** MultiplicationMatInfxSup(int **a,int n,int **b)
{
    int i,j,z,y;
    int** c=(int**)malloc(n*sizeof(int *));
    for (int i=0;i<n;i++)
{
    c[i]=(int*)calloc(n,sizeof(int));
}
    for(i=0;i<n;i++)
    {   y=0;
        for(j=0;j<n;j++)
        {
            for(z=0;z<y+1;z++)
            {
                c[i][j]=c[i][j]+a[i][z]*b[z][j];
            }
            if(y<i){
                y++;
            }
        }

    }
    return c;
}
void resolution_inf_1(int **M, int *x, int *b, int n)
{
int i,j
for(i=0;i<n;i++)
{
x[i]=b[i];
for(j=0;j<i;j++)
{
x[i]-=M[i][j]*x[j];
}
AffichageVecteur(x,n);
}
