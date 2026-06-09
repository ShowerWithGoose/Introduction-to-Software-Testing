#include<stdio.h>
int main(){
	int m=0,n=0,i=0,j=0;
	int k=0;

	struct aa{
		int xi;
		int zhi;
	};
	struct aa a1[300],a2[300],a3[500];
	for(i=0;i<100;i++){
		a1[i].xi=0;
		a1[i].zhi=0;
		a2[i].xi=0;
		a2[i].zhi=0;
	}
i=0;
char line1[10000],line2[10000];
gets(line1);
gets(line2);
//puts(line1);
//puts(line2);
//////////×Ö·û´®×ªÊý×Ö 
while(line1[k]!='\0'){
	while(line1[k]!=' '){
		a1[i].xi=a1[i].xi*10+line1[k]-'0';
		k++;
	}
	k++;
	while(line1[k]!=' '&&line1[k]!='\0'){
		a1[i].zhi=a1[i].zhi*10+line1[k]-'0';
		k++;
	} 
	k++;
	i++;
}
int cnt1=i;
k=0;i=0;
while(line2[k]!='\0'){
	while(line2[k]!=' '){
		a2[i].xi=a2[i].xi*10+line2[k]-'0';
		k++;
	}
	k++;
	while(line2[k]!=' '&&line2[k]!='\0'){
		a2[i].zhi=a2[i].zhi*10+line2[k]-'0';
		k++;
	} 
	k++;
	i++;
}
int flag=0;
int cnt2=i;
int cnt=0;
int temp=0;
////////////////////////////////////////////////////³Ë 
for(i=0;i<cnt1;i++){
	for(j=0;j<cnt2;j++){
		temp=a1[i].zhi+a2[j].zhi;
		for(k=0;k<cnt+1;k++){
			if(a3[k].zhi==temp){
				a3[k].xi+=(a1[i].xi*a2[j].xi);flag=1;
			}
		}
		if(flag==1){
			flag=0;
			continue;
		}
		a3[cnt].zhi=a1[i].zhi+a2[j].zhi;
		a3[cnt].xi=a1[i].xi*a2[j].xi;
		cnt++;
	}
} 
///////////////////////////Ã°ÅÝ 
struct aa *p1[100],*p2;
for(i=0;i<=cnt;i++){
	p1[i]=&a3[i];
}
for(i=0;i<cnt+1;i++){
	for(j=0;j<cnt-i;j++){
		if((p1[j]->zhi)>p1[j+1]->zhi){
			p2=p1[j];
			p1[j]=p1[j+1];
			p1[j+1]=p2;
		}
	}	
}
	for(i=cnt;i>=0;i--){
		if((p1[i]->xi)==0)break;
		printf("%d %d ",p1[i]->xi,p1[i]->zhi);
}
	return 0;
} 


