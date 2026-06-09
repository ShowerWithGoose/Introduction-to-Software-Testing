#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
int x[4][200]={0};
int y[200]={0};
int z,q1,q2,q3,q4,op,j,min,i=1,n,c1,c2,k1,k2,k3,max1,max2,max3=1;
scanf("%d",&n);
getchar();
for(i=1;i<=n;i++)
 {
 scanf("%d",&x[0][i]);
 scanf("%d",&x[1][i]);
 scanf("%d",&x[2][i]);
 scanf("%d",&x[3][i]);	
 }
i=1;
min=x[0][1];
for(i=1;i<=n;i++)
 {
 op=i;
 min=x[0][i];	
 j=i;	
 for(j=i;j<=n;j++)
  {
  if(x[0][j]<min)  	
   {
   min=x[0][j];
   op=j;   	
   }		
  }
 q1=x[0][i];q2=x[1][i];q3=x[2][i];q4=x[3][i];
 x[0][i]=x[0][op];x[1][i]=x[1][op];x[2][i]=x[2][op];x[3][i]=x[3][op]; 	
 x[0][op]=q1;x[1][op]=q2;x[2][op]=q3;x[3][op]=q4;
 }
i=1;
for(i=1;i<=n;i++) 
 {
 if(y[i]==0)
  {
  z=i; 
  y[i]=1;	
  k3=1;	
  j=i;
  for(j=j;j<=n;j++)	
   {
   if(y[j]==0&&x[2][z]==x[0][j]&&x[3][z]==x[1][j])  	
    {
    k3++;
	y[j]=1;
	z=j;  	
    }		
   }
  if(k3>=max3)
   {
   max3=k3;	
   max1=x[0][i];
   max2=x[1][i]; 	
   } 	
  }
 }
printf("%d %d %d",max3,max1,max2); 
return 0; 
}




