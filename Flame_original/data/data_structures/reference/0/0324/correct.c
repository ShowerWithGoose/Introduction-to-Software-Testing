#include<stdio.h>
#include<string.h>
int main(){
	char s[10000],t[10000];
	int i,j,k;
	gets(s);
	for(i=1;s[i]!='\0';i++){
		if(s[i]=='-'&&(((s[i-1]>='a')&&(s[i+1]<='z'))||((s[i-1]>='0')&&(s[i+1]<='9'))||((s[i-1]>='A')&&(s[i+1]<='Z')))&&s[i-1]<s[i+1]){		
			for(j=i+1,k=0;s[j]!='\0';j++,k++)
				t[k]=s[j];
			t[k]='\0';
			for(j=1,k=i;j<t[0]-s[i-1];k++,j++)
				s[k]=s[i-1]+j;
			for(j=0;t[j]!='\0';k++,j++)
				s[k]=t[j];
			s[k]='\0';
		}
	}
	puts(s);
	return 0;
}

