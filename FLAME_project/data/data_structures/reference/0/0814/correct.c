#include <stdio.h>
int main()
{
	char ch[105],s[205];
    scanf("%s",ch);
	int i=0,j=0;
	s[0]=ch[0];
	for(i=1,j=1;ch[i+1]!='\0';i++,j++)
	{
		if((ch[i]=='-')&&((ch[i-1]>='a'&&ch[i-1]<ch[i+1]&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i-1]<ch[i+1]&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i-1]<ch[i+1]&&ch[i+1]<='9')))
		{
			s[j]=ch[i-1]+1;
			while(s[j]<ch[i+1]-1)
			{
				s[j+1]=s[j]+1;
				j++;
			}
		}
		else s[j]=ch[i];
	}
	s[j]=ch[i];
	s[j+1]='\0';
	puts(s);
	return 0;
}

