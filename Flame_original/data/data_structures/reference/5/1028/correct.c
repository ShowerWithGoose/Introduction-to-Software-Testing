#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
#define ll long long
int main () {
	
	struct xiang {
		int xishu;
		int zhishu;
	};

	struct xiang duo1[20], duo2[20], zong[50];
	int flag, l = 0, k = 0, u = 0, max, mark;
	
	char ch1[200];
	char ch2[200];
    gets(ch1);
	gets(ch2);
	int o=0,v=1;
	int x=strlen(ch1);
	int y=strlen(ch2);
	for(int i=x-1;i>=0;i--){
		o=0;    v=1;
		while(ch1[i]!=' ' && i>=0){
			o+=v*(ch1[i]-'0');
			v*=10;
			i--;
		}
		i--;
		duo1[l].zhishu=o;
		
		o=0;    v=1;
		while(ch1[i]!=' ' && i>=0){
			o+=v*(ch1[i]-'0');
			v*=10;
			i--;
		}
		duo1[l].xishu=o;
		l++;		
	}

	for(int i=y-1;i>=0;i--){
		o=0;    v=1;
		while(ch2[i]!=' ' && i>=0){
			o+=v*(ch2[i]-'0');
			v*=10;
			i--;
		}
		i--;
		duo2[k].zhishu=o;
		
		o=0;    v=1;
		while(ch2[i]!=' ' && i>=0){
			o+=v*(ch2[i]-'0');
			v*=10;
			i--;
		}
		duo2[k].xishu=o;	
		k++;	
	}
	
	for (int i = 0; i <l; i++) {
		for (int j = 0; j <=k; j++) {
			zong[u].xishu = duo1[i].xishu * duo2[j].xishu;
			zong[u].zhishu = duo1[i].zhishu + duo2[j].zhishu;
			u++;
		}
	}

	for (int i = 0; i < u; i++) {
		for (int j = i + 1; j < u; j++) {
			if (zong[i].zhishu == zong[j].zhishu) {
				zong[i].xishu += zong[j].xishu;
				zong[j].xishu = 0;
			}
		}
	}

	flag = 1;
	while (flag) {
		max = -1;
		mark = 0;
		for (int i = 0; i < u; i++) {
			if (max < zong[i].zhishu && zong[i].xishu!=0) {
				max = zong[i].zhishu;
				mark = i;
			}
		}
		if (max == -1) {
			flag = 0;
		} else {
            printf("%d %d ",zong[mark].xishu,zong[mark].zhishu);
            zong[mark].xishu=0;
		}
	} 
	return 0;
}

