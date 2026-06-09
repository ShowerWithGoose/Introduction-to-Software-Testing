#include<stdio.h>
#include<string.h>
#include<ctype.h>
char ch[100];
int main()
{
	char str;
    int i;
    gets(ch);

    for(i=0;ch[i]!='\0';i++)
    {
    	printf("%c",ch[i]);
    	if(ch[i+1]=='-'&&ch[i]<ch[i+2]&&((isupper(ch[i])==isupper(ch[i+2])&&isupper(ch[i+2])!=0)||(islower(ch[i])==islower(ch[i+2])&&islower(ch[i+2])!=0)||((ch[i]>='0'&&ch[i]<='9')&&(ch[i+2]>='0'&&ch[i+2]<='9'))))
    	{
    		for(str=ch[i]+1;str<ch[i+2];str++)
    		{
    			printf("%c",str);
			}
			i+=1;
			continue;
		}
		
	}
    
	return 0;
}



