#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char str[100001];

int main()
{
    scanf("%s",&str);
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
                printf("%c",str[i]);
            }
        }
        e:
        printf("e-"); // @@ The code unconditionally prints "e-" for numbers starting with 0, but the exponent calculation `a-1` might be negative (requiring a minus sign) or potentially handled incorrectly if the logic for `a` results in a double negative or incorrect sign handling. Specifically for input "0.9", `a` becomes 2 (index of '9'). The exponent should be -1. The code prints "e-" and then `a-1` which is `1`. Result: "e-1". Wait, let's re-evaluate. Input "0.9". `str[0]='0'`. Loop starts `i=2`. `str[2]` is out of bounds if len is 3 ("0.9"). `str[0]='0', str[1]='.', str[2]='9', str[3]='\0'`. Loop `i=2`. `str[2]!='0'` ('9'!='0') is true. `str[3]!='\0'` is false. So it goes to `else if`. `str[2]!='0'` is true. `str[3]=='\0'` is true. Prints "9". Does NOT go to label `e`. Falls through. The code after the loop/label is executed? No, `goto e` is not called. The code continues to `printf("e-");`. This is executed because it's after the label `e:` but the label is just a marker. The execution flow falls through from the `else if` block to the statement after the `if-else` block? No, the `if-else` is inside the `for` loop. After the loop finishes (without `goto`), the execution proceeds to `e:` label. So it prints "e-". Then `printf("%d", a-1)`. `a` was initialized to 0. So it prints "0-1" -> "-1". Total output: "9e--1". The error is that `a` is not updated when the number is like "0.9" (single non-zero digit after decimal). And the sign is hardcoded as "-".
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
        printf("%d",a-1);
    }
    
    return 0;
}