#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str);
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if (str[i]!='-')
            putchar(str[i]);        
        else
        {
            if (str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1]) // @@ The condition checks if the previous character is lowercase and the next is within 'z', but it fails to verify that the next character is also lowercase (>= 'a'). More importantly, for input "B-e", this condition is false because 'B' is not >= 'a'. However, the subsequent conditions are also flawed. The main issue is that if none of the expansion conditions are met, the '-' character itself is not printed. The code only prints characters when str[i] != '-', or prints expanded content inside the if blocks. If the expansion conditions fail, the '-' is skipped entirely.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) // @@ Similar to above, if this condition fails, nothing is printed for the '-'. Also, it doesn't check if str[i+1] >= '0'.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) // @@ Similar to above, if this condition fails, nothing is printed for the '-'. Also, it doesn't check if str[i+1] >= 'A'. For "B-e", 'e' is not <= 'Z', so this is false. Since all three ifs are false, the '-' is not output.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            } 
        }

    }
    return 0;
}