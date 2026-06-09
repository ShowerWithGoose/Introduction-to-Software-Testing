#include <stdio.h>


int main(){
	char s[10000], a[10000];
	gets(s);
	int i = 0, j = 0;
	for(; s[i] != '\0'; i++){
		if(s[i] != ' ') a[j++] = s[i];
		else continue;
	}

	int sum = 0;
	
	char sign1[10000];
	int n1[10000];
	int c1 = 0, j1 = 0;
	
	for(i = 0; a[i] != '='; i++){ 
		if(a[i] >= '0' && a[i] <= '9') c1 = c1 * 10 + a[i] - '0';//如果符号前面有数字 
		else if(a[i] == '*' || a[i] == '/'){
			
			char sign2[10000];
			int n2[10000] = {1};
			int c2 = 0, j2 = 0, k2 = 0;
			
			for(; a[i] != '+' && a[i] != '-' && a[i] != '='; i++){//如果最开始没有加减号 
				if(a[i] >= '0' && a[i] <= '9') c2 = c2 * 10 + a[i] - '0';	
				else{
					n2[j2] = c2;
					c2 = 0;
					sign2[j2++] = a[i];
				}					
			}
			
			i--;
			
			n2[j2] = c2;

			for(; k2 < j2; ){
				if(sign2[k2] == '*') c1 *= n2[++k2];
				else c1 /= n2[++k2];	 				
			}

//			sign2[0] = '\0'; 

		}
		else{//如果遇到加减号 
			sign1[j1] = a[i];

			int c = 0, m = 1, n[10000] = {1};
			j = 0;
			char sign3[10000];
	
			for(i += 1; a[i] != '+' && a[i] != '-' && a[i] != '='; i++){
				if(a[i] >= '0' && a[i] <= '9') c = c * 10 + a[i] - '0';
				else{
					n[j] = c;
					c = 0;
					sign3[j++] = a[i];
				}
			}
//			sign3[j] = '\0';

			i--;
			
			n[j] = c;
			
			m *= n[0];

			int k = 0;
			for(; k < j; ){
				if(sign3[k] == '*') m *= n[++k];
				else m /= n[++k];
				n[k-1] = 1;
			}
			sign3[0] = '\0';
			n[k] = 1;
			n1[j1++] = m;
		}
	}
	int k = 0;
	for(; k < j1; k++){
		if(sign1[k] == '+') sum += n1[k];
		else sum -= n1[k]; 
	}
	
 	sum += c1;
 	
	printf("%d", sum);
}





