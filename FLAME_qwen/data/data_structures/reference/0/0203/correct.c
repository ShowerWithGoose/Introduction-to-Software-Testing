#include <stdio.h>
#include <ctype.h>
char origin[105];
int whether_extent(int x){
	if(((isupper(origin[x-1]))*(isupper(origin[x+1]))!=0)||((islower(origin[x-1]))*(islower(origin[x+1]))!=0)||((isdigit(origin[x-1]))*(isdigit(origin[x+1]))!=0)&&origin[x+1]-origin[x-1]>0)
	return 1;
	else
	return -1;
}
int main()
{
	char extension[105];
	int i=0,j=0,k=0;
	gets(origin);
	for(i=0;origin[i]!='\0';i++)
	{
		if(origin[i]!='-'||whether_extent(i)<0)
		extension[j++]=origin[i];
		else
		{
			for(k=0;k<origin[i+1]-origin[i-1]-1;k++)
			extension[j++]=origin[i-1]+1+k;
		}
	}
	for(k=0;k<j;k++)
	printf("%c",extension[k]);
	return 0;
}

