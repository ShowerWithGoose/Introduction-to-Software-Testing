#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1024
int main()
{
	int op,num,stack[BUFSIZE],top=-1,ans[BUFSIZE],p=-1;
	char *err="error ";
	while(scanf("%d",&op)){
		if(op==-1) break;
		switch(op){
			case 0:
				/*pop*/
				if(top>-1)
					ans[++p]=stack[top--];
				else
					ans[++p]=-1;  //-1 means error
				break;
			case 1:
				scanf("%d",&num);
				stack[++top]=num;
				break;
		}
	}
	for(int i=0;i<=p;i++){
		if(ans[i]!=-1) printf("%d ",ans[i]);
		else printf(err);
	}
	return 0;
}

