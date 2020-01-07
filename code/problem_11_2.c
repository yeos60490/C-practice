#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS



int *createIntArray (int row, int column){
    
    int *array = (int *)malloc((row * column)*sizeof(int));
     
    return array;
}

int main() {
    

    int row, col;
    int c,d,e;
    
    scanf("%d %d %d %d %d", &row, &col, &c, &d, &e);
    
    int *A = createIntArray(row, col);
    //int *B[row][col];
    int **B =(int **)malloc((row)*sizeof(int));
    for (int i =0;i<row;i++){
        *B = (int *)malloc((col)*sizeof(int));
                //B[i] = A+(i*col);
    }
    for(int i =0;i<row;i++){
        *(B+i) = (A+i*col);
    }
    //B = &A;
    
    for (int i = 0; i < row*col; i++) {
        *(A+i) = i;
        
    }
    //B = &A;
    
    *(A+c) = 100;
    B[d][e] = 200;
  ]
    
    for (int i=0; i<row*col; i++){
        printf("%d", A[i]);
    }
    
    
    for (int i=0; i<row; i++){
        printf("\n");
        for (int j=0; j<col; j++){
            printf("%d", B[i][j]);
        }
    }
    

    
    //free(A);
    
    return 0;
}



