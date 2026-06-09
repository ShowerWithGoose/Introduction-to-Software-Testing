#include<stdio.h>
#include<string.h>


int main()
{
	char s[100], j;
	int i=0;
	gets(s);

	for (i=0;i<100&&s[i]!='\0';i++){

		if (s[i]=='-'){

			if ((s[i+1]>s[i-1])&&( ((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z')) ||((s[i-1]>='A'&&s[i-1]<='Z')&&(s[i+1]>='A'&&s[i+1]<='Z'))||((s[i-1]>='0'&&s[i-1]<='9')&&(s[i+1]>='0'&&s[i+1]<='9')))){

				for (j=s[i-1]+1;j<s[i+1];j++){
					printf("%c", j);
				}
 			}else printf("-");
		}
		else printf("%c", s[i]);

	}


    return 0;

}





