#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
int a[100];
int top=-1,i=0;

int flag=0,tmp;
int ttp[100],ans[100],j=0;
int main(){
	 for(int i=0;i<100;i++)
	 {
	 	scanf("%d",&ttp[i]);
	 	//printf("%d ",ttp[i]);
	 	flag=i;
	 	if(ttp[i]==-1)break;
	 }
	 for(int i=0;i<flag;i++)
	 {
	 	 	if(ttp[i]==1)
		 	{
		 		if(top>=100)continue;
		 		a[++top]=ttp[++i];
		 		//printf("a[%d]=%d\n",j,a[top]);
		 	}	
		 		else if(ttp[i]==0)
		 		{
		 		//printf("a[%d]=%d\n",j,a[top]);	
		 		top--;
		 		//printf("top=%d\n",top);
		 		if(top>=-1){
		 		
		 		ans[j]=a[top+1];
		 		//printf("ans[%d]=%d\n",j,ans[j]);
		 		//printf("j=%d\n",j);
		 		j++;
		 		}
		 		else if(top<-1){top=-1;ans[j]=1;j++;}
		 		}
		 		 	
	 }
	
	 for(int k=0;k<j;k++)
	 {
	 	if(ans[k]==1){printf("error ");}
	 	else printf("%d ",ans[k]);
	 }

return 0;
}

