#include<stdio.h>
#include<string.h>
char ch[150];
int i,j;
int num[150];
int po,f=-1,sy=1;

int judge(char a)
{
    if(a>='0'&&a<='9')
    return (a-'0');
    else
    return -1;

}


int main()
{
    gets(ch);//input
    i=0;
    if(ch[0]=='-')//symble
    {
        sy=-1;
        i++;
    }
    else if(ch[0]=='+')
    {
        sy=1;
        i++; 
    }
    while(ch[i]!='\0')//exchange
    {
        if(ch[i]!='0'&&ch[i]!='.'&&f==-1)
        f=i;
        if(judge(ch[i])==-1)
        po=i;
        if(f!=-1&judge(ch[i])>=0)
        {
            num[j]=judge(ch[i]);
            j++;
        }
        i++;
    }
    if(sy==-1)//output
    printf("-");
    //effcient num
    printf("%d",num[0]);
    if(j>1)
    {
        printf(".");
        for(i=1;i<j;i++)
        printf("%d",num[i]);
    }
    printf("e");
    sy=po-f;
    if(sy>0)
        sy-=1;
    else
    {
        printf("-");
        sy=-sy;
    }
    printf("%d",sy);
}
