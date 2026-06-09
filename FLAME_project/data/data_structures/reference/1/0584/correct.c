#include<stdio.h>
  
int arry[20]={0};

void swap(int a[],int k,int j){
	int temp;
	temp=arry[k];
	arry[k]=arry[j];
	arry[j]=temp;
}
  
void Permutation(int len)  
{    
    int i,j,k,l,r;  
    while (1)  
    {  
        for(i=0;i<len;i++){
        	printf("%d ",arry[i]);
		}
        printf("\n");
        for (j=len-2;j>=0&&arry[j]>arry[j+1];j--); 
        if (j<0) return; 
        for (k=len-1;k>j&&arry[k]<arry[j];k--);  
        swap(arry,k,j);  
        l=j+1;
        r=len-1;
        for (;l<r;l++,r--)  
            swap(arry,l,r);  
    }  
}  
  
int main()  
{  
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	arry[i]=i+1;
	}
    Permutation(n);  
    return 0;  
}

