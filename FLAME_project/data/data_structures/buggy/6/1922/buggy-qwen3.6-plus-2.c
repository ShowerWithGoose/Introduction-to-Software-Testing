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
    while((scanf("%d",&n))!=(-1)){ // @@ The condition (scanf("%d",&n))!=(-1) is incorrect. scanf returns the number of items successfully read, or EOF. It does not return the value read into n. This causes the loop to terminate incorrectly or behave unpredictably. It should check if n == -1 after reading.
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); // @@ Passing s[100] passes a single integer (out of bounds access) instead of the array. The function expects an array (pointer), so it should be pop(s). Also, the function definition int pop(int s[100]) is misleading but technically accepts a pointer, however calling with s[100] is invalid.
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); // @@ Passing s[100] passes a single integer (out of bounds access) instead of the array. It should be push(s, item).
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}