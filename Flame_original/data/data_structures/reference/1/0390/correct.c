#include <stdio.h>
int Next_Permutation(int a[], int n);
void dict_Permutation(int a[],int n);
void sort(int *a,int* b);
int main(){
    int i,n,cnt;
    int a[10];
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        a[i]=i+1;
    }
    dict_Permutation(a,n);
    return 0;
}
int Next_Permutation(int a[], int n){
    int i,m,temp;
    for(i = n-2;i >= 0;i--){
        if(a[i+1] > a[i]) 
		break;
    }
    if(i < 0) 
		return 0;
    m = i;
    i++;
    for(;i<n;i++){
        if(a[i] <= a[m]){
            i--;
            break;
        }
        else if(i==n-1) 
		break;
        }
    temp=a[m];
    a[m]=a[i];
    a[i]=temp;
    sort(a+m+1,a+n-1);
    printf("%d",a[0]);
    for(int i=1;i<n;i++){
        printf(" %d",a[i]);
    }
    printf("\n");
    return 1;
}

void dict_Permutation(int a[],int n){
    sort(a,a+n-1);
    printf("%d",a[0]);
    for(int i=1;i<n;i++){
        printf(" %d",a[i]);
    }
    printf("\n");
    while(Next_Permutation(a,n));
}

void sort(int *a,int* b){
	int *p,t,*q;
	if(a<b)
	for(q=b;q>=a;q--){
		for(p=a;p<b;p++){
			if(*p>*(p+1)){
				t=*p;
				*p=*(p+1);
				*(p+1)=t;	
			}
		}
	}
}



