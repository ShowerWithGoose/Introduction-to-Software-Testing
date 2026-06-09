#include<stdio.h>
#include<string.h>
char str0[BUFSIZ],str[BUFSIZ], *p;
int i,j,t;

int dif(char,char);
 
int main(){
	scanf("%s",str0);
	int len0=strlen(str0);
	//printf("%d\n",len0);
	for(i=0,j=0;i<len0;i++){//i为原组数，j为新组数 
		
		if(str0[i]!='-'){
			str[j]=str0[i];
			j++;
			//复制正常字母 
		}
		else{
				p=str0+i;
				if(*(p-1)>=48&&*(p+1)<=57&&*(p-1)<=*(p+1)){
					for(t=1;t<dif(*(p-1),*(p+1));t++,j++){//补充-之中缺少的内容 
						str[j]=*(p-1)+t;
						 
					}
				}
				else if(*(p-1)>=65&&*(p+1)<=90&&*(p-1)<=*(p+1)){
					for(t=1;t<dif(*(p-1),*(p+1));t++,j++){//补充-之中缺少的内容 
						str[j]=*(p-1)+t;
						 
					}
				}
				else if(*(p-1)>=97&&*(p+1)<=122&&*(p-1)<=*(p+1)){
					for(t=1;t<dif(*(p-1),*(p+1));t++,j++){//补充-之中缺少的内容 
						str[j]=*(p-1)+t;
						 
					}
				}
				else {str[j]='-';
				j++;
				}
				
				}
				
				//else if(*(p-1)>=48&&*(p+1)<=57&&*(p-1)<=*(p+1))
//			printf("%d ",dif(*(p-1),*(p+1)));
			 }
			
		
	printf("%s",str);
   
	return 0;
		
	}
	
	
int dif(char a,char b){
	return (b-a);
}
	
	
	

	
	
	
	
	
	




