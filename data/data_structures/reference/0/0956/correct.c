 #include<stdio.h>
 #include<string.h>
 #include<math.h>
 #include<stdlib.h>
 #include<ctype.h>
 char s[10000],c[10000];
 int location[10000];
 int main()
 {
 	int i,num,k,t;
 	scanf("%s",s);
	for(i=0,k=0;i<strlen(s);i++,k++)
	{
		if(s[i+1]!='-')
		c[k]=s[i];
		else
		{
			if((('a'<=s[i]&&s[i]<'z'&&'a'<s[i+2]&&s[i+2]<='z')||('0'<=s[i]&&s[i]<'9'&&'0'<s[i+2]&&s[i+2]<='9')||('A'<=s[i]&&s[i]<'Z'&&'A'<s[i+2]&&s[i+2]<='Z'))&&s[i]<s[i+2])
			{
				num=s[i+2]-s[i];
				c[k]=s[i];
				 for(t=1;t<num;t++)
				 {
				 	c[k+t]=s[i]+t;
				 }
				 c[k+num]=s[i+2];
				 k=k+num-1;
				 i++;
			}
			else
			{
				c[k]=s[i];
			}
		}
	}
	c[k]='\0';
	printf("%s",c);
	return 0;
 }

 

