/*
四元结构体数组存线段（顺带编号
遍历全部线段，只看尾部连的线段
遍历过程记录线段数和起始线段编号
*/
#include<stdio.h>

void line_judg(int form);

struct line {
	int fir_a;
	int fir_b;
	int lat_a;
	int lat_b;
} table[505] = {{0, 0}};
int num_l = 0, num_n = 0, temp = 0, n = 0;
/*
num_l is the number of lines leaded by last line
num_n is the number of lines leaded by new line
temp is the line's id
*/
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		scanf("%d%d%d%d", &table[i].fir_a, &table[i].fir_b, &table[i].lat_a, &table[i].lat_b);
	}//imput
	for(int i = 0; i < n; i ++) { 
		num_n = 1;
		line_judg(i);
		if(num_n > num_l) {
			num_l = num_n;
			temp = i;
		}
	}
	printf("%d %d %d", num_l, table[temp].fir_a, table[temp].fir_b);
	return 0;
}

void line_judg(int form){
    for(int j = 0; j < n; j ++){
        if(table[form].lat_a == table[j].fir_a && table[form].lat_b == table[j].fir_b) {
            num_n ++;
            return line_judg(j);
        }
    }
    return;
}
