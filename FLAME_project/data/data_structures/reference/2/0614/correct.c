#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 1005
char arr[MAXSIZE];
int num[MAXSIZE];
char op[MAXSIZE];
int top_num = -1, top_op = -1;
int exchange();
int calculate(int,char,int);
int main()
{
	gets(arr);
	int ans = 0;
    ans = exchange();
	printf("%d",ans);
	return 0;
} 
int exchange(){
    int i = 0;
    while(arr[i] != '=')
    {
        if(arr[i] <= '9' && arr[i] >= '0')
        {
            int tmp = 0;
            for(int j = i; arr[j] <= '9' && arr[j] >= '0'; j++)
            {
                tmp = tmp*10 + arr[j] - '0';
                i++;
            }
            num[++top_num] = tmp;
            if(arr[i] == '=')
            {
                while(top_op != -1)
                {
                    num[top_num-1] = calculate(num[top_num-1],op[top_op],num[top_num]);
                    top_num--;
                    top_op--;
                }
            }
            continue;
        }
        else if(arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')
        {
            if(top_op == -1)
            {
                op[++top_op] = arr[i];
            }
            else if(top_op == top_num - 1)//此时开始判断是否计算
            {
                if((op[top_op] == '+' || op[top_op] == '-')&&(arr[i] == '*' || arr[i] == '/'))
                {
                    op[++top_op] = arr[i];
                }
                else if((op[top_op] == '*' || op[top_op] == '/')&& (arr[i] == '*' || arr[i] == '/'))
                {
                    num[top_num-1] = calculate(num[top_num-1],op[top_op],num[top_num]);
                    top_num--;
                    top_op--;
                    op[++top_op] = arr[i];
                }
                else if((op[top_op] == '+' || op[top_op] == '-') && (arr[i] == '+' || arr[i] == '-'))
                {
                    num[top_num-1] = calculate(num[top_num-1],op[top_op],num[top_num]);
                    top_num--;
                    top_op--;
                    op[++top_op] = arr[i];
                }else if((op[top_op] == '*' || op[top_op] == '/') && (arr[i] == '+' || arr[i] == '-'))
                {
                    while(top_op != -1)
                    {
                        num[top_num-1] = calculate(num[top_num-1],op[top_op],num[top_num]);
                        top_num--;
                        top_op--;
                    }
                    op[++top_op] = arr[i];
                }
            }   
        }
        else if(arr[i+1] == '=' && top_op != -1)
            {
                while(top_op != -1)
                {
                    num[top_num-1] = calculate(num[top_num-1],op[top_op],num[top_num]);
                    top_num--;
                    top_op--;
                }
            }
        i++;
    }
    return num[0];
}
int calculate(int a, char op ,int b)
{
    switch (op)
    {
        case '+': return a + b; 
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default:
        printf("ERROR");
        return -1;
    }
}
