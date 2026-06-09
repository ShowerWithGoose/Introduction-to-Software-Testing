#include<stdio.h>
#include<string.h>
char str[1000000];
int main()
{
    int flag=1,len,dot=-1,validnum=-1;
    gets(str);
    len=strlen(str);
    //if(str[0]=='0')flag=-1;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='.')
        {
            dot=i;
        }
        if(str[i]!='0'&&str[i]!='.'&&validnum==-1)
        {
            validnum=i;
        }
        if(dot!=-1&&validnum!=-1)break;
    }
    if(validnum==0)
    {
        printf("%c.",str[0]);
        for(int i=1;i<len;i++)
        if(str[i]!='.')printf("%c",str[i]);
        //if(dot!=-1)
        printf("e%d",dot-1);
        //else printf("e%d",len-1);
    }
    else 
    {
        printf("%c",str[validnum]);
        if(validnum!=len-1)printf(".");
        for(int i=validnum+1;i<len;i++)
        {
            printf("%c",str[i]);
        }
        if(dot!=-1)printf("e%d",dot-validnum);
    }
    return 0;
}


