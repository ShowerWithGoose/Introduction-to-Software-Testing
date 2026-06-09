#include<stdio.h>
int hash[100],line[100];
int main(void) {
	int n,x1[100],x2[100],y1[100],y2[100];
	int i,j,k;
	scanf("%d",&n);
	for(i = 0; i < n; i++) {
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
		for(j = 0; j < i; j++) {
			if(x1[i] == x2[j]&&y1[i] == y2[j]) {
				hash[i] ++;
				hash[j] ++;
			}
		}
		for(j = 0; j < i; j++) {
			if(x2[i] == x1[j]&&y2[i] == y1[j]) {
				hash[i] ++;
				hash[j] ++;
			}
		}
	}
	for(i = 0; i < n; i++) {
		int flag = 0,q=i;
		if(hash[i] == 2||hash[i] == 0) continue;
		else if(hash[i] == 1) {
			for(j = 0; j <= n; j++) {
				if(x1[i] == x2[j]&&y1[i] == y2[j]) {
					flag = 1;
					break;
				}
			}
			if(flag == 0) {
				int k=i;
				line[k] = 1;
				for(j = 0; j < n; j++) {
					if(x2[i] == x1[j]&&y2[i] == y1[j]) {
						line[k]++;
						i=j;
						j=-1;
					}
				}
			}
		}
		i=q;
	}
	int z = 0;
	int p=line[0];
	for(i = 1; i < n; i++) {
		if(line[i] > p) {
			z = i;
			p = line[i];
		} else continue;
	}
	printf("%d %d %d",p,x1[z],y1[z]);
	return 0;
}



