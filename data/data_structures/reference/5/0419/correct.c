#include<stdio.h>
#include<string.h>
struct line
{
    int num;
    int index;
    struct line* next;
};

int main()
{
    struct line arr[500],brr[500],crr[1000];
    int n1=0,n2=0;
    scanf("%d%d",&arr[n1].num,&arr[n1].index);n1++;
    while(getchar()!='\n')
        {scanf("%d%d",&arr[n1].num,&arr[n1].index);arr[n1-1].next=&arr[n1];n1++;}
    arr[n1-1].next=NULL;


    scanf("%d%d",&brr[n2].num,&brr[n2].index);n2++;
    while(getchar()!='\n')
    {scanf("%d%d",&brr[n2].num,&brr[n2].index);brr[n2-1].next=&brr[n2];n2++;}
    brr[n2-1].next=NULL;
    struct line* plist1=&arr[0],*plist2=&brr[0];
    struct line* plist3;int n3=0;
    struct line* trans=plist2;
    while(plist1!=NULL)
    {
        plist2=trans;
        while(plist2!=NULL)
        {
            crr[n3].num=plist1->num*plist2->num;
            crr[n3].index=plist1->index+plist2->index;
            n3++;
            plist2=plist2->next;
        }
        plist1=plist1->next;
    }
int i;
int max=0,j=-1,k;
for(i=0;i<n3;i++)
{
    for(k=i+1;k<n3;k++)
    {
        if(crr[k].index==crr[i].index)
        {
            crr[i].num=crr[i].num+crr[k].num;
            crr[k].num=0;crr[k].index=0;
        }
    }
}
    for(i=0;i<n3;i++)
    {
        max=-1;j=-1;
        for(k=0;k<n3;k++)
    {
       if(crr[k].index>max)
        {
            max=crr[k].index;
            j=k;
        }

    }
    if(crr[j].num!=0)
    printf("%d %d ",crr[j].num,crr[j].index);
    crr[j].index=-1;
    }

    return 0;
}



