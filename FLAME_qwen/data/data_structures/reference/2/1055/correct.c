#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int i=0,j=0,k=0;
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
	switch (ss.fu[j-1]){
		case '+':			
        s.shu[i-2]=s.shu[i-2]+s.shu[i-1];
        i--;
        s.shu[i]=0;
        ss.fu[j-1]='\0';
        break;
        case '-':
       	s.shu[i-2]=s.shu[i-2]-s.shu[i-1];
        i--;
        s.shu[i]=0;
        ss.fu[j-1]='\0';
        break;
        case '*':
       	s.shu[i-2]=s.shu[i-2]*s.shu[i-1];
        i--;
        s.shu[i]=0;
        ss.fu[j-1]='\0';
        break;
        case '/':
        s.shu[i-2]=s.shu[i-2]/s.shu[i-1];
        i--;
        s.shu[i]=0;
        ss.fu[j-1]='\0';
        break;
	}
   
}
int main()
{
    int n=0;
    char c;
    while((c=getchar())!='=')
    {
        if(c>='0'&&c<='9')
        {
            for(;c>='0'&&c<='9';c=getchar())
                n=(c-'0')+10*n;
            s.shu[i]=n;
            i++;
            n=0;
        }
        if(c=='('||c=='+'||c=='*'||c=='/'||c=='-')
        {
            if(c=='+'||c=='-')
            {
                for(j;j>0&&ss.fu[j-1]!='(';j--)
                    calculate();
                    ss.fu[j]=c;
            j++;
            }
            else if(c=='*'||c=='/')
            {
                for(j;j>0&&ss.fu[j-1]!='('&&ss.fu[j-1]!='+'&&ss.fu[j-1]!='-';j--)
                   calculate();
                   ss.fu[j]=c;
            j++;
            }
            else if(c=='('){
            	 ss.fu[j]=c;
            j++;
			}
       
        }
        else if(c==')')
            {
                for(j;ss.fu[j-1]!='(';j--)
                    calculate();
                ss.fu[j-1]='\0';
                j--;
            }
        else if(c=='=')
            break;
    }
    for(j;j>0;j--)
      calculate();

    printf("%d",s.shu[0]);
}


