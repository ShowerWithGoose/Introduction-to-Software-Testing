#include<stdio.h>
#include<string.h>
char x1[101][10];
char y1[101][10];
char x2[101][10];
char y2[101][10];
char xmax[10],ymax[10];
int max=1,temp,cnt=1,array[1000];
int fun(char x2[][10],char x1[][10],int i,int cnt,int n,int array[],char y2[][10],char y1[][10]);
int i,j,k;
int main()
{
    int n;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf(" %s%s%s%s",x1[i],y1[i],x2[i],y2[i]);
    }
    for(i=0;i<n;i++)
    {
        array[i]=1;
       temp=fun(x2,x1,i,cnt,n,array,y2,y1);
       for (k=0;k<n;k++)
        array[k]=0;
       if(temp>max)
       {
           max=temp;
           strcpy(xmax,x1[i]);
           strcpy(ymax,y1[i]);
           cnt=1;
       }
    }
    printf("%d %s %s",max,xmax,ymax);
    return 0;
}
int fun(char x2[][10],char x1[][10],int i,int cnt,int n,int array[],char y2[][10],char y1[][10])//cnt表示最长线段数量
{
    int a=i;
    int shuliang=0;
    int flag=0;
    for (i=0;i<n;i++)
    {
        if(array[i]==1)
            shuliang++;
    }
    if(shuliang==n)
    {
        return cnt;
    }
    for(i=0;i<n;i++)
    {
        if(strcmp(x2[a],x1[i])==0 &&strcmp(y2[a],y1[i])==0 && array[i]==0)
        {   flag=1;
            array[i]=1;
            cnt++;
            return fun(x2,x1,i,cnt,n,array,y2,y1); 
        }
    }
    if(flag==0)
    return 1*cnt;
}


