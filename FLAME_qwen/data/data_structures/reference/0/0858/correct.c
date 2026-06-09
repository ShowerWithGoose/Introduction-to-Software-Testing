#include<stdio.h>
#include<stdlib.h>
int main()
{
    char s[1024], t[1024];
    int i, j;
    scanf("%s", s);
    i = j = 0;
    while(s[i]!='\0')
    {
        if(s[i]!='-'||i==0||s[i+1]=='\0')
        {
            t[j] = s[i];
            i++;
            j++;
        }
        else
        {
            if(s[i-1]<s[i+1]&&((s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9')||(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z')))
            {
                while(t[j]<s[i+1])
                {
                    t[j] = t[j - 1] + 1;
                    if(t[j]>=s[i+1])
                    {
                        i++;
                        break;
                    }
                    j++;
                }
            }
            else
            {
                t[j] = s[i];
                i++;
                j++;
            }
        }
    }
    printf("%s", t);
    system("pause");
    return 0;
}


