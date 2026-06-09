 #include<stdio.h>
 #include<string.h>
 #include<math.h>
 #include<stdlib.h>
 #include<ctype.h>
 void F();
 int eva[100000],n,i,j=0,temp,k,flag[100000]; 
 int main()
 {
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		if(i==0)
 		{
 			scanf("%d",&eva[0]);
 			flag[0]=1;
 			j++;
		 }
		else
		{
			scanf("%d",&temp);
			for(k=0;;)
			{
				if(flag[k]==1)
				{
					if(eva[k]>temp)
					{
						k=k*2+1;
					}
					else
					{
						k=k*2+2;
					}
				}
				else
				{
					eva[k]=temp;
					flag[k]=1;
					break;
				}
			}
		}
	 }
	F(0,1);
	return 0; 
 }
 
 void F(int a,int t)
 {
 	if(flag[a*2+1]==0&&flag[a*2+2]==0)
 	{
 		printf("%d %d\n",eva[a],t);
	 }
	else
	{
		if(flag[a*2+1]!=0)
		{
			F(a*2+1,t+1);
		}
		if(flag[a*2+2]!=0)
		{
			F(a*2+2,t+1);
		}
	}
 }

