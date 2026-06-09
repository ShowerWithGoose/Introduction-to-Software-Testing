#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int p=0,j=0,k=0;
struct stack1 {
	int top1;
	int shu[2000];
};
struct stack1 shu;
struct stack2 {
	int top2;
	char fu[2000];
};
struct stack2 fu;
void calculate()
{
	switch (fu.fu[j-1]){
		case '+':			
        shu.shu[p-2]=shu.shu[p-2]+shu.shu[p-1];
        p--;
        shu.shu[p]=0;
        fu.fu[j-1]='\0';
        break;
        case '-':
       	shu.shu[p-2]=shu.shu[p-2]-shu.shu[p-1];
        p--;
        shu.shu[p]=0;
        fu.fu[j-1]='\0';
        break;
        case '*':
       	shu.shu[p-2]=shu.shu[p-2]*shu.shu[p-1];
        p--;
        shu.shu[p]=0;
        fu.fu[j-1]='\0';
        break;
        case '/':
        shu.shu[p-2]=shu.shu[p-2]/shu.shu[p-1];
        p--;
        shu.shu[p]=0;
        fu.fu[j-1]='\0';
        break;
	}
   
}
int main()
{
    int ans=0;
    char str;
    while((str=getchar())!='=')
    {
        if(str>='0'&&str<='9')
        {
            for(;str>='0'&&str<='9';str=getchar())
                ans=(str-'0')+10*ans;
            shu.shu[p]=ans;
            p++;
            ans=0;
        }
        if(str=='('||str=='+'||str=='*'||str=='/'||str=='-')
        {
            if(str=='+'||str=='-')
            {
                for(j;j>0&&fu.fu[j-1]!='(';j--)
                    calculate();
                    fu.fu[j]=str;
            j++;
            }
            else if(str=='*'||str=='/')
            {
                for(j;j>0&&fu.fu[j-1]!='('&&fu.fu[j-1]!='+'&&fu.fu[j-1]!='-';j--)
                   calculate();
                   fu.fu[j]=str;
            j++;
            }
            else if(str=='('){
            	 fu.fu[j]=str;
            j++;
			}
       
        }
        else if(str==')')
            {
                for(j;fu.fu[j-1]!='(';j--)
                    calculate();
                fu.fu[j-1]='\0';
                j--;
            }
        else if(str=='=')
            break;
    }
    for(j;j>0;j--)
      calculate();

    printf("%d",shu.shu[0]);
}


