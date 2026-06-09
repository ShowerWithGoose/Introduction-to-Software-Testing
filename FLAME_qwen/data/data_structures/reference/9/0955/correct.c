#include<stdio.h>
int main(){
	struct keys{
		int x1;
		int y1;
		int x2;
		int y2;
	};
	struct keys key[105];
	struct keys temp;
	int flag[105][105]={0};
	int n,t=0,f=0,max=0,fl;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d%d%d%d",&key[i].x1,&key[i].y1,&key[i].x2,&key[i].y2);
	for(int i=0;i<n;i++)
	    for(int j=i+1;j<n;j++){
	    	if(key[i].x1>key[j].x1){
	    		temp=key[i];
	    		key[i]=key[j];
	    		key[j]=temp;
			}
		}
	for(int i=0;i<n;i++){
		t=i;
		flag[f][1]=key[t].x1;
		flag[f][2]=key[t].y1;
	   for(int j=t+1;j<n;j++){
	   	if(key[t].x2==key[j].x1&&key[t].y2==key[j].y1){
	   		t=j;
	   		flag[f][0]++;
		   }
	   }
	   f++;}
	for(int i=0;i<n;i++){
		if(flag[i][0]>max){
		max=flag[i][0];
		fl=i;}
	}
	printf("%d %d %d",flag[fl][0]+1,flag[fl][1],flag[fl][2]);
	return 0;
} 

