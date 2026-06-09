#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char s[30000];
int main()
{
    gets(s);
    int l=strlen(s),sum1=0,sum2=0,x=1,z;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='0'||s[i]=='.')
        sum1+=1;
        else
        break;
    }
    if(s[0]=='0')
    x=-x;
    else
    x=x;
    printf("%c",s[sum1]);
    if(sum1!=l-1)
    {
        printf(".");
    }
    for(int j=sum1+1;j<l;j++)
    {
        if(s[j]=='.')
        {
            z=j;
            continue;
        }
        else 
        {
            printf("%c",a[j]); // @@ [undefined variable 'a'; should be 's[j]' instead of 'a[j]']
            sum2++;
        }
    }
    printf("e");
    if(s[0]=='0')
    {
        printf("-%d",sum1-1);
        
    }
    else
    {
        printf("%d",z-1); // @@ [variable 'z' may be used uninitialized if the input has no decimal point, leading to undefined behavior]
    }
    return 0;
}