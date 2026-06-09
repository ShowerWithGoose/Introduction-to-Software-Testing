#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define MAXN 100000 
bool Judge(char a, char b)
{
    if(a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && b > a) return 1;
    if(a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z' && b > a) return 1;
    if(a >= '0' && a <= '9' && b >= '0' && b <= '9' && b > a) return 1;
    return 0;
}
void Expand(char* str, int len)
{
    char *i = str;
    int dist = 0;
    i = strchr(i, '-');
    while(i != NULL)
    {
        if(i != str && Judge(*(i - 1), *(i + 1)))
        {
            char a = *(i + 1), b = *(i - 1);
            dist = (a - b - 2);
            for(int p = len - 1; p >= i - str + 1; p --)
            {
                str[p + dist] = str[p];
            }//pointer method?
            len += dist; 
            for(int j = 0; j < a - b - 1; j ++)
            {
                *(i + j) = b + j + 1;
            }
        }
        i = strchr(i + 1, '-');
    }
    
}
//should divide
//head - may overflow
int main()
{
    char str[MAXN];
    gets(str);
    int len = strlen(str);
    Expand(str, len);
    puts(str);
    return 0;
}


