#include<stdio.h>
#include<string.h>
char a[1005];
int main()
{
    int sum,flag=0,b,c,d;
    gets(a);
    for(int i=0;i<strlen(a);i++)
    {    
        if(flag==0&&a[i]!='0'&&a[i]!='.')
        {
            flag=1;
            b=i;
        }
        if(a[i]=='.')
        {
            c=i;
        }
    }
//    i=strlen(a)
//    while(i>0&&a[i]==0)
//    {
//        
//    }
    for(int i=strlen(a)-1;i>c;i--)
    {
        if(a[i]!='0'&&a[i]!='.')
        {
            d=i;
            break;
        }
    }
    //printf("%d",d);
    if(flag==1)
    {
        for(int i=b;i<=b+d;i++) // @@ [Loop bound should be i<=d, not i<=b+d. Using i<=b+d may cause out-of-bounds access and produce incorrect base output.]
        {
            if(i==b+1&&i!=strlen(a)) // @@ [Condition for printing decimal point is incorrect. It should be based on whether d > b (i.e., more than one digit) rather than checking i==b+1. Also i!=strlen(a) is insufficient to prevent out-of-bounds access.]
            printf(".");
            //printf("$");
            if(a[i]!='.')
            printf("%c",a[i]);
        }
        int p;
        if(a[0]=='0')
        p=c-b;
        else
        p=c-b-1;
        if(p>=0)
        printf("e%d\n",p);
        else
        {
            p=-p;
            printf("e-%d\n",p);
        }
        
    }
    else
    printf("0e0\n");
}