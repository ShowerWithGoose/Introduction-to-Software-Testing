#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct s			
{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;					
}s[101];

int main()
{
    struct s s[101];
    int n;
    scanf("%d",&n);										
    int i,j;
    for(i=0;i<n;i++)
    scanf("%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2),s[i].num=1;
    struct s tmp;
    for(i=0;i<n;i++)
    for(j=i;j<n;j++){
        if(s[i].x1<s[j].x1)
        {
            tmp=s[i];
            s[i]=s[j];
            s[j]=tmp;
        }
    }			
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n-1;j++)					
        {											
            if(s[i].x1==s[j+1].x2&&s[i].y1==s[j+1].y2)
            s[j+1].num += s[i].num;
        }
    }
    int max=-1,flag=0;
    for(i=0;i<n;i++)
    {
        if(s[i].num>max)
        max=s[i].num,flag=i;			
    }
    printf("%d %d %d",max,s[flag].x1,s[flag].y1);		
    return 0;
}


