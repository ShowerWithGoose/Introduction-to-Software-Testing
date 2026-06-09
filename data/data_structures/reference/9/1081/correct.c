#include <stdio.h>
typedef struct{
	 int x1;
	 int y1;
	 int x2;
	 int y2;
}  line;
line a[101];
int n;
int len_max=0;
int sx,sy;
int hash[101];
void dfs(int len,int now,int start_x,int start_y,int side)
{    len++;
	 if(len>len_max||(len==len_max&&start_x<sx))  
	 {
	 	 len_max=len;
	 	 sx=start_x;
	 	 sy=start_y;
	 }
	 int i;
	 for(i=1;i<=n;i++)
	 {
	 	  if(!hash[i])
	 	  {
	 	  	    if(side==1) 
	 	  	    {
	 	  	    	 if(a[now].x2==a[i].x1&&a[now].y2==a[i].y1)
	 	  	    	 {
	 	  	    	 	 hash[i]++;
	 	  	    	 	 dfs(len,i,start_x,start_y,1);
	 	  	    	 	 hash[i]--;
						}
				else	 if(a[now].x2==a[i].x2&&a[now].y2==a[i].y2)
					 {
					 	  hash[i]++;
					 	  dfs(len,i,start_x,start_y,2);
					 	  hash[i]--;
					 }
				   }
				if(side==2)
				{
					   if(a[now].x1==a[i].x1&&a[now].y1==a[i].y1)
					   {
					   	 hash[i]++;
					   	 dfs(len,i,start_x,start_y,1);
					   	 hash[i]--;
					   }
					   else if(a[now].x1==a[i].x2&&a[now].y1==a[i].y2)
					   {
					   	  hash[i]++;
					   	  dfs(len,i,start_x,start_y,2);
					   	  hash[i]--;
					   }
				}
		   }
	 }
}
int main()
{
	 scanf("%d",&n);
	 int i;
	 for(i=1;i<=n;i++)
	 {
	 	 scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	 }
	 for(i=1;i<=n;i++)
	 {   
	     hash[i]++;
	 	 dfs(0,i,a[i].x1,a[i].y1,1);
	 	 dfs(0,i,a[i].x2,a[i].y2,2);
	 	 hash[i]--;
	 }
	 printf("%d %d %d",len_max,sx,sy);
}



