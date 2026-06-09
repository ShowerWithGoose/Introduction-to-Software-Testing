#include <stdio.h>
#include <string.h>
int main(){
	int a[200]={0};
	int b[200]={0};
	int c[200]={0};
	int d[200]={0};
	int i=0;int n=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	}
	int q=0;int s1=0,s2=0;int yu=0;
	int y=0,z=0;int we=0;
	for(i=0;i<n;i++){
		y=c[i];z=d[i];s2=0;
		for(yu=0;yu<n;yu++){for(q=0;q<n;q++){
			if(a[q]==y&&b[q]==z){
				y=c[q];z=d[q];
				s2++;
			}
		}
		}
		
		if(s2>s1){
			s1=s2;
			we=i;
		}
	}
	printf("%d %d %d",s1+1,a[we],b[we]);
	return 0;
}

