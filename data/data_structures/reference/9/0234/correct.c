#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int main(){
	int n,m=1;	
	int k; 
	int x1[50],x2[50],y1[50],y2[50],num[50],sx[50],sy[50],ex[50],ey[50];
	scanf("%d ",&n);
	//printf("%d\n",n);
	int i=0,j=0;
	scanf("%d %d %d %d ",&x1[i],&y1[i],&x2[i],&y2[i]);
	//printf("%d:%d %d %d %d \n",i,x1[i],y1[i],x2[i],y2[i]);
	sx[0]=x1[0];
	ex[0]=x2[0];
	sy[0]=y1[0];
	ey[0]=y2[0];
	//printf("                          line%d:%d %d %d %d     num%d=%d\n",j,sx[j],sy[j],ex[j],ey[j],j,num[j]);
	int flag=0,flag2=0;
	for(i=0;i<50;i++)
	{
		num[i]=1;
	}
	int t;	
	for(i=1;i<n;i++)
	{
		flag=0;
		scanf("%d %d %d %d ",&x1[i],&y1[i],&x2[i],&y2[i]);
		//printf("%d:%d %d %d %d \n",i,x1[i],y1[i],x2[i],y2[i]);
		for(j=0;j<m;j++)
		{
			if(flag==1) break;//单一线段最多加在一根直线上 
			if(x1[i]==ex[j]&&y1[i]==ey[j])
			{
				ey[j]=y2[i];
				ex[j]=x2[i];
				num[j]++;
				//printf("                          line%d:%d %d %d %d     num%d=%d\n",j,sx[j],sy[j],ex[j],ey[j],j,num[j]);
				
				flag=1;
				
			}
			if(x2[i]==sx[j]&&y2[i]==sy[j])
			{
				sy[j]=y1[i];
				sx[j]=x1[i];
				num[j]++;
				//printf("                          line%d:%d %d %d %d     num%d=%d\n",j,sx[j],sy[j],ex[j],ey[j],j,num[j]);
				
				flag=1;
				
			}
			
			/*if(x2[i]==ex[j]&&y2[i]==ey[j])
			{
				ey[j]=y1[i]>sy[i]?y1[i]:sy[i];
				sy[j]=y1[i]<sy[i]?y1[i]:sy[i];
				ex[j]=x1[i]>sx[i]?x1[i]:sx[i];
				sx[j]=x1[i]<sx[i]?x1[i]:sx[i];
				num[j]++;
				flag=1;
			}
			if(x1[i]==sx[j]&&y1[i]==sy[j])
			{
				ey[j]=y2[i]>ey[i]?y2[i]:ey[i];
				sy[j]=y2[i]<ey[i]?y2[i]:ey[i];
				ex[j]=x2[i]>ex[i]?x2[i]:ex[i];
				sx[j]=x2[i]<ex[i]?x2[i]:ex[i];
				num[j]++;
				flag=1;
			}	
			*/		
		}
		if(flag==0)
		{
			sx[m]=x1[i];
			ex[m]=x2[i];
			sy[m]=y1[i];
			ey[m]=y2[i];
			//printf("                          line%d:%d %d %d %d \n",m,sx[m],sy[m],ex[m],ey[m]);
			m+=1;//序号=数量-1 
		}
		do{
			flag2=0;
			for(j=0;j<m;j++)
			{
				for(k=0;k<m;k++)
				{	
					if(sx[k]==ex[j]&&sy[k]==ey[j]&&k!=j)
					{
						num[j]=num[k]+num[j];
						ex[j]=ex[k];
						ey[j]=ey[k];
						ex[k]=-t;sx[k]=-t;sy[k]=-t;ey[k]=-t;num[k]=-t;
						t++;
						flag2=1;
						//printf("                          line%d:%d %d %d %d     num%d=%d\n",j,sx[j],sy[j],ex[j],ey[j],j,num[j]);
					}
					else
					{
						/*if(ex[k]==ex[j]&&ey[k]==ey[j]&&k!=j)
						{
							num[j]=num[k]+num[j];
							if(sx[j]<sx[k])
							{
								ex[j]=sx[k];
								ey[j]=sy[k];
							}
							ex[k]=-t;sx[k]=-t;sy[k]=-t;ey[k]=-t;num[k]=-t;
							t++;
							flag2=1;
						}
						if(sx[k]==sx[j]&&sy[k]==sy[j]&&k!=j)
						{
							num[j]=num[k]+num[j];
							sx[j]=ex[j]<ex[k]?ex[j]:ex[k];
							ex[j]=ex[j]>ex[k]?ex[j]:ex[k];
							ey[j]=ey[j]>ey[k]?ey[j]:ey[k];
							sy[j]=ey[j]>ey[k]?ey[j]:ey[k];
							ex[k]=-t;sx[k]=-t;sy[k]=-t;ey[k]=-t;num[k]=-t;
							t++;
							flag2=1;
						}*/ 
					}
				}
			}
		}while(flag2==1);
	}
	
	int max=0,mark=-2;
	for(j=0;j<m;j++)
	{
		//printf("num[%d]=%d\n",j,num[j]);
		if(num[j]>max) 
		{
			max=num[j];
			//printf("max=%d\n",max);
			mark=j;			
		}

		//printf("mark=%d\n",mark);
	}
	//printf("mark=%d\n",mark);
	printf("%d %d %d",max,sx[mark],sy[mark]);
	return 0;
}

