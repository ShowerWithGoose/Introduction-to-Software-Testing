 #include<stdio.h>
 #include<string.h>
 #include<math.h>
 #include<stdlib.h>
 #include<ctype.h>
 int cmp(const void *a,const void *b);
 struct xiang{
 	int xishu;
 	int zhishu;
 };
 int main()
 {
 	struct xiang a[100],b[100],c[1000];
 	int i,j,num1=0,num2=0,k=0;
 	char t;
 	for(i=0;;i++)
 	{
 		scanf("%d %d",&a[i].xishu,&a[i].zhishu);
 		num1++;
 		t=getchar();
 		if(t=='\n')
 		{
 			break;
		 }
	 }
	for(i=0;;i++)
 	{
 		scanf("%d %d",&b[i].xishu,&b[i].zhishu);
 		num2++;
 		t=getchar();
 		if(t=='\n')
 		{
 			break;
		 }
	}
	for(i=0;i<num1;i++)
	{
		for(j=0;j<num2;j++)
		{
			c[k].xishu=a[i].xishu*b[j].xishu;
			c[k].zhishu=a[i].zhishu+b[j].zhishu;
			k++;
		}
	}
 	qsort(c,k,sizeof(c[0]),cmp);
 	for(i=0;i<k;i++)
 	{
 		for(j=i+1;j<k;j++)
 		{
 			if(c[i].zhishu==c[j].zhishu&&c[i].zhishu!=-1)
 			{
 				c[j].xishu=c[j].xishu+c[i].xishu;
 				c[i].zhishu=-1;
			 }
		 }
	 }
 	for(i=0;i<k;i++)
 	{
 		if(c[i].zhishu>=0)
 		printf("%d %d ",c[i].xishu,c[i].zhishu);
	 }
 	return 0;
 }
 int cmp(const void *p1,const void *p2)
{
	struct xiang *a=(struct xiang*)p1;
	struct xiang *b=(struct xiang*)p2;
	return b->zhishu-a->zhishu;
}


