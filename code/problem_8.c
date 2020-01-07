#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS



char* add_big_number(char a[], char b[], char buf[], int length){
    int length_a = strlen(a);
    int length_b = strlen(b);
    char* add;
    buf[length-1] = '\0';
    length--;

    int carry = 0;
    
    while(length_b>0){
        int num_a = a[length_a-1] - '0';
        int num_b = b[length_b-1] - '0';
        int c = num_a + num_b + carry;
        carry = 0;
        if (c>9){
            carry = c/10;
            c = c%10;
        }
        buf[length-1] = c + '0';
        length_b--; length_a--; length--;
    }
    a[length_a-1] = a[length_a-1] + (carry);
    while (length_a>0){
        buf[length-1] = a[length_a-1];
        add = &buf[length-1];
        length_a--; length--;
    }


    return add;
}


int main() {


    char a[100], b[100], buf[100], c[100], d[100];
    char *res;
    scanf("%s %s", c, d);
    int l_c = strlen(c);
    int l_d = strlen(d);
    if (l_c > l_d){
        strcpy(a,c);
        strcpy(b,d);
    }
    else{
        strcpy(a,d);
        strcpy(b,c);
    }
    
    
    res = add_big_number(a,b,buf,100);
    printf("%s\n", res);

    return 0;
}


