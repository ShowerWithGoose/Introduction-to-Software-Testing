#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char str[100001];

int main()
{
    scanf("%s",&str); // @@ Using &str is incorrect; str is already a pointer to char, should be scanf("%s", str);
    int len = strlen(str);
    int a = 0;
    if(str[0]-'0'==0)
    {
        for(int i=2;i<len;i++)
        {
            if(str[i]!='0'&&str[i+1]!='\0')
            {
                printf("%c.",str[i]);
                a = i;
                for(int p=i+1;p<len;p++)
                {
                    printf("%c",str[p]);
                }
                goto e;
            }
            else if(str[i]!='0'&&str[i+1]=='\0')
            {
                printf("%c",str[i]); // @@ Missing newline or 'e' exponent part when last non-zero digit is at end; also doesn't set 'a' correctly for exponent
            }
        }
        e:
        printf("e-");
        printf("%d",a-1); // @@ If no non-zero digit found after leading zeros (e.g., "0.0"), 'a' remains 0, leading to wrong exponent -1
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
        printf("%d",a-1); // @@ If input has no decimal point (violates problem constraints but still), 'a' remains 0, causing wrong exponent -1
    }
    
    return 0;
}