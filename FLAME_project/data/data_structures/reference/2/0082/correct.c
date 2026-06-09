#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
char d[100],o[100];
int num[100],vis[100];
int main()
{ 
	int i,j,k,ans; 
	gets(d);
	int number=0,op=0; 
	int len=strlen(d);
	for(i=0;i<len;i++){
		if(d[i]==' ') continue; 
		else if(!isdigit(d[i])){
			o[op++]=d[i];  
			number++; 
		}
		else{
			num[number]=num[number]*10+d[i]-'0';
		}
		
	}
	//我突然觉得这个方法挺好玩的，我把这题试着写一下吧 
	//下面是对运算符数组进行遍历,目的是把乘除运算都先做完，然后那些已经运算完的数我标记上，之后就不访问它了
	//vis是visit的意思,已经访问过第下标个数就把它标记为1 
    for(i=0;i<op;i++){
    	if(o[i]=='+'||o[i]=='-') continue;
    	int tmp=i;
    	while(o[i]=='*'||o[i]=='/'){
    		if(o[i]=='*') num[tmp]*=num[i+1];
    		else num[tmp]/=num[i+1];
    		i++;
    		vis[i]=1;
		}
	}
	//找到第一个没被访问过的数字 
	for(i=0;i<number;i++){
		if(vis[i]==0) {
			ans=num[i];
			j=i;
			break;
		}
	}
//  我debug用来着 
//	for(i=0;i<number;i++){
//		printf("%d ",vis[i]);
//	}
//	printf("\n");
//	for(i=0;i<number;i++){
//		printf("%d ",num[i]);
//	}
	for(i=0;i<op;i++){
		if(o[i]=='*'||o[i]=='/') continue;
		else{
			if(o[i]=='+'){
				j++;
				for( ;j<number;j++){
					if(!vis[j]){
						ans+=num[j];
						break;
					}
				}
			}
			else if(o[i]=='-') 
			{
				j++;
				for( ;j<number;j++){
					if(!vis[j]){
						ans-=num[j];
						break;
					}
				}	
			}
			else{
				printf("%d",ans);
			}
		}
	}


    return 0;
}




