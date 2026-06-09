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
	int i = 0;
	gets(ch);
	while(ch[i] != '\0'){
		
		if(ch[i] == '-'){
			
			
			if( (isdigit(ch[i-1]) && isdigit(ch[i+1])) || (islower(ch[i-1]) && islower(ch[i+1])) || (isupper(ch[i-1]) && isupper(ch[i+1]))){
				if(ch[i-1] < ch[i+1]) {
					int k = ch[i+1] - ch[i-1] - 2;
					for(int j = strlen(ch) - 1;j >= i + 1;j--){
						ch[k + j] = ch[j];//∫Û“∆ 
					}
				
					for(int j = i;j <= k + i;j++){//Õ˘÷–∏≥÷µ 
						ch[j] = ch[i-1] + j + 1 - i; 
					}
				}
				
			} 
		}
		
		i++;
	}
	puts(ch);
	

	return 0;
}




