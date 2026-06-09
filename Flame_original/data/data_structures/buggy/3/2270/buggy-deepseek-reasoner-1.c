#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char str[100001];

int main()
{
    scanf("%s",&str); // @@ Error: scanf expects a char*, but &str gives a pointer to the array (type char(*)[100001]). Use str instead of &str.
    int len = strlen(str);
    int a = 0;
    if(str[0]-'0'==0)
    {
        for(int i=2;i<len;i++)
        {
            if(str[i]!='0'&&str[i+1]!='\0') // @@ Error: when i == len-1, str[i+1] accesses out-of-bounds memory. Should check i+1 < len.
            {
                printf("%c.",str[i]);
                a = i;
                for(int p=i+1;p<len;p++)
                {
                    printf("%c",str[p]);
                }
                goto e;
            }
            else if(str[i]!='0'&&str[i+1]=='\0') // @@ Error: same out-of-bounds access when i == len-1. Also this branch does not go to label e, causing the later "e-" to print incorrectly.
            {
                printf("%c",str[i]);
            }
        }
        e:
        printf("e-"); // @@ Error: This line executes even if the else-if branch was taken, causing an extra "e-" after the digit printed there.
        printf("%d",a-1); // @@ Error: For the else-if branch, a remains 0, so a-1 = -1 is printed, which is incorrect. Also for the case where no non-zero digit is found, a is 0, output is wrong.
    }
    else
    {
        printf("%c.",str[0]);
        for(int i=1;i<len;i++)
        {
            if(str[i]!='.')
            {
                printf("%c",str[i]);
            }
            else
            {
                a = i;
            }
        }
        printf("e");
        printf("%d",a-1);
    }
    
    return 0;
}