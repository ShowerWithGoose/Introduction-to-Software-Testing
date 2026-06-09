#include <stdio.h>
#include <string.h>
int main()
{
    int i=0,point=0,inf=0;
    char s[105];
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if (s[i]=='.')
        {
            point = i;
            break;
        }
    }
    if(point>1)
    {
        printf("%c.",s[0]);
        for(i=1;i<point;i++)
            printf("%c",s[i]);
        for(i=point+1;i<strlen(s);i++)
            printf("%c",s[i]);
        printf("e%d",point-1);
    }
    else if(point==1&&s[0]!='0')
    {
        printf("%c.",s[0]);
        for(i=2;i<strlen(s);i++)
            printf("%c",s[i]);
        printf("e0");
    }
    else
    {
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]!='0'&&s[i]!='.')
            {
                inf=i;
                break;
            }
        }
        printf("%c",s[i]);
        if(i<strlen(s)-1)
		{
			printf(".");
			i++;
			for(i;i<strlen(s);i++)
            printf("%c",s[i]);
		}
        printf("e-%d",inf-1);
    }
    return 0;
}


