
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h> //log10(int a)
#define R 1001
#define INT_MIN -2147483648
#define _CRT_SECURE_NO_WARNINGS


int Atoi(char s[]){
    int n = 0;
    int i = 0;

    for(i = 0; s[i] != '\0'; i++){
        if(isdigit(s[i])){
            n = 10 * n + (s[i] - '0');
        }
        else{
            n = INT_MIN;
            break;
        }
    }

    printf("%d", n);
    return n;
}


int main(){
    
    char input[R];
    
    scanf("%s", input);
    

    Atoi(input);

}
