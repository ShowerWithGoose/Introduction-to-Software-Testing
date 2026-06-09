#include<stdio.h>
#include<string.h>
#include<ctype.h>
void movespace(char *c)
{
    int i , j;
    int len = strlen(c);
    for(i = 0 ; i < len ; i++)
        {
            if(*(c + i) != ' ')
                c[j++] = c[i];
        }
    c[j] = '\0';
    return;
}

void devide(char *c , int * num , char * op)
{
    int i , len = strlen(c);
    int n = 0 , o = 0;
    for(i = 0 ; i < len ; i++)
    {
        if(isdigit(c[i]))
        {
            int ans = 0;
            do
            {
                ans = ans * 10 + c[i] - '0';
                i++;
            }
            while(isdigit(c[i]));
            num[n++] = ans;
            i--;
        }
        else
        {
            op[o++] = c[i];
        }
    }
    op[o] = '\0';
    return ;
}

int calculate(int a , char c , int b)
{
    switch(c)
    {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
}
int analysis(char p1 ,char p2)
{
    if(p1 == '*' || p1 == "/") // @@ [Error: comparing char to string literal; should be p1 == '/'. This causes incorrect precedence handling, eventually leading to division by zero in output function.]
        return 1;
    else
    {
        if(p2 == '+' || p2 == '-')
            return 1;
        else
            return 0;
    }
}
int output(int *num , char *op)
{
    if(op[0] == '=')
        return num[0];
    else if(op[1] == '=')
        return calculate(num[0] , op[0] , num [1]);
    else
        {
            int i = 0, j = 0 , curn = 2 , curo = 2;
            int x = num[0], y = num[1] , z;
            char o1 = op[0] , o2=op[1];
            while(o2 != '=')
            {

                z = num[curn++];
                int prio = analysis(o1 , o2);
                    if(prio)
                    {
                        x = calculate(x , o1 , y);
                        y = z;
                        o1 = o2;
                    }
                    else
                    {
                        y = calculate(y , o2 , z);
                    }
                o2 = op[curo++];
            }
            return calculate(x , o1 , y);
        }
}

int main()
{
    char c[10004];
    int num[10003];
    char op[10002];
    // gets(c);
    // movespace(c);
    // devide(c , num , op);
    // freopen("in.txt","rb",stdin);
    int cnt = 0;
    while(scanf("%d %c",&num[cnt], &op[cnt]) != EOF) 
        cnt++;
    printf("%d" ,output(num , op));
    return 0;
}