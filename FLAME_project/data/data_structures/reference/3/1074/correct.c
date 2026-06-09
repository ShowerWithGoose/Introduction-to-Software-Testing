#include<stdio.h>
#include<string.h>	
char c[1000];
int main()
{

	char ts[200];
	gets(c);
	int d=strlen(c);
	int flag=0;
	int flag2=0;
	int t=0;
	int t2=0;
	for(int i=0;i<d;i++)
	{
	 flag=i;
	 if(c[i]=='.')
	 break;
	 }
	 int m;
	 for(int i=0;i<d;i++)
	 {
	 if(c[i]!='0'&&c[i]!='.')
	 {m=i;
	 t++;}
	 }
	 
	 if(t==0) printf("0\n");
	 else
	 {
	 	for(int i=0;i<d;i++)
	 	{
	 		if(c[i]!='0'&&c[i]!='.')
	 		{flag2=i;
	 		break;
	 		}
		 }
		int l=flag-flag2;
		if(t==1&&l==1) printf("%c",c[flag2]);
		else if(t==1&&l!=1&&l!=2) {
			if(l<0)
		printf("%ce%d",c[flag2],l);
		else if(l>0)
		printf("%ce%d",c[flag2],l-1);
		}
		else if(t==1&&l==2&&c[flag2]==1) printf("10\n");
		else if(t==1&&l!=1&&c[flag2]!=1) {
			if(l<0)
		printf("%ce%d",c[flag2],l);
		else if(l>0)
		printf("%ce%d",c[flag2],l-1); 
		}
		else if(t!=1)
		
		{  int r=0;
		for(int i=flag2;i<=m;i++)
		{
			if(c[i]!='.')
			{
				ts[r]=c[i];
				r++;
			}
		}
		printf("%c.",c[flag2]);
		for(int i=1;i<r;i++)
		{
			printf("%c",ts[i]);
		}
		{
			if(l<0)
		printf("e%d",l);
		else if(l>0)
		printf("e%d",l-1);
		}
		}
	 }
	 return 0;
	 
	 
	 
	 
	 
	
}



