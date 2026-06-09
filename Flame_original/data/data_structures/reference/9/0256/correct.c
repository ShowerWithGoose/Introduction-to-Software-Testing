#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct line{
	int x1;
	int x2;
	int y1;
	int y2;
	int xuhao;
};
int num[105];
int k[105];
struct line in[105];
int n;
int fanhui=1;
int bijiao(int m[105]){
	int max=m[0];
	in[0].xuhao=0;
	for(int i=1;i<105;i++){
		if(m[i]>m[i-1]){
			max=m[i];
			in[i].xuhao=i;
		}
		else m[i]=m[i-1];
		max=m[i];
	}
	return max;
}
int duanshu(int a2,int b2){
	for(int j=0;j<n;j++){
	for(int i=0;i<n;i++){
		if(a2==in[i].x1&&b2==in[i].y1){
			a2=in[i].x2;
			b2=in[i].y2;
			fanhui++;
			break;
		}
	}
	}
	//duanshu(a1,b1,a2,b2);
	return fanhui;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&in[i].x1,&in[i].y1,&in[i].x2,&in[i].y2);
	}
	num[0]=duanshu(in[0].x2,in[0].y2);
	k[0]=num[0];
	//in[0].xuhao=1;
	for(int j=1;j<n;j++){
		fanhui=1;
		num[j]=duanshu(in[j].x2,in[j].y2);
		k[j]=num[j];
	}
	int kmax;
	kmax=bijiao(k);
	for(int i=0;i<105;i++){
		if(k[i]==kmax){
	printf("%d",kmax);
	printf(" %d %d",in[i].x1,in[i].y1);
	break;
	}
	}
    return 0;
}



