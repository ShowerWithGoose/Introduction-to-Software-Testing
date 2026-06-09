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
    while((scanf("%d",&n))!=(-1)){ // @@ scanf returns the number of successfully read items, not the input value. It should check if n == -1 to terminate.
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); // @@ s[100] accesses out-of-bounds memory and passes an integer instead of the array. It should be pop(s).
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); // @@ s[100] accesses out-of-bounds memory and passes an integer instead of the array. It should be push(s, item).
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}