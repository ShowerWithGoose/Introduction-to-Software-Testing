#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
char n[100010];
char ans[100010];
int isyes(char n[],int i){
	if (n[i-1]<=n[i+1]) {
		if(48<=n[i-1]&&57>=n[i-1]&&48<=n[i+1]&&n[i+1]<=57) return 1;
		else if (65<=n[i-1]&&90>=n[i-1]&&65<=n[i+1]&&n[i+1]<=90) return 1;
		else if (97<=n[i-1]&&122>=n[i-1]&&97<=n[i+1]&&n[i+1]<=122) return 1;
	}
	return 0;
}
int main(){
	scanf("%s",n);//读入 
	ans[0]=n[0];//答案数组和原数组 
	for(int i=1,j=1;i<strlen(n);i++){
		if(n[i]=='-'){
			if(isyes(n,i)){
				for(int k=1;n[i-1]+k<n[i+1];j++,k++) ans[j]=n[i-1]+k;//拓展数组 
			}
			else ans[j++]=n[i];
		}
		else ans[j++]=n[i];
	}
	printf("%s",ans);
	return 0;
}



