#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char sen1[2000],sen2[2000];

struct node{
    int a;
    int n;
}in1[2000],in2[2000],ans[2000],out[2000];

int cmp(const void *a, const void *b)
{
    struct node c = *(struct node *)a;
    struct node d = *(struct node *)b;
    if(c.n>d.n)
        return -1;
    else if(c.n<d.n)
        return 1;
    return 0;
}

int main()
{
    int i=0,j=0,cnt1=0,cnt2=0,hold=0,flag=0;
    int cnt=0;
    gets(sen1);
    gets(sen2);
    for(i=0;i<strlen(sen1);i++)
    {
        if(sen1[i]==' '&&flag)
        {
            in1[cnt1].n=hold;
            hold=0;
            flag=0;
        }
        else if(sen1[i]==' ')
        {
            in1[++cnt1].a=hold;
            hold=0;
            flag=1;
        }
        else
        {
            hold=hold*10+sen1[i]-'0';
            if(i==strlen(sen1)-1)
            {
                in1[cnt1].n=hold;
                flag=0;
                hold=0;
            }
        }
    }
    for(i=0;i<strlen(sen2);i++)
    {
        if(sen2[i]==' '&&flag)
        {
            in2[cnt2].n=hold;
            hold=0;
            flag=0;
        }
        else if(sen2[i]==' ')
        {
            in2[++cnt2].a=hold;
            hold=0;
            flag=1;
        }
        else
        {
            hold=hold*10+sen2[i]-'0';
            if(i==strlen(sen2)-1)
            {
                in2[cnt2].n=hold;
                flag=0;
                hold=0;
            }
        }
    }
    /*for(i=1;i<=cnt1;i++)
    {
        printf("%d %d\n",in1[i].a,in1[i].n);
    }
    for(i=1;i<=cnt2;i++)
    {
        printf("%d %d\n",in2[i].a,in2[i].n);
    }*/
    for(i=1;i<=cnt1;i++)
    {
        for(j=1;j<=cnt2;j++)
        {
            ans[++cnt].a=in1[i].a*in2[j].a;
            ans[cnt].n=in1[i].n+in2[j].n;
        }
    }
    /*for(i=1;i<=cnt;i++)
    {
        printf("%d %d\n",ans[i].a,ans[i].n);
    }*/
    qsort(ans+1,cnt,sizeof(ans[1]),cmp);
    for(i=1;i<=cnt;i++)
    {
        if(i>=2&&ans[i].n==ans[i-1].n)
        {
            ans[i].a+=ans[i-1].a;
            ans[i-1].a=0;
            ans[i-1].n=0;
        }
    }
    j=0;
    for(i=1;i<=cnt;i++)
    {
        if(ans[i].a!=0)
        {
            out[++j]=ans[i];
        }
    }
    for(i=1;i<=j;i++)
    {
        printf("%d %d ",out[i].a,out[i].n);
    }

    return 0;
}

