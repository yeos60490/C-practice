#include <stdio.h>

int main(){
    int c,i,nwhite,nother;
    int ndigit[10];
    
    nwhite = nother = 0;
    for (i=0; i<10; ++i) ndigit[i] = 0;
    
    while ((c=getchar()) != EOF)
        if (c>='0' && c<='9')
            ++ndigit[c-'0'];
        else if (c==' ' || c=='\n' || c=='\t')
            ++nwhite;
        else
            ++nother;

    for (int i=0; i<10; i++){
        printf("%d:", i);
        int j=0;
        while(j<ndigit[i]){
            printf("*");
            j++;
        }
        printf("\n");
    }
    
    printf("white space:");
    int j=0;
    while(j<nwhite){
        printf("*");
        j++;
    }
    printf("\nother:");
    j=0;
    while(j<nother){
        printf("*");
        j++;
    }
}
