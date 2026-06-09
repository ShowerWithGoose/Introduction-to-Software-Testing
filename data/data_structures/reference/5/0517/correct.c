#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct line
{
	int an;
	int exp;
	int pd0;
}LINE;
void sortfc(LINE* fc0, int k)
{
	int i, j, m, n;
	LINE tem;
	for(i = 0; i < k; i++){
		if(fc0[i].pd0 == 1){
			continue;
		}
		for(j = 0; j < k; j++){
			if(fc0[j].pd0 == 1 || i == j){
				continue;
			}
			if(fc0[i].exp > fc0[j].exp){
				tem = fc0[i];
				fc0[i] = fc0[j];
				fc0[j] = tem;
			}
			else if(fc0[i].exp == fc0[j].exp){
				if(i > j){
					m = j;
					n = i;
				}
				else{
					m = i;
					n = j;
				}
				fc0[m].an = fc0[i].an + fc0[j].an;
				fc0[n].pd0 = 1;
			}
		}
	}
}
int main()
{
	LINE fc1[2000], fc2[2000], fc0[4100];
	LINE *p = fc0;
	int i, j, k, n1, n2, t, pd;
	char del;
	del = '0';
	pd = 0;
	n1 = 0;
//scan
	while(del != '\n'){
		pd++;
		t = 0;
		if(del == ' '){
			scanf("%c", &del);
		}
		while(del >= '0' && del <= '9'){
			t *= 10;
			t += (del - '0');
			scanf("%c", &del);
		}
		if(pd % 2){
			fc1[n1].an = t;
		}
		else{
			fc1[n1].exp = t;
			n1++;
		}
	}
	del = '0';
	pd = 0;
	n2 = 0;
	while(del != '\n'){
		pd++;
		t = 0;
		if(del == ' '){
			scanf("%c", &del);
		}
		while(del >= '0' && del <= '9'){
			t *= 10;
			t += (del - '0');
			scanf("%c", &del);
		}
		if(pd % 2){
			fc2[n2].an = t;
		}
		else{
			fc2[n2].exp = t;
			n2++;
		}
	}
//compute
    k = 0;
    for(i = 0; i < n1; i++){
    	for(j = 0; j < n2; j++){
    		fc0[k].an = (fc1[i].an)*(fc2[j].an);
    		fc0[k].exp = (fc1[i].exp)+(fc2[j].exp);
    		k++;
		}
	}
	for(i = 0; i < k; i++){
		fc0[i].pd0 = 0;
	}
	sortfc(p, k);
	for(i = 0; i < k; i++){
		if(fc0[i].pd0){
			continue;
		}
		printf("%d %d", fc0[i].an, fc0[i].exp);
		if(i != k-1){
			printf(" ");
		}
	}
	return 0;
}

