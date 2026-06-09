/*#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
		
} xd[200],*p,*q;

int main(){
	int n;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d%d",&xd[i].x1,&xd[i].y1,&xd[i].x2,&xd[i].y2);

		int len=0,lenmax=0,flag=-1;
		int a=0;
	for(int i=0;i<n;i++){
		
		p=&xd[i];
		len=0;
					
	A:
		a=0;
		for(int j=0;j<n;j++){
			q=&xd[j];
			if(p->x2==q->x1 && p->y2==q->y1){
				p=q;
				len++;
				a=1;
			}			
		
		if(len>=lenmax) {
			lenmax=len;
			flag=i;
		}
		if(a==1) goto A;	
	}

}
	printf("%d %d %d",flag+1,xd[flag].x1,xd[flag].y1);
		
	return 0;
} */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
int main(){
	int a[105][4];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	int len=0,k,flag;
	int lenmax=0;
	int num;
	int Num;
	for(int i=0;i<n;i++){
		k=i;
		len=0;
		num=1;
		A:
		for(int j=0;j<n;j++){
			if(a[i][2]==a[j][0] && a[i][3]==a[j][1]){
				len++;
				i=j;
				num++;
				goto A;
			}
		}
		i=k;
		if(len>lenmax) {
			lenmax=len;
			flag=i;
			Num=num;
		}
	}
	printf("%d %d %d",Num,a[flag][0],a[flag][1]);
	
	return 0;
} 

