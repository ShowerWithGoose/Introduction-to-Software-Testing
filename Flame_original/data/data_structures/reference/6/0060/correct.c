#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	int dat[1000];
	int text[1000];
	int p = 0;
	while (1) {
		scanf("%d", &dat[p]);
		if (dat[p] == -1) {
			break;
		}
		p++;
	}
	/*	for(int i=0;i<p;i++)
		{
			printf("%d",dat[i]);
		}
	*/
	int x = 0;
	for (int i = 0; i < p; i++) {
		if (dat[i] == 1) {
			i++;
			text[x] = dat[i];
			x++;
		} else if (dat[i] == 0) {
			if (text[x-1] == 0) {
				printf("error ");
			} else {
				printf("%d ", text[x - 1]);
				x--;
			}
		}
	}
	return 0;
}

