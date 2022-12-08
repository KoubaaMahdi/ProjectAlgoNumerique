#ifndef MatriceDense_H_INCLUDED
#define MatriceDense_H_INCLUDED
int** MatriceDense(int*);
void AffichageMatriceDense (int**,int);
int * MultiplicationMatVect (int**,int,int*);
int ** MultiplicationMat (int**,int,int**);
int ** MultiplicationMatCar (int**,int);
int ** MultiplicationMatTransp (int** ,int );
int ** MultiplicationMatinf(int **,int,int **);
int ** MultiplicationMatSup(int **,int,int **);
void LU(int **, int ***, int ***,int);
void Cholesky(int **, int ***,int );
void GaussAvecVecteur(int **, int *, int **, int );
void Gauss_Jordan_vecteur(int **, int *, int **, int );
#endif // MatriceDense_H_INCLUDED
