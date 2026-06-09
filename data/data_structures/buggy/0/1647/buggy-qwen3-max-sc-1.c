#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int i,j;
    fgets(a,100,stdin);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='-')
        {
            if((a[i-1]>='a')&&(a[i-1]<='z'))
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);} @@ [Missing bounds check on a[i+1] to ensure it's within 'a'-'z'; also fails to verify that a[i+1] > a[i-1] and that both sides are same type]
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z'))
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);} @@ [Missing bounds check on a[i+1] to ensure it's within 'A'-'Z'; also fails to verify that a[i+1] > a[i-1] and that both sides are same type]
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9'))
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);} @@ [Missing bounds check on a[i+1] to ensure it's within '0'-'9'; also fails to verify that a[i+1] > a[i-1] and that both sides are same type]
            }
            else
            {printf("%c",a[i]);} @@ [Missing else clause to print '-' when expansion conditions are not met; original code skips printing '-' in invalid cases]
        }
        else
        {printf("%c",a[i]);}
    }
    return 0;
}