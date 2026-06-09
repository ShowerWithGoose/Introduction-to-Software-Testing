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
        else if(i>0) // @@ If the input string starts with '-', i is 0, causing an infinite loop since i is never incremented. Also fails to print '-' when expansion conditions are not met.
        {
            if(ifproper(str[i-1],str[i+1])) // @@ Missing check for str[i-1] < str[i+1] as required by the problem. Also lacks an else clause to print '-' when expansion conditions are not satisfied, causing '-' to be omitted from the output.
            {
                for(s=str[i-1]+1;s<=str[i+1]-1;s++)
                {
                    printf("%c",s);
                }
            }
            i++; // @@ Incrementing i here without printing '-' when conditions fail leads to missing '-' in the output. The logic should print '-' in an else block before incrementing.
        }
    }
    return 0;
}