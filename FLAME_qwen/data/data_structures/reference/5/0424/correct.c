#include <stdio.h>
#include <string.h>

int A[1001],B[1001],N[1001],M[1001],Num[1000001],Z[1000001],n,m;

char temp[1000001],S1[1000001],S2[1000001];

void sort(int l,int r){
	int num[r-l+2],z[r-l+2],T=1,i=l,j=(r+l)/2+1;
	if(l==r)return;
	else if(l+1==r){
		if(Z[l]<Z[r]){
			Num[0]=Num[l];
			Num[l]=Num[r];
			Num[r]=Num[0];
			Z[0]=Z[l];
			Z[l]=Z[r];
			Z[r]=Z[0];
		}return;
	}
	sort(l,(l+r)/2),sort((l+r)/2+1,r);
	while(T<=r-l+1){
		if(j^(r+1)&&i^((r+l)/2+1)){
			if(Z[i]>Z[j])z[T]=Z[i],num[T]=Num[i],++i;
			else z[T]=Z[j],num[T]=Num[j],++j;
		}
		else if(j^(r+1))z[T]=Z[j],num[T]=Num[j],++j;
		else z[T]=Z[i],num[T]=Num[i],++i;
		++T;
	}
	for(i=l;i<=r;++i)
		Num[i]=num[i-l+1],Z[i]=z[i-l+1];
	return;
}

int main(){
	gets(S1);
	gets(S2);
	int i=0;
	while(S1[i])
	{
		while(S1[i]<'0')++i;
		A[++n]=S1[i]-'0';
		while(S1[++i]>='0')A[n]=A[n]*10+S1[i]-'0';
		while(S1[i]<'0')++i;
		N[n]=S1[i]-'0';
		while(S1[++i]>='0')N[n]=N[n]*10+S1[i]-'0';
		while(S1[i]<'0'&&S1[i])++i;
	}
	i=0;
	while(S2[i])
	{
		while(S2[i]<'0')++i;
		B[++m]=S2[i]-'0';
		while(S2[++i]>='0')B[m]=B[m]*10+S2[i]-'0';
		while(S2[i]<'0')++i;
		M[m]=S2[i]-'0';
		while(S2[++i]>='0')M[m]=M[m]*10+S2[i]-'0';
		while(S2[i]<'0'&&S2[i])++i;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			Num[(i-1)*m+j]=A[i]*B[j],Z[(i-1)*m+j]=N[i]+M[j];
	sort(1,n*m);
	Z[0]=-1;
	for(int i=1;i<=n*m;++i)
		if(Z[i]==Z[i-1])Num[i]+=Num[i-1],Num[i-1]=0;
	for(int i=1;i<=n*m;++i)
		if(Num[i])printf("%d %d ",Num[i],Z[i]);
	return 0;
}
