#include<stdio.h>
int check(char a,char b) 
{
	if(a>='a'&&a<='z')
	{
		if(b>='a'&&b<='z'&&b-a>0)
		    return 1;
		else
		    return 0;
	}
	if(a>='A'&&a<='Z')
	{
		if(b>='A'&&b<='Z'&&b-a>0)
		    return 1;
		else
		    return 0;
	}
	if(a>='0'&&a<='9')
	{
		if(b>='0'&&b<='9'&&b-a>0)
		    return 1;
		else
		    return 0;
	}
}
void output(char a,char b)
{
	int i;
	for(i=0;a+i<b;i++)
	    printf("%c",a+i);
}
int main()
{
	char line[100];
	int i;
	gets(line);
	for(i=0;line[i]!='\0';i++)
	{
		if(line[i+1]=='-')
		{
			if(check(line[i],line[i+2])==0)
			    printf("%c%c",line[i],line[i+1]);
			else
			    output(line[i],line[i+2]);
			i++;
		}
		else
		    printf("%c",line[i]);
	}
	return 0;
}



