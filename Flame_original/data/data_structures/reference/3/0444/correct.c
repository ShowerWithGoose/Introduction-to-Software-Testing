#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char s[101];
    int a,b,d;
    d=0;
    int c=0;
    scanf("%s",s);
    for(int i=0;s[i]>='0'&&s[i]<='9';i++)
    {
        c=10*c+s[i]-'0';
    }
    if(c==0)
    {
        for(int i=0;s[i]=='0'||s[i]=='.';i++)
        {
                d=i;
        }
            printf("%c",s[d+1]);
            if(d+2!=strlen(s))
                printf(".");
                for(int i=d+2;i<strlen(s);i++)
                {
                printf("%c",s[i]);
                }
            printf("e");
            printf("-");
            printf("%d",d);
    }
    else
{
    for(int i=0,j=0;i<strlen(s);i++,j++)
    {
        s[j]=s[i];
        if(s[i]=='.')
        {
            d=i;
            j--;
        }
    }
     printf("%c",s[0]);
     printf(".");
     for(int i=1;i<strlen(s)-1;i++)
     {
         printf("%c",s[i]);
     }
     printf("e");
     printf("%d",d-1);
}
return 0;
}

