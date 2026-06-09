
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include <stdio.h>
int main(){
struct lenz{
	int x1,y1,x2,y2;
	char toge1[10];
	char toge2[10];
    int toe1;
	int toe2;
};
struct lenz lenzer[500];
struct conlen{
	int x1,y1,x2,y2;
	int num;
};
struct conlen conzer[120];
int n;
scanf("%d",&n);
int i=0,j=0;
for(i=0;i<n;i++){
scanf("%d%d%d%d",&lenzer[i].x1,&lenzer[i].y1,&lenzer[i].x2,&lenzer[i].y2);
lenzer[i].toe1=0;
lenzer[i].toe2=0;
}
for(i=0;i<n-1;i++){
	for(j=i+1;j<n;j++){
		if(lenzer[i].x1==lenzer[j].x2&&lenzer[i].y1==lenzer[j].y2){
			sprintf(lenzer[i].toge1,"%d+%d",i,j);
			sprintf(lenzer[j].toge2,"%d+%d",i,j);
			lenzer[i].toe1=1;
			lenzer[j].toe2=1;
		}
		if(lenzer[i].x2==lenzer[j].x1&&lenzer[i].y2==lenzer[j].y1){
			sprintf(lenzer[i].toge2,"%d+%d",i,j);
			sprintf(lenzer[j].toge1,"%d+%d",i,j);
			lenzer[i].toe2=1;
			lenzer[j].toe1=1;
		}
	}
}

for(j=0;j<120;j++){
	conzer[j].num=1;
}
j=0;
int start=0;
int end=0;
int poin=0;
int mark=0;
for(i=0;i<n;i++){
   if(lenzer[i].toe1==0){
   	conzer[j].x1=lenzer[i].x1;
   	conzer[j].y1=lenzer[i].y1;
   }
   if(lenzer[i].toe1!=0){
   	mark=i;
   	do{
   		sscanf(lenzer[mark].toge1,"%d+%d",&start,&end);
   		poin=start+end-mark;
   		if(lenzer[poin].toe1==0){
   			conzer[j].x1=lenzer[poin].x1;
   	        conzer[j].y1=lenzer[poin].y1;
		   }
		   mark=poin;
   		conzer[j].num+=1;
	   }while(lenzer[mark].toe1!=0);
   }
   if(lenzer[i].toe2==0){
   	j++;
   }
   if(lenzer[i].toe2!=0){
   	mark=i;
   	do{
   		sscanf(lenzer[mark].toge2,"%d+%d",&start,&end);
   		poin=start+end-mark;
   		if(lenzer[poin].toe2==0){
   			conzer[j].num+=1;
   	        j++;
		   }
		   mark=poin;
	   }while(lenzer[mark].toe2!=0);
}
}
int note=0;
int max=conzer[0].num;
for(j=1;j<120;j++){
	if(max<conzer[j].num){
		max=conzer[j].num;
		note=j;
	}
}
printf("%d %d %d",max,conzer[note].x1,conzer[note].y1);
return 0;
}


