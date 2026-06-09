#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int hash[12000];
int Hash(int n)
{
    unsigned long long h=n*31799;
    return h%11027;
}
struct Number
{
    int a;//系数
    int b;//指数
};
struct Number n1[10000],n2[10000],n3[1000000];
int cmp(const void*e,const void*f)
{
    struct Number ee = *(struct Number *)e;
    struct Number ff = *(struct Number *)f;
    if((ee.b-ff.b)<0) return 1;
    else return -1;
}
int main()
{
    char c='0';
    int cnt1=0,cnt2=0,cnt3=0,ans1,ans2;
    while(c!='\n'&&c!='\r')
    {
        cnt1++;
        scanf("%d %d",&n1[cnt1].a,&n1[cnt1].b);
        c=getchar();
    }
    c='0';
    while(c!='\n'&&c!='\r')
    {
        cnt2++;
        scanf("%d %d",&n2[cnt2].a,&n2[cnt2].b);
        c=getchar();
    }
    for(int i=1;i<=cnt1;i++)
    {
        for(int j=1;j<=cnt2;j++)
        {
            ans1=n1[i].a*n2[j].a;
            ans2=n1[i].b+n2[j].b;
            if(!hash[Hash(ans2)])
            {
                cnt3++;
                hash[Hash(ans2)]=1;
                n3[cnt3].a=ans1;
                n3[cnt3].b=ans2;
            }
            else
            {
                int i;
                for(i=1;i<=cnt3;i++)
                {
                    if(n3[i].b==ans2)
                    break;
                }
                n3[i].a+=ans1;
            }
        }
    }
    qsort(n3+1,cnt3,sizeof(n3[1]),cmp);
    for(int i=1;i<=cnt3;i++)
    {
        printf("%d %d ",n3[i].a,n3[i].b);
    }
    return 0;
}
