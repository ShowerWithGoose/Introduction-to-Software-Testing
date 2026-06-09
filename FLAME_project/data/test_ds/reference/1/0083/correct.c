#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	char s[1000],c[1000];
	int i,j;
	gets(s);
	for(i=0;i<strlen(s);i++){
		if(s[i]=='-'){
			if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'){
				for(j=0;j<(s[i+1]-s[i-1]-1);j++){
					c[j]=s[i-1]+1+j;
					c[s[i+1]-s[i-1]-1]='\0';
				}
				strcat(c,&s[i+1]);
				s[i]='\0';
				strcat(s,c);
			}else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'){
				for(j=0;j<(s[i+1]-s[i-1]-1);j++){
					c[j]=s[i-1]+1+j;
					c[s[i+1]-s[i-1]-1]='\0';
				}
				strcat(c,&s[i+1]);
				s[i]='\0';
				strcat(s,c);
			}else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'){
				for(j=0;j<(s[i+1]-s[i-1]-1);j++){
					c[j]=s[i-1]+1+j;
					c[s[i+1]-s[i-1]-1]='\0';
				}
				strcat(c,&s[i+1]);
				s[i]='\0';
				strcat(s,c);
			}
		}
		
	}
	printf("%s",s);
}

