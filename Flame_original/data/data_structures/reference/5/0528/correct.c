#include<stdio.h>
struct poly{
    int num;
    int index;
    struct poly *next;
}a[1000],b[1000],ans[1000];
int alen=0,blen=0,anslen=0;
int main()
{
    int i,j,k,sindex;
    char c=0;
    struct poly* p;
    while(c!='\n'){
        scanf("%d%d",&a[alen].num,&a[alen].index);
        a[alen].next=&a[alen+1];
        alen++;
        c=getchar();
    }
    while(~scanf("%d%d",&b[blen].num,&b[blen].index)){
        b[blen].next=&b[blen+1];
        blen++;
    }
    for(i=0;i<alen;i++)
    for(j=0;j<blen;j++)
    {
        sindex=a[i].index+b[j].index;
        for(p=&ans[0],k=0;k<anslen&&sindex>p->index;k++,p=p->next);
        if(k==anslen){
            p->index=sindex;
            p->num+=a[i].num*b[j].num;
            p->next=&ans[k];
            anslen++;
        }
        else if(sindex==p->index)
            p->num+=a[i].num*b[j].num;
        else{
            ans[anslen].num=p->num;
            ans[anslen].index=p->index;
            ans[anslen].next=p->next;
            p->num=a[i].num*b[j].num;
            p->index=sindex;
            p->next=&ans[anslen];
            anslen++;
        }
    }
    printf("\n");
    p=&ans[0];
    for(i=0;i<anslen;i++){
        p=&ans[0];
        for(j=0;j<anslen-i-1;j++)
            p=p->next;
        if(p->num!=0)
            printf("%d %d ",p->num,p->index);
    }
    return 0;
}


