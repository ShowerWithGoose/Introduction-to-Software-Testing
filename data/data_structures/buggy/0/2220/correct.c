#include <stdio.h>
#include <string.h>
int main()
{
	char str[100];
	gets(str);
	//printf("%c",str[3]);
	int len=strlen(str);
	//printf("%d",len);
	printf("%c",str[0]); 
	for(int i=1;i<len;i++)
	{
		if(str[i]=='-')
		{
		if(((str[i-1]-'a')>=0 )&& ((str[i-1]-'a')<=26)){
			if(((str[i+1]-'a')>=0 && (str[i+1]-'a')<=26)&&(str[i+1]>str[i-1])){
				
			    int k;
				k=str[i+1]-str[i-1];
				int m;
				m=(str[i-1]);
				for(int v=1;v<k;v++)
				{
					char q;
					q=(m+v);
					printf("%c",q);
				}
			}
			else {
				printf("%c",str[i]);
			}
		}
			if(((str[i-1]-'A')>=0 )&& ((str[i-1]-'A')<=26)){
			if(((str[i+1]-'A')>=0 && (str[i+1]-'A')<=26)&&(str[i+1]>str[i-1])){
				
			    int k;
				k=str[i+1]-str[i-1];
				int m;
				m=(str[i-1]);
				for(int v=1;v<k;v++)
				{
					char q;
					q=(m+v);
					printf("%c",q);
				}
			}
			else {
				printf("%c",str[i]);
			}
		}
			if(((str[i-1]-'0')>=0 )&& ((str[i-1]-'0')<=9)){
			if(((str[i+1]-'0')>=0 && (str[i+1]-'0')<=9)&&(str[i+1]>str[i-1])){
				
			    int k;
				k=str[i+1]-str[i-1];
				int m;
				m=(str[i-1]);
				for(int v=1;v<k;v++)
				{
					char q;
					q=(m+v);
					printf("%c",q);
				}
			}
			else {
				printf("%c",str[i]);
			}
		}
		}
		else{
			printf("%c",str[i]); 
		} 
	}
return 0;
}





