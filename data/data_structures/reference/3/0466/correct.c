#include <stdio.h>
#include <string.h>
#include <ctype.h>



int main()
{
	int i,j,k,r=0;
	char s[1005];
	int p1=0, p2=-1, ans;
	gets(s);
	int l = strlen(s);
	if(l==1&&s[0]=='0')
	{
		printf("0e0");
		return 0;
	}
	for(i = 0; i < l; i++)
	{
		if(s[i] == '.')
			p1 = i;
		else if(p2 == -1 && s[i] != '0')
			p2 = i;
		if(s[i]!='0')
			r = i;
	}
	
	p2 = (p2 >= 0) ? p2 : 0;
	p1 = (p1 == 0) ? l : p1;
	ans = p1-p2;
	if(p2<p1)	
		ans--;
	int flag = 0, pt = 0;
	for(i = 0; i <= r; i++)
	{
		if(isdigit(s[i]) && (s[i]!='0' || flag))
			printf("%c", s[i]), flag = 1;
		if(i == p2 && i!=r)
			printf(".");
	}
	
	printf("e%d", ans);
	
	

	return 0;
} 


