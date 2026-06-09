#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main(){
	char c,a[120];
	int b[120],k=0,tmp,cnt=-2;
	for(int i=0;i<=120;i++)
		b[i]=0;
	memset(a,0,sizeof(a));	
	while(1){
		c=getchar();
		if(c=='\n')
			break;
		if(c!='.'){
			b[k]=c-48;
			if(b[k]!=0&&cnt==-2)
				cnt=k;			
			k++;
		}
		if(c=='.'){
			b[k]=-1;
			tmp=k;
			k++;
		}
	}
	if(cnt==0){
	printf("%d.",b[0]);
	for(int i=1;i<k;){
		if(b[i]==-1)
			i++;
		printf("%d",b[i]);
		i++;
	}
	printf("e");
		printf("%d",tmp-1);			
	}
	else{
		if(k-cnt>1)
			printf("%d.",b[cnt]);
		else
			printf("%d",b[cnt]);
		for(int i=cnt+1;i<k;i++)
			printf("%d",b[i]);
		printf("e");		
		printf("%d",tmp-cnt);		
	}
	return 0;
}


