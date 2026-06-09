#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char s[102];
int main()
{
    int i;
    fgets(s,104,stdin);
    int count=0,numb=0,leng =strlen(s);
    for(i = 0;i < leng - 1;i++){
        if (s[i] == '0')
            continue;
        if (s[i] != '0'&&s[i] != '.'){
            if (numb!= 0)
                continue;
            numb= i + 1;
            if (s[0] == '0')
                numb= i - 1;
        }
        if (s[i] == '.')
            count = i - 1;
    }
    if (s[0] == '0'){
        if (numb+ 2 >= leng - 1)
            printf("%c", s[numb + 1]);
        else
            printf("%c.", s[numb + 1]);
        for (i = numb + 2; i < leng - 1; i++){
            printf("%c", s[i]);
        }
        printf("e-%d", abs(numb - count));
    }
    if (s[0] != '0'){
        printf("%c.", s[numb - 1]);
        for (i = numb; i < leng - 1; i++){
            if (s[i] == '.')
                continue;
            printf("%c", s[i]);
        }
        printf("e%d", abs(numb - count - 1));
    }
    return 0;
}



