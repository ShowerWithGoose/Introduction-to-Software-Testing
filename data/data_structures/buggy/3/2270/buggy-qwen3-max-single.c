#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char str[100001];

int main()
{
    scanf("%s",&str); // @@ Using &str is incorrect; str is already a pointer to char array, should be scanf("%s", str);
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
                printf("%c",str[i]); // @@ Missing newline or 'e' exponent part when last digit is non-zero after zeros (e.g., "0.005")
            }
        }
        e:
        printf("e-");
        printf("%d",a-1);
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
        printf("%d",a-1); // @@ If input has no decimal point (though problem says it does), this logic fails; but more critically, if the number is like "123.45", it prints "1.2345e2" correctly, but if input is just "5" (not per spec), it would break. However, per problem, input always has digits before and after '.', so this may be okay. But note: a is only set if '.' is found; if not, a remains 0 → wrong exponent.
    }
    
    return 0;
}