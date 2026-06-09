#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
// stack
typedef char * string;
typedef string ElementType;
typedef ElementType * Stack;

Stack Push(Stack s, ElementType t);
ElementType Check(Stack s);
Stack Pop(Stack s);
int cnt = 0;
int isEmpty()
{
    if (cnt == 0)
    {
        return 1;
    }
    return 0;
    
}

Stack Push(Stack s, ElementType t)
{
    *(s+1) = t;
    cnt++;
    return s+1;
}

ElementType Check(Stack s)
{
    return *s;
}

Stack Pop(Stack s)
{
    cnt--;
    return s-1;
}

int operation(char op, int num1, int num2)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    }
}

int getLevel(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void cleanBlank(char str[])
{
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main()
{
    string save[500];
    int i_save = 0;
    char getStr[100];
    gets(getStr);
    cleanBlank(getStr);
    // puts(getStr);
    for (int i = 0; getStr[i] != '\0'; )
    {
        if (isdigit(getStr[i]))
        {
            int start = i;
            while (isdigit(getStr[++i]));
            // printf("start: %d, end: %d\n", start, i);
            save[i_save] = malloc(sizeof(char)*(i-start+1));
            memcpy(save[i_save], getStr+start, i-start);
            save[i_save][i-start] = '\0';
            i_save++;
        }
        else if (getStr[i] != '=')
        {
            save[i_save] = malloc(sizeof(char)*2);
            sprintf(save[i_save], "%c", getStr[i]);
            // printf("%c\n", getStr[i]);
            i_save++;
            i++;
        }
        else
        {
            break;
        }
        
    }

    // test
    // for (int i = 0; i < i_save; i++)
    // {
    //     puts(save[i]);
    // }
    // test
    
    ElementType s[500];
    Stack stack = s;
    string newSave[500];
    int i_new = 0;
    for (int i = 0; i < i_save; i++)
    {
        if (isdigit(*save[i]))
        {
            newSave[i_new++] = save[i];
        }
        else
        {
            while (!isEmpty() && getLevel(*save[i]) <= getLevel(*Check(stack)))
            {
                newSave[i_new++] = Check(stack);
                stack = Pop(stack);
            }
            stack = Push(stack, save[i]);
        } 
    }
    while (!isEmpty())
    {
        newSave[i_new++] = Check(stack);
        stack = Pop(stack);
    }
    // string newStr = malloc(sizeof(char)*50);
    for (int i = 0; i < i_new; i++)
    {
       if (isdigit(*newSave[i]))
       {
            stack = Push(stack, newSave[i]);
       }
       else
       {
            string sright = Check(stack);
            stack = Pop(stack);
            string sleft = Check(stack);
            stack = Pop(stack);
            int ans = operation(*newSave[i], atoi(sleft), atoi(sright));
            // printf("do: %d %c %d = %d\n", atoi(sleft), *newSave[i], atoi(sright), ans);
            sprintf(sleft, "%d", ans);
            stack = Push(stack, sleft);
       }
    }
    printf("%s", Check(stack));

    // system("pause");
    return 0;
}

