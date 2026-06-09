#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int a[105];
int main() {
	int i,j,k,x,y,z,n,m,cnt=0;
	a[0]=cnt;
	while((scanf("%d",&m))!=-1) {
		if(m==1) {
			scanf("%d",&n);
			cnt++;
			a[cnt]=n;
		}
		if(m==0) {
			if(cnt) {
				printf("%d ",a[cnt]);
				cnt--;
			} else
				printf("error ");
		}
	}






	return 0;
}


