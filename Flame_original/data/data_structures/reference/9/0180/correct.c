#include <stdio.h>
struct LINE{
	int x1;int y1;int x2;int y2;int link;int count;
};
int main(){
int n;scanf("%d",&n);
struct LINE line[120];
int i,j;
for(i=0;i<n;i++) {
scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
line[i].link=i;line[i].count=0;}
for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1)	
		{line[i].count++;line[i].link=j;
		}
	}
}	
for(i=0;i<n;i++){
if(line[i].count){
	int link=line[i].link;
while(line[link].count)	
	{   line[i].count++;
		link=line[link].link;	
	}
}	
}
int max=0;int m=0;
for(i=0;i<n;i++){
	if(max<line[i].count) {
		m=i;max=line[i].count;
	}
}	
printf("%d %d %d",line[m].count+1,line[m].x1,line[m].y1);
	return 0;
} 

