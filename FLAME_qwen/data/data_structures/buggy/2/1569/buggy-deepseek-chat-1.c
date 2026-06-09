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
            strcpy(str+i, str+i+1); // @@ [Error: strcpy with overlapping memory regions leads to undefined behavior; should use memmove or a different approach to remove spaces]
        }
    }
}

int atoi(char s[]);
int func(int a, int num, int h);
int main()
{
    
    gets(str); // @@ [Error: gets() is unsafe and deprecated; it can cause buffer overflow. Should use fgets() instead]
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
        }else if(isdigit(str[i]) && !(isdigit(str[i-1])) && i != 0) // @@ [Error: When i=0, str[i-1] accesses out-of-bounds memory, causing undefined behavior]
        {
            for(k = i; isdigit(str[k]); k++){
            };
            strncpy(str1, str+i, k-i);
            str1[strlen(str1)] = '\0'; // @@ [Error: str1 is not null-terminated before strlen; strncpy does not add null if source is shorter than limit, and here the length is exactly k-i, so no null is appended]
            a[n] = atoi(str1);
            n++;
            memset(str1,'\0',sizeof(str1));
        }else if(i == 0)
        {
            for(k = i; isdigit(str[k]); k++){
            };
            strncpy(str1, str+i, k-i);
            str1[strlen(str1)] = '\0'; // @@ [Error: Same issue as above - str1 not null-terminated before strlen]
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
        
        
        for(i = 0; i < n; i++) // @@ [Error: Loop condition i < n is incorrect; should iterate based on the number of operators (j from earlier), not the number of operands (n), leading to out-of-bounds access]
        {
            if(h[i] == 3 || h[i] == 4)
            {
                num[j] = func(num[j], a[i+1], h[i]); // @@ [Error: When i reaches n-1, a[i+1] accesses out-of-bounds memory]
                
                
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
                num[j] = a[i+1]; // @@ [Error: When i reaches n-1, a[i+1] accesses out-of-bounds memory]
                
            }
        }
    
        for(i = 0; i < k; i++)
        {
            num[0] = func(num[0], num[i+1], h1[i]);
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