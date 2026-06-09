#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void printfs(int s[],int n);
void swap(int *a,int *b);
int jiecheng(int n);
void reverse(int *hi,int *lo);
int main(){
	int n,k=0,m=0,i=0,count=1,s[12];
	scanf("%d",&n);
	while(k<=(n-1)){
		s[k]=k+1;
		k++;
	}
	printfs(s,n);
	while(count<jiecheng(n)){
		k=n-1;
		while(s[k-1]>s[k]){
			k--;
		}
		i=k-1;
		k=n-1;
		while(s[k]<s[i]){
			k--;
		}
		m=k;
		swap(&s[i],&s[m]);
		reverse(&s[n-1],&s[i+1]);
		printfs(s,n);
		count++;
	}
	return 0;
}
void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void printfs(int s[],int n){
	int p=0;
	while(p<=n-1){
		printf("%d ",s[p]);
		p++;
	}
	printf("\n");
}
int jiecheng(int n){
	if(n==1) return 1;
	else return n*jiecheng(n-1);
}
void reverse(int *hi,int *lo){
    int t;
    while(hi>lo){
        t=*lo;
        *lo=*hi;
        *hi=t;
        lo++,hi--;
    }
    return 0;
}

