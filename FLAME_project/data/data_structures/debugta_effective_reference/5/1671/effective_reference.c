#include<stdio.h>
struct result{
	int xs;
	int ms;
};
int main(){
	int a[1000],b[1000],c[1000],d[1000],i,j,m,n,x,y,z,k,flag;
	char ch;
	struct result e[100];
	e[1].xs=0;e[1].ms=0;
	for(i=2;i<=999;i++) e[i]=e[1];
	i=1;
	b[0]=1;
	while(1) {
		scanf("%d%d",&a[i],&b[i]);
		i++;
		scanf("%c",&ch);
		if(ch=='\n') break;	
	}
	j=1;
	d[0]=1;
	while(scanf("%d%d",&c[j],&d[j])!=EOF) {
		j++;
	}
	j--;
	z=0;
	for(m=1;m<=i;m++)
		for(n=1;n<=j;n++){
			flag=0;
			x=a[m]*c[n];
			y=b[m]+d[n];
			for(k=1;k<=z;k++) if(e[k].ms==y) {
				flag=1;
				e[k].xs=e[k].xs+x;
				break;
			}
			if(flag==0) {
				z++;
				e[z].ms=y;
				e[z].xs=x;
			}
		}
	for(i=1;i<z;i++)
		for(j=1;j<=z-i;j++)
			if(e[j].ms<e[j+1].ms){
				e[0]=e[j];
				e[j]=e[j+1];
				e[j+1]=e[0];
			}
	for(i=1;i<=z;i++) if(e[i].xs!=0) printf("%d %d ",e[i].xs,e[i].ms);
	return 0;
}

