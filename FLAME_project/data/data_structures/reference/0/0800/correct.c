#include<stdio.h>
int main()
{
    char s[10000];
    scanf("%s",s);
    int i,j;
    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i+1]!='-') printf("%c",s[i]);
        else
        {
            if(s[i]<s[i+2]&&((s[i]>='0'&&s[i+2]<='9')||(s[i]>='a'&&s[i+2]<='z')||(s[i]>='A'&&s[i+2]<='Z')))
            {

                for(j=0; j<(s[i+2]-s[i]); j++)
                    printf("%c",s[i]+j);
            }
            else
                printf("%c%c",s[i],s[i+1]);


          i++;

        }



    }

return 0;
}












