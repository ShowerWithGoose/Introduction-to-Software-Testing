#include<stdio.h>
#include<stdlib.h>
struct Node{
	int coe;//xishu
	int pow;//mi
}a[50001],b[50001],c[500000];
int main(){
	int i=0,la,lb;
	for(i=0;;i++)
    {
        scanf("%d%d",&a[i].coe,&a[i].pow);
        la=i+1;
        if(getchar()=='\n')
            break;
    }
    i=0;
	for(i=0;;i++)
    {
        scanf("%d%d",&b[i].coe,&b[i].pow);
        lb=i+1;
        if(getchar()=='\n')
            break;
    }
    int n,k;
    i=0;
    for(i=0,n=0;i<la;i++){
    	for(k=0;k<lb;k++,n++){
    		c[n].coe =a[i].coe *b[k].coe ;
    		c[n].pow =a[i].pow +b[k].pow ;
    		
		}
	}
	int m,tmp,q;
	for(m=0;m<n+1;m++){
		for(q=m+1;q<n+1;q++){
		if(c[m].pow  <c[q].pow  ){
			tmp=c[m].coe ;
			c[m].coe =c[q].coe ;
			c[q].coe =tmp;
			tmp=c[m].pow ;
			c[m].pow =c[q].pow ;
			c[q].pow =tmp;
		}
		else if(c[m].pow ==c[q].pow ){
			c[m].coe +=c[q].coe ;
			c[q].coe =0;
			c[q].pow =0;
		}
	}
	}
	m=0;
	for(m=0;c[m].coe !=0;m++){
	  printf("%d %d ",c[m].coe ,c[m].pow );	
	}
	return 0;
}

