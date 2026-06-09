#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char*s;
    scanf("%s",s); // @@ Pointer 's' is uninitialized; it does not point to valid memory, causing undefined behavior (likely segmentation fault). The code must allocate a buffer for the input string.
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