#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char nub[10001];
char s[10001];
long long int a[10001];

int main()
{
    gets(s);
    long long int sum = 0;
    int j = 0;
    
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            nub[j++] = s[i];
        }
    }
    
    int len = strlen(nub);
    int p = 0,z = 1;
    
    for(int i=0;i<len;i++)
    {
        if(nub[i]=='+')
        {
            a[p] *= z;
            p++;
            z = 1;
        }
        else if(nub[i]=='-')
        {
            a[p] *= z;
            p++;
            z = -1;
        }
        else if(nub[i]=='*')
        {
            i++;
            long long int sumz = 0;
            while(nub[i]!='+'&&nub[i]!='-'&&nub[i]!='*'&&nub[i]!='/'&&nub[i]!='=')
            {
                sumz = sumz*10 + nub[i] - '0';
                i++;
            }
            a[p] *= sumz;
            i--;
            sumz = 0;
        }
        else if(nub[i]=='/')
        {
            
            i++;
            long long int sumz = 0;
            while(nub[i]!='+'&&nub[i]!='-'&&nub[i]!='*'&&nub[i]!='/'&&nub[i]!='=')
            {
                sumz = sumz*10 + nub[i] - '0';
                i++;
            }
            a[p] /= sumz;
            i--;
            sumz = 0;
        }
        else if(nub[i]!='=')
        {
            a[p] = 10*a[p] + nub[i] - '0';
        }
        else
        {
            break;
        }
    }
    a[p] *= z; // @@ [This line applies the sign `z` only to the last term, but terms processed by * or / already had their signs applied incorrectly earlier. The logic of handling signs and multiplicative operations is flawed because `z` is only applied when encountering '+' or '-', but multiplicative terms are stored in `a[p]` without considering the current sign context.]
    for(int i=0;a[i]!='\0';i++) // @@ [The array `a` is not null-terminated, so this loop may read uninitialized memory beyond the actual number of terms, leading to undefined behavior or wrong results. The loop should run only up to `p+1` terms instead of checking for '\0'.]
    {
        sum += a[i];
    }
    
    printf("%lld",sum);
    
    return 0;
}