#include <stdio.h>
int top=-1;
int stack[105]={0};
typedef Maxnum 100; // @@ [typedef syntax error: 'typedef' is used to create type aliases, not to define constants. Should use '#define Maxnum 100' instead.]
void pushin(){
    int num;
    scanf("%d",&num);
    if(top==Maxnum-1){ // @@ [Maxnum is not defined due to typedef error, causing compilation failure]
    printf("error ");
    }else{
        stack[++top]=num;
    }
    return ;
}
void popout(){
    if(top==-1){
    printf("error ");
    }else{
        printf("%d ",stack[top--]);
    }
    return ;
}
int main(){
 int op;
 scanf("%d",&op);
 while (1)
 {
    if(op==1){
        pushin();
    }else if(op==0){
        popout();
    }
    scanf("%d",&op);
    if(op==-1){
        break;
    }
 }
 return 0;
}