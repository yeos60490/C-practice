#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define R 1001
#define _CRT_SECURE_NO_WARNINGS



int strrindex(char input[], char c, int len){
    int count = -1;
    
    for (int i=len-1; i>-1; i--){
        if(input[i] == c){
            count = i;
            return count;
        }
    }
    
    return count;
    
}



int main() {


    char input[R];
    scanf("%s", input);
    char c;
    scanf("%s", &c);
    
    unsigned int len = strlen(input);

    int i = strrindex(input,c,len);
    
    printf("%d", i);
    
    return 0;
}
