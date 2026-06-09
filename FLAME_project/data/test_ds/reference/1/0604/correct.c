#include<stdio.h>
#include<string.h>

int main()
{
	char s[1000],t[1000];
	int i=0,l,j=0,h=1; 
	fgets(s,1000,stdin);
	l=strlen(s);

	for(i=j=0;i<=l;i++) 
	{
		
		if(s[i]=='-'&&s[i+1]>s[i-1]+1)
		{
			if(s[i-1]>='0'&&s[i+1]<='9')
			{
				
				while(h<s[i+1]-s[i-1])
					{
					t[j]=s[i-1]+h;
					j++;
					h++;
					
				 }
				 h=1;
				 
				
			}
			else if(s[i-1]>='a'&&s[i+1]<='z')
			{
				while(h<s[i+1]-s[i-1])
					{
					t[j]=s[i-1]+h; 
					j++;
					h++;
				 }
				 h=1;
				 
			}
			else if(s[i-1]>='A'&&s[i+1]<='Z')
			{
				while(h<s[i+1]-s[i-1])
					{
					t[j]=s[i-1]+h; 
					j++;
					h++;
				 }
				 h=1;
				 
			}
			else 
			{
			t[j]=s[i];j++;
			}
		}
	else	{
	t[j]=s[i];
	j++;
}
	}
	
	puts(t); 
	  
	return 0;
}



