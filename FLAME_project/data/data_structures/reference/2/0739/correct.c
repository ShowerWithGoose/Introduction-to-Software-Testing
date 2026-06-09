#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[1000], s[1000];
int num[1000], sym[1000];
int t;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, j, k, p, q;
	int n = 0, ans = 0;
	gets(str);
	//删除空格 
	for(i = 0, j = 0;i < strlen(str);i++){
		if(str[i] != ' '){
			s[j] = str[i];
			j++; 
		}
	}
	//把数字算出来存着 
	for(i = 0, k = 0, t = 0;i < strlen(s);i++){
		if(s[i] == '+')	{
			sym[t] = 0;
			t++;
			continue;
		}
		if(s[i] == '-'){
			sym[t] = 1;
			t++;
			continue;
		}
		if(s[i] == '*'){
			sym[t] = 2;
			t++;
			continue;
		}
		if(s[i] == '/'){
			sym[t] = 3;
			t++;
			continue;
		}
		if(s[i] == '='){
			sym[t] = 4;
			t++; 
			break;
		} 
		for(j = i;s[j] >= '0'&&s[j] <= '9';j++){
			num[k] = 10*num[k] + s[j] - '0';
		}
		k++;//只要不为符号，则一定计算出了num[k] 
		i = j - 1;	
	}
	if(s[0] != '-'){
		//计算所有 
			if(sym[0] == 0||sym[0] == 1||sym[0] == 4){
				ans += num[0];
			}
			if(sym[0] == 2 ||sym[0] == 3){
				n = num[0];
				for(q = 0;q < t;q++){
				if(sym[q] == 2)
					n *= num[q + 1];
				else if(sym[q] == 3)
					n /= num[q + 1];
				else break;
			}
			ans += n;
			}
		for(p = 0;p < t;p++){
		
			if(sym[p] == 0 && (sym[p + 1] !=2&&sym[p + 1] !=3)){
				ans += num[p + 1];
				continue;
			} 
			if(sym[p] == 1 && (sym[p + 1] !=2&&sym[p + 1] !=3)){
				ans -= num[p + 1];
				continue;
			}
			if((sym[p] == 0||sym[p] == 1 ) && (sym[p + 1] == 2||sym[p + 1] == 3||sym[p + 1] == 4)){
			n = num[p + 1];
			for(q = p + 1;q < t;q++){
				if(sym[q] == 2)
					n *= num[q + 1];
				else if(sym[q] == 3)
					n /= num[q + 1];
				else break;
			}
			if(sym[p] == 0) ans += n;
			else if(sym[p] == 1 ) ans -= n;
			p = q - 1;
		}
		}

	}
	else if(s[0] == '-'){
		for(p = 0;p < t;p++){
			if(sym[p] == 0&&(sym[p + 1] !=2&&sym[p + 1] !=3)){
				ans += num[p];
				continue;
			} 
			if(sym[p] == 1&&(sym[p + 1] !=2&&sym[p + 1] !=3)){
				ans -= num[p];
				continue;
			}
			if((sym[p] == 0||sym[p] == 1)&&(sym[p + 1] == 2||sym[p + 1] == 3 || sym[p + 1] ==4 )){
			n = num[p];
			for(q = p + 1;q < t;q++){
				if(sym[q] == 2)
					n *= num[q];
				else if(sym[q] == 3)
					n /= num[q];
				else break;
			}
			if(sym[p] == 0)	ans += n;
			else if(sym[p] == 1) ans -= n;
			p = q - 1;
		}
	}
	}
	printf("%d\n", ans);
	return 0;
}

