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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')) // @@ [Error: The condition does not check that both characters are within the same range. For example, it would incorrectly treat 'a' and 'z' as valid, but also 'a' and 'Z' or '0' and 'b'. It should separately check lowercase, uppercase, and digit ranges with proper bounds, and also ensure ch[i+1] > ch[i-1].]
            {
                lon=ch[i+1]-ch[i-1];
                for(j=0;j<lon-1;j++)
                {
                    printf("%c",j+ch[i-1]+1);
                }
            }
        }
        else printf("%c",ch[i]);
        lon=0;
    }
    return 0;
}