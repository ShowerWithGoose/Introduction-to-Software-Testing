#include<stdio.h>

#define MAXSIZE 100

int stack[MAXSIZE];

int top=-1;

int main(){

    int n;

    for(;;){

        scanf("%d",&n);

        if(n==-1) break;

        else if(n==1){

            if(top==MAXSIZE-1){

                printf("error ");

                continue;
            }

            else{

                scanf("%d",&stack[top]);

                top++;
            }
        }

        else{

            if(top==-1){

                printf("error ");

                continue;
            }

            else{

                top--;

                printf("%d ",stack[top]);
            }
        }
    }

    return 0;
}



