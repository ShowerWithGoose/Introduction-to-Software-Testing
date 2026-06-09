#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct _element{
	int an;
	int n;
}element,*pelement;
int num(char *s){
	int i=1;
	int a=0;
	for(a=s[0]-'0';s[i]!='\0';i++){
		a=a*10+(s[i]-'0');
	}
	return a;
}
int cmp(const void *p1,const void *p2){
	int ans;
	pelement element1=(pelement) p1;
	pelement element2=(pelement) p2;
	ans=-(element1->n-element2->n);
	return ans;
}
int main(){
	element a[1024];
	element b[1024];
	element c[1024];
	char ele1[1024];
	char ele2[1024];
	char mi[5];
	int m,i,j,k,anum,bnum;
	gets(ele1);
	gets(ele2);
	for(i=0,j=0,k=0;ele1[i]!='\0';i++){
		if(ele1[i]!=' '){
			mi[j]=ele1[i];
			j++;
		}else{
			if(k%2==0){
				a[k/2].an=num(mi);
				for(m=0;m<5;m++){
					if(mi[m]!='\0'){
						mi[m]='\0';
					}
				}
				j=0;
				k++;
			}else{
				a[k/2].n=num(mi);
				for(m=0;m<5;m++){
					if(mi[m]!='\0'){
						mi[m]='\0';
					}
				}
				j=0;
				k++;
			}
		}
	}
	a[k/2].n=num(mi);
	j=0;
	k++;
	a[k/2].an='\0';
	anum=k/2;
	for(m=0;m<5;m++){
		if(mi[m]!='\0'){
			mi[m]='\0';
		}
	}
	for(i=0,j=0,k=0;ele2[i]!='\0';i++){
		if(ele2[i]!=' '){
			mi[j]=ele2[i];
			j++;
		}else{
			if(k%2==0){
				b[k/2].an=num(mi);
				for(m=0;m<5;m++){
					if(mi[m]!='\0'){
						mi[m]='\0';
					}
				}
				j=0;
				k++;
			}else{
				b[k/2].n=num(mi);
				for(m=0;m<5;m++){
					if(mi[m]!='\0'){
						mi[m]='\0';
					}
				}
				j=0;
				k++;
			}
		}
	}
	b[k/2].n=num(mi);
	j=0;
	k++;
	b[k/2].an='\0';
	bnum=k/2;
	for(m=0;m<5;m++){
		if(mi[m]!='\0'){
			mi[m]='\0';
		}
	}
	for(i=0,k=0;a[i].an!='\0';i++){
		for(j=0;b[j].an!='\0';j++){
			c[k].an=a[i].an*b[j].an;
			c[k].n=a[i].n+b[j].n;
			for(m=0;m<k;m++){
				if(c[k].n==c[m].n){
					c[k].n=0;
					c[m].an+=c[k].an;
					k--;
					break;
				}
			}
			k++;
		}
	}
	qsort(c,k,sizeof(element),cmp);
	for(i=0;i<k;i++){
		printf("%d %d ",c[i].an,c[i].n);
	}
	return 0;
}

