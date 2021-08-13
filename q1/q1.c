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

int main() {
    int M = 2, N = 2;
    double **m1 = IdentityMat(M, N);

    print_matrix( m1, M, N );
    free_matrix(m1, M, N);
    return 0;
}