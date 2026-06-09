#include <stdio.h> 
int f(char s,char t)
{
	int flag=0;
	if(s>='0'&&t<='9')
	flag+=1;
	else
	if(s>='a'&&t<='z')
	flag+=1;
	else
	if(s>='A'&&t<='Z')
	flag+=1;
	if(s>=t)
	flag=flag*0;
	return flag; 
}
int main()
{
	char s[105];
	int i,n,z;
	int j[105];
	gets(s);
	for(i=0;i<=105;i++)
	j[i]=0;
	for(i=1;s[i]!='\0';i++)
	{
		if(s[i]=='-')
		{
			if(f(s[i-1],s[i+1]))
            j[i]=1;
		}	
	}
	i=0;
	while(s[i]!='\0')
	{
		if(j[i]==1)
		for(z=1;s[i-1]+z<s[i+1];z++)
		{
			printf("%c",s[i-1]+z);
		}
		else
		{
			printf("%c",s[i]);
	    }
	    i++;
	}
	return 0;
}


