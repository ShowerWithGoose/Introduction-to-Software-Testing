#include<stdio.h>     // line 1
#include<string.h>    // line 2
int main()           // line 3
{                    // line 4
    int i=0,j=0,k=0,l; // line 5
    char s[100],s1[200]; // line 6
    scanf("%s",s);    // line 7
    int len = strlen(s); // line 8
    for(i=0;i<len;i++) // line 9
    {                // line 10
        if(s[i]!='-') s1[j++] = s[i]; // line 11
        else          // line 12
        {            // line 13
            if((isupper(s[i-1])&&isupper(s[i+1])&&(s[i-1]<s[i+1]))||(islower(s[i-1])&&islower(s[i+1])&&(s[i-1]<s[i+1]))||isdigit(s[i-1])&& isdigit(s[i+1])&&(s[i-1]<s[i+1])) // line 14
            {        // line 15
                k = s[i+1] - s[i-1]; // line 16
                for(l=1;l<k;l++) // line 17
                {    // line 18
                    s1[j++]=s[i-1]+l; // line 19
                }    // line 20
            }        // line 21
            else s[j++]= s[i]; // @@ [ERROR: Should be s1[j++] = s[i]; otherwise the '-' is not stored in the output array, causing missing characters when expansion condition fails.] // line 22
        }            // line 23
    }                // line 24
    s1[j]='\0';      // line 25
    printf("%s",s1); // line 26
    return 0;        // line 27
}                    // line 28