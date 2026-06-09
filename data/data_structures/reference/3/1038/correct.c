#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],t[1000];
    int i,j,k=-1;
    double d,f;
    gets(s);
    if(s[0]=='0'){
		for(i=2;s[i]=='0';i++){
    		k--;
		} 
		for(j=0;s[i]!='\0';i++){
			if(j==1) t[j++]='.';
			t[j++]=s[i];
		}
		t[j]='\0';
	}
	else{
		for(i=0;s[i]!='.'&&s[i]!='\0';i++){
			k++;
		} 
		for(i=0,j=0;s[i]!='\0';i++){
			if(j==1) t[j++]='.';
			if(s[i]=='.') continue;
			t[j++]=s[i];
		}
		t[j]='\0';
	}
	printf("%se%d",t,k);
	return 0; 
}

