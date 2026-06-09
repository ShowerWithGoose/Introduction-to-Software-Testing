#include<stdio.h>
#include<string.h>
char ch[1000],new_str[26],final[1000];
int main()
{
	int i,j,k;
	scanf("%s",ch);
	for(i=0;ch[i]!='\0';i++)
	{
		if(ch[i]=='-')
		{
			if((ch[i-1]>='0'&&ch[i+1]<='9'&&ch[i-1]<ch[i+1])||(ch[i-1]>='a'&&ch[i+1]<='z'&&ch[i-1]<ch[i+1])||(ch[i-1]>='A'&&ch[i+1]<='Z'&&ch[i-1]<ch[i+1]))
			{
				for(j=0;j<ch[i+1]-ch[i-1]-1;j++)
				{
					if(j==0) new_str[j]=ch[i-1]+1;
					else new_str[j]=new_str[j-1]+1;
				}
				for(j=0;j<i;j++) final[j]=ch[j];
				for(j=i,k=0;k<ch[i+1]-ch[i-1]-1;k++,j++) final[j]=new_str[k];
				for(j,k=i+1;ch[k]!='\0';k++,j++) final[j]=ch[k];
				k=0;
				j=0;
				strcpy(ch,final);
			}
		}
	}
	if(final[0])
	puts(final);
	else puts(ch);
	return 0;
}

