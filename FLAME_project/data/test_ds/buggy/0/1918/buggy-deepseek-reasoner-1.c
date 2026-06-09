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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')) // @@ [Incorrect condition: only checks lower bound of left char and upper bound of right char, does not ensure both characters are of the same type and within the full range. For example, 'B' and 'e' may falsely trigger the lowercase branch? Actually for "B-e" it does not enter, but the condition is too permissive overall.]
            {
                lon=ch[i+1]-ch[i-1];
                for(j=0;j<lon-1;j++)
                {
                    printf("%c",j+ch[i-1]+1);
                }
            } // @@ [Missing else clause: when the condition is false, the dash should be printed as is using `printf("%c",ch[i]);` Without it, the dash is simply omitted, leading to incorrect output like "Be" for "B-e".]
        }
        else printf("%c",ch[i]);
        lon=0;
    }
    return 0;
}