 #include<stdio.h>
 #include<string.h>

 int main()
 {
 	char s[100];
 	gets(s);
 	int n=strlen(s);
 	int q=0,i=0,p=0;
	while(s[i]!='.')
	{
		q++;
		i++;
	}
	 if(q>1)
	 {
	 	printf("%c.",s[0]);
	 for(int i=1;i<n;i++)
	 {
	 	if(s[i]!='.')
	 	{
	 	printf("%c",s[i]);	
		}
	 }
	 	printf("e");
	 	printf("%d",q-1);
	 }
	 else if(q==1&&s[0]!='0')
	 {
	 	printf("%s",s);
	 	printf("e0");
	 }

	 else
	 for(int i=2;i<n;i++)
	 {
	 	if(s[i]=='0')
	 	{
	 	p++;	
		}
		else
		{
			if(i==n-1)
			printf("%c",s[p+2]);
			else
				printf("%c.",s[p+2]);
		printf("%s",s+p+3);
		printf("e-%d",p+1);
		break;
		}
	 }
	 return 0;
	 
}
