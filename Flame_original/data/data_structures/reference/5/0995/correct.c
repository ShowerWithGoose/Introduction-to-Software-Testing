#include <stdio.h>
#include <stdlib.h>
typedef struct poly
{
    int coe;
    int exp;
    struct poly *next;
}POLY;
int main()
{
    int m=0,n=0,Coe,Exp;
    POLY *first1=NULL,*last1=NULL,*first2=NULL,*last2=NULL,*head=NULL,*tail=NULL;
    while(scanf("%d",&Coe)!=EOF){
        scanf("%d",&Exp);
        POLY *p=(POLY *)malloc(sizeof(POLY));
        if(first1==NULL){
            first1=last1=p;
            p->coe=Coe,p->exp=Exp;
            p->next=NULL;
        }else{
            last1->next=p;
            last1=p;
            p->coe=Coe,p->exp=Exp;
            p->next=NULL;
        }
        m++;
        if(!Exp)break;
        if(getchar()=='\n')break;
    }
    while(scanf("%d",&Coe)!=EOF){
        scanf("%d",&Exp);
        POLY *p=(POLY *)malloc(sizeof(POLY));
        if(first2==NULL){
            first2=last2=p;
            p->coe=Coe,p->exp=Exp;
            p->next=NULL;
        }else{
            last2->next=p;
            last2=p;
            p->coe=Coe,p->exp=Exp;
            p->next=NULL;
        }
        n++;
        if(!Exp)break;
        if(getchar()=='\n')break;
    }
    //两个初始储存链表创建完毕
    POLY *NLast1=(POLY *)malloc(sizeof(POLY)),*NLast2=(POLY *)malloc(sizeof(POLY));
    last1->next=NLast1,NLast1->next=NULL;m++;
    last2->next=NLast2,NLast2->next=NULL;n++;
    POLY *pos1=first1,*pos2=first2,*pos=NULL;
    int N=0;
    while(pos1!=NLast1){
        pos2=first2;
        while(pos2!=NLast2){
            if(head==NULL){
                POLY *p=(POLY *)malloc(sizeof(POLY));
                head=tail=p;
                p->coe=pos1->coe*pos2->coe;
                p->exp=pos1->exp+pos2->exp;
                p->next=NULL;
                N++;
                pos2=pos2->next;
                continue;
            }
            pos=head;
            for(int i=0;i<N;i++){
                if((pos1->exp+pos2->exp)==pos->exp){
                    pos->coe=pos->coe+pos1->coe*pos2->coe;
                    break;
                }
                if(i==N-1){
                    POLY *p=(POLY *)malloc(sizeof(POLY));
                    tail->next=p;
                    tail=p;
                    p->coe=pos1->coe*pos2->coe;
                    p->exp=pos1->exp+pos2->exp;
                    p->next=NULL;
                    N++;
                    break;
                }
                pos=pos->next;
            }
            pos2=pos2->next;
        }
        pos1=pos1->next;
    }
    //交叉相乘（卷积），无序排列
    for(int j=0;j<N;j++){
        pos=head;
        for(int i=0;i<N-1;i++){
            if(pos->exp<pos->next->exp){
                int tempC,tempE;
                tempC=pos->coe,pos->coe=pos->next->coe,pos->next->coe=tempC;
                tempE=pos->exp,pos->exp=pos->next->exp,pos->next->exp=tempE;
            }
            pos=pos->next;
        }
    }
    pos=head;
    for(int i=0;i<N;i++){
        if(pos->coe!=0){
            printf("%d %d ",pos->coe,pos->exp);
        }
        pos=pos->next;
    }
    for(int i=0;i<m;i++){
        pos1=first1;
        first1=first1->next;
        free(pos1);
    }
    for(int j=0;j<n;j++){
        pos2=first2;
        first2=first2->next;
        free(pos2);
    }
    for(int i=0;i<N;i++){
        pos=head;
        head=head->next;
        free(pos);
    }
    return 0;
}
