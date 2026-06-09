#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long zhuanhua(char a[], long long n); 
long long lianxu(char a[],long long chengchu[], long long n);
long long zhizhen;

int main(){
    char a[100] = {"0"}, b[100] = {"0"}, e[100] = {"0"};
    long long d[100], jiajian[100], i, j, k, jieguo;
    gets(a);
    for(i = j = 0;i <=strlen(a) - 1;i++){
        if(a[i] != ' '){
            b[j] = a[i];
            j++;
        }
    }
	for(i = k = j = 0;i <= strlen(b) - 1;i++){
		if(b[i] >= '0'&&b[i] <= '9'){
			d[k] = zhuanhua(b, i);
			k++;
			i = zhizhen - 1;
		}
		else{
			e[j] = b[i];
			j++;
		}
	}
	for(i = k = 0;i <= j;i++){
		if(e[i] == '*'||e[i] == '/'){
			jiajian[k] = lianxu(e, d, i);
			k++;
			i = zhizhen - 1;
		}
		else if((e[i] == '+'||e[i] == '-'||e[i] == '=')&&(i == 0||e[i - 1] == '+'||e[i - 1] == '-')){
			jiajian[k] = d[i];
			k++;
	    }
	}
	jieguo = jiajian[0];
	for(i = 0, k = 1;i <= j;i++){
		if(e[i] == '+'){
			jieguo = jieguo + jiajian[k];
			k++;
		}
		else if(e[i] == '-'){
			jieguo = jieguo - jiajian[k];
			k++;
		}
	}
	printf("%lld", jieguo);
	return 0;
}

long long zhuanhua(char a[], long long n){
	long long m = 0, end= 0 ,k = 1;
	while(a[n] != '*'&&a[n] != '/'&&a[n] != '+'&&a[n] != '-'&&a[n] != '='){
		m = m + (a[n] - '0')*k;
		k *= 10;
		n++;
	}
	k /= 10;
	while(m != 0){
		end = end + (m%10)*k;
		m /= 10;
		k /= 10;
	}
	zhizhen = n;
	return end;
}

long long lianxu(char a[],long long chengchu[], long long n){
	long long end = chengchu[n];
	while(a[n] == '*'||a[n] == '/'){
		if(a[n] == '*'){
		  end = end*chengchu[n+1];
		  n += 1;
		}
		else{
			end = end/chengchu[n+1];
			n += 1;
		}
	}
	zhizhen = n;
	return end;
}


