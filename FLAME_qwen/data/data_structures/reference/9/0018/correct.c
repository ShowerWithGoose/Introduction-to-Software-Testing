#include<stdio.h>
#include<stdlib.h>
int num;
typedef struct OK{
	int x1;
	int y1;
	int x2;
	int y2;
} locate ,*locatep;

int main(){
	scanf("%d",&num);
	int i,j,k,qtt[BUFSIZ],m=0,nb=0;locate pnt[BUFSIZ],mid[BUFSIZ];
	for(i=0;i<num;i++){
		scanf("%d%d%d%d",&pnt[i].x1,&pnt[i].y1,&pnt[i].x2,&pnt[i].y2);
	}
	//printf("%d",pnt[i-1].x1);
	k=0;
	for(i=0;i<num;i++){

		{
			mid[k].x1=pnt[i].x1;
			mid[k].y1=pnt[i].y1;
			mid[k].x2=pnt[i].x2;
			mid[k].y2=pnt[i].y2;
		
			k++;
		}
	} 



	for(i=0;i<k;i++){
		qtt[i]=1;
		for(j=0;j<num;j++){
			if (mid[i].x2==pnt[j].x1&&mid[i].y2==pnt[j].y1){
				mid[i].x2=pnt[j].x2;
				mid[i].y2=pnt[j].y2;
				qtt[i]++;
				j=-1;
			}
		}
	}





	for(i=0;i<k;i++){
		if(m<qtt[i]){
			m=qtt[i];
			nb=i;
		}
	}
	printf("%d %d %d\n", qtt[nb],mid[nb].x1,mid[nb].y1);




	return 0;
}

