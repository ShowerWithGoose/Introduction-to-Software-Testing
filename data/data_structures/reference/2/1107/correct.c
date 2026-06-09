#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int ans;
	int a[2];
	char c[3];
	ans=0;
	c[0]='+';
	int flag=0;
	while(1){
		scanf("%d %c",&a[0],&c[1]);
	    if(c[1]=='*'||c[1]=='/') flag=1;
		while(flag){
			scanf("%d %c",&a[1],&c[2]);
			if(c[1]=='*')a[0]*=a[1];
			else a[0]/=a[1];
			c[1]=c[2];
			if(c[1]!='*'&&c[1]!='/') flag=0;
		}
		
		if(c[0]=='+') ans+=a[0];
		else ans-=a[0];
		c[0]=c[1];
		if(c[0]=='=') {printf("%d",ans);return 0;
		}
	}

}
