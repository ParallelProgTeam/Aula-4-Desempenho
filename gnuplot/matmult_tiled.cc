#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <omp.h>
using namespace std;
//#define DEBUG

#define N_b  13
//(From L1=32KB, sqrt((32*1024)/3.0)/8bytes each double~=13..)


void sub_mat_mult(int n, double A[][N_b], double B[][N_b], double C[][N_b]) {
   for (int ii = 0; ii < n; ii++){
     for (int kk = 0; kk < n; kk++){
       register double aik = A[ii][kk];
       for (int jj = 0; jj < n; jj++){
         C[ii][jj] = C[ii][jj] + aik * B[kk][jj];
       }
     }
   }
}

void mat_mult(int n, double **A, double **B, double **C) {
   double Aa[N_b][N_b], Bb[N_b][N_b], Cc[N_b][N_b];
   for (int i = 0; i < n/N_b; i++){
     for (int j = 0; j < n/N_b; j++){
       for (int ii = 0; ii < N_b; ii++) {
         for (int jj = 0; jj < N_b; jj++) {
             Cc[ii][jj] = C[i*N_b+ii][j*N_b+jj];
	 }
       }
       for (int k = 0; k < n/N_b; k++){
         for (int jj = 0; jj < N_b; jj++) {
           for (int kk = 0; kk < N_b; kk++){
             Aa[jj][kk] = A[i*N_b+jj][k*N_b+kk];
             Bb[jj][kk] = B[k*N_b+jj][j*N_b+kk];
	   }
         }
         sub_mat_mult(N_b, Aa, Bb, Cc);
       }
       for (int ii = 0; ii < N_b; ii++) {
         for (int jj = 0; jj < N_b; jj++) {
           C[i*N_b+ii][j*N_b+jj] = Cc[ii][jj];
	   //printf("%lf ",C[i*N_b+ii][j*N_b+jj]);
	   //printf("%lf ",Cc[ii][jj]);
         }
	 //printf("\n");
       }
     }
   }
}

void fill_mat(int n, double **Matrix, int flag) {
  for (int i = 0; i < n; i++){
    Matrix[i] = (double *)malloc(n * sizeof(double));
    for (int j = 0; j < n; j++)
      if (flag == 1)
        Matrix[i][j] = 1;//rand()%50;
      else
        Matrix[i][j] = 0;
  }
}

int main(int argc, char *argv[]) {
  int n;
  if (argc == 2) 
    n = stoi(argv[1]);
  else 
    {printf("Exec needs n argument\n"); exit(1);}
  srand (1);
  //srand (time(NULL));
  double **A = (double **)malloc (n * sizeof(double *));
  double **B = (double **)malloc (n * sizeof(double *));
  double **C = (double **)malloc (n * sizeof(double *));
  fill_mat(n, A, 1);
  fill_mat(n, B, 1);
  double stime = omp_get_wtime();
  fill_mat(n, C, 0);
  mat_mult(n, A, B, C);
  printf ("n = %i\t Tempo %lf\n", n, omp_get_wtime() - stime);

  #ifdef DEBUG
  for (int i = 0;i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%lf ",C[i][j]);
    printf("\n");
  }
  #endif

  return 0;
}

