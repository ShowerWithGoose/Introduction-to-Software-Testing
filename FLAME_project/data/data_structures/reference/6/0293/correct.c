#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int main(){
    int line[10*MAX] = {};
    int stack[MAX] = {};
    int i = 0,j = 0;
    for(;;i++){
        scanf("%d",&line[i]);
        if(line[i] == -1)
            break;
    }
    i = 0;
    A:for(;line[i] != -1;){
        if(line[i] == 1){
            if(j == MAX - 1){
                printf("error ");
                i+=2;
                goto A;
            }
            else{
                stack[j] = line[i+1];
                j++,i+=2;
            }  
        }
        else if(line[i] == 0){
            if(j == 0){
                printf("error ");
                i++;
                goto A;
            }
            else{
                printf("%d ",stack[j-1]);
                j--,i++;
            }
        }
    }
    return 0;
}


