#include <stdio.h>
#include <string.h>
char ch[100000],map[100000];

void sert(int i,int k,int x,int j)
{
    int temp;
    for(k=1;k<=x;k++)
    {
        ch[i+k-1]=ch[i-1]+k;
    }
    for(temp=0;temp<j;temp++)
    {
        ch[i+x+temp]=map[temp];
    }
}//拓展并入 
int main()
{
    gets(ch);
    int len,i=0,j=0,x,k,hold,temp;
    int w,e,r,t,y,u;
    len=strlen(ch);
    for(i=0;i<len;i++)
    {
        if(ch[i]=='-'&&ch[i+1]>ch[i-1])
        {
            x=ch[i+1]-ch[i-1]-1;
            hold=i;
            for(hold++,j=0;hold<len;hold++,j++)
               {
                 map[j]=ch[hold];
               }
               w=ch[i-1]-'a';
               e=ch[i+1]-'a';
               r=ch[i-1]-'A';
               t=ch[i+1]-'A';
               y=ch[i-1]-'0';
               u=ch[i+1]-'0';//判断类型 
            if(0<=w&&w<25&&0<e&&e<=25)
                {
                    sert(i,k,x,j);
                }
            else if(0<=r&&r<25&&0<t&&t<=25)
                {
                    sert(i,k,x,j);
                }
            else if(0<=y&&y<9&&0<u&&u<=9)
                {
                    sert(i,k,x,j);
                }
        len=strlen(ch);//迭代长度 
        }
    }
    printf("%s",ch);
}

