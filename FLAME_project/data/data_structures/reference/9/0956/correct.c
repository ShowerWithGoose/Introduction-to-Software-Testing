 #include<stdio.h>
 #include<string.h>
 #include<math.h>
 #include<stdlib.h>
 #include<ctype.h>
 int f(int,int);
 struct line{
 	int x1;
 	int y1;
 	int x2;
 	int y2;
 }; 
 struct line xian[1000];
 int n,c;
 int main()
 {
 	int i,num,max=0,ans1=0,ans2=0,x,y;
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		scanf("%d %d %d %d",&xian[i].x1,&xian[i].y1,&xian[i].x2,&xian[i].y2);
	 }
	for(i=0;i<n;i++)
	{
		c=1;
		x=xian[i].x2;
		y=xian[i].y2;
		num=f(x,y);
		if(num>max)
		{
			max=num;
			ans1=xian[i].x1;
			ans2=xian[i].y1;
		}
	}
	printf("%d %d %d",max,ans1,ans2);
	return 0;
 }
 int f(int a,int b)
 {
 	int j;
 	for(j=0;j<n;j++)
 	{
 		if(xian[j].x1==a&&xian[j].y1==b)
 		{
 			c++;
 			f(xian[j].x2,xian[j].y2);
 			break;
		 }
	 }
	return c;
 }


