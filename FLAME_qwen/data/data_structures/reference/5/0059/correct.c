#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define tolower(c)  ((c)>='A'&&(c)<='Z'?'a'+c-'A':c)
#define For(i,a,b) for(int i = (a); i < (b); i++)
#define Form(i,a,b) for(int i = (a); i >= (b); i--)
#define If(a,b) if(a ==  b)
#define If1(a,b) else if(a< b)
#define If2(a,b,c) if(a >=  b && a <= c)
//10 80000 2 6000 7 300 5 10 18 0
//3 6000 5 20 8 10 6 0
//½á¹û30 86000 50 80020 80 80010 60 80000 6 12000 21 6300 10 6020 31 6010 66 6000 35 320 56 310 42 300 25 30 130 20 174 10 108 0 
struct item{
    int coe;
    int pow;
};

int main(){
	int a[1005];
	int b[1005];
	int m=0;
	int n=0;
	int i=0;
	int j=0;
	int k=0;
	struct item array[1005], array1[1005],array2[1005],temp;
	while(scanf("%d",&a[m]) != EOF && getchar()!='\n')  m++;
	while(scanf("%d",&b[n]) != EOF && getchar()!='\n')  n++;
	m+=1;n+=1;
	For(i , 0,  m){
		if(i % 2 == 0){
			array1[i/2].coe = a[i];
		}
		else{
			array1[i/2].pow = a[i];
		}
	}
	
	For(i , 0, n){
		if(i % 2 == 0){
			array2[i/2].coe = b[i];
		}
		else{
			array2[i/2].pow = b[i];
		}
	}
	For(i , 0 , m/2){
		For(j , 0,  n/2){
			array[k].coe = array1[i].coe * array2[j].coe;
			array[k].pow = array1[i].pow + array2[j].pow;
			k++;
		}
	}
	For(j , 0, k-1){
		For(i , 0,  k-j-1){
			if(array[i].pow < array[i+1].pow){
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp; 
			}
		}
	}
	For(i , 0, k){
		while(i<k-1&&array[i+1].pow==array[i].pow){
			array[i+1].coe+=array[i].coe;
			i++;
		}
		printf("%d %d ",array[i].coe,array[i].pow);
	}
	return 0;
}










