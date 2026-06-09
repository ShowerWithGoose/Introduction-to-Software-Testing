#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100000], str1[100000];
int a[100000] = {0};
int h[100000] = {0};
int num[100000] = {0};
int h1[100000] = {0};
void blank(char *str)
{
    int w = strlen(str);
    int i;
    for(i = 0; i < w; i++)
    {
        if(str[i] == ' ')
        {
            strcpy(str+i, str+i+1);
        }
    }
}

int atoi(char s[]);
int func(int a, int num, int h);
int main()
{
    
    gets(str); // @@ [Using `gets()` is unsafe and may cause buffer overflow; more critically, it does not handle the trailing newline correctly which affects parsing. Also, the input includes '=' at the end, but the parsing logic assumes operators between numbers without accounting for the final '=' properly in all cases.]
    blank(str);
    
    int i = 0, j = 0, k = 0, n = 0;
    int w = strlen(str);
    for(i = 0; i < w; i++)
    {
        if(!(isdigit(str[i])))
        {
            if(str[i] == '+') h[j] = 1;
            if(str[i] == '-') h[j] = 2;
            if(str[i] == '*') h[j] = 3;
            if(str[i] == '/') h[j] = 4;
            if(str[i] == '=') h[j] = 0;
            
            j++;
        }else if(isdigit(str[i]) && !(isdigit(str[i-1])) && i != 0)
        {
            for(k = i; isdigit(str[k]); k++){
            };
            strncpy(str1, str+i, k-i);
            str1[strlen(str1)] = '\0';
            a[n] = atoi(str1);
            n++;
            memset(str1,'\0',sizeof(str1));
        }else if(i == 0)
        {
            for(k = i; isdigit(str[k]); k++){
            };
            strncpy(str1, str+i, k-i);
            str1[strlen(str1)] = '\0';
            a[n] = atoi(str1);
            n++;
            memset(str1,'\0',sizeof(str1));
        }
    }
    //for(i = 0; i < n; i++)
    //printf("%d ", a[i]);
    //puts(str);
    //printf("%d", n);
    

    if(h[0] != 0)
    {
        j = 0;
        k = 0;
        
        num[j] = a[0];
        
        
        for(i = 0; i < n; i++) // @@ [Loop condition should be `i < n - 1` because `h[i]` corresponds to operator after `a[i]`, and `a[i+1]` is accessed. When `i == n-1`, `a[i+1]` is out of bounds. This causes undefined behavior and wrong results.]
        {
            if(h[i] == 3 || h[i] == 4)
            {
                num[j] = func(num[j], a[i+1], h[i]); // @@ [When processing multiplication/division, the code uses `num[j]` (which may already be a result of prior operations) and `a[i+1]`, but fails to skip the next number in the `a[]` array properly. This leads to reusing numbers or skipping them incorrectly in subsequent steps.]
                
                
            }else
            {
                if(h[i] == 0) 
                {
                    h1[k] = 0;
                    
                    break;
                }
                h1[k] = h[i];
                k++;
                j++;
                num[j] = a[i+1]; // @@ [Same issue: `a[i+1]` may be out of bounds when `i == n-1`. Also, after processing * or /, the next number should not be added again as a separate operand. The algorithm doesn't collapse the `a[]` array after combining terms, leading to misalignment between operators and operands.]
                
            }
        }
    
        for(i = 0; i < k; i++)
        {
            num[0] = func(num[0], num[i+1], h1[i]); // @@ [This assumes that after processing * and /, the remaining `num[]` array holds only the terms for + and -, but due to incorrect handling in the previous loop, `num[]` may contain garbage or unprocessed values, and `k` may not reflect the correct number of remaining operators.]
        }
        
        printf("%d", num[0]);
    }else if(h[0] == 0)
    {
        printf("%d", a[0]);
    }
    
    
    
    return 0;
}

void reverse(char s[])
{
    int c, i, j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


int atoi(char s[])
{
    int i, n;
    for(n = 0, i = 0; s[i] >= '0' && s[i] <= '9'; i++)
    {
        n = n * 10 + s[i] - '0';
    }
    return n;
}

int func(int a, int num, int h)
{
    int ans;
    if(h == 1)
    {
        ans = a + num;
    }else if(h == 2)
    {
        ans = a - num;
    }else if(h == 3)
    {
        ans = a * num;
    }else if(h == 4)
    {
        ans = a / num; // @@ [Integer division is required and this is correct, but if `num` is zero, it would crash. However, problem states expression is valid, so this may not be the direct cause. The real issue is operand/operator misalignment.]
    }
    return ans;
}