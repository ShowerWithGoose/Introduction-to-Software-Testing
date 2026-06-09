#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct f{
	int num;
	int deg;
	
	
}a[150000],b[150000],c[150000],d[150000]; 
int main()
{
int i,j,k;
int sum1=0,sum2=0;
char op;
op=' ';
while(op!='\n'){
	scanf("%d%d%c",&a[sum1].num,&a[sum1].deg,&op);
	sum1++;
}
op=' ';
while(op!='\n'){
	scanf("%d%d%c",&b[sum2].num,&b[sum2].deg,&op);
	sum2++;
}
int q,w;				

k=0;
for(i=0;i<sum1;i++){
	for(j=0;j<sum2;j++){
	
	c[k].deg=a[i].deg+b[j].deg;
	c[k].num=a[i].num*b[j].num;
	k++;
	}
} 
c[k].deg=10000;
 q=0;
 w=0; 
  for(q=0;q<k;q++){ 
for(w=q+1;w<k;w++){ 
if(	c[w].deg>c[q].deg){ 
c[150000]=c[w]; 
c[w]=c[q]; 
c[q]=c[150000]; 
} 
} 
 }
i=0;
j=0;
for(i=0;i<k;i++){
	if(c[i].deg==c[i+1].deg){ 
		c[i+1].num=c[i].num+c[i+1].num;
		for(j=i;j<k;j++){
			c[j]=c[j+1];
		}
			i--;
	k--;
	}

}
int x,y,z;
for(x=0;x<k;x++){
	printf("%d %d ",c[x].num,c[x].deg);
}
return 0;
}





