#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char c;

struct s
{
    int x;
    int e;
} a[100],b[100],temp,s[10000];

int main()
{
    int tempx,tempe,n,m,num=0;

    scanf("%d%d%c",&tempx,&tempe,&c);    //输入a
    for(n=0;c!='\n';n++){
        a[n].x=tempx;
        a[n].e=tempe;
        scanf("%d%d%c",&tempx,&tempe,&c);
    }
    a[n].x=tempx;
    a[n].e=tempe;

    scanf("%d%d%c",&tempx,&tempe,&c);    //输入b
    for(m=0;c!='\n';m++){
        b[m].x=tempx;
        b[m].e=tempe;
        scanf("%d%d%c",&tempx,&tempe,&c);
    }
    b[m].x=tempx;
    b[m].e=tempe;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            s[num].x=a[i].x*b[j].x;
            s[num].e=a[i].e+b[j].e;
            num++;
        }
    }

    for(int i;i<num;i++){
        for(int j=i+1;j<num;j++){
            if(s[i].e<s[j].e){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }

    for(int i=0;i<num;i++)
    {
        if(s[i].e== s[i+1].e&&s[i].e!= 0)        //合并指数相同的项数
        {
            s[i+1].x+=s[i].x;
            s[i].x= 0;
        }
    }

    for(int i=0;i<num;i++)
        if(s[i].x!= 0)
        printf("%d %d ",s[i].x,s[i].e);               //输出

    return 0;
}


