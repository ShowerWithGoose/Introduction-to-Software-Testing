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
            if(ifproper(str[i-1],str[i+1])) // @@ [Condition should also check that str[i+1] > str[i-1] (character after '-' is greater than before); additionally, when expansion is not performed (either types differ or c2 <= c1), the '-' itself must be printed. Currently there is no else branch for that.]
            {
                for(s=str[i-1]+1;s<=str[i+1]-1;s++) // @@ [Loop upper bound should be s<=str[i+1] (including the last character), not str[i+1]-1.]
                {
                    printf("%c",s);
                }
            }
            i++; 
        }
    }
    return 0;
}