// 1.两个栈  数字栈  符号栈
//2. 数字栈入栈数字   符号栈顶元素更高，弹出，弹出两个数字
// 3.符号栈不为空的话，弹出所有计算
// 返回数字栈中的元素

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


bool isNumber(char ch)
{
    return ch >= '0' && ch <= '9';
}


bool islow(char tmp, char ch)
{
    return (tmp == '+' || tmp == '-') && (ch == '*' || ch == '/');
}


int Compute(int num1, int num2, char ch)
{
    switch(ch)
    {
        case '+':
        return num2 + num1;
        case '-':
        return num2 - num1;
        case '*':
        return num2 * num1;
        case '/':
        return num2 / num1;
    }
}


int main()
{
    char s[500] = {0};
    gets(s);

    int stk1[500] = {0};
    char stk2[500] = {0};

    int top1 = 0;
    int top2 = 0;

    for(int i = 0; s[i] != '='; i++)
    {
    char ch = s[i];
    
    if(i == 0 && ch == '-')
    {
        stk1[top1++] = atoi(&s[i]);
        
        i++;
        while((isNumber(s[i])))
        {
            i++;
        }
        i--;
        continue;
    }    

    if(isNumber(ch))
    {
        stk1[top1++] = atoi(&s[i]); 

        while((isNumber(s[i])))
        {
            i++;
        }
        i--;
    }

    else if(ch == ' ')
    {
        continue;
    }

    else 
    {
        if(top2 > 0)
        {
        char tmp = stk2[top2 - 1];

        while(!islow(tmp, ch))
        {
        int num1 = stk1[--top1];
        int num2 = stk1[--top1];

        stk1[top1++] = Compute(num1, num2, tmp);
        
        top2--;

        if(top2 == 0)
        {
            break;
        }

        tmp = stk2[top2 - 1];
        }
        }

        stk2[top2++] = ch;
    }
    }

    while(top2 > 0)
    {
    char tmp = stk2[--top2];

    int num1 = stk1[--top1];
    int num2 = stk1[--top1];
    stk1[top1++] = Compute(num1, num2, tmp);

    }

    printf("%d", stk1[0]);
    return 0;
}
