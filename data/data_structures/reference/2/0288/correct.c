#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int j=0,i=0,k=0,m=0,n=0,p=0,q=0,r=0;
    int len=0;
    int sum=0;
    int result[1000]={};
    char equa[1000]={};
    int num[1000]={};
    char fuhao[1000]={};

    gets(equa);
    len=strlen(equa);

    //去掉equa中的空格
    for(j=0;j<len;j++)
    {
        if(equa[j]==' ')
        {
            for(i=j;i<len;i++)
            {
                equa[i]=equa[i+1];
            }
        }
    }
    len=strlen(equa);

    //数字和符号分类存放
    for(j=0;j<len;j++)
    {
        if(equa[j]>='0'&&equa[j]<='9')
        {
            num[k]=num[k]*10+equa[j]-'0';
        }
        else
        {
            fuhao[m]=equa[j];
            m++;
            k++;
        }
    }

    //第一个数为正则补“0+”，为负则无需操作
    if(equa[0]>='0'&&equa[0]<='9')
    {
        for(j=m;j>0;j--)
        {
            fuhao[j]=fuhao[j-1];
        }
        fuhao[0]='+';

        for(j=k;j>0;j--)
        {
            num[j]=num[j-1];
        }
        num[0]=0;
    }

    //无运算情况
    if(fuhao[1]=='=')
    {
        if(fuhao[0]=='+')
        {
            printf("%d\n",num[1]);
            return 0;
        }
        else if(fuhao[0]=='-')
        {
            printf("-%d\n",num[1]);
            return 0;
        }

    }

    //n对应符号

    for(n=0;fuhao[n]!='\0';n++)
    {
        if(fuhao[n]=='+'&&fuhao[n+1]=='*')// + * /
        {
            result[q]=result[q]+(num[n+1]*num[n+2]);
            for(p=n+2;fuhao[p]=='*'||fuhao[p]=='/';p++)// * *
            {
                if(fuhao[p]=='*')
                {
                    result[q]=result[q]*num[p+1];
                }
                else if(fuhao[p]=='/')
                {
                    result[q]=result[q]/num[p+1];
                }
            }
            q++;
        }
        else if(fuhao[n]=='+'&&fuhao[n+1]=='/')// + / *
        {
            result[q]=result[q]+(num[n+1]/num[n+2]);
            for(p=n+2;fuhao[p]=='*'||fuhao[p]=='/';p++)// / *
            {
                if(fuhao[p]=='*')
                {
                    result[q]=result[q]*num[p+1];
                }
                else if(fuhao[p]=='/')
                {
                    result[q]=result[q]/num[p+1];
                }
            }
            q++;
        }


        else if(fuhao[n]=='-'&&fuhao[n+1]=='*')// - * /
        {
            result[q]=result[q]-(num[n+1]*num[n+2]);
            for(p=n+2;fuhao[p]=='*'||fuhao[p]=='/';p++)// * *
            {
                if(fuhao[p]=='*')
                {
                    result[q]=result[q]*num[p+1];
                }
                else if(fuhao[p]=='/')
                {
                    result[q]=result[q]/num[p+1];
                }
            }
            q++;
        }
        else if(fuhao[n]=='-'&&fuhao[n+1]=='/')// - / *
        {
            result[q]=result[q]-(num[n+1]/num[n+2]);
            for(p=n+2;fuhao[p]=='*'||fuhao[p]=='/';p++)// / *
            {
                if(fuhao[p]=='*')
                {
                    result[q]=result[q]*num[p+1];
                }
                else if(fuhao[p]=='/')
                {
                    result[q]=result[q]/num[p+1];
                }
            }
            q++;
        }


        else if(fuhao[n]=='+'&&(fuhao[n+1]=='+'||fuhao[n+1]=='-'||fuhao[n+1]=='='))// + +-
        {
            result[q]=result[q]+num[n+1];
            q++;
        }
        else if(fuhao[n]=='-'&&(fuhao[n+1]=='+'||fuhao[n+1]=='-'||fuhao[n+1]=='='))// - +-
        {
            result[q]=result[q]-num[n+1];
            q++;
        }
    }

    for(r=0;r<q;r++)
    {
        sum+=result[r];
    }

    printf("%d\n",sum);

    return 0;
}

