#include<stdio.h>
struct line{
	int x[10],y[10];
	int len;
};
int main(){
	int i,n,x1[200]={},x2[200]={},y1[200]={},y2[200]={},cnt1=0,j,f=0;
	int max,maxl=0;
	struct line l[100];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		l[i].len=0;
	}
	for(i=1;i<=n;i++){
		f=0;
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
		if(i==1){
			l[1].len++;
			l[1].x[1]=x1[i];
			l[1].x[2]=x2[i];
			l[1].y[1]=y1[i];
			l[1].y[2]=y2[i];
			cnt1++;
		}
		else if(i>1){
			for(j=1;j<=cnt1;j++){
				if((x1[i]==l[j].x[2])&&(y1[i]==l[j].y[2])){
					l[j].x[2]=x2[i];
					l[j].y[2]=y2[i];
					l[j].len++;
					f=1;
					break;
				}
				else if((x2[i]==l[j].x[1])&&(y2[i]==l[j].y[1])){
					l[j].x[1]=x1[i];
					l[j].y[1]=y1[i];
					l[j].len++;
					f=1;
					break;
				}
			}
			    if(f==0){
				cnt1++;
				l[cnt1].len++;
				l[cnt1].x[1]=x1[i];
				l[cnt1].x[2]=x2[i];
				l[cnt1].y[1]=y1[i];
				l[cnt1].y[2]=y2[i];
			}
		}
	}
	for(i=1;i<=cnt1;i++){
		for(j=1;j<=i;j++){
			if((l[i].x[1]==l[j].x[2])&&(l[i].y[1]==l[j].y[2])){
				l[i].x[1]=l[j].x[1],l[i].y[1]=l[j].y[1];
				l[i].len=l[i].len+l[j].len;
				i--;
				break;
			}
			else if((l[i].x[2]==l[j].x[1])&&(l[i].y[2]==l[j].y[1])){
				l[i].x[2]=l[j].x[2],l[i].y[2]=l[j].y[2];
				l[i].len=l[i].len+l[j].len;
				i--;
				break;
			}
		}
	}
	for(i=1;i<=cnt1;i++){
		if(l[i].len>maxl){
			maxl=l[i].len;
			max=i;
		}
	}
	printf("%d %d %d",l[max].len,l[max].x[1],l[max].y[1]);
	return 0;
	
}

