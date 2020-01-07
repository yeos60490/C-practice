#include <stdio.h>
#include <string.h>
#define R 1001
#define _CRT_SECURE_NO_WARNINGS


char* itoa(int n, char s[], int length){
    char* add;
    s[length-1]= '\0';
    length--;
    
    do{
        int at = n%10;
        s[length-1] = at+ '0';
        add = &s[length-1];
        length--;
    }while( (n = n/10)>0);
    
    return add;
}


int main() {

    int number;
    char s[12];
    char *address;
    int length = 12;
    scanf("%d", &number);
    

    address = itoa(number, s, length);
    printf("%s", address);
    
    return 0;
}


