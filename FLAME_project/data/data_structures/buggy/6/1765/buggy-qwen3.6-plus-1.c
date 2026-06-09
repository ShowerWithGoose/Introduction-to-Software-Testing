#include<stdio.h>
int main(){
    int b[100];
    int c;
    int i=-1;
    scanf("%d ",&c);
    while(c!=-1){
        if(c==1){
        scanf("%d ",&c);
        if(i==100){
            printf("error ");
        }
        else{
            i++;
            b[i]=c;
        }
    }

        else{ // @@ The logic for handling '0' (pop) is incorrect. The code reads the next integer into 'c' immediately, treating it as the next command instead of processing the pop operation first. This causes the program to skip operations and misinterpret the input sequence.
            scanf("%d ",&c);
            if(i==-1){
                printf("error ");
            }
            else{
                printf("%d ",b[i]);
                i--;
            }
        }
        scanf("%d ",&c);
    }
    return 0;
}