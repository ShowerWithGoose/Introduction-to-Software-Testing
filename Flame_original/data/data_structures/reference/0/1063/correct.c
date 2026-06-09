#include<stdio.h>
int main()
{
    char s[1000];
    int i,k;
    gets(s);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!='-')
        {
            printf("%c",s[i]);
        }
        else
        {
         while(s[i]=='-')
         {
            if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z')
            {
                for(k=1;k<=(s[i+1]-s[i-1]);k++)
                {
                    printf("%c",s[i-1]+k);
                }  
            }
            else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z')
            {
                for(k=1;k<=(s[i+1]-s[i-1]);k++)
                {
                    printf("%c",s[i-1]+k);
                }
            }
            else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9')
            {
                for(k=1;k<=(s[i+1]-s[i-1]);k++)
                {
                    printf("%c",s[i-1]+k);
                }
            }
            else
            {
                printf("-");
                printf("%c",s[i+1]);
            }
            i++;   
         }
        }
    }
    return 0;
}


