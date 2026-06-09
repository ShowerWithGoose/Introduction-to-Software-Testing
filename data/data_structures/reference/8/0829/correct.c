#include<stdio.h>
int a[100][100],b[100],n,q=0,c[100],p=0;
void shdu(int a[][100],int i,int j){
	if(b[i]==0){
            b[i]=1;
			printf("%d ",i);
		}
	for(j=j;j<n;j++){
		if(a[i][j]==0)continue;
		else if(a[i][j]==1&&b[j]!=1){
			shdu(a,j,0);
		}
	}
	return ;
}
void gudu(int a[][100],int i,int j){
		if(b[i]==0){
	    	b[i]=1;
	    	c[p++]=i;
		}

		for(j=0;j<n;j++)
	    	if(a[i][j]==1&&b[j]==0){
	    		b[j]=1;
	    		c[p++]=j;
			}
		q++;
		if(q<n)	
		gudu(a,c[q],0);
}
int main(){
	int m,v1[100],v2[100],i,j,flag=0,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&v1[i],&v2[i]);
		a[v1[i]][v2[i]]=1;
		a[v2[i]][v1[i]]=1;
	}
	scanf("%d",&k);
	i=0;
	j=0;
	shdu(a,i,j);
	printf("\n");
	for(i=0;i<n;i++)b[i]=0;
	gudu(a,0,0);
	for(i=0;i<p;i++)printf("%d ",c[i]); 
	printf("\n");
	for(i=0;i<n;i++){
		a[i][k]=0;
		a[k][i]=0;
	}
	for(i=0;i<n;i++)b[i]=0;
	i=0;
	j=0;
	shdu(a,i,j);
	printf("\n");
	q=0;
	p=0;
	for(i=0;i<n;i++){
		b[i]=0;}
	gudu(a,0,0);
	for(i=0;i<p;i++)printf("%d ",c[i]); 
	return 0;
}

