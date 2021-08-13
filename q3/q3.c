#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double **matrix( int m, int n ) {
    double **mat = (double **)malloc( m*sizeof(double*) );
    if ( mat ) { 
        for ( int i=0; i < n; i++ ) {
           mat[i] = (double *)malloc( n*sizeof(double) );
        }
    }
    return mat;
}


void free_matrix( double **mat, int m, int n ) {
    if (mat) {
    for ( int i=0; i < n; i++ ) {
if (mat[i]) free(mat[i]);
    }
        free(mat);
}
}

void print_matrix( double **mat, int m, int n ) {
    printf("[\n");
    for ( int r=0; r < m; r++ ) {
        printf(" [ ");
        for ( int c=0; c < n; c++ ) {
           printf( "%+.3lf ", mat[r][c] );
    }   
        printf("]\n");
    }
    printf("]\n");
}

double **fill_matrix( 
    double **mat, int m, int n, double *vec, int len )
{
int r, c;
for ( int i=0; i < len; i++ ) {
r = i/n;
c = i%m;
    mat[r][c] = vec[i];
    }
    return mat;
}

double **copy_matrix( 
    double **dst, double **src, int m, int n ) 
{
for ( int r=0; r < m; r++ ) {
    for ( int c=0; c < n; c++ ) {
dst[r][c] = src[r][c];
        }
    }
    return dst;
}

double **Transpose(double **mat, int M, int N){
    double **transpose = matrix(N, M);
    copy_matrix(transpose, mat, M,N);
    printf("copied\n");
    print_matrix(transpose, M, N);
    printf("\n\n");

    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            transpose[j][i] = mat[i][j];
        }
    }
    return transpose;
}   

int main() {
    int M = 3, N = 3;
    double **m1 = matrix(M, N);
    double numbers[][9] = { 
                    {1,2,3,4,5,6,7,8,9 },
                    {1,0,0,0,1,0,0,0,1 } 
                                        };

    fill_matrix(m1, M, N, numbers[0], M*N);

    double **transpose_mat = Transpose(m1, M, N);

    printf("m1 :\n");
    print_matrix(m1, M, N);

    printf("m1 transpose :\n");
    print_matrix(transpose_mat, M, N);

    free_matrix(m1, M, N);
    free_matrix(transpose_mat, M, N);
    return 0;
}