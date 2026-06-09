#include<stdio.h>
#include<string.h>
int main()
{
	char ch[1000]={0};
	gets(ch);
	int i=0,len=strlen(ch),j;
	while(i<len)
	{
		if(ch[i+1]!='-')
		printf("%c",ch[i]);
		else if(i+2>=len)
		printf("%c",ch[i]);
		else if(ch[i]>='0'&&ch[i+2]<='9'&&ch[i]<ch[i+2]){
	    for(j=ch[i];j<ch[i+2];j++)
	    printf("%c",j);
	    i++;}
	    else if(ch[i]>='a'&&ch[i+2]<='z'&&ch[i]<ch[i+2]){
	    for(j=ch[i];j<ch[i+2];j++)
	    printf("%c",j);
	    i++;}
		else if(ch[i]>='A'&&ch[i+2]<='Z'&&ch[i]<ch[i+2]){
	    for(j=ch[i];j<ch[i+2];j++)
	    printf("%c",j);
	    i++;}
	    else
	    printf("%c",ch[i]);
	    i++;
	}
	
	return 0;
}

