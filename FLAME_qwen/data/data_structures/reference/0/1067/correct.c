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
    char *p = str;
    int dist = 0;
    p = strchr(p, '-');
    while(p != NULL)
    {
        if(p != str && Judge(*(p - 1), *(p + 1)))
        {
            char a = *(p + 1), b = *(p - 1);
            dist = (a - b - 2);
            for(int i = len - 1; i >= p - str + 1; i --)
            {
                str[i + dist] = str[i];
            }//pointer method?
            len += dist; 
            for(int j = 0; j < a - b - 1; j ++)
            {
                *(p + j) = b + j + 1;
            }
        }
        p = strchr(p + 1, '-');
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


