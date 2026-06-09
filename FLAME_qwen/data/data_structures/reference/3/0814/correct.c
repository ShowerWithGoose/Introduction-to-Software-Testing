#include <stdio.h>
int main()
{
	char ch[105],s[105];
	int i=0,j=0,power=0;
	gets(ch);
		if(ch[0]=='0')
		{
			for(i=2;ch[i]=='0';i++);
			power=i-1;
			s[0]=ch[i];
			if(ch[i+1]!='\0')
			{
			    s[1]='.';
			    for(j=2;ch[i+1]!='\0';j++,i++)
			    s[j]=ch[i+1];
			    s[j]='e';
			    s[j+1]='-';
			    s[j+2]='\0';
			}
			else 
			{
				s[1]='e';
				s[2]='-';
				s[3]='\0';
			}
		}
		else if(ch[1]=='.')
		{
			for(i=0;ch[i]!='\0';i++)
			{
				s[i]=ch[i];
			}
			s[i]='e';
			s[i+1]='\0';
		}
		else
		{
			int flag=0;
			for(i=0;ch[i]!='\0';i++)
			{
				if(ch[i]=='.')
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				s[0]=ch[0];
			s[1]='.';
			for(i=0,j=2;ch[i+1]!='\0';i++)
			{
				if(ch[i+1]=='.')
				{
					power=i;
					continue;
				}
				s[j++]=ch[i+1];
			}
			    s[j]='e';
			    s[j+1]='\0';
			}
			else
			{
				s[0]=ch[0];
				s[1]='.';
				if(ch[1]=='\0')
				{
					power=0;
					s[2]='0';
					s[3]='e';
					s[4]='\0';
				}
				else
				{
					int id=0;
					for(i=0;ch[i]!='\0';i++)
					{
						if(ch[i]!='0') id=i;
					}
					power=i-1;
					if(id==0)
					{
						s[2]='0';
					    s[3]='e';
					    s[4]='\0';
					}
					else
					{
						for(i=1;i<=id;i++)
						{
							s[i+1]=ch[i];
						}
						s[i+1]='e';
						s[i+2]='\0';
					}
				}
			}
		}
	printf("%s%d",s,power);
	return 0;
}




