#include<stdio.h>
#include<string.h>
char str[1001];
int main()
{    gets(str); // @@ [gets is removed in the C11 standard and causes compilation errors in modern compilers; use scanf or fgets instead]
    int i,j,k; // @@ [Variable declarations after executable statements are not allowed in C89/C90, which causes compilation errors in strict environments]
    if(str[0]!='0'&&str[1]=='.')
    printf("%se0",str);
    else
    {    if(str[0]=='0')
        {for(i=2;i<=strlen(str)-1;i++)
        if(str[i]!='0')
        {j=i;
        break;
        }
        printf("%c.",str[j]);
        for(k=j+1;k<=strlen(str)-1;k++)
        printf("%c",str[k]);
        printf("e-%d",j-1);
        }
        
        else
        {for(i=2;i<=strlen(str)-1;i++)
        if(str[i]=='.')
        {
        j=i;
        break;
        }
        printf("%c.",str[0]);
        for(k=1;k<j;k++)
        printf("%c",str[k]);
        for(k=j+1;k<=strlen(str)-1;k++)
        printf("%c",str[k]);
        printf("e%d",j-1);
        }
        
        
        
        
    }

return 0;
}