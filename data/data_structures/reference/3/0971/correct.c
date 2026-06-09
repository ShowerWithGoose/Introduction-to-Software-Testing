#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	char a[200];
	int i,j,k,len;j=k=0;
	scanf("%s",a);
	len=strlen(a)-1;
	for(i=0;a[i]!='.'&&i<=len;i++){
		if(a[i]!='0'){
			j++;
		}
	}//a[i]此时为'.'或者len+1； 
	if(j==0){
		i++;//小于1的情况 
		for(;i<=len;i++){
			if(a[i]=='0'){
				k++;
			}
			else{
				k++;
				break;
			}
		}
		if(i==len){
			printf("%c",a[i]);	
		}
		else{
			printf("%c.",a[i]);
		}
		i++;
		for(;i<=len;i++){
			printf("%c",a[i]);
		}
		printf("e-%d",k);
	}
	else{
		if(i==len+1){//无小数部分 
			for(i=0;i<=len;i++){
				printf("%c",a[i]);
			}
			printf("e0");
		} 
		else{//有小数部分 
			for(i=0;a[i]!='.';i++){
						k++;
					}//a[i]为'.'k为多少位
					for(;i<=len;i++){
						a[i]=a[i+1];
					}
					printf("%c.",a[0]);
					for(i=1;i<len;i++){
						printf("%c",a[i]);
					}
					printf("e%d",k-1);
				}
		}
 	return 0;
}

