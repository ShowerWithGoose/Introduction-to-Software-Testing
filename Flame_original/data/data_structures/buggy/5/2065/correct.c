#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct{
	int num;
	int exp;
}asketla;
asketla a[100],b[100],c[1000];

int cmp(const void*aa,const void*ab){
	if(((asketla*)aa)->exp<((asketla*)ab)->exp)
	return 1;
	return -1;
} 

int main(){
    int i;
    for(i=0;;i++){
    	scanf("%d%d",&a[i].num,&a[i].exp);
    	if(getchar()=='\n')
    	break;
	}
	int m=0;
	for(int j=0;;j++){
    	scanf("%d%d",&b[j].num,&b[j].exp);
		for(int k=0;k<=i;k++,m++){
			c[m].num =a[k].num*b[j].num ;
			c[m].exp =a[k].exp+b[j].exp ;
		}
		if(getchar()=='\n')
    	break;		
	}
	int sum=m;
	for(int k=0;k<m;k++){
		for(int xk=0;xk<sum;xk++){
			if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
				c[k].num+=c[xk].num ;
				c[xk].exp=-1;
				sum--; 
			}
		}
	}
	qsort(c,m,sizeof(asketla),cmp);
	for(int s=0;s<sum;s++){
		printf("%d %d ",c[s].num,c[s].exp);
	}
	return 0;
	
}



