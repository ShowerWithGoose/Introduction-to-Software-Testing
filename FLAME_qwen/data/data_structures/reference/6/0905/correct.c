#include<stdio.h>
int main()
{	
	int zhan[100];
	int top=-1;
	int type,item;
	int flag[100]={0};
	int i=0,len;
	int Item[100]={0};
	int mark;
	scanf("%d",&type);
	mark=type;
	while(1)
	{	
		if(type==1){
			scanf("%d",&item);
			if(top==99){
			flag[i]=i;
			i++;}
			else{
				top++;
				zhan[top]=item;
				i++;
				//printf("%d ok  flag[%d]=%d\n",i,i,flag[i]);
			}
		//	printf("flag[%d]=%d\n",i,flag[i]);
		}
		else if(type==0)
		{	
			if(top!=-1)
			{
				
				Item[i]=zhan[top];
				top--;
				i++;
				//printf("%d ok  flag[%d]=%d\n",i,i,flag[i]);
			}else {
			flag[i]=i;
			i++;}
		//	printf("flag[%d]=%d\n",i,flag[i]);
		}
		else break;
		scanf("%d",&type);
	}
	 len=i;
	//for(i=0;i<len;i++)printf("flag[%d] =%d\n ",i,flag[i]);
	 //printf("\n");
	for(i=0;i<len;i++) 
	{
		if(Item[i]!=0)printf("%d ",Item[i]);
		if(flag[i]==i&&i!=0)printf("error ");
		if(mark==0)printf("error");
	}
	return 0;
}

