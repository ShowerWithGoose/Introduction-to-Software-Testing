#include<stdio.h>

int main(){
	char a[1000], b[1000];
	long long i, j = 0, t= 0, c[100], d[100], k[100], f[100], temp,e[100] = {0}, sum[200],sum1[200] ,h = 0, n = 1, m = 0, x = 0, q = 0, y = 0, wide = 0, wide1 = 0;
	gets(a);
	gets(b);
	for(i = 0;i < strlen(a);i++){
		if(a[i] == ' '){
			if(t%2 == 0){
				c[m] = h;
				m++;
			}
			else{
				d[x] = h;
				x++;
			}
			n = 1;
			h = 0;
			t++;
			continue;
		}
		h = h*10+a[i]-48;
		if(i == strlen(a) - 1){
			d[x] = h;
			x++;
		}
	}
	h = 0;
	t = 0;
	for(i = 0;i < strlen(b);i++){
		if(b[i] == ' '){
			if(t%2 == 0){
				k[q] = h;
				q++;
			}
			else{
				f[y] = h;
				y++;
			}
			n = 1;
			h = 0;
			t++;
			continue;
		}
		h = h*10+b[i]-48;
		if(i == strlen(b) - 1){
			f[y] = h;
			y++;
		}
	}
	t = 0;
	h = 0;
	for(i = 0;i < m;i++){
		for(j = 0;j < q;j++){
			sum[wide] = c[i]*k[j];
			sum1[wide1] = d[i]+f[j];
			wide++;
			wide1++;
		}
	}
	for(i = 0;i < wide;i++){
		e[i] = i;
	}
	for(i = 0;i < wide;i++){
		for(j = i+1;j < wide;j++){
			if(sum1[e[i]] == sum1[e[j]]){
				sum[e[i]] += sum[e[j]];
				e[j] = -1;
			}
			else if(sum1[e[i]] < sum1[e[j]]&&e[j]!=-1&&e[i]!=-1){
				temp = e[i];
				e[i] = e[j];
				e[j] = temp;
			}
		}
	}
	for(i = 0;i < wide;i++){
		if(e[i] >= 0){
			printf("%lld %lld ", sum[e[i]], sum1[e[i]]);
		}
	}
	return 0;
} 

