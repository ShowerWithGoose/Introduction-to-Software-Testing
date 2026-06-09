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
    while((scanf("%d",&n))!=(-1)){ @@ [The condition (scanf(...) != -1) is incorrect. scanf returns the number of successfully read items, not -1 on EOF or failure in all cases. Also, the loop never stops because -1 (end marker) is stored in r[] and loop continues until scanf fails, which may never happen with valid input ending in -1. This causes infinite loop or reading beyond intended input.]
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); @@ [Incorrect function call: passing s[100] (an out-of-bounds element) instead of the array s. Should be pop(s).]
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); @@ [Incorrect function call: passing s[100] (an out-of-bounds element) instead of the array s. Should be push(s, item).]
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}