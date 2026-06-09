#include <stdio.h>
#include <string.h>
int main()
{
    char in[110];
    gets(in);
    int len = strlen(in), i = 0;
    ///先算小于1
    if(in[0]=='0')//////0.0008222    e-4    0.001
    {
        for(i = 2; i < len;i++)
        {
            if(in[i]!='0')
                break;
        }
        if(i==len-1)
        {
            printf("%c", in[i]);
            printf("e-%d\n", i - 1);
            return 0;
        }
        printf("%c.", in[i]);
        for (int j = i + 1; in[j] != '\0';j++)
            printf("%c", in[j]);
        printf("e-%d\n", i - 1);
        return 0;
    }
    else if(in[0]>'0'&&in[1]=='.')////2.59    e0
    {
        for (i = 0; i < len;i++)
            printf("%c", in[i]);
        printf("e0\n");
        return 0;
    }
    else////22333.555   . 5  e4
    {
        while(in[i]!='.')
            i++;
        printf("%c.", in[0]);
        for(int j = 1; j < i;j++)
            printf("%c", in[j]);
        for (int j = i + 1; in[j] != '\0';j++)
            printf("%c", in[j]);
        printf("e%d\n", i - 1);
        return 0;
    }
}
