#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
char s[105]; 
flag=0;   //当flag为1的时候，说明e前面是个整数，输出不含小数点 
int main()
{
	int i,j,k,num;
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++){
		if(s[i]>='1' && s[i]<='9'){//找到第一个有效数字 
			j=i;//j是有效数字的位置 
			if(s[j+1]=='\0'){  //后面没有其他数字 
			  flag=1;	
			}
			break;
		}		
	}
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='.'){
	
			k=i;//k是小数点的位置 
			break;	}
	}
	if(k>j) num=k-j-1;
	else num=k-j;
	
	if(flag==1){
		printf("%ce%d",s[j],num);	
	}
	else if(flag==0){
		printf("%c.",s[j]);
		for(i=j+1;s[i]!='\0';i++){
			if(s[i]=='.') i++;
			printf("%c",s[i]);
		}
		
		printf("e%d",num);
	}
	

 return 0;
}

/*思路：
1、字符数组max为100
2、科学计数法的几种形式：
e前面为整数（不含小数点）
e前面为小数（小数点前不为0，小数点后末位不为零）
e后面为整数（负数要带负号）
3、先从左到右扫描，找到第一个有效数字，判断它后面是否还有
其他数字，如果没有，直接输出这个数字，紧接着输出e，再数小数点到该
数字的距离，输出指数部分即可；如果有，先输出一个小数点，然后把后面的所有数字
全都照搬输出，然后输出e，再数小数点到该数字的距离，输出即可。 

2345.12345=2.34512345e3  j=0;k=4;k-j-1=3;
0.0032=3.2e-3    j=4;k=1;k-j=-3
2.345=2.345e0   j=0;k=1;k-j-1=0


*/ 
 

