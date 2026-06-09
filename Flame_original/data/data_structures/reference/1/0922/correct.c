#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct lln{
		int item;
		struct lln *pnext;
}llist;

int sort[11], book[11], n;  
void sorting(int);
int main()
{
	scanf("%d",&n);
	sorting(1);
    return 0;
}

void sorting(int step){
	int i;
	if(step==n+1){
		for(i=1;i<=n;i++)
			printf("%d ",sort[i]);
		putchar('\n');
		return;
	}
	for(i=1;i<=n;i++){
		if(!book[i]){
			//book[a[step]]=0;
			sort[step]=i;
			book[i]=1;
			sorting(step+1);
			book[i]=0;
		}
	}
	return;
}

