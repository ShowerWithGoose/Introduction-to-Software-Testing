#include <stdio.h>
#define N 200005
int a[N],b[N],z[N],x[N],flag[N];
int s[N],t[N];
void bubble(int x[],int z[],int n);
int main()
{
	int i=0,j=0,k,n1=0,n2=0,m,l;
	char c;
	i=0;
	do{
		scanf("%d%d%c",&a[i],&b[i],&c);
		i++;
		n1++;
	}while(c!='\n');
	i=0;
	do{
		scanf("%d%d%c",&s[i],&t[i],&c);
		i++;
		n2++;
	}while(c!='\n');
	k=0;
	for(l=0;l<n1;l++){
		for(j=0;j<n2;j++){
			x[k]=a[l]*s[j];
			z[k]=b[l]+t[j];
			k++;
		}
	}
	for(l=0;l<k;l++){
		for(m=l+1;m<k;m++){
			if(z[l]==z[m]){
				x[m]+=x[l];
				x[l]=0;
			}
		}
	} 
	bubble(x,z,k);
	for(l=0;l<k;l++){
		if(x[l]!=0)printf("%d %d ",x[l],z[l]);
	}
	return 0;
}
void bubble(int x[],int z[],int n)
{
	int i,j,temp,hold;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(z[j]<z[j+1]){
				hold=z[j];
				z[j]=z[j+1];
			    z[j+1]=hold;
				temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
			}
		}
	}
}

