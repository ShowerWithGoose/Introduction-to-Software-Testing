#include <stdio.h>
#include <stdlib.h>

typedef struct Linenode{
    int x1,y1,x2,y2;
    struct Linenode *next;
}Linenode ;

typedef struct Linelist{
    Linenode Head;
    int num;
    struct Linelist* next;
}Linelist;


int link(Linelist* LinelistHead,Linenode* readLine);
void linklines(Linelist* LinelistHead);

int main(){

    Linelist* LinelistHead=(Linelist*)malloc(sizeof(Linelist)),*Now=(Linelist*)malloc(sizeof(Linelist));
    LinelistHead->Head.next=NULL;
    Now->Head.next=NULL;
    Now->next=NULL;
    Now->num=0;
    LinelistHead->next=Now;


    int n;
    scanf("%d",&n);


    for(int i=0;i<n;i++){
        Linenode *p=(Linenode *)malloc(sizeof(Linenode));
        scanf("%d%d%d%d",&p->x1,&p->y1,&p->x2,&p->y2);
        p->next=NULL;

        if (link(LinelistHead,p)==-1){
            Now->num=1;//连接线段失败
            Now->Head.next=p;

            if(i<n-1){
            Linelist *temp=(Linelist *)malloc(sizeof(Linelist));
            temp->Head.next=NULL;
            temp->next=NULL;
            temp->num=0;
            Now->next=temp;
            Now=temp;   
            }


        }
    }

    // linklines(LinelistHead);  // @@ Missing function call: This function is necessary to merge separate chains that can be connected. Without it, chains remain disjoint and the maximum chain length is underestimated.

    int maxLineNum=0,x1_max,y1_max;
    Linelist *p=LinelistHead->next;
    while (p!=NULL)
    {
        if(p->num>maxLineNum){
            maxLineNum=p->num;
            x1_max=p->Head.next->x1;
            y1_max=p->Head.next->y1;
        }
        p=p->next;
    }



    printf("%d %d %d",maxLineNum,x1_max,y1_max);

    return 0;
}

int link(Linelist* LinelistHead,Linenode* readLine){
    Linelist *p=LinelistHead->next;
    while (p!=NULL)
    {
        if(p->Head.next!=NULL){
            int x1_first,y1_first,x2_last,y2_last;
            x1_first=p->Head.next->x1;
            y1_first=p->Head.next->y1;
            if(readLine->x2==x1_first&&readLine->y2==y1_first){
                Linenode* temp=p->Head.next;
                p->Head.next=readLine;
                readLine->next=temp;

                (p->num)++;

                return 0;
            }

            Linenode *lastNode=p->Head.next;
            while (lastNode->next!=NULL)
            {
                lastNode=lastNode->next;
            }
            x2_last=lastNode->x2;
            y2_last=lastNode->y2;
            if(readLine->x1==x2_last&&readLine->y1==y2_last){
                lastNode->next=readLine;

                (p->num)++;

                return 0;
            }
        }

        p=p->next;
    }

    return -1;
}

void linklines(Linelist* LinelistHead){
    Linelist *Pre=LinelistHead;
    Linelist *Now=LinelistHead->next;

    while (Now!=NULL&&Now->Head.next!=NULL)
    {
        int renew=0;
        Linelist *Target=LinelistHead->next;
        while (Target!=NULL&&Target->Head.next!=NULL)
        {   
            if(Target==Now){
                Target=Target->next;
                continue;
            }

            int x_head,y_head,x_tail,y_tail;
            x_head=Now->Head.next->x1;
            y_head=Now->Head.next->y1;

            Linenode *lastNode=Target->Head.next;
            while (lastNode->next!=NULL)
            {
                lastNode=lastNode->next;
            }
            x_tail=lastNode->x2;
            y_tail=lastNode->y2;

            if(x_head==x_tail&&y_head==y_tail){
                Pre->next=Target;
                lastNode->next=Now->Head.next;

                Target->num+=Now->num;

                free(Now);
                renew=1;

                Pre=LinelistHead;
                Now=LinelistHead->next;
                break;
            }else{
                Target=Target->next;
            }
        }
        if(!renew){
            Pre=Now;
            Now=Now->next;
        }
    }

}