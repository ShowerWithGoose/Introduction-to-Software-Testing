#include<stdio.h>
#include<string.h>
#include<math.h>
char s[200],m[200],marks[50];
int numbers[50];
int main()
{
	char *p,*q;
	int i,j1,k,flag=0,answer=0,answer1=1;
	gets(s);
	for(i=0,j1=0;s[i]!='\0';i++)
	{
		if(s[i]==' ')
			continue;
		m[j1++]=s[i];
	}
	for(i=0,j1=0,k=0;m[i]!='=';i++)
	{
		if(m[i]=='+'||m[i]=='-'||m[i]=='*'||m[i]=='/')
		{
			marks[j1++]=m[i];
			continue;
		}	
		while(m[i]>='0'&&m[i]<='9')
		{
			numbers[k]=numbers[k]*10+(m[i]-'0');
			i++;
		}
		k++;
		i--;		 	
	}	
	p=marks;
	while(strchr(p,'*')!=NULL||strchr(p,'/')!=NULL)
	{
		if(strchr(p,'*')==NULL) p=strchr(p,'/');
		else if(strchr(p,'/')==NULL) p=strchr(p,'*');
		else if(strchr(p,'*')-strchr(p,'/')>0)
			p=strchr(p,'/');
		else if(strchr(p,'*')-strchr(p,'/')<0)
			p=strchr(p,'*');
		if(p-marks==0) flag=0;
		else if(p[-1]=='+') flag=0;
		else if(p[-1]=='-') flag=1;
		q=p;
		i=k=q-marks;
		while(q[0]=='*'||q[0]=='/')
			q++;
		j1=q-marks-1;
		answer1=numbers[k];
		while(k<=j1)
		{
			if(marks[k]=='*')
				answer1*=numbers[k+1];
			if(marks[k]=='/')
				answer1/=numbers[k+1];
			k++;	
		}
		if(flag) answer-=answer1;
		else answer+=answer1;
		for(k=i;k<=j1;k++)
		{
			marks[k]='?';
			numbers[k]=0;
		}
		numbers[k]=0;
	}
		for(i=0;marks[i]!='\0';i++)
		{
			if(marks[i]=='-')
				answer-=numbers[i+1];
			else
				answer+=numbers[i+1];
		}
	answer+=numbers[0];
	if(marks[0]=='\0') printf("%d",numbers[0]);	
	else printf("%d",answer);		
	return 0;
	
}


