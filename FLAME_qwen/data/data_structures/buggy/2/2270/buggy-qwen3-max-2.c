#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char nub[10001];
char s[10001];
long long int a[10001];

int main()
{
    gets(s); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
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
    a[p] *= z;
    for(int i=0;a[i]!='\0';i++) // @@ [Incorrect loop termination: `a[i]` is a `long long int`, not a char; comparing against `'\0'` is invalid and leads to undefined behavior. Should iterate up to `p+1` instead.]
    {
        sum += a[i];
    }
    
    printf("%lld",sum);
    
    return 0;
}