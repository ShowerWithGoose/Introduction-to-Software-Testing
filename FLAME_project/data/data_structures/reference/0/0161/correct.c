#include<stdio.h>
#include<string.h>
char start[100000],end[100000];
int main()
{
	int len,i,j;
	gets(start);
	len=strlen(start);
	for(i=0,j=0;i<len;i++,j++)
	{
		if(start[i]!='-')
		end[j]=start[i];
		else if(start[0]=='i') continue;
		else{
		
			if((start[i-1]<='z'&&start[i-1]>='a'&&start[i+1]<='z'&&start[i+1]>='a')||(start[i-1]<='Z'&&start[i-1]>='A'&&start[i+1]<='Z'&&start[i+1]>='A')||(start[i-1]<='9'&&start[i-1]>='0'&&start[i+1]<='9'&&start[i+1]>='0')){
			while(start[i-1]<start[i+1]-1)
			{
				start[i-1]++;
				end[j]=start[i-1];
				j++;
			}
			j--;
		}
		else end[j]=start[i];
		}
	}
	puts(end);
	return 0 ;
}

