#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int a[100][5],s[100],ans[5];
int main() {
	int i,j,k,x,y=0,z,n,m,cnt=1,max=1,o,p;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d%d%d%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
	}
//	printf("%d",cnt);
	for(i=1; i<=n; i++) {
//		printf("%d\n",i);
		for(j=1; j<=n+1; j++) {
			if(a[i][3]==a[j][1]&&a[i][4]==a[j][2]) {
				s[cnt]=i;
				cnt++;
//				ans[1]=a[]
				i=j-1;
				break;
			}
		}
//		printf("%d*%d*%d*%d***\n",s[1],s[2],s[3],j);
		if(j==n+2&&cnt!=1) {
			cnt=1;
			i=s[1];
			for(k=0; k<100; k++) {
				s[k]=0;
			}
//			printf("&&&&&&&&&&&&&&&&");
		}
		if(cnt>max) {
			max=cnt;
			ans[1]=a[s[1]][1];
			ans[2]=a[s[1]][2];
		}
	}
	printf("%d %d %d",max,ans[1],ans[2]);
	return 0;
}


