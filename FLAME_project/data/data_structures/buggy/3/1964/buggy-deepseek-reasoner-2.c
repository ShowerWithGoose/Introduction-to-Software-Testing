#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char num[1005];
    int len,mid1,mid2,result; 
    int flag=0;
    gets(num);
    len=strlen(num);
    for(int i=0;i<len;i++)
    {
        if(num[i]=='.')
        mid2=i;
        else if(num[i]!='0'&&flag==0)
        {
            mid1=i;
            flag=1;
        }
    }  
    result=mid1-mid2;
    if(result<0)
    {
        printf("%c.",num[mid1]);
        for(int i=mid1+1;i<len;i++)
        {
            if(num[i]=='.')
            continue;
            else
            printf("%c",num[i]);
        }
        printf("e%d",-result-1);
    }
    else
    {
        printf("%c",num[mid1]); // @@ Missing decimal point after first digit when there are additional significant digits. Should print '.' if there are digits after mid1 (excluding '.') before printing the rest.
        for(int i=mid1+1;i<len;i++)
        {
            if(num[i]=='.')
            continue;
            else
            printf("%c",num[i]);
        }
        printf("e-%d",result);
    }
    return 0;
}