#include<stdio.h>
char ch[1000];
int main()
{
    scanf("%s",ch);
    int i;
    char j;
    for(i=1; ch[i]!='\0'; i++)
    {
        if(ch[i]!='-')
printf("%c",ch[i-1]);
        else if(ch[i]=='-'&&ch[i-1]>='0'&&ch[i+1]<='9'&&ch[i-1]<ch[i+1])
        {
            j=ch[i-1];
              for(; j<ch[i+1]; j++)
                  printf("%c",j);
                  i++;
        }
        else if(ch[i]=='-'&&ch[i-1]>='a'&&ch[i+1]<='z'&&ch[i-1]<ch[i+1])
        {
            j=ch[i-1];
              for(; j<ch[i+1]; j++)
                  printf("%c",j);
                  i++;
        }
        else if(ch[i]=='-'&&ch[i-1]>='A'&&ch[i+1]<='Z'&&ch[i-1]<ch[i+1])
        {
            j=ch[i-1];
              for(; j<ch[i+1]; j++)
                  printf("%c",j);
                  i++;
        }
        else printf("%c",ch[i-1]);
    }
    printf("%c",ch[i-1]);
    return 0;
}



