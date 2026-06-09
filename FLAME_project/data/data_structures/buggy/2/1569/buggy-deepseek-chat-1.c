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
            strcpy(str+i, str+i+1); // @@ This line is incorrect because strcpy with overlapping memory regions leads to undefined behavior; also, after shifting, the loop index i should not increment to avoid skipping characters.
        }
    }
}

int atoi(char s[]);
int func(int a, int num, int h);
int main()
{
    
    gets(str); // @@ This line is unsafe and deprecated; it can cause buffer overflow, but for this assignment it may be acceptable.
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
            str1[strlen(str1)] = '\0'; // @@ This line is incorrect because str1 may not be null-terminated properly; strlen(str1) after strncpy may read uninitialized memory.
            a[n] = atoi(str1);
            n++;
            memset(str1,'\0',sizeof(str1));
        }else if(i == 0)
        {
            for(k = i; isdigit(str[k]); k++){
            };
            strncpy(str1, str+i, k-i);
            str1[strlen(str1)] = '\0'; // @@ Same issue as above: using strlen on potentially uninitialized str1.
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
        
        
        for(i = 0; i < n; i++)
        {
            if(h[i] == 3 || h[i] == 4)
            {
                num[j] = func(num[j], a[i+1], h[i]); // @@ This line is incorrect because it modifies num[j] in place without considering operator precedence correctly; it should compute the result and store it back, but the loop logic is flawed.
                
                
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
                num[j] = a[i+1];
                
            }
        }
    
        for(i = 0; i < k; i++)
        {
            num[0] = func(num[0], num[i+1], h1[i]); // @@ This line is incorrect because it assumes left-to-right evaluation for + and - without considering that multiplication/division were already processed, but the indexing of num and h1 may be misaligned.
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