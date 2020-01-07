
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define R 1001
#define _CRT_SECURE_NO_WARNINGS

int trial = 0;
int user[3] = {0,0,0};
int pwd[3] = {0,0,0};
int num_users = 0;


void add_user(){
    
    if (num_users>2) printf("error\n");
    for(int i=0; i<3; i++){
        if (user[i]==0 && pwd[i]==0){
            scanf("%d %d", &user[i], &pwd[i]);
            num_users++;
            break;
        }
    }
}

void delete_user(){
    int input_user, input_pwd;
    int check = 0;
    scanf("%d %d", &input_user, &input_pwd);
    
    for (int i=0; i<3; i++){
        if(input_user == user[i] && input_pwd == pwd[i]){
            user[i] = 0; pwd[i] = 0;
            check = 1;
            num_users--;
        }
    }
    if(check==0) printf("error\n");
}

int verify (int input_id, int input_pwd){
    int check = 0;
    for (int i=0; i<2; i++){
        //printf("%d %d",input_id,user[i]);
        if(input_id == user[i] && input_pwd == pwd[i]){
            printf("login succeed\n");
            check = 1;
            trial = 0;
            //return 0;
        }
    }
    if(check == 0) trial ++;
    return trial;
}

void log_in(){
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
    
}


int main() {

    int menu = 0;
    do{
        printf("menu: ");
        scanf("%d", &menu);
        
        switch (menu) {
            case 1:
                add_user();
                break;
            case 2:
                delete_user();
                break;
            case 3:
                log_in();
                break;
            default:
                break;
        }
        
    }while(menu != 4);
    
    return 0;
}



