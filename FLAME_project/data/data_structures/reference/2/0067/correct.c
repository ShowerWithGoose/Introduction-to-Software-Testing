#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define pf printf
#define sc scanf
#define N 10005
int main()
{
	char ch[N];
	gets(ch);
		for(int i = 0;i < strlen(ch);i++){//去除空格 
		if(ch[i] == ' '){
			for(int j = i;j < strlen(ch);j++){
				ch[j] = ch[j + 1];
			}
			i--;
		}
	}
	
	int count1 = 0;
	for(int i = 0;i < strlen(ch);i++){
		if(!isdigit(ch[i]))	count1++;
	}
	if(count1 == 1){//只有一个数字
		for(int i = 0;i < strlen(ch) - 1;i++){
			pf("%c",ch[i]);
		}
		return 0;
	}
	
	//先算乘除
	for(int i = 0;ch[i] != '\0';i++){
			if(ch[i] == '*' || ch[i] == '/'){
			int num1 = 0,num2 = 0,num3 = 0,k1 = 0,k2 = 0,k3 = 0;
			
			for(int j = i - 1,k = 0;isdigit(ch[j]);j--,k++){
				num1 += ((ch[j] - '0') * pow(10,k));
				k1++;
			}//num1,k1为num1的位数
			int j1;
			for(j1 = i + 1;isdigit(ch[j1]);j1++);j1--;
			 for(int k = 0;isdigit(ch[j1]);j1--,k++){
				num2 += ((ch[j1] - '0') * pow(10,k));
				k2++;
			}//num2,k2为num2的位数
			
			if(ch[i] == '*')	num3 = num1 * num2;
			else num3 = num1 / num2;
			
			//将num3转化位字符串
			char ch1[N];
			if(num3 == 0){
				ch1[0] = '0';
				ch1[1] = '\0';
				k3 = 1;
			}
			for(int k = 0;num3 > 0;k++){
				ch1[k] = num3 % 10 + '0';
				num3 /= 10;
				k3++;
			}
			
			
			for(int j = i - k1;j < i - k1 + k3;j++){
				ch[j] = ch1[k3 - 1 - j + i - k1];
			}//将num3置于字符串中
			
			for(int j = i - k1 + k3;ch[j] != '\0';j++){
				ch[j] = ch[j + k1 - k3 + k2 + 1];
			}//移动字符串
			ch[strlen(ch)] = '\0';
			
			i -= k1 ;
			
		}
	}
	
	//再算加减
	int count = 0,i1 = 0,i2 = 0;
	for(int i = 0;i < strlen(ch);i++){
		if(!isdigit(ch[i]))	count++;
	}
	
	long long num[count],k2 = 0;
	
	if(count == 1){//只有乘除，无加减 
		for(int i = 0;i < strlen(ch);i++){
			if(ch[i] != '=')	pf("%c",ch[i]);
		}
		return 0;
	}

	for(i2 = 0;i2 < strlen(ch);i2++){//第一次，剩下只用符号后面的字符 
		
		if(ch[i2] == '+' || ch[i2] == '-'){
			int num1 = 0,num2 = 0;
		
			for(int j = i2 - 1,k = 0;isdigit(ch[j]);j--,k++){
					num1 += ((ch[j] - '0') * pow(10,k));
				}//num1
	
			int j1;
			
			for(j1 = i2 + 1;isdigit(ch[j1]);j1++);j1--;
			for(int k = 0;isdigit(ch[j1]);j1--,k++){
				num2 += ((ch[j1] - '0') * pow(10,k));
				k2++;
			}//num2
			
			if(ch[i2] == '+')	num[i1] = num1 + num2;
			else num[i1] = num1 - num2;
			i1++;
			break;
		}
		
		
	}
	for(i2 = i2 + k2;i2 < strlen(ch);i2++){
		if(ch[i2] == '+' || ch[i2] == '-'){
			int num2 = 0;
			
			int j1;
			for(j1 = i2 + 1;isdigit(ch[j1]);j1++);j1--;
			for(int k = 0;isdigit(ch[j1]);j1--,k++){
				num2 += ((ch[j1] - '0') * pow(10,k));
			}//num2
			
			if(ch[i2] == '+')	num[i1] = num[i1 - 1] + num2;
			else	num[i1] = num[i1 - 1] - num2;
			i1++;
		}
	}
	
	pf("%lld\n",num[count - 2]);
	
	return 0;
}




