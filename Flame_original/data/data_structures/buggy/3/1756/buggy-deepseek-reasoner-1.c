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
        for(int i=b;i<=b+d;i++) // @@ [Error: Loop range is incorrect; should be i<=d to cover only significant digits, and decimal point character should be skipped to avoid printing extra dot and the original decimal point.]
        {
            if(i==b+1&&i!=strlen(a)) // @@ [Error: Dot insertion logic flawed; it prints a dot before printing the original decimal point character, resulting in duplicate dots or incorrect placement. Should check if there are more digits after the first and skip the original decimal point when printing.]
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