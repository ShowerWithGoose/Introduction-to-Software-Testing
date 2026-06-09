#include<stdio.h>
#include<string.h>
char c[90]={0},ans[90]={'l'};
int t,tt,ttt;
int main()
{
    gets(c); // @@ gets() is removed from the C11 standard and causes a compilation error in modern compilers; use fgets() instead.
    if(c[0]!='-')
    {
        for(int i=0;c[i]!=0;i++) 
        {
            if(c[i]==0) t=i-1;//数一共t位
            if(c[i]=='.') tt=i;//小数点前有tt位
            if(c[i]!='.') ans[ttt++]=c[i];
        }
        if(c[0]=='0')
        {
            int st;
            for(int i=1;i<ttt;i++)
            {
                if(ans[i]!='0')
                {
                    st=i;
                    printf("%c.",ans[i]);
                    for(int j=i+1;j<ttt;j++)
                    {
                        printf("%c",ans[j]);
                    }
                    break;
                }
            }
            printf("e-%d",st);
        }else if(tt==1&&c[0]!='0')
        {
            printf("%se0",c);
        }
        else{
            printf("%c.",ans[0]);
            for(int i=1;i<ttt;i++) printf("%c",ans[i]);
            printf("e%d",tt-1);
        }
    }else{
        for(int i=0;c[i]!=0;i++)
        {
            if(c[i]!='-'&&c[i]!='.') ans[ttt++]=c[i];
            if(c[i]==0) t=i-2;//数一共t位
            if(c[i]=='.') tt=i-1;//小数点前有tt位
        }
        if(c[1]=='0')
        {
            int st;
            for(int i=1;i<ttt;i++)
            {
                if(ans[i]!='0')
                {
                    st=i;
                    printf("-%c.",ans[i]);
                    for(int j=i+1;j<ttt;j++)
                {
                    printf("%c",ans[j]);
                }
                    break;
                }
            }
            printf("e-%d",st);
        }else if(tt==1&&c[1]!='0')
        {
            printf("%se0",c);
        }
        else{
            printf("-%c.",ans[0]);
            for(int i=1;i<ttt;i++) printf("%c",ans[i]);
            printf("e%d",tt-1);
        }
    }
    
    
    return 0;
}