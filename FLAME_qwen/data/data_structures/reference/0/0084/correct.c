#include<stdio.h>
int judge(char a,char b)
{
    if(((a>='0'&&a<='9'&&b>='0'&&b<='9')||(a>='A'&&a<='Z'&&b>='A'&&b<='Z')||(a>='a'&&a<='z'&&b>='a'&&b<='z'))&&b>a)
        return 1;
    else
        return 0;
}
int main()
{
    char a[500],b[500];
    int i,j;
    gets(a);
    for(i=0,j=0;a[i]!='\0';i++)
    {
        if(a[i]!='-')
        {
            b[j]=a[i];
            j++;
        }
        if(a[i]=='-')
        {
            if(judge(a[i-1],a[i+1])==0)
            {
                b[j]=a[i];
                j++;
                continue;
            }
            if(judge(a[i-1],a[i+1])==1)
            {
                do
                {
                    b[j]=b[j-1]+1;
                    j++;
                }while(b[j-1]<a[i+1]-1);
            }
        }
    }
    b[j]='\0';
    puts(b);
    return 0;
}

