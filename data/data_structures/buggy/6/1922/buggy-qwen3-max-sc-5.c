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
    while((scanf("%d",&n))!=(-1)){ @@ [The condition (scanf(...) != -1) is incorrect. scanf returns the number of successfully read items, not -1 on EOF or failure in a way that matches this logic. Also, the loop never stops because -1 input won't break it properly as intended by the problem.]
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); @@ [Passing s[100] is wrong: it passes an integer (the 101st element, out of bounds), not the array. Should pass 's'.]
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); @@ [Same error: passing s[100] instead of 's'. This causes undefined behavior and incorrect function operation.]
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}