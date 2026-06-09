#include<stdio.h>
#include<stdlib.h>
typedef struct _num{
	int coe;
	int pow;
} Num;
void sort(Num[],int);
int main()
{
	Num a[1000],b[1000],p[1000];
	int i=0,j=0,k=0,la,lb,m;
	int flag;
	char c;
	do{
		scanf("%d%d%c",&a[i].coe,&a[i].pow,&c);
		i++;
	} while(c!='\n');
	la=i;
	do{
		scanf("%d%d%c",&b[j].coe,&b[j].pow,&c);
		j++;
	} while(c!='\n');
	lb=j;
	for(i=0;i<la;i++){
		for(j=0;j<lb;j++){
			p[k].coe=a[i].coe*b[j].coe;
			p[k].pow=a[i].pow+b[j].pow;
			k++;
		}
	}
	for(i=0;i<k;i++){
		for(j=i+1;j<k;){
			flag=0;
			if(p[i].pow==p[j].pow){
				flag=1;
				p[i].coe+=p[j].coe;
				for(m=j;m<k-1;m++)
				p[m]=p[m+1];
				k--;
			}
			if(flag==0)
			j++;
		}
	}
	sort(p,k);
	for(i=0;i<k;i++){
		printf("%d %d ",p[i].coe,p[i].pow);
	}
	return 0;
}
void sort(Num n[],int m){
	int i,j;
	Num temp;
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			if(n[i].pow<n[j].pow){
				temp=n[i];
				n[i]=n[j];
				n[j]=temp;
			}
		}
	}
}



