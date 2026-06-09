#include<stdio.h>
#include<string.h>
int right(char a,char b)
{
	if(a>='a'&&b<='z'&&b>a) return 1;
	if(a>='A'&&b<='Z'&&b>a) return 1;
	if(a>='0'&&b<='9'&&b>a) return 1;
	return 0;
}
int main()
 {
    char str[1005],fin[1005];
    gets(str);
    int s=strlen(str),i,j;
    for(i=0,j=0;i<s;i++)
	{  
		if(str[i]=='-'&&right(str[i-1],str[i+1]))
		{
			int l=str[i+1]-str[i-1]-1;
			for(int num=1;num<=l;num++)
			{
				fin[j++]=str[i-1]+num;
			}
		}
    	else fin[j++]=str[i];
	}
    for(int h=0;h<=strlen(fin);h++) printf("%c",fin[h]);
	return 0;
}




