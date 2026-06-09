#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char s[120] = {};
    char t[120] = {};
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers.]
    int i,sum;
    sum=0;
    int l=strlen(s);
    if(s[0]=='0')
    {
        sum+=1;
        i=2;
        while(s[i]=='0')
        {
            i++;
            sum++;
        }
        if(sum<l-2)
        {
            printf("%1c.",s[i]);
            int j;
            j=i+1;
            while(j<=l) // @@ [Loop condition should be 'j < l' instead of 'j <= l'; accessing s[l] reads past the end of the string (null terminator), which may print garbage or cause undefined behavior.]
            {
                printf("%1c",s[j]);
                j++;
            }
        }
        else
        {
            printf("%1c",s[i]);
        }
        printf("e-%d",sum);
    }
    else
    {
        while(s[sum]!='.'&&sum<l)
        {
            sum++;
        }
        sum--; // @@ [If the input has no decimal point (though problem says it does), this could lead to negative exponent; but more critically, if '.' is at index 0, sum becomes -1, which is invalid. However, per problem description, there are digits before '.', so this may not trigger. Still, logic assumes '.' exists.]
        int j=0;
        i=0;
        while(i<l)
        {
            if(s[i]!='.')
            {
                t[j]=s[i];
                j++;
            }
            i++;
        }
        int le=strlen(t);
        int len=0;
        i=l-1; // @@ [Should be 'i = le - 1' because 't' has length 'le', but 'l' is length of original string including '.', so 'l-1' may exceed 't' bounds if '.' was present. This leads to reading uninitialized memory in 't'.]
        while(t[i]=='0')
        {
            len++;
            i--;
        }
        if((le-len)==1)
        {
            printf("%1c",t[0]);
        }
        else
        {
            printf("%1c.",t[0]);
            i=1;
            while(i<le-len)
            {
                printf("%1c",t[i]);
                i++;
            }
        }
        printf("e%d",sum);
    } 
    return 0;
}