
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define R 1001
#define _CRT_SECURE_NO_WARNINGS

int user_id = 12345;
int user_pwd = 98760;
int trial = 0;

int verify (int input_id, int input_pwd){

    //static int trial = 0;

    if(input_id == user_id){
        if(input_pwd == user_pwd){
            printf("login succeed\n");
            return 0;
        }
        else{
            trial++;
        }
    }
    else{
        trial++;
    }
    return trial;
}


int main() {

    int input_id;
    int input_pwd;
    int count = 1;
    int error = 0;
    
    scanf("%d", &input_id);
    scanf("%d", &input_pwd);
        
    count = verify (input_id, input_pwd);
    while (count > 0){
        if (count == 5) {
            printf("login failed(%d)\n", count);
            error ++;
            printf("wait %d seconds\n", error*10);
            trial = 0;
        }
        else{
            printf("login failed(%d)\n", count);
        }
        scanf("%d", &input_id);
        scanf("%d", &input_pwd);
        count = verify (input_id, input_pwd);
    }
    
    
    
    return 0;
    
}
