#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>


//int main() {
//    char s[1000];
//    scanf("%s", s);
//    for (int i = 0; s[i] != '\0'; i++)
//    {
//        if ((s[i] == '-') && (s[i - 1] < s[i + 1]) && ((('a' <= s[i - 1]) && (s[i + 1] <= 'z')) || (('a' <= s[i - 1]) && (s[i + 1] <= 'z')) || (('0' <= s[i - 1]) && (s[i + 1] <= '9'))))
//        {
//            for (int j = 1; j < s[i + 1] - s[i - 1]; j++) {
//                printf("%c", s[i - 1] + j);
//            }
//        }
//        else
//            printf("%c", s[i]);
//    }
//    return 0;
//}

int main() {
    char s[100];
    int k=0;
    scanf("%s", s);
    if (strlen(s) == 1)
        printf("%ce0", s[0]);
    else if (s[0] == '0')
    {
        for (int i = 2; i < strlen(s); i++)
        {
            if (s[i] != '0')
            {
                if (i == (strlen(s) - 1))
                    printf("%ce-%d", s[i], i - 1);
                else 
                {
                    printf("%c.", s[i]);
                    {
                        for (int j = i; j < strlen(s); j++) // @@ The loop should start from i + 1 to avoid printing the first non-zero digit twice, as it was already printed by printf("%c.", s[i]);
                            printf("%c", s[j]);
                    }
                    printf("e-%d", i - 1);
                }
                break;
            }
        }
        
    }
    else
    {
        printf("%c.", s[0]);
        for (int i = 1; i < strlen(s); i++)
        {
            if (s[i] == '.')
                k = i;
            else
                printf("%c", s[i]);
        }
        printf("e%d", k-1);
    }
    return 0;
}