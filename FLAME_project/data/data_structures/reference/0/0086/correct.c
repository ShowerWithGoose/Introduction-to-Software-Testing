#include <stdio.h>
#include <stdlib.h>
int judge(char a[],int i)
{
    if(a[i-1]<='9'&&a[i-1]>='0')
        {if(a[i+1]<='9'&&a[i+1]>='0')
        return 1;}
    else if(a[i-1]<='z'&&a[i-1]>='a')
        {if(a[i+1]<='z'&&a[i+1]>='a')
        return 1;}
    else if(a[i-1]<='Z'&&a[i-1]>='A')
        {if(a[i+1]<='Z'&&a[i+1]>='A')
        return 1;}
    else
        {return 0;}

}
int main()
{
    char a[100],e;
    gets(a);
    int i=0;
    for(;a[i]!='\0';i++)
    {
        if(a[i]!='-')
            printf("%c",a[i]);
        else
        {
            if(judge(a,i)==1)
            {for(e=a[i-1]+1;e<a[i+1];e++)
            printf("%c",e);}
            else
                printf("-");
        }
    }
    return 0;
}


