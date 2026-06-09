#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define ep 1e-6
#define pi 3.14159265
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define NumberOf(x) (sizeof(x)/sizeof(x[0])
#define max(A,B) ((A)>(B)?(A):(B))

int main()
{
	char s1[1000],s2[1000];
	gets(s1);
	int i,j,k;
	for(i=0,j=0;s1[i]!='\0';i++)
	{
		if(s1[i]!='-')
		{
			s2[j++]=s1[i];
		}
		else
		{
			if(s1[i+1]=='\0')
			s2[j++]=s1[i];
			else if((s1[i-1]>='a'&&s1[i-1]<='z')&&(s1[i+1]>='a'&&s1[i+1]<='z')&&(s1[i+1]>s1[i-1]))
			{
						if((s1[i+1]-s1[i-1])==1)
						continue;
						else{
						for(k=1;k<s1[i+1]-s1[i-1];k++)
						{
							s2[j]=s1[i-1]+k;
							j++;
						}
						}
			}
			else if((s1[i+1]>='A'&&s1[i+1]<='Z')&&(s1[i-1]>='A'&&s1[i-1]<='Z')&&(s1[i+1]>s1[i-1]))
			{
						if((s1[i+1]-s1[i-1])==1)
						continue;
						else{
						for(k=1;k<s1[i+1]-s1[i-1];k++)
						{
							s2[j]=s1[i-1]+k;
							j++;
						}
						}
			}
			else if((s1[i+1]>s1[i-1])&&(s1[i+1]>='0'&&s1[i+1]<='9')&&(s1[i-1]>='0'&&s1[i-1]<='9'))
			{
						if((s1[i+1]-s1[i-1])==1)
						continue;
						else{
						for(k=1;k<s1[i+1]-s1[i-1];k++)
						{
							s2[j]=s1[i-1]+k;
							j++;
						}
						}
			}
			else
			s2[j++]=s1[i];
		}
	}
	s2[j]='\0';
	puts(s2);
}



