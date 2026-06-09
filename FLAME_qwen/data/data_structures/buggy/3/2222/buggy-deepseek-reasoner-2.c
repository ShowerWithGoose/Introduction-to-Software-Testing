#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char s[120] = {};
    char t[120] = {};
    gets(s);
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
            while(j<=l) // @@ Error: should be j<l to avoid printing the null terminator at s[l]
            {
                printf("%1c",s[j]);
                j++;
            }
        }
        else
        {
            printf("%1c",s[i]); // @@ Error: for input "0" (length 1), i=2 is out of bounds; also misses the case l==1
        }
        printf("e-%d",sum);
    }
    else
    {
        while(s[sum]!='.'&&sum<l)
        {
            sum++;
        }
        sum--;
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
        i=l-1; // @@ Error: should be i=le-1; l is length of original string, not number of digits in t
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