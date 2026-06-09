/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
struct pol{
	int num;
	int pow;
}fir[200],sec[200],con[400];
int main(){
	int i=0,j=0,q=0;
	char c;
	while(1){
		scanf("%d%d",&fir[i].num,&fir[i].pow);
		i++;
		scanf("%c",&c);
		if(c=='\n')
		break;
	}
	while(1){
		scanf("%d%d",&sec[j].num,&sec[j].pow);
		j++;
		scanf("%c",&c);
		if(c=='\n')
		break;
	}
	for(int k=0;k<i;k++){
		for(int p=0;p<j;p++){
			con[q].num=fir[k].num*sec[p].num;
			con[q].pow=fir[k].pow+sec[p].pow;
			q++;
		}
	}
	for(int k=0;k<q;k++){
		for(int p=k+1;p<q;p++){
			if(con[k].pow<con[p].pow){
				fir[0]=con[k];
				con[k]=con[p];
				con[p]=fir[0];
			}
			else if(con[k].pow==con[p].pow){
				con[k].num=con[k].num+con[p].num;
				con[p].num=0;
			}
		}
	}
	for(int k=0;k<q;k++){
		if(con[k].num!=0)
		printf("%d %d ",con[k].num,con[k].pow);
	}
	return 0;
}

