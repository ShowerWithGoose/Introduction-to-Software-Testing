#include<stdio.h>
#include <math.h> //数学公式
#include <stdlib.h> //快排和malloc
#include <ctype.h> //字符处理函数
#include <string.h> //字符串函数
#define ll long long
#define eps 1e-6
#define MAX 1000005
int l1[MAX];
int l2[MAX];
int n;
void put();
void pai(int t);
int main() {
	scanf("%d",&n);
	pai(0);
	return 0;
}
void pai(int t){
	if(t==n) put();
	else {
		for(int i=0;i<n;i++){
			if(l1[i]==0){
				l1[i] = 1; 
                l2[t] = i+1; 
                pai(t+1); 
                l1[i] = 0; 
			}
		}
	}
}
void put(){ 
        int i; 
        for(i = 0; i < n-1; i++){
        printf("%d ", l2[i]); 
    }
        printf("%d", l2[i]);
        printf("\n"); 
    } 



