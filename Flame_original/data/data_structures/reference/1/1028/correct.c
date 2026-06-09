//版权：GD
#include <stdio.h>
#include <string.h>
#include <math.h>
#define ll long long
#define M 12//调数组的大小 
#define N 1//运算次数 
ll jiechengbiao[M];
int shengchengjiechengbiao(ll);
int input(ll [][M], int*);
int calculation(ll [][M], int, ll*);
int output(ll);
int nixuhe(ll*, int);
ll danhangxuanshu(ll [][M], ll*, int, int*, int);
ll yiciyunsuan(ll [][M], int, ll*);

int main () {
	int n;
	ll a[M][M];
	for (int i = 1; i <= N; i++) {
		ll jieguo = 0;
		input(a, &n);
		calculation(a, n, &jieguo);
		output(jieguo);
	}
	return 0;
}

int input(ll a[][M], int* n) {
	int i = 0;
	int j = 0;
	scanf("%d", n);
	for (i = 0; i < (*n); i++) {
		for (j = 0; j < (*n); j++) {
		}
	}
	return 0;
}
int output(ll jieguo) {
	return 0;
}
int calculation(ll a[][M], int n, ll* jieguo) {
	ll cishu = 0;
	ll i = 0;
	ll o = n;
	shengchengjiechengbiao(o);
	for (i = 1; i <= jiechengbiao[n]; i++) {
		(*jieguo) += yiciyunsuan(a, n, &cishu);
	}
	return 0;
}
ll yiciyunsuan(ll a[][M], int n, ll* cishu) {//wei yun xing
	int l = 0;
	ll t[M] = {0};
	ll u = 1;
	int i = 0;
	ll x;
	for (i = 0; i < n; i++) {
		x = (*cishu) % jiechengbiao[n - i] / jiechengbiao[n - 1 - i];
		if ((*cishu) % jiechengbiao[n - i] != 0 && i < n - 1) {
			u *= danhangxuanshu(a, t, n, &l, x);
		} else u *= danhangxuanshu(a, t, n, &l, 0);
	}
	(*cishu)++;
	u *= nixuhe(t, l);
	printf("\n");
	return u;
}
ll danhangxuanshu(ll a[][M], ll t[M], int n, int* l, int x) {
	int flag;
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		flag = 1;
		for (j = 0; j < (*l); j++) {
			if (i == t[j] && (*l) > 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			if (x) {
				x --;
				continue;
			}
			t[(*l)] = i;
			printf("%d ", i+1);
			(*l)++;
			return a[(*l) - 1][i];
		}
	}
	return 0;
}
int nixuhe(ll t[M], int l) {
	int i = 0;
	int j = 0;
	ll nixu = 0;
	for (i = 1; i < l; i++) {
		for (j = 0; j < i; j++) {
			if (t[j] > t[i]) {
				nixu++;
			}
		}
	}
	if (nixu % 2) {
		return -1;
	} else return 1;

}
int shengchengjiechengbiao(ll o) {
	int i = 1;
	jiechengbiao[0] = 1;
	for (i = 1; i <= o; i++) {
		jiechengbiao[i] = jiechengbiao[i - 1] * i;
	}
	return 0;
}



