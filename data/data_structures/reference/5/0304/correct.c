#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	int a;
	int n;
	int q;
}ele;
int input(ele *a,char *a1){
	int i,temp=0,k=0,flag=0;
	for(i=0;i<strlen(a1);i++){
		if(a1[i]==' '){
			if(flag==0){
				a[k].a=temp;
				flag=1;
				temp=0;
			}
			else{
				a[k].n=temp;
				a[k].q=1;
				k++;
				flag=0;
				temp=0;
			}
		}
		else{
			temp=temp*10+a1[i]-'0';
		}
	}
	a[k].n=temp;
	a[k].q=1;
	k++;
	return k;
}
void multi(ele *c,ele *a, ele *b,int an,int bn){
	int i,j,k=0;
	for(i=0;i<bn;i++){
		for(j=0;j<an;j++){
			c[k].a=b[i].a*a[j].a;
			c[k].n=b[i].n+a[j].n;
			c[k].q=1;
			k++;
		}
	}
}
void sort(ele *c,int an,int bn){
	int m=an*bn;
	int i,j;
	int temp;
	int tem;
	for(i=0;i<m-1;i++){
		temp=c[i].n;
		tem=i;
		for(j=i+1;j<m;j++){
			if(c[j].q!=0){
				if(c[j].n>temp){
					temp=c[j].n;
					tem=j;
				}
				else if(c[j].n==temp){
					c[tem].a+=c[j].a;
					c[j].q=0;
				}
			}
		}
		c[tem].n=c[i].n;
		c[i].n=temp;
		temp=c[tem].a;
		c[tem].a=c[i].a;
		c[i].a=temp;
	}
}
int main(){
	ele a[100],b[100];
	char a1[1000],b1[1000];
	gets(a1);
	gets(b1);
	int an,bn,i;
	an=input(a,a1);
	bn=input(b,b1);
	ele c[an*bn];
	multi(c,a,b,an,bn);
	sort(c,an,bn);
	for(i=0;i<an*bn;i++){
		if(c[i].q!=0){
		printf("%d %d ",c[i].a,c[i].n);
		}
	}
	return 0;
}

