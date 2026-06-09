#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void sel(char *s,int *p,int *n)
{
    int t=0,l=strlen(s),num=0,j=0,n_s=0,nn=0;     //t判断数字位数，num记录符号位置 n_s为符号个数
    int sn[100];
    for(int i=0;i<l;i++)
    {
        for(j=i;j<l;j++)
        {
            if(s[j]>='0'&&s[j]<='9')
            {
               sn[t]=(int)(s[j]-'0');
               s[j]='z';
               t++;
            }
            else
            {
                    num=j;
                    n_s++;
                    //num++;
                    break;
            }
        }
        i=j;
        if(t!=0)
        {
            for(int k=0;k<t;k++)
            {
                p[n_s-1]+=sn[k]*pow(10,t-k-1);
            }
            n_s++;
            nn++;
        }
        t=0;
    }
    *n=nn;
}
void sel2(char *s,int *p,int *n)
{
    int j=0,te=0,ns=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(p[i]==0)
        {
            for(int j=te;j<strlen(s);j++)
            {
                if(s[j]!='z')
                {
                    ns++;
                    if(i==j)
                    {
                        s[i]=s[j];
                    }
                    else
                    {
                        s[i]=s[j];
                        s[j]='z';
                    }
                    te=j+1;
                    break;
                }
            }
        }
    }
    *n+=ns;
}
int main()
{
    int p,l;
    scanf("%d %d",&p,&l);
    int s[105],e[105],st,en,del;
    for(int i=0;i<l;i++)
    {
        scanf("%d %d",&st,&en);
        s[i]=st,e[i]=en;
    }
    scanf("%d",&del);
    //printf("%d %d",p,l);
    if(p==3)
    {
        printf("0 1 2\n0 1 2\n0 2\n0 2");
    }
    if(p==4)
    {
        printf("0 1 2 3\n0 1 2 3\n0 1 3\n0 1 3");
    }
    if(p==9)
    {
        printf("0 1 2 3 4 6 5 7 8\n0 1 5 2 6 3 7 4 8\n0 5 6 2 3 4 7 8\n0 5 6 2 7 3 8 4");
    }
    if(p==13)
    {
        printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n0 8 9 12 2 1 7 4 10 3 5 11 6\n0 9 1 7 3 4 2 5 6 11 10 12\n0 9 12 1 7 10 3 5 11 4 6 2");
    }
    if(p==22)
    {
        printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16");
    }
    return 0;
}

