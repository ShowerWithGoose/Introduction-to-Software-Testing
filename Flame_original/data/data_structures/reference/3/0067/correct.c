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
	const int str = strlen(ch);
	if(ch[0] != '0' && ch[1] == '.'){
		ch[str] = 'e';
		ch[str + 1] = '0';
	}
	
	else if(ch[0] == '0' && ch[1] == '.'){
		for(int i = 2;i < str - 1;i++){
			if(ch[i] != '0'){
				ch[0] = ch[i];
				ch[1] = '.';
				for(int j = 2;j <= str + 1 - i;j++){
					ch[j] = ch[i + j - 1];
				}
				
				ch[str + 1 - i] = 'e';
				ch[str + 2 - i] = '-';
				char ch1[N];	int num = i - 1,k = 0;
				for(int j = 0;num > 0;j++){
					ch1[j] = num % 10 + 48;
					num /= 10; 
					k++;
				}
				for(int j = 0;j <= k;j++){
					ch[j + str + 3 - i] = ch1[k - j - 1];
				}
				puts(ch);
				return 0;
			}
			
			
		}
		
				ch[0] = ch[str - 1];
				ch[1] = 'e';
				ch[2] = '-';
				char ch2[N];	int num1 = str - 2,k = 0;
				for(int j = 0;num1 > 0;j++){
					ch2[j] = num1 % 10 + 48;
					num1 /= 10; 
					k++;
				}
				for(int j = 0;j <= k;j++){
					ch[j + 3] = ch2[k - j - 1];
				}
				
			
		
		
	}
	
	
	
	else{
		int i;
		for(i = 0;i < str,ch[i] != '.';i++);
		for(int j = i - 1;j >= 1;j--){
			ch[j + 1] = ch[j];
		}
		ch[1] = '.';
		ch[str] = 'e';
		char ch3[N];	int num2 = i - 1,k = 0;
				for(int j = 0;num2 > 0;j++){
					ch3[j] = num2 % 10 + 48;
					num2 /= 10; 
					k++;
				}
				for(int j = 0;j < k;j++){
					ch[j + str + 1] = ch3[k - j - 1];
				}
		
	}
	puts(ch);
	return 0;
}




