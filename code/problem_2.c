#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 80
typedef int bool;
enum { false, true };
char string[MAX];

void squeeze2(char s1[], char s2[]){
    bool check = true;
    int k=0;
    
    for (int i=0; s1[i] != '\0'; i++){
        for(int j=0; s2[j] != '\0'; j++){
            if (s1[i] == s2[j]){
                check = false;
            }
        }
        
        if(check){
            string[k] = s1[i];
            k++;
        }
        check = true;
    }
}


int main(){
    char input1[MAX], input2[MAX];
    scanf("%s%s", input1, input2);
    squeeze2(input1, input2);
    printf("result:%s", string);
    
}
