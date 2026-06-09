#include<stdio.h>
#include<string.h>
void DELETELIST(char a[],int n,int i)
{
    int j;
    for(j=i;j<n;j++)
        a[j-1]=a[j];
    n--;
}
char s[101];
int i,j,k;
int num=0;
int main()
{
    gets(s);
    if(s[0]=='0'&&s[1]=='.')
    {
        for(k=2;k<strlen(s);k++)
        {
            if(s[k]=='0')
                num++;
            else
                break;
        }
        num+=1;
        num=-num;
    }
    else
    {
        for(k=0;k<strlen(s);k++)
        {
            if(s[k]!='.')
                num++;
            else
                break;
        }
        num-=1;
    }

    for(i=j=0;s[i]!='\0';i++)
        if(s[i]!='.')
            s[j++]=s[i];
            s[j]='\0';               //É¾³ýÐ¡Êýµã
    for(i=0;i<101;i++)
    {
        if(s[0]=='0')
            DELETELIST(s,101,0);
        else
            break;
    }                               //É¾³ý0
    if(s[1]!='\0')
    {
        for(j=strlen(s)-1;j>=1;j--)
        s[j+1]=s[j];
        s[1]='.';
    }
    printf("%s",s);
    printf("e%d",num);
    return 0;


}

