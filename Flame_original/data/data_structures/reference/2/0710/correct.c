#include <stdio.h>
#include <string.h>
int data[1000],i=0,j=0;
char fu[1000];
void jisuan()
{
    if(fu[j-1]=='+')
    {
        data[i-2]=data[i-2]+data[i-1];
        i--;
        data[i]=0;
        fu[j-1]='\0';
    }
    else if(fu[j-1]=='-')
    {
        data[i-2]=data[i-2]-data[i-1];
        i--;
        data[i]=0;
        fu[j-1]='\0';
    }
    else if(fu[j-1]=='*')
    {
        data[i-2]=data[i-2]*data[i-1];
        i--;
        data[i]=0;
        fu[j-1]='\0';
    }
    else if(fu[j-1]=='/')
    {
        data[i-2]=data[i-2]/data[i-1];
        i--;
        data[i]=0;
        fu[j-1]='\0';
    }
    else if(fu[j-1]=='%')
    {
        data[i-2]=data[i-2]%data[i-1];
        i--;
        data[i]=0;
        fu[j-1]='\0';
    }
}
int main()
{
    int shu=0;
    char a;
    while((a=getchar())!='=')
    {
        if(a>='0'&&a<='9')
        {
            for(;a>='0'&&a<='9';a=getchar())
                shu=(a-'0')+10*shu;
            data[i]=shu;
            i++;
            shu=0;
        }
        if(a=='('||a=='+'||a=='*'||a=='%'||a=='/'||a=='-')
        {
            if(a=='+'||a=='-')
            {
                for(j;j>0&&fu[j-1]!='(';j--)
                    jisuan();
            }
            else if(a=='*'||a=='/'||a=='%')
            {
                for(j;j>0&&fu[j-1]!='('&&fu[j-1]!='+'&&fu[j-1]!='-';j--)
                    jisuan();
            }
            fu[j]=a;
            j++;
        }
        else if(a==')')
            {
                for(j;fu[j-1]!='(';j--)
                    jisuan();
                fu[j-1]='\0';
                j--;
            }
        else if(a=='=')
            break;
    }
    for(j;j>0;j--)
        jisuan();
    printf("%d",data[0]);
    return 0;
}

