#include <stdio.h>
//using namespace std;
struct node{
		int coe;//系数
		int ind;//指数
}a[100], b[100], sum[100], pro[100];
struct node tmp[100] = {{0, -1}};
struct node tmp2[100] = {{0, -1}};
int pron = 1;

void print_ans(struct node a[], int n);
int do_sum(struct node a[], struct node b[], int n1, int n2, struct node sum[]);
int do_time(int n1, int n2);
int main()
{
	int n1, n2;
	int i=1;
	char x = 0;
	while (x  != '\n'){
		scanf("%d%d", &(a[i].coe), &(a[i].ind));
		i++;
		x = getchar();
	}
	n1 = i;
	for (int l=1, r=n1; l<r; l++, r--){
		struct node temp = a[l];
		a[l] = a[r];
		a[r] = temp;
	}
	x = 0;
	i = 1;
	while (x  != '\n'){
		scanf("%d%d", &(b[i].coe), &(b[i].ind));
		i++;
		x = getchar();
	}
	n2 = i;
	for (int l=1, r=n2; l<r; l++, r--){
		struct node temp = b[l];
		b[l] = b[r];
		b[r] = temp;
	}
	

 	a[0].ind = b[0].ind = -1;
 	int nn = do_time(n1, n2);
	print_ans(pro, nn);
	
//	putchar('\n');
//	int n = do_sum(a, b, n1, n2, sum);
	//printf("k = %d\n",sumn); 
//	print_ans(sum, n);
	
	
	return 0;
}

void print_ans(struct node a[], int n)
{
	int flag = 0;
	if (a[100].coe == 0)
		printf("0 0");
	for (int i = 100; i > 101 - n; i--){
		
		if (!a[i].coe)
			continue;
		if (flag)
			printf(" %d %d", a[i].coe, a[i].ind);
		else{
			printf("%d %d", a[i].coe, a[i].ind);
			flag++;
		}

}
}
int do_sum(struct node a[], struct node b[], int n1, int n2, struct node sum[])
{
	int sumn = 1;
	for (int i = n1, j = n2, k = 100; !(i == 0 && j == 0); k--){
		if (a[i].ind != b[j].ind){
			sum[k] = (a[i].ind > b[j].ind ? a[i--]: b[j--]);
		}
		else{
			sum[k].coe = a[i].coe + b[j].coe;
			sum[k].ind = a[i].ind;
			i--;
			j--;
		}
		sumn++;
	} 	
	return sumn;
}

int do_time(int n1, int n2){
	int nn = 1;
	
	for (int i = n1; i > 0; i--){
		for (int j = n2; j > 0; j--){
			tmp[j].coe = a[i].coe * b[j].coe;
			tmp[j].ind = a[i].ind + b[j].ind;
		}
		for (int i = 1; i<nn; i++){
			tmp2[nn-i] = pro[101-i];
		}
		nn = do_sum(tmp2, tmp, nn - 1 , n2, pro);
	}
	return nn;
}
	                           
