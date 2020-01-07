#include <math.h> //log10(int a)
#define R 1001


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>


int strrindex(char input[], char c){
    int count = -1;
    
    for (int i=0; input[i] !='\0' ; i++){
        if (input[i] == c){
            count = i;
        }
    }
    return count;
}



int main() {


    char input[R];
    scanf("%s", input);
    
    char c;
    scanf("%s", &c);
    
    int i = strrindex(input,c);
    
    //printf("%s", input);
    //printf("%c", c);
    
    printf("%d", i);
    
    return 0;
}
