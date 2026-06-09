#include <stdio.h>

int num[100];
int i1 = 0; 
char fuhao[100];
int i2 = 0; 
char s[205];
char s1[205]; 

int main ()
{
	gets(s1);
	int len1 = 0;
	int len = 0;
	while(s1[len1] != '='){
		if(s1[len1] == ' '){
			len1 ++;
		}
		else
		{
			s[len] = s1[len1];
			len ++;
			len1 ++;
		}
	}
	s[len] = '=';//去空格 
	
	for(int i = 0 ; i <= len ; i ++){
		if(!(s[i] >= '0' && s[i] <= '9'))
		
		{
			fuhao[i2] = s[i];
			i2 ++;
		}
		if(s[i] >= '0' && s[i] <= '9'){
					num[i1] = s[i] -'0';
					
					while(s[i + 1] >= '0' && s[i + 1] <= '9'){
						num[i1] = num[i1] * 10 + (s[i + 1] - '0');
						
						i ++;
					}
					
					i1 ++;
				}
	}
	
	
	

	
	int ci = i2;
	int index1 = 0;
	while(ci --){//可能有错 
		if(fuhao[index1] == '*'){
			num[index1] = num[index1] * num[index1 + 1];
			
			for(int i = index1 + 1 ; i < i1 ; i ++){
				num[i] = num[i + 1];
			}		
			for(int i = index1 ; i < i1 ; i ++){
				fuhao[i] = fuhao[i + 1];
			}
			i1 --;
			i2 --;
		}
		else if(fuhao[index1] == '/'){
			num[index1] = num[index1] / num[index1 + 1];
			for(int i = index1 + 1 ; i < i1 ; i ++){
				num[i] = num[i + 1];
			}		
			for(int i = index1 ; i < i1 ; i ++){
				fuhao[i] = fuhao[i + 1];
			}
			i1 --;
			i2 --;	
		}
		else index1 ++;
	}

	
	
	int index = 0;
	for(index = 0 ; index < i1 ; index ++){
		if(fuhao[index] == '+'){
			num[index] = num[index] + num[index + 1];
			for(int i = index + 1; i < i1 ; i ++){
				num[i] = num[i + 1];
			}
			for(int i = index ; i < i1 ; i ++){
				fuhao[i] = fuhao[i + 1];
			}
			i1 --;
			i2 --;
			index --;
		}
		if(fuhao[index] == '-'){
					num[index] = num[index] - num[index + 1];
					for(int i = index + 1; i < i1 ; i ++){
						num[i] = num[i + 1];
					}
					for(int i = index ; i < i1 ; i ++){
						fuhao[i] = fuhao[i + 1];
					}
					i1 --;
					i2 --;
					index --;
				}
	}
	
	
	printf("%d", num[0]);
	return 0 ;
}

