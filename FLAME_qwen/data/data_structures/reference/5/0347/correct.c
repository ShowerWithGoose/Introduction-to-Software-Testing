#include<stdio.h>
#include<stdlib.h>
struct multi{
	int expo;//指数
	int coef;//系数 
};
struct multi a[1000],b[1000],res0[100000];
int comp(const void* p1,const void* p2){
      struct multi* a = (struct multi*) p1;
      struct multi* b = (struct multi*) p2;
      if(a->expo<b->expo){
      	return 1;
	  }
	  else if(a->expo > b->expo){
	  	return -1;
	  }
	  else{
	  	return 0;
	  }    
}
int main()
{
	int i = 0,j = 0,k = 0;
	int len1,len2,len;
	do{
	    scanf("%d%d",&a[i].coef,&a[i].expo);
	    len1 = i + 1;
	    i++;
	}while(getchar()!='\n');
	do{
	    scanf("%d%d",&b[j].coef,&b[j].expo);
	    len2 = j + 1;
	    j++;
	}while(getchar()!='\n');
	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++,k++){
			res0[k].coef =  a[i].coef * b[j].coef;
			res0[k].expo =  a[i].expo + b[j].expo;
		}
	}
	len = k;
	qsort(res0,len,sizeof(res0[0]),comp);
	for(i=0;i<len;i++){
	    for(j=i+1;j<len;j++){
	    	if(res0[i].expo == res0[j].expo){
	    		res0[j].coef = res0[j].coef + res0[i].coef; 
	    		res0[i].coef = 0;	
			}
		}
	}
	for(i=0;i<len;i++){
		if(res0[i].coef!=0){
			printf("%d %d ",res0[i].coef,res0[i].expo);
		}
	}
	return 0;
}


