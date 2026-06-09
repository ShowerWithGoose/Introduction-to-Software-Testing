#include<stdio.h>
int max=0,max1,cnt=0,i,j,l,x1[600],y1[600],x2[600],y2[600],num[600]={0},n,k;
int back(int m){
		for(j=0;j<n;j++){
			k=m;
			if(x2[k]==x1[j]&&y2[k]==y1[j]&&k!=j){
				num[i]++;
	        l=j;
			 	cnt=1;		
			}
		}
		if(cnt)
			return 1;
			else return 0;
			cnt=0;
	} 
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for(i=0;i<n;i++){
		if(back(i)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
		if(back(l)==1)
		back(l);
	}
	for(i=0;i<n;i++){
		if(num[i]>max){
		max=num[i];
		max1=i;
	}
	}
	printf("%d %d %d",max+1,x1[max1],y1[max1]); 
}



