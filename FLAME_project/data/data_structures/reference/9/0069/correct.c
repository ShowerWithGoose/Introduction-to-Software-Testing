#include<stdio.h>
#include<stdlib.h>

struct xianduan
{
    int lpo[2],rpo[2];
    struct xianduan *lline,*rline;
};
typedef struct xianduan xianduan;

void showLine(xianduan *a){
    printf("position:\n");
    printf("L(%d,%d)",a->lpo[0],a->lpo[1]);
    printf("R(%d,%d)\n",a->rpo[0],a->rpo[1]);
    if (a->lline!=NULL)
    {
        printf("<---");
    }
    if (a->rline!=NULL)
    {
        printf("--->");
    }
    printf("\n");
}

int LineLen(xianduan *a){
    int len=1;
    xianduan *nextL=a->rline;
    while (nextL!=NULL)
    {
        nextL=nextL->rline;
        len++;
    }
    return len;
}

int main(){
    xianduan *a[100];
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        //输入捏
        a[i]=(xianduan *)malloc(sizeof(xianduan));
        scanf("%d%d",&(a[i]->lpo[0]),&(a[i]->lpo[1]));
        scanf("%d%d",&(a[i]->rpo[0]),&(a[i]->rpo[1]));
        a[i]->lline=NULL;a[i]->rline=NULL;
        //判断链接捏
        for (int j = 0; j < i; j++)
        {
            if (a[i]->lpo[0]==a[j]->rpo[0]&&a[i]->lpo[1]==a[j]->rpo[1])//i_head->j_tail
            {
                a[i]->lline=a[j];
                a[j]->rline=a[i];
            }
            if (a[i]->rpo[0]==a[j]->lpo[0]&&a[i]->rpo[1]==a[j]->lpo[1])//i_tail->j_head
            {
                a[i]->rline=a[j];
                a[j]->lline=a[i];
            }
        }
    }
    
    xianduan *maxp=a[0];
    int maxl=1;
    for (int i = 0; i < n; i++)
    {
        if (maxl<LineLen(a[i]))
        {
            maxl=LineLen(a[i]);
            maxp=a[i];
        }
    }
    printf("%d %d %d",maxl,maxp->lpo[0],maxp->lpo[1]);
}
