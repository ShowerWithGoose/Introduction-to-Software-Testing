#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M 100

int main(){
    int stack[M];
    int in, top = -1;
    do{
        scanf("%d", &in);
        switch(in){
            case 1:
                if(top == 100)
                    printf("error ");
                else
                    scanf("%d",&stack[++top]);
            break;
            case 0:
                if(top==-1)
                    printf("error ");
                else
                    printf("%d ", stack[top--]);
            break;
        }
    }while(in!=-1);

    return 0;
}
