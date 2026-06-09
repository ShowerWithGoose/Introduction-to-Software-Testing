#include<stdio.h>
#include<string.h>
int main ()
{
    int i= 0, k = 0, flag = 0, num = 0;
    char a[105];
    char b[105];
    gets(a); // @@ [Use of unsafe function 'gets' which has been removed from C standard; causes compilation error in modern compilers]
    int len = strlen(a);
    if(a[0] == '0')
    {
        for(i = 1; i < len ; i++)
        {
            if(a[i] == '0' && a[i+1] != '0')
            {
                flag = i + 1;
                break;
            }
        }
        if(a[flag + 1] == '\0') // @@ [Potential out-of-bounds access: if 'flag' is not set (e.g., all zeros after decimal), 'flag' remains 0, leading to accessing a[1], but more critically, if input is "0.0", loop doesn't set 'flag', so 'flag' is 0, then a[1] is '.', and a[2] may be '\0', but logic is flawed]
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
       while(a[i] != '.') // @@ [If input has no decimal point (violates problem assumption but still), this loops beyond string end causing undefined behavior; also, 'num' counts digits before '.', but loop increments 'i' and 'num' together incorrectly: 'num' starts at 0, and for "123.45", it becomes 3, which is correct, but logic relies on '.' being present]
       {
           i++;
           num++;
       }
       b[0] = a[0];
       b[1] = '.';
       for(i = 0 ; i < len ; i++) // @@ [Loop uses 'i' from 0 again, but condition checks a[i+1]; when i = len-1, accesses a[len] which is '\0', but also copies non-'.' characters including those before decimal again; e.g., for "12.34", it will copy '2','.','3','4' incorrectly because it doesn't skip the decimal properly]
       {
           if(a[i+1] != '.') // @@ [Accesses a[i+1] when i can be len-1 → reads past end of string (a[len] is '\0', so not '.' usually, but still undefined if len is max); also logic fails to exclude the decimal point correctly]
           {
               b[2 + k] = a[i + 1];
               k++;
           }
       }
       printf("%s",b);
       printf("e%d",num - 1);
       return 0;
    }

    return 0;
}