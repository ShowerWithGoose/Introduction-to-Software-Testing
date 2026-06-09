#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
struct ind{
    int xs;
    int mc;
};
int compare(const void *a,const void *b){
    struct ind *c,*d;
    c=(struct ind*)a,d=(struct ind*)b;
    return(-c->mc+d->mc);
}
int main()
{
    struct ind s1[1000],s2[1000],s[100000];
    char c=' ';
    int i=0,j=0,k=0,len1=0,len2=0,len=0,flag[100000]={0};
    while(c!='\n')
    {
        scanf("%d%d%c",&s1[i].xs,&s1[i].mc,&c);
        i++;
    }
    len1=i,c=' ',i=0;
    while(c!='\n')
    {
        scanf("%d%d%c",&s2[i].xs,&s2[i].mc,&c);
        i++;
    }
    len2=i,c=' ',i=0,k=0;
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            s[k].mc=s1[i].mc+s2[j].mc;
            s[k].xs=s1[i].xs*s2[j].xs;
            k++;
        }
    }
    len=k;
    qsort(s,len,sizeof(s[0]),compare);
    for(i=0;i<len;i++)
    {
        if(flag[i]==1)
        continue;
        for(j=i+1;j<len;j++)
        {
            if(s[j].mc==s[i].mc)
            {
                s[i].xs+=s[j].xs;
                flag[j]=1;
            }
            else
            break;
        }
    }
    for(i=0;i<len;i++)
    {
        if(flag[i]==1)
        continue;
        else
        printf("%d %d ",s[i].xs,s[i].mc);
    }
    return 0;
}
