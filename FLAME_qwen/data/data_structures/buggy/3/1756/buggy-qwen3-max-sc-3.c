#include<stdio.h>
#include<string.h>
char a[1005];
int main()
{
    int sum,flag=0,b,c,d;
    gets(a); // @@ [Use of unsafe function 'gets' which has been removed from C standard; causes compilation error in modern compilers]
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
        for(int i=b;i<=b+d;i++) // @@ [Incorrect loop bound: 'b+d' exceeds valid index range and logic for extracting significant digits is flawed]
        {
            if(i==b+1&&i!=strlen(a))
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