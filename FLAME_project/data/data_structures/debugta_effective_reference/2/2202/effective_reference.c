#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int p=0,t=0,k=0;
struct stack1 {
	int top1;
	int shu[2000];
};
struct stack1 s;
struct stack2 {
	int top2;
	char fu[2000];
};
struct stack2 ss;
void calculate()
{
	switch (ss.fu[t-1]){
		case '+':			
        s.shu[p-2]=s.shu[p-2]+s.shu[p-1];
        p--;
        s.shu[p]=0;
        ss.fu[t-1]='\0';
        break;
        case '-':
       	s.shu[p-2]=s.shu[p-2]-s.shu[p-1];
        p--;
        s.shu[p]=0;
        ss.fu[t-1]='\0';
        break;
        case '*':
       	s.shu[p-2]=s.shu[p-2]*s.shu[p-1];
        p--;
        s.shu[p]=0;
        ss.fu[t-1]='\0';
        break;
        case '/':
        s.shu[p-2]=s.shu[p-2]/s.shu[p-1];
        p--;
        s.shu[p]=0;
        ss.fu[t-1]='\0';
        break;
	}
   
}
int main()
{
    int k=0;
    char c;
    while((c=getchar())!='=')
    {
        if(c>='0'&&c<='9')
        {
            for(;c>='0'&&c<='9';c=getchar())
                k=(c-'0')+10*k;
            s.shu[p]=k;
            p++;
            k=0;
        }
        if(c=='('||c=='+'||c=='*'||c=='/'||c=='-')
        {
            if(c=='+'||c=='-')
            {
                for(t;t>0&&ss.fu[t-1]!='(';t--)
                    calculate();
                    ss.fu[t]=c;
            t++;
            }
            else if(c=='*'||c=='/')
            {
                for(t;t>0&&ss.fu[t-1]!='('&&ss.fu[t-1]!='+'&&ss.fu[t-1]!='-';t--)
                   calculate();
                   ss.fu[t]=c;
            t++;
            }
            else if(c=='('){
            	 ss.fu[t]=c;
            t++;
			}
       
        }
        else if(c==')')
            {
                for(t;ss.fu[t-1]!='(';t--)
                    calculate();
                ss.fu[t-1]='\0';
                t--;
            }
        else if(c=='=')
            break;
    }
    for(t;t>0;t--)
      calculate();

    printf("%d",s.shu[0]);
}


