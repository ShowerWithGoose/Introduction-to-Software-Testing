#include <stdio.h>
int main(){
	char a[1000];
	int i,l,ta=0;
	for(i=0;i<1000;i++){
		a[i]='@';//初始化字符数组 
	}
		
	i=0;
	gets(a);//输入待扩展字符串
	
	
	for(i=0;a[i]!='@';i++){//遍历每一位并进行接下来的操作 
		if(a[i]!='-'){//情况一。不为-照常输出 
			printf("%c",a[i]);
			continue;
		}
		if(a[i]=='-'){//情况二。为-进行扩展判断（记得是否跳位） 
			ta=0;
			if((a[i+1]<='9'&&a[i+1]>='0')&&(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]-a[i-1]>1)){
				for(l=a[i-1]+1;l<a[i+1];l++){
					printf("%c",(l));
				}
				ta=1;
				continue;
			}//完成了数字扩展 
			
			if((a[i+1]<='Z'&&a[i+1]>='A')&&(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]-a[i-1]>1)){
				for(l=a[i-1]+1;l<a[i+1];l++){
					printf("%c",(l));
				}
				ta=1; 
				continue;
			}//完成了大写扩展 
			
			if((a[i+1]<='z'&&a[i+1]>='a')&&(a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]-a[i-1]>1)){
				for(l=a[i-1]+1;l<a[i+1];l++){
					printf("%c",(l));
				} 
				ta=1;
				continue;
			}//完成了小写扩展 
			if(ta==0){
				printf("-");
				continue;
			}
		}
	} 
	

	return 0;
}
	
	

