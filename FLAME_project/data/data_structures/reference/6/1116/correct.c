#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int Stack[101],cnt=0;
void Insert(int n)
{
    if(cnt<100)
    {
        cnt++;
        Stack[cnt]=n;
    }
    else
    printf("error ");
}
void Delete()
{
    if(cnt==0)
    printf("error ");
    else
    {
        printf("%d ",Stack[cnt]);
        cnt--;
    }
}
int main()
{
    int order,n0;
    while(1)
    {
    scanf("%d",&order);
    if(order==1)
    {
        scanf("%d",&n0);
        Insert(n0);
    }
    if(order==0) Delete();
    if(order==-1) return 0;
    }
}
