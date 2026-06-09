#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct stack{
    int num;
    char s;
    struct stack * next; 
}stack;
typedef stack* Ptrstack;

Ptrstack Initstack(){
    Ptrstack s = NULL;
    return s;
}
void PushSign(Ptrstack*list,char c){
    Ptrstack q;
    q = (Ptrstack)malloc(sizeof(stack));
    q->next = *list;
    q->s= c; 
    *list = q;
}
void PushNum(Ptrstack*list,int c){
    Ptrstack q;
    q = (Ptrstack)malloc(sizeof(stack));
    q->next = *list;
    q->num= c; 
    *list = q;
}
char PopSign(Ptrstack*list){
    Ptrstack q;char c;
    c = (*list)->s;
    q = *list;
    (*list) = (*list) ->next;
    free(q); 
    return  c;
}
int IsEmpty(Ptrstack list){
    if(list == NULL)
    return 1;
    else 
    return 0;
}
Ptrstack Calculation(Ptrstack list,char c){
    Ptrstack q = list;
    Ptrstack p = q->next;
    switch (c)
    {
    case '/':
        p->num = (p->num)/(q->num);
        free(q);
        break;
    case '*':
        p->num = (p->num)*(q->num);
        free(q);
        break;
    case '+':
        p->num = (p->num)+(q->num);
        free(q);
        break;
    case '-':
        p->num = (p->num)-(q->num);
        free(q);
        break;
    default:
        break;
    }
    return p;
}
int OrderJudge(char a,char b){
    int val_a,val_b;
    if(a == '*' || a=='/')
    val_a = 2;
    else
    val_a = 1;

    if(b == '*' || b=='/')
    val_b = 2;
    else
    val_b = 1;
    
    return (val_a>=val_b);
}
char s[10005];

int main(){
    Ptrstack num,sign;
    num = Initstack();
    sign = Initstack();
    gets(s);
    
    for(int i=0;s[i] != '\0';i++){
       if(isdigit(s[i])){
            int k = 0;
            while(isdigit(s[i])){
                k = k*10 + (s[i++] - '0');
            }
            i -= 1;
            PushNum(&num,k);
        }
        else if(s[i] ==' ')
        continue;
        else{
            if(IsEmpty(sign))
            PushSign(&sign,s[i]);
            else{
                while(!IsEmpty(sign)&&OrderJudge(sign->s,s[i])){
                    num = Calculation(num,PopSign(&sign));
                }
                PushSign(&sign,s[i]);
            }
           
        }               
    }
    printf("%d",num->num);
    return 0;
      
}
