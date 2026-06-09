#include<stdio.h>
#include<string.h>
char start[100000],end[100000];
int main()
{
	int len,i,m;
	gets(start);
	len=strlen(start);
	for(i=0,m=0;i<len;i++,m++)
	{
		if(start[i]!='-')
		end[m]=start[i];
		else if(start[0]=='i') continue;
		else{
		
			if((start[i-1]<='z'&&start[i-1]>='a'&&start[i+1]<='z'&&start[i+1]>='a')||(start[i-1]<='Z'&&start[i-1]>='A'&&start[i+1]<='Z'&&start[i+1]>='A')||(start[i-1]<='9'&&start[i-1]>='0'&&start[i+1]<='9'&&start[i+1]>='0')){
			while(start[i-1]<start[i+1]-1)
			{
				start[i-1]++;
				end[m]=start[i-1];
				m++;
			}
			m--;
		}
		else end[m]=start[i];
		}
	}
	puts(end);
	return 0 ;
}

