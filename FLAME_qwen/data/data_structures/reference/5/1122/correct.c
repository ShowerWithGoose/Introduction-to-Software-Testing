#include <stdio.h>
#include <string.h>
typedef struct Node{
    int zhishu;
    int xishu;
    struct Node *link;
}LNode,*Linkline;
void delete(Linkline p,Linkline q){
    p->link=q->link;
    q->link=NULL;
}
int num[10000];
void getnumber(char s[]){
    
    int len=strlen(s);
    int j=0;
    int a=0;
    int t=0;
    for(int i=0;i<len;i++)
    {
        
        if(s[i]<='9'&&s[i]>='0'){
            a=a*10+s[i]-'0';
            
        }
        else if(s[i]=='-')
            t=1;
        else{    
            if(t==1){
                num[j]=-a;
                t=0;
            }
            else
                num[j]=a;
            a=0;
            j++;
        }
        if(i==len-1){
            num[j]=a;
            j++;
        }     
    }
    num[j]=2147483647;
}

Linkline create_link();
Linkline bs(Linkline list);
int main(){
    Linkline list1,list2;
    list1=create_link();
    list2=create_link();
    Linkline p=list1,q=list2;
    Linkline k,list3;
    k=(Linkline)malloc(sizeof(LNode));
    list3=k;
    k->xishu=p->xishu*q->xishu;
    k->zhishu=p->zhishu+q->zhishu;
    k->link=NULL;
    q=q->link;
    while(p!=NULL){
        while(q!=NULL){
            Linkline r;
            r=(Linkline)malloc(sizeof(LNode));
            r->xishu=p->xishu*q->xishu;
            r->zhishu=p->zhishu+q->zhishu;
            r->link=NULL;
            k->link=r;
            k=r;        
            q=q->link;
        }
        p=p->link;
        q=list2;
    }
    list3=bs(list3);
    p=list3;
    while(p!=NULL){
        if(p->xishu!=0){
            printf("%d %d",p->xishu,p->zhishu);
            printf(" ");
        }
        p=p->link;
    }
    return(0);
}
Linkline create_link(){
    int a,b;
    char s[10000];
    gets(s);
    getnumber(s);
    a=num[0];
    b=num[1];    
    Linkline list,p,r;
    p=(Linkline)malloc(sizeof(LNode));
    p->xishu=a;
    p->zhishu=b;
    p->link=NULL;
    list=p;
    
    for(int i=2;num[i]!=2147483647;i+=2){
        a=num[i];
        b=num[i+1];
        r=(Linkline)malloc(sizeof(LNode));
        r->xishu=a;
        r->zhishu=b;
        r->link=NULL;
        p->link=r;
        p=r;
        

    }
    return(list);  
}
Linkline bs(Linkline list){
    Linkline p,q,r;
    p=list;
    q=list;
    while(p!=NULL){
        r=NULL;
        while(q!=NULL&&q->link!=NULL){
            int a=q->zhishu;
            int b=q->link->zhishu;
            if(a<b){
                if(r==NULL){
                    Linkline k=q->link;
                    q->link=k->link;
                    k->link=q;
                    list=k;
                }
                else{
                    Linkline k=q->link;
                    q->link=q->link->link;
                    k->link=q;
                    r->link=k;
                }
            }
            
            r=q;
            q=q->link;
        }
        q=list;
        p=p->link;
    }
    p=list;
    while(p!=NULL&&p->link!=NULL){
        int a=p->zhishu;
        int b=p->link->zhishu;
        if(a==b){
            p->xishu+=p->link->xishu;
            delete(p,p->link);
        }
        else{
        p=p->link;
        }
    }
    return(list);
}
