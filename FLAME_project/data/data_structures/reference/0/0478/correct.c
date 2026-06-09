#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char a[100];
int str(char s1,char s2){
		if((s1>='0'&&s2<='9')||(s1>='a'&&s2<='z')||(s1>='A'&&s2<='Z'))
	return 1;
	else 
	return 0;
}
int main()
{

    int i;
    char j;
    gets(a);
    for(i=0;i<strlen(a)-1;i++)
    {

        if(a[i+1]!='-'&&a[i]!='-')
            printf("%c",a[i]);
        else if(a[i+1]=='-')
        {
            if(a[i]<a[i+2]&&str(a[i],a[i+2]))
            {
                for(j=a[i];j<a[i+2];j++)
                    printf("%c",j);
            }
            else
               printf("%c%c",a[i],'-');

        }
}
     printf("%c",a[i]);
    return 0;
}


