#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char*s; // @@ Uninitialized pointer 's' is used in scanf, which will cause undefined behavior or segmentation fault. It should be declared as an array (e.g., char s[1000];) or allocated memory.
    scanf("%s",s); // @@ Writing to an uninitialized pointer causes a runtime crash. Memory must be allocated before reading input.
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(*(s+i)!='-')
            printf("%c",*(s+i));
        else
        {
            if(*(s+i-1)<*(s+i+1)) // @@ Accessing s[i-1] when i=0 results in out-of-bounds memory access. A boundary check (i > 0) is required.
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