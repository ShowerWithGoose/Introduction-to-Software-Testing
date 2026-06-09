#include<stdio.h>
int main()
{
	char in[10000];
	char out[10000];
	int  length;
	int  i=0,j=0,k;
	gets(in);
	out[j++]=in[i++];
	for(i=1;in[i]!='\0';i++)
	{
		if(in[i]=='-')
		{
			if(in[i-1]>='a'&&in[i-1]<='z'&&in[i+1]>='a'&&in[i+1]<='z')
			{
				length=(in[i+1]-in[i-1]);
				if(length>0&&length<25)
				{
					for(k=1;k<length;k++)
					out[j++]=in[i-1]+k;
				}
				//i++;
				continue;
			}
			if(in[i-1]>='A'&&in[i-1]<='Z'&&in[i+1]>='A'&&in[i+1]<='Z')
			{
				length=(in[i+1]-in[i-1]);
				if(length>0&&length<25)
				{
					for(k=1;k<length;k++)
					out[j++]=in[i-1]+k;
				}
				//i++;
				continue;
			}
			if(in[i-1]>='0'&&in[i-1]<='9'&&in[i+1]>='0'&&in[i+1]<='9')
			{
				length=(in[i+1]-in[i-1]);
				if(length>0&&length<25)
				{
					for(k=1;k<length;k++)
					out[j++]=in[i-1]+k;
				}
				//i++;
				continue;
			}
				
		}
		
		out[j++]=in[i];
		
	}
	out[j]='\0';
	printf("%s",out);
	return 1;
	
	
}



