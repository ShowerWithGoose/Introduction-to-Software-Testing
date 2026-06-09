#include<stdio.h>
#include<string.h>

int main()
{
    char a[100];
    scanf("%s",a);
    int i=0;
    for(;a[i]!='\0';i++)
    {
        printf("%c",a[i]);
        if(a[i+1]!='-'||a[i]>=a[i+2]);
        else if((a[i]<='z'&&a[i]>='a')&&(a[i+2]<'a'||a[i+2]>'z'));
        else if((a[i]<='Z'&&a[i]>='A')&&(a[i+2]<'A'||a[i+2]>'Z'));
        else if((a[i]<='9'&&a[i]>='0')&&(a[i+2]<'0'||a[i+2]>'9'));
        else
        {
            for(char k=a[i]+1;k<a[i+2];k++)
                printf("%c",k);
            i+=1;
        }
    }
    return 0;
}



