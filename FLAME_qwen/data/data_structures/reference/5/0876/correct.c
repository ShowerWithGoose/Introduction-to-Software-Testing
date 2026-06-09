#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


struct number{
	int co;
	int index;
};

int cmp(const void *a, const void *b)
{
	return ((struct number *)b)->index-((struct number*)a)->index;//½µÐò 
}

int main()
{
	struct number a[100], b[100], result[100];
	int len1, len2;
	char ch;
	int i=0, j=0, k=0;
	int flag;
	i=0;
	while(ch != '\n'){
		scanf("%d%d%c",&a[i].co, &a[i].index,&ch);
		i++;
	}
	len1=i;
	i=0, ch='\0';
	while(ch != '\n'){
		scanf("%d%d%c",&b[i].co, &b[i].index, &ch);
		i++;
	}
	len2=i;
	int re_co, re_index;
	int re_len=0;
	flag=0;
	for(i=0; i<len1; i++){
		for(j=0; j<len2; j++){//a[i],b[j]
			re_index = a[i].index + b[j].index;
			re_co = a[i].co * b[j].co;
			for(k=0; k<re_len; k++){
				if(re_index == result[k].index){
					result[k].co += re_co;
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				result[re_len].co = re_co;
				result[re_len].index = re_index;
				re_len++;
			}
			flag=0;
		}
	}
	qsort(result, re_len, sizeof(result[0]), cmp);
	for (i=0; i<re_len; i++){
		printf("%d %d ",result[i].co, result[i].index);
	}
	return 0; 
}



