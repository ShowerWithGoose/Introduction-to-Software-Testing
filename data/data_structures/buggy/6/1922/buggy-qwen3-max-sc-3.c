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
    while((scanf("%d",&n))!=(-1)){ @@ [The condition (scanf(...) != -1) is incorrect. scanf returns the number of successfully read items, not -1 on EOF. It should be compared to 1 or checked for EOF properly. Also, this loop never stops because even on EOF, scanf returns EOF (typically -1), so condition becomes (-1 != -1) → false, but the problem expects input until -1 is read as an operation, not until EOF. This causes infinite loop or wrong input reading.]
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); @@ [Incorrect function call: passing s[100] (an out-of-bounds element) instead of s (the array). Should be pop(s).]
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); @@ [Incorrect function call: passing s[100] (an out-of-bounds element) instead of s (the array). Should be push(s, item).]
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}