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

double **IdentityMat(int size1, int size2){
    if(size1 == size2){
        int size = size1;
        double **mat = matrix(size, size);
        int row, col;
        for(row = 0; row < size;row++){
            for(col = 0;col < size;col++){
                if(row == col){
                    mat[row][col] = 1;
                }
            }
        }
        return mat;
    }
    else{
        printf("Can't Create Identity Matrix");
        return 0;
    }
    
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

double **Permutation(double **mat, int M, int N, int row1, int row2){
    double **pmat = matrix(M, N);
    copy_matrix(pmat, mat, M, N);

    for(int i = 0;i < N;i++){
        pmat[row2-1][i] = mat[row1-1][i];
        pmat[row1-1][i] = mat[row2-1][i];
    }
    return pmat;
}

int main() {
    int M = 3, N = 3;
    double **m1 = matrix(M, N);
    double numbers[][9] = { 
                    {1,2,3,4,5,6,7,8,9 },
                    {1,0,0,0,1,0,0,0,1 } 
                                        };

    fill_matrix(m1, M, N, numbers[0], M*N);

    double **m2 = Permutation(m1, M, N, 2, 3);

    printf("m1 :\n");
    print_matrix( m1, M, N );

    printf("m2(permutation) :\n");
    print_matrix( m2, M, N );

    free_matrix(m1, M, N);
    return 0;
}