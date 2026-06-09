#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int a1;
    int a2;
    int b1;
    int b2;
}stu;
int cmp(const void *a,const void *b)
{
    return (*(stu *)a).a1-(*(stu *)b).a1;
}
int hash[100];
int main()
{
    int n,i,j,max,dot;
    scanf("%d",&n);
    stu line[100]; 
    
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&line[i].a1,&line[i].a2,&line[i].b1,&line[i].b2);
    }
    qsort(line,n,sizeof(stu),cmp);
    for(i=0;i<n;i++)
    {
        for(j=i;j>=0;j--)
        {
            if(line[i].a1==line[j].b1&&line[i].a2==line[j].b2)
            {
                line[j].b1=line[i].b1;
                line[j].b2=line[i].b2;
                line[i].a1=0;
                line[i].a2=0;
                line[i].b1=0;
                line[i].b2=0;
                hash[j]++;
            }
        }
    }
    max=hash[0];
    dot=0;
    for(i=0;i<n;i++)
    {
        if(hash[i]>=max)
       {
            max=hash[i];
            dot=i;
       }
    }
    printf("%d %d %d",max+1,line[dot].a1,line[dot].a2);
    return 0;
}
