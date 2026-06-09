#include<stdio.h>
#include<math.h>
#include<string.h>
//数组从0开始！！
//检查 & ！！

int n;
int main(){
	char a[100];
	scanf("%s",a);
	n=strlen(a);
	for(int i=1;i<=n;i++){
		if(a[i-1]=='-'){
			if((a[i]-a[i-2])<26&&(a[i]-96)*(a[i-2]-96)>0&&(a[i]-64)*(a[i-2]-64)>0){
				for(int j=a[i-2]+1;j<=a[i]-1;j++){
					printf("%c",j);
				}
			}
			else printf("-");
		}
		else printf("%c",a[i-1]);
		
	}
	
	
	return 0;
}


