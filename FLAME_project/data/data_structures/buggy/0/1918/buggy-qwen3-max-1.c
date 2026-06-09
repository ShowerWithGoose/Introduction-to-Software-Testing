#include<stdio.h>
#include<string.h>
char ch[1000];
int main()
{
    scanf("%s",ch);
    int len=strlen(ch),i=0,lon,j=0;
    for(;i<len;i++)
    {
        if(ch[i]=='-')
        {
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')) // @@ [The condition is incorrect: it checks only lower bound for the first char and upper bound for the second char without ensuring both belong to the same category. For example, 'B' >= 'A' is true and 'e' <= 'Z' is false, but due to flawed logic, it may incorrectly pass in mixed cases. Also missing validation that both chars are of the same type and that ch[i-1] < ch[i+1].]
            {
                lon=ch[i+1]-ch[i-1];
                for(j=0;j<lon-1;j++)
                {
                    printf("%c",j+ch[i-1]+1);
                }
            }
            else printf("%c",ch[i]); // @@ [Missing else clause to print '-' when expansion conditions are not met. In current code, if the condition fails, nothing is printed for '-', causing omission of '-' in output like "B-e" becoming "Be".]
        }
        else printf("%c",ch[i]);
        lon=0;
    }
    return 0;
}