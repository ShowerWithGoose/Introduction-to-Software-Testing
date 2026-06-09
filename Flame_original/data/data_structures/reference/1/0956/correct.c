 #include<stdio.h>
 #include<string.h>
 #include<math.h>
 #include<stdlib.h>
 #include<ctype.h>
 void track(int);
 void pop(int);
 int k,n,i,t=0,ans[9],num[10]={1,2,3,4,5,6,7,8,9,10},ins,op=0,zer;
 int main()
 {
	 scanf("%d",&n);
	  track(t);
	  return 0;
 }
 void track(int t)
 {
 	if(t>=n)
 	{
 		for(k=0;k<n;k++)
 		{
 			printf("%d ",ans[k]);
		 }
		 	printf("\n");
	 }
	else
	{
		for(i=0;i<n;i++)
		{
			if(num[i]!=0)
			{
				ins=num[i];
				num[i]=0;
				ans[t]=ins;
				break;
			}
		}
		if(ans[t]==ans[t-1]||ans[t]==ans[t-2]||ans[t]==ans[t-3])
		return ; 
		track(t+1);
		pop(t); 
	}
	return ;
 }
 void pop(int t)
 {
 	op=0;
 	for(i=ans[t];i<n;i++)
 	{
 		if(num[i]!=0)
 		{
 			zer=num[i];
 			num[i]=0;
 			num[ans[t]-1]=ans[t];
 			ans[t]=zer;
 			if(ans[t]==ans[t-1]||ans[t]==ans[t-2]||ans[t]==ans[t-3])
 			return ;
 			track(t+1);
		 }
		 else
		 {
		 	op++;
		 }
	 }
	if(op==n-ans[t])
	{
		num[ans[t]-1]=ans[t];
		if(t==0)
		return ;
		pop(t-1);
	}
	return ;
 }


