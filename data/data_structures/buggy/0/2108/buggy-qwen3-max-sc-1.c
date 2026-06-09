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
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
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
            i++; 
        }
    }
    return 0;
}