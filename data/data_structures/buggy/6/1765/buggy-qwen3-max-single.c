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

        else{
            scanf("%d ",&c); // @@ [This line incorrectly reads another input when c is 0 (pop operation). It should not read a new value for pop; the 'else' block handles pop (-1 is end, 0 is pop), but reading again consumes the next operation prematurely.]
            if(i==-1){
                printf("error ");
            }
            else{
                printf("%d ",b[i]);
                i--;
            }
        }
        scanf("%d ",&c); // @@ [This line causes double consumption of input in the pop case: one inside the 'else' block and another here. For push (c==1), it reads the value correctly inside the if-block, then this reads the next operation. But for pop (c==0), it already read an extra value inside the else block, so this reads yet another, skipping operations.]
    }
    return 0;
}