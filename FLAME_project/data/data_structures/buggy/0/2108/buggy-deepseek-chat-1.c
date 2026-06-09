#include <stdio.h>
#include <string.h>
int ifproper(char c1,char c2)
{
    if(48<=c1&&c1<=57&&48<=c2&&c2<=57)
    {
        return 1;
    }
    else if(97<=c1&&c1<=122&&97<=c2&&c2<=122)
    {
        return 1;
    }
    else if(65<=c1&&c1<=90&&65<=c2&&c2<=90)
    {
        return 1;
    }
    else return 0;
}
int main()
{
    char str[100],s;
    int i=0,j;
    gets(str);
    while(str[i]!=0)
    {
        if(str[i]!=45) 
        {
            s=str[i];
            printf("%c",s);
            i++;
        }
        else if(i>0)
        {
            if(ifproper(str[i-1],str[i+1]))
            {
                for(s=str[i-1]+1;s<=str[i+1]-1;s++)
                {
                    printf("%c",s);
                }
            }
            i++; // @@ [Error: When the condition `ifproper` is false (e.g., 'B' and 'e' are different types), the code does not output the '-' character. It should output '-' before incrementing i, but it only increments i, skipping the dash entirely. The correct behavior is to output '-' and then the next character, but here the dash is lost.]
        }
    }
    return 0;
}