#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char*s; // @@ The pointer 's' is declared but not initialized or allocated memory. Using it in scanf causes undefined behavior (segmentation fault). It should be an array like char s[1000] or allocated via malloc.
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(*(s+i)!='-')
            printf("%c",*(s+i));
        else
        {
            if(*(s+i-1)<*(s+i+1))
            {
                if((*(s+i-1)>='a'&&*(s+i-1)<='z'&&*(s+i+1)>='a'&&*(s+i+1)<='z')||(*(s+i-1)>='A'&&*(s+i-1)<='Z'&&*(s+i+1)>='A'&&*(s+i+1)<='Z')||(*(s+i-1)>='0'&&*(s+i-1)<='9'&&*(s+i+1)>='0'&&*(s+i+1)<='9'))
                {
                    int len1=*(s+i+1)-*(s+i-1);
                    for(int j=1;j<len1;j++)
                        printf("%c",*(s+i-1)+j);
                }
                else
                    printf("-");
            }
            else
                printf("-");
        }
    }
    return 0;
}