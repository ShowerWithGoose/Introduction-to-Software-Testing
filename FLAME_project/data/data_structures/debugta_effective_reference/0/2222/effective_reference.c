#include <stdio.h>
#include <ctype.h>
#include <string.h>
char t[100];
void expand(char s[])
{
	int i,j,k;
	k=0;
for (i=0; s[i]!='\0'; i++)
	{
		for (j=i;s[j]!='-'&&s[j]!='\0';j++,k++)
			t[k]=s[j];
		if((isupper(s[j-1])&&isupper(s[j+1]))||(islower(s[j-1])&&islower(s[j+1]))||(isdigit(s[j-1])&&isdigit(s[j+1])))
			{
				int delta=s[j+1]-s[j-1];
				if (delta<=0)
						;
				else
				{
					for (int l=1; l<=delta; l++)
						{
							t[k++]=s[j-1]+l;
						}
				}
				i=j+1;
			}
		else {
			t[k++]=s[j];
			i=j;
		}		
		

	}
}
int main() {
	char s[100];
	gets(s);
	expand(s);
	puts(t);
	
	return 0;
}


