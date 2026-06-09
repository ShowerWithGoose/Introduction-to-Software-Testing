#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<memory.h>
#define MAXN 1000

void squeez(char s0[],char c)//把s中的c去除
{
	int i,j;
	for(i=j=0;s0[i]!='\0';i++)
	{
		if(s0[i]!=c)
		s0[j++]=s0[i];
	}
	s0[j]='\0';
 }

char s[MAXN];
int main() 
{ 
	
	gets(s);
	squeez(s,' ');
	int Len=strlen(s);
	s[Len-1]='\0';
	printf("%d\n",cal(s)); 
	return 0; 
} 

int cal(char* s) {
    int i;
	int len = strlen(s);
    int stack[len], top = 0;
    char op = '+';
    int num = 0;
    for ( i = 0; i < len; i++) {
        if (s[i]>='0'&&s[i]<='9') {
            num = num * 10 + s[i] - '0';
        }
        if ((s[i]>'9'||s[i]<'0')|| i == len - 1) {
            switch (op) {
                case '+':
                    stack[top++] = num;
                    break;
                case '-':
                    stack[top++] = -num;
                    break;
                case '*':
                    stack[top - 1] *= num;
                    break;
                case '/':
                    stack[top - 1] /= num;
                    break;
                    
                default:
                    break;
            }
            op = s[i];
            num = 0;
        }
    }
    int res = 0;
    for (i = 0; i < top; i++) {
        res += stack[i];
    }
    return res;
}

