#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define MAXN 100000 
char memo[MAXN];
int GetNextNum(char memo[], int i)
{
    int ret = 0;
    for(int j = i + 1; isdigit(memo[j]) || memo[j] == ' '; j ++)
        if(isdigit(memo[j]))
            ret = ret * 10 + memo[j] - '0';
    return ret;
}
int calc(char memo[], int len)
{
    int tmp = GetNextNum(memo, -1), ans = 0;//space?
    for(int i = 0; i <= len - 2; i ++)
    {
        if(memo[i] != ' ' && !isdigit(memo[i]))
        {
            switch(memo[i])
            {
                case '+' :
                    ans += tmp;
                    tmp = GetNextNum(memo, i);
                    break;
                case '-' :
                    ans += tmp;
                    tmp = -GetNextNum(memo, i);
                    break;
                case '*' :
                    tmp *= GetNextNum(memo, i);
                    break;
                case '/' :
                    tmp /= GetNextNum(memo, i);
                    break;
            }
        }
    }
    ans += tmp;
    return ans;
}
int main()
{
    gets(memo);
    int len = strlen(memo);
    printf("%d", calc(memo, len));
}


