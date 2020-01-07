#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS



int *createIntArray (int row, int column){
    
    int *array = (int *)malloc((row * column)*sizeof(int));
     
    return array;
}

int main(  ) {
    
    
    
    int row, col;
    
    scanf("%d %d", &row, &col);
    
    int *Array = createIntArray(row, col);
    for(int i=0; i<row * col; i++){
        Array[i] = i;
        printf("%d", Array[i]);
        
    }
    
    
    free(Array);
    
    return 0;
}



