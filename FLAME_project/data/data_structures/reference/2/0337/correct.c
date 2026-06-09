#include <stdio.h>
#include <string.h>

char s[100000] ;/* record by "i"*/
int i = 0 ;
long long num[100000] ;/* record by "n" */
int n = 1;
char op[100000] ;/* record by "o"*/ 
int o = 1;
/* 局部变量："j" */

int main(){
	
	gets(s); //input "s"
	
	/*delete " " */
	for(;i<=strlen(s) -1;i++)
		if(s[i] == ' ')
		{	int j = 0;
		 	for(;i+j<=strlen(s)-1;j++)
		 		s[i+j] = s[i+j+1];
		}
		
	/* record the operator  */ 
	i = strlen(s) - 1;
	for(;i>=0;){
		if(s[i]>='0'&&s[i]<='9'){
			int j =1;
			for(;s[i]>='0'&&s[i]<='9';i--){
				num[n] +=j * (s[i] - '0');
				j *= 10; 
			}
			n++;
		}	
		else {
			op[o] = s[i];
			o++;
			i--;
		}
	} 
	/* op */
	/* 原则：数字与运算符交替出现，*/
	//原则：倒叙
	//原则：前缩
	int l_of_n = n - 1;
	int l_of_o = o - 1 ;//record length of op & num 
	for(o=l_of_o;o>=1;o--){
		if(op[o] =='*'){
			num[o] = num[o] * num[o-1];
			int j ;
			for(j =o;j<=l_of_o;j++)
				op[j] = op[j+1];
			l_of_o -= 1; 
			for(j =o;j<=l_of_n;j++)
				num[j-1]= num[j];
			l_of_n -= 1;
		}
		else if(op[o] =='/'){
			num[o] = num[o] / num[o-1];
			int j ;
			for(j =o;j<=l_of_o;j++)
				op[j] = op[j+1];
			l_of_o -= 1; 
			for(j =o;j<=l_of_n;j++)
				num[j-1]= num[j];
			l_of_n -= 1;
		}
		
		
	}/* 乘法  除法 */
	

	
	for(o=l_of_o;o>=1;o--){
		if(op[o] =='+'){
			num[o] = num[o] + num[o-1];
			int j ;
			for(j =o;j<=l_of_o;j++)
				op[j] = op[j+1];
			l_of_o -= 1; 
			for(j =o;j<=l_of_n;j++)
				num[j-1]= num[j];
			l_of_n -= 1;
		}
		else if (op[o] =='-'){
			num[o] = num[o] - num[o-1];
			int j ;
			for(j =o;j<=l_of_o;j++)
				op[j] = op[j+1];
			l_of_o -= 1; 
			for(j =o;j<=l_of_n;j++)
				num[j-1]= num[j];
			l_of_n -= 1;
		}
	}/* 加减 */
	
	printf("%d",num[1]); 
	
	return 0;
} 



