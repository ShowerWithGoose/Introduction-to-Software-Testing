#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct point{
    int x;
    int y;
};

struct line{
    struct point a;
    struct point b;
    int flag;
};

int lineforming(struct line q,struct line tab[],int n,int cnt);
void bubblesort(struct line tab[],int n);


int main()
{
    int n,i;
    int ans=1,num[105]={0};
    struct line tab[105];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&tab[i].a.x,&tab[i].a.y,&tab[i].b.x,&tab[i].b.y);
        tab[i].flag=0;
    }

    bubblesort(tab,n);

    /*for(i=0;i<n;i++)
    {
        printf("%d %d %d %d\n",tab[i].a.x,tab[i].a.y,tab[i].b.x,tab[i].b.y);
    }
    */



    for(i=0;i<n;i++)
    {
        num[i]=lineforming(tab[i],tab,n,1);
    }
    for(i=0;i<n;i++)
    {
        if(ans<num[i])
        {
            ans=num[i];
        }
    }

    printf("%d",ans);
    for(i=0;i<n;i++)
    {
        if(ans==num[i])
        {
            printf(" %d %d\n",tab[i].a.x,tab[i].a.y);
            return 0;
        }
    }

}

int lineforming(struct line q,struct line tab[],int n,int cnt)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(q.b.x==tab[i].a.x&&q.b.y==tab[i].a.y&&tab[i].flag==0)
        {
            cnt++;
            tab[i].flag=1;
            //printf("%d\n",cnt);
            return lineforming(tab[i],tab,n,cnt);
        }
    }
    return cnt;


}


void bubblesort(struct line tab[],int n)
{
    int i,j;
    struct line hold;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(tab[j].a.x>tab[j+1].a.x||(tab[j].a.x==tab[j+1].a.x&&tab[j].b.y>tab[j+1].b.y))
            {
                hold=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=hold;
            }
        }
    }
}

