#include<stdio.h>
#include<string.h>
 
char ch[500], num[20] = {'\0'};
int list[500], one, ano, i_last;
int len_list;

void getlen(int n){
	int n_0;
	for(len_list = 0; n_0 > 0; len_list ++){
		n_0 /= 10;
	}
}

void tnum_find(int list[], int i){
	int k;
	for(k = i; list[k] == -666; k --){
		;
	}
	one = list[k];
	list[k] = -666;
	for(k = i; list[k] == -666; k ++){
		;
	}
	ano = list[k];
	list[k] = -666;
}

int main(){
	int j = 0, r;
	for(int s = 0; s < 500; s ++){
		list[s] = -666;
	}
	for(int i = 0; (ch[i] = getchar()) != EOF && ch[i - 1] != '='; i ++){
		if(ch[i] >= '0' && ch[i] <= '9'){
			num[0] = ch[i];
			ch[i] = ' ';
			for(r = 1;(num[r] = getchar()) != '=' && num[r] <= '9' && num[r] >= '0'; r ++){
			}
			list[i] = num[0] - '0';
			for(int k = 1; k < r; k ++){
				list[i] = list[i] * 10 + num[k] - '0';
			}
			i_last = i;
			ch[++ i] = num[r];
		} 
	}
	j = strlen(ch);
	for(int i = 0; i < j; i ++){
		if(ch[i] == '/'){
			tnum_find(list, i);
			list[i] =one / ano;
			i_last = i;
		}
		else if(ch[i] == '*'){
			tnum_find(list, i);
			list[i] = one * ano;
			i_last = i;
		}
	}
	for(int ii = 0; ii < j; ii ++){
		if(ch[ii] == '+'){
			tnum_find(list, ii);
			list[ii] = one +  ano;
			i_last = ii;
		}
		else if(ch[ii] == '-'){
			tnum_find(list, ii);
			list[ii] = one - ano;
			i_last = ii;
		}
	}
	printf("%d", list[i_last]);
	return 0;
}

