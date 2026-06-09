#include<stdio.h>
#include<string.h>

int main()
{
    char s[105];
    scanf("%s",s);
    int len=strlen(s);
    int i,j,k;
    if(s[0]=='-')
        printf("-");
    for(i=0;i<len;i++)
    {
        if(s[i]>'0'&&s[i]<='9')
        {
            printf("%c",s[i]);
            break;
        }
    }
    //printf("%d",i);
    if(i==len-1)
    {
        printf("e-%d",i-1);
        return 0;
    }else {
        printf(".");
        for(j=i+1;j<len;j++)
        {
            if(s[j]!='.')
                printf("%c",s[j]);
        }
    }
    printf("e");
    for(k=0;k<len;k++)
    {
        if(s[k]=='.')
            break;
    }
    //printf("\n%d",k);
    if(k>i)
        printf("%d",k-i-1);
    else printf("%d",k-i);

    return 0;
}



