#include<stdio.h>
#include<string.h>
struct duo
	{                                                               
		int an;
		int xn;
		struct duo *link;
	}duo ;
struct duo a[100];	
struct duo b[100];
struct duo cu[1000];

	int main(){
	char c,d;
	long long temp,temp2;
	int  x;
	long long p,q;
	int l=0;
	int sum1=0,sum2=0;
	int i,j;
	scanf("%d%d%c",&a[sum1].an,&a[sum1].xn,&c);
	sum1++;
		while(c!='\n')
		{
			scanf("%d%d%c",&a[sum1].an,&a[sum1].xn,&c);
			sum1++;
		}
		scanf("%d%d%c",&b[sum2].an,&b[sum2].xn,&d);
	sum2++;
		while(d!='\n')
		{
			scanf("%d%d%c",&b[sum2].an,&b[sum2].xn,&d);
			sum2++;
		}
		
		for(i=0;i<sum1;i++)
		{
			for(j=0;j<sum2;j++)
			{
			
				
				p=a[i].an*b[j].an;
				q=a[i].xn+b[j].xn;
				if(l==0)
				{
					cu[l].an=p;
					cu[l].xn=q;
					l++;
				}
				else
				{
					int flag=0;
				 for(x=0;x<l;x++)
				 {
				 	if(cu[x].xn==q)
				{
					flag=1;
					break;
				}
						
				 	
				 }
				 if(flag==0)
				 {
				 	cu[l].an=p;
					cu[l].xn=q;
					l++;
				 }
				 else
				 {
				 	cu[x].an+=p; 
				 }
				}
			}	
		}

   for(i=0;i<l-1;i++)
    {
    for(j=0;j<l-1-i;j++){
	
    	if(cu[j].xn < cu[j+1].xn)
    	{
    		temp=cu[j].an;
    		temp2=cu[j].xn;
    		cu[j].an=cu[j+1].an;cu[j].xn=cu[j+1].xn;
    		cu[j+1].an=temp;cu[j+1].xn=temp2;
		}
	
	}
}
		for(i=0;i<l;i++)
			{
			printf("%d %d ",cu[i].an,cu[i].xn); 
    }
}

