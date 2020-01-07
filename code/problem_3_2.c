
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
int count = 1;
int MAX = 33;
int main(){
    
    srand(time(NULL));
    
    int user;
    int com=0;

    while (count<MAX+1){

        do{
            printf("user:");
            scanf("%d", &user);
        }while(user>3 || user<1);
        
        for(int i=0; i<user; i++){
            printf("%d", count);
            if(count == MAX) {
                printf("\ncomputer win!\n");
                return 0;
            }
            else count ++;
        }
        
        //printf("\n%d\n", (count-1)%4);
        switch ((count-1)%4){
            case (1): com = 3;break;
            case (2): com = 2;break;
            case (3): com = 1;break;
        }

        printf("\ncomputer:%d\n", com);
        for(int i=0; i<com; i++){
            printf("%d", count);
            if(count == MAX) {
                printf("\nuser win!\n");
                return 0;
            }
            else count ++;
        }
        printf("\n");

    }
    
    
}
