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
    
    gets(str); // @@ [Using `gets` is unsafe and may cause buffer overflow; more critically, it doesn't handle the newline properly which can interfere with parsing. Also, the input ends with '=', but the parsing logic assumes operators between numbers without accounting for the final '=' correctly in all cases.]
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
        }else if(isdigit(str[i]) && !(isdigit(str[i-1])) && i != 0) // @@ [This condition fails when a number starts at index 0 and is followed by another number later; also, when i=0, str[i-1] is str[-1] which is undefined behavior. However, the next `else if(i == 0)` handles i=0, so this line may skip valid digits after an operator if the previous char is non-digit but current is digit — but logic is fragile.]
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
        
        
        for(i = 0; i < n; i++) // @@ [Loop runs `i` from 0 to n-1, but accesses `a[i+1]` which goes out of bounds when i = n-1. This causes undefined behavior (reading garbage values), leading to wrong results like -1204215707.]
        {
            if(h[i] == 3 || h[i] == 4)
            {
                num[j] = func(num[j], a[i+1], h[i]);
                
                
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
                num[j] = a[i+1]; // @@ [Same out-of-bounds access: when i = n-1, a[i+1] is invalid. The number of operators `h` should be one less than number of operands `a`, but the code assumes h has same length as a, which is incorrect.]
                
            }
        }
    
        for(i = 0; i < k; i++)
        {
            num[0] = func(num[0], num[i+1], h1[i]); // @@ [If k >= 1, then num[i+1] when i = k-1 accesses num[k], but only num[0..j] were set (j <= k). This may read uninitialized or garbage values, contributing to wrong output.]
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
        ans = a / num;
    }
    return ans;
}