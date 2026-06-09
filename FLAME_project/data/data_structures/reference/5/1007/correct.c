#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct d{
	int xishu;
	int zhishu;
}d1[1000],d2[10000],d[10000];
 
int main()
{
	int i,j=0,k;
	int len1=0,len2=0,temp;
	for(i=0;;i++){
		scanf("%d%d",&d1[i].xishu,&d1[i].zhishu);
		len1++;
		if(getchar()=='\n')
		break;
	}
	for(i=0;;i++){
		scanf("%d%d",&d2[i].xishu,&d2[i].zhishu);
		len2++;
		if(getchar()=='\n')
		break;
	}

	for(i=0,j=0;i<len1;i++){
		for(k=0;k<len2;k++,j++){
			d[j].xishu=d1[i].xishu*d2[k].xishu;
			d[j].zhishu=d1[i].zhishu+d2[k].zhishu;
			
		} 
	}
	int len3=j;
	for(i=0;i<len3;i++){
		for(j=i+1;j<len3;j++){
			if(d[i].zhishu==d[j].zhishu){
				d[i].xishu+=d[j].xishu;
				d[j].xishu=0,d[j].zhishu=0;
			}
			if(d[i].zhishu<d[j].zhishu){
				temp=d[j].xishu;
				d[j].xishu=d[i].xishu;
				d[i].xishu=temp;
				temp=d[j].zhishu;
				d[j].zhishu=d[i].zhishu;
				d[i].zhishu=temp;
				
			}
		}
	}
	for(i=0;d[i].xishu!=0;i++){
		printf("%d %d ",d[i].xishu,d[i].zhishu);
	}	
 	return 0;
}


