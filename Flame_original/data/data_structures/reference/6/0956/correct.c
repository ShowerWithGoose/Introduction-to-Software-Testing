 #include<stdio.h>
 #include<string.h>
 #include<math.h>
 #include<stdlib.h>
 #include<ctype.h>
 int main()
 {
 	int i,flag=0,a[100];
	while(scanf("%d",&i)!=EOF)
	{
		if(i==1)
		{
			scanf("%d",&i);
			a[flag]=i;
			flag++;
		}
		else if(i==0)
		{
			flag--;
			if(flag!=-1)
			{
				printf("%d ",a[flag]);
			}
			else
			{
				printf("error ");
				flag=0;
			}
		}
		else
		{
			return 0;
		}
	}
 }

