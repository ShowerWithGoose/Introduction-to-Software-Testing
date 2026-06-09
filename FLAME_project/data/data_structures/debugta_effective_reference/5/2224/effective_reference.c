#include <stdio.h>
#include <string.h>
typedef struct Node{
    int zhishu;
    int xishu;
    struct Node *link;
}LNode,*Linkline;
void delete(Linkline q,Linkline p){
    q->link=p->link;
    p->link=NULL;
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
    Linkline q=list1,p=list2;
    Linkline h,list3;
    h=(Linkline)malloc(sizeof(LNode));
    list3=h;
    h->xishu=q->xishu*p->xishu;
    h->zhishu=q->zhishu+p->zhishu;
    h->link=NULL;
    p=p->link;
    while(q!=NULL){
        while(p!=NULL){
            Linkline f;
            f=(Linkline)malloc(sizeof(LNode));
            f->xishu=q->xishu*p->xishu;
            f->zhishu=q->zhishu+p->zhishu;
            f->link=NULL;
            h->link=f;
            h=f;        
            p=p->link;
        }
        q=q->link;
        p=list2;
    }
    list3=bs(list3);
    q=list3;
    while(q!=NULL){
        if(q->xishu!=0){
            printf("%d %d",q->xishu,q->zhishu);
            printf(" ");
        }
        q=q->link;
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
    Linkline list,q,f;
    q=(Linkline)malloc(sizeof(LNode));
    q->xishu=a;
    q->zhishu=b;
    q->link=NULL;
    list=q;
    
    for(int i=2;num[i]!=2147483647;i+=2){
        a=num[i];
        b=num[i+1];
        f=(Linkline)malloc(sizeof(LNode));
        f->xishu=a;
        f->zhishu=b;
        f->link=NULL;
        q->link=f;
        q=f;
        

    }
    return(list);  
}
Linkline bs(Linkline list){
    Linkline q,p,f;
    q=list;
    p=list;
    while(q!=NULL){
        f=NULL;
        while(p!=NULL&&p->link!=NULL){
            int a=p->zhishu;
            int b=p->link->zhishu;
            if(a<b){
                if(f==NULL){
                    Linkline h=p->link;
                    p->link=h->link;
                    h->link=p;
                    list=h;
                }
                else{
                    Linkline h=p->link;
                    p->link=p->link->link;
                    h->link=p;
                    f->link=h;
                }
            }
            
            f=p;
            p=p->link;
        }
        p=list;
        q=q->link;
    }
    q=list;
    while(q!=NULL&&q->link!=NULL){
        int a=q->zhishu;
        int b=q->link->zhishu;
        if(a==b){
            q->xishu+=q->link->xishu;
            delete(q,q->link);
        }
        else{
        q=q->link;
        }
    }
    return(list);
}
