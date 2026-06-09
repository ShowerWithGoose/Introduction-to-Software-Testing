#include <stdio.h>
#include <stdlib.h>
int n;
int a[50];
char b[50];
void c(int x,long long num)
{
	int i;
	if(n<10){
		if(x==n+1){ 
	        sprintf(b,"%lld",num);
	    for(i=0;b[i];i++)
	        printf("%c ",b[i]);
	        printf("\n");
		return;
	    }
		for(i=1;i<=n;i++){
		    if(!a[i]){
			    a[i]=1;//让进入递归时不满足该if 
			    c(x+1,num*10+i);
			    a[i]=0;
		}
		/*当n=4时, 
		从c(5,1234)return后,
		回到c(4,123)->a[4]=0由于i=n=4,
		又回到c(3,12)->a[3]=0->i++
		然后i=4进入c(4,124) */ 
	    }
	}
	else{
		if(x==n+1){ 
	        sprintf(b,"%lld",num);
	    for(i=0;b[i];i++){
	    	if(b[i+1]=='0'){
	    		printf("10 ");
				i++;
			}
			else
			printf("%c ",b[i]);
		}
	        printf("\n");
		return;
	    }
		for(i=1;i<n;i++){
		    if(a[i]==0){
			    a[i]=1; 
			    c(x+1,num*10+i);
			    a[i]=0;
		    }
	    }
	    if(i==10){
	    	if(a[i]==0){
			    a[i]=1;
			    c(x+1,num*100+i);
			    a[i]=0;
		    }
		}
    }   
}
int main()
{
	scanf("%d",&n);
	c(1,0);	//第一个参数代表当前正在考虑第几个数,第二个参数代表 当前的数字 
	return 0;
}


