#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS


int main(int argc, char *argv[]) {
    
    int stack[1000];
    int top = 0;
    
    //printf("%c %c", *argv[1], *argv[2]);

    
    if(argc < 10){
        printf("error");
        return 0;
    }
    
    for (int i=1; i<argc; i++){
        if(*argv[i] == '+'){
            int a = stack[--top];
            int b = stack[--top];
            int c = a+b;
            stack[top++] = c;
            //printf("%d\n", c);
        }
        else if(*argv[i] == '-'){
            int a = stack[--top];
            int b = stack[--top];
            int c = b-a;
            //printf("%d\n", c);
            stack[top++] = c;
            
        }
        else if(*argv[i] == 'x'){
            int a = stack[--top];
            int b = stack[--top];
            int c = a*b;
            stack[top++] = c;
        }
        else if(*argv[i] == '%'){
            int a = stack[--top];
            int b = stack[--top];
            if (b==0){
                printf("error");
                return 0;
            }
            else{
                int c = b/a;
                stack[top++] = c;
            }
        }
        else{
            //printf("%d %c\n", *argv[i]-'0', *argv[i]);
            stack[top] = *argv[i]-'0';
            top ++;
        }

    }
    while (top >0){
        printf("%d\n", stack[--top]);
    }

    return 0;
}



