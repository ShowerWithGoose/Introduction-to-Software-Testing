#include<stdio.h>
int s[100];
int item;
int top=-1;
int flag;
void push(int s[100],int item){
    if(top==99){
        flag=-1;
    }
    if(flag!=-1)
    s[++top]=item;
     
}
int pop(int s[100]){
    if(top==-1){
        return -1;
    }
    else
    return s[top--];
}
int main(){
    int n,r[500];
    int i=0;
    while((scanf("%d",&n))!=(-1)){ // @@ The condition should check for -1 as the input value, not the return value of scanf. scanf returns the number of items read, not the input value. This loop will never terminate as intended.
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); // @@ Incorrect argument: should be 's' (the array name), not 's[100]'. 's[100]' is out of bounds and not a valid array reference.
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); // @@ Incorrect argument: should be 's' (the array name), not 's[100]'. Same issue as above.
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}