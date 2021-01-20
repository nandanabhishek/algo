#include <stdio.h>

int m; // size of square matrix A, B and C

void readMatrix(int arr[][m]) {
    for(int i =0; i<m; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

printMatrix(int arr[][m]) {
    for(int i =0; i<m; i++) {
        for(int j=0; j<m; j++) {
            printf(" %d  ", arr[i][j]);
        }
        printf("\n");
    }
}


mul_matrix(int A[][m], int B[][m], int C[][m]) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            int sum = 0;
            for(int k=0; k<m; k++){
                sum += A[i][k] * B[k][j];
            }
            C[i][j]=sum;
        }
    }
}


int main() {

    printf("\n Enter the size of Square-Matrix(Row = Column) : ");
    scanf("%d", &m);

    int A[m][m], B[m][m], C[m][m]; // declaration of 2D square matrix A, B and C of size m X m

    printf("\n Enter the elements of Matrix-A :\n");
    readMatrix(A);

    printf("\n Matrix-A is :\n");
    printMatrix(A);

    printf("\n Enter the elements of Matrix-B :\n");
    readMatrix(B);

    printf("\n Matrix-B is :\n");
    printMatrix(B);

    mul_matrix(A, B, C);
    printf("\n The product of Matrix-A and Matrix-B is :\n");
    printMatrix(C);


    return 0;
}
