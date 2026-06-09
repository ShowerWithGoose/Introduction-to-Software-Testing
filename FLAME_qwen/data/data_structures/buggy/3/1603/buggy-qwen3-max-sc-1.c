#include<stdio.h>
#include<string.h>
int main ()
{
    int i= 0, k = 0, flag = 0, num = 0;
    char a[105];
    char b[105];
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings.]
    int len = strlen(a);
    if(a[0] == '0')
    {
        for(i = 1; i < len ; i++)
        {
            if(a[i] == '0' && a[i+1] != '0') // @@ [This condition fails to handle cases where the first non-zero digit appears immediately after the decimal point (e.g., "0.1"), because it only triggers when a zero is followed by a non-zero. Also, accessing a[i+1] when i == len-1 leads to out-of-bounds read.]
            {
                flag = i + 1;
                break;
            }
        }
        if(a[flag + 1] == '\0') // @@ [If 'flag' was never set (e.g., input like "0.0" which shouldn't occur per problem but still), this accesses invalid memory. Also, if the loop didn't find any non-zero digit, 'flag' remains 0, leading to incorrect access at a[1].]
        {
            printf("%ce-%d",a[flag],flag - 1);
            return 0;
        }
        else
        {
            b[0] = a[flag];
            b[1] = '.';
            for(k = 0 ;  k < len - flag - 1 ; k++)
            {
                b[k+2] = a[flag + k + 1];
            }
            printf("%s",b);
            printf("e-%d",flag - 1);
            return 0;
        }


    }
    else
    {
       while(a[i] != '.') // @@ [If the input has no decimal point (which shouldn't happen per problem statement, but code doesn't validate), this loop runs past the string end, causing undefined behavior.]
       {
           i++;
           num++;
       }
       b[0] = a[0];
       b[1] = '.';
       for(i = 0 ; i < len ; i++) // @@ [Loop uses 'i' starting from 0 again, but also uses 'i+1' inside, so when i == len-1, a[i+1] is out of bounds. Additionally, logic incorrectly copies characters including the decimal point or skips needed digits.]
       {
           if(a[i+1] != '.') // @@ [Same out-of-bounds access when i == len-1. Also, this condition doesn't properly skip the decimal point; it just avoids copying '.' but messes up indexing.]
           {
               b[2 + k] = a[i + 1];
               k++;
           }
       }
       printf("%s",b); // @@ [The array 'b' is not null-terminated, so printf("%s", b) results in undefined behavior.]
       printf("e%d",num - 1);
       return 0;
    }

    return 0;
}