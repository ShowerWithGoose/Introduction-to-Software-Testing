#include<stdio.h>
#define N 100002
int ch[N][2], s[N];
int n, cnt;
void ins(int o, int x) {
	if(x < s[o]) {
		if(!ch[o][0]) 
			s[ch[o][0] = ++ cnt] = x;
		else ins(ch[o][0], x);
	} else {
		if(!ch[o][1])
			s[ch[o][1] = ++ cnt] = x;
		else ins(ch[o][1], x);
	}
}
void prin(int o, int dt) {
	if(ch[o][0]) prin(ch[o][0], dt + 1);
	if(ch[o][1]) prin(ch[o][1], dt + 1);
	if(!(ch[o][0] + ch[o][1]))
		printf("%d %d\n", s[o], dt); 
}
int main() {
	int i, x;
	scanf("%d", &n);
	scanf("%d", &x);
	s[++ cnt] = x;
	for(i = 1; i < n; ++ i)
		scanf("%d", &x), ins(1, x);
	prin(1, 1);
	return 0;
}

