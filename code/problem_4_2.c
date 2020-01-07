
#include <math.h> //log10(int a)
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS


void itoa(int n) {

    char s[10];
    int sign = 0;
    int j = 0, i = 1;

    if ((sign = n) < 0) {
        n = -1 * n;
        s[j++] = '-';
    }

    while (n / i > 10) {
        i = 10 * i;
    }

    while (i > 0) {
        s[j++] = n / i + '0';
        n = n % i;
        i = i / 10;
    }
    s[j] = '\0';

    
    for (j = 0; s[j] != '\0'; j++) {
        printf("%c", s[j]);
    }
}



int main() {

    int input;
    scanf("%d", &input);
    itoa(input);

}
