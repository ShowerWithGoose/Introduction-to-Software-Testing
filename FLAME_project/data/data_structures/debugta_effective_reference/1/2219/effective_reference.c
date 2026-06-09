#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int a[20]; 
int b[20];
int num1;
int compare(const void* a,const void* b){
	int* pa=(int*)a;
	int* pb=(int*)b;
	int num1=*pa;
	int num2=*pb;
	return num1-num2;//升序 
}
int main()
{
	int N,i,min,num2;
	int num1,k,m,temp,n;
	scanf("%d",&N);
	//for(i=0;i<N;i++){
	//	scanf("%d",&a[i]);
	//}
	switch (N){

		case 1: num2=1;break;
		case 2: num2=2;break;
		case 3: num2=6;break;
		case 4: num2=24;break;
		case 5: num2=120;break;
		case 6: num2=720;break;
		case 7: num2=5040;break;
		case 8: num2=40320;break;
		case 9: num2=362880;break;
		case 10: num2=2628800;break;
}	
    num2--;
	for(i=0;i<N;i++){  //初始化 全排列第一个（全递增）1 2 3 ...
		a[i]=i+1;
	}
	for(i=0;i<N;i++)
	printf("%d ",a[i]);
	printf("\n");
	while(num2--){

	for(i=N-1;i>=0;i--){
		if(a[i-1]<a[i]){   //递增 ，记录交换点为j 
			num1=i-1;
			break;
		}
	}
	for(i=num1+1,k=0;i<N;i++){  //找到后面所有比交换点值大的数 
		if(a[i]>a[num1]) 
		b[k++]=a[i];
	}
	qsort(b,k,sizeof(int),compare);  
	for(i=num1+1;i<N;i++){          //找到原数组中被交换点，记为m 
		if(a[i]==b[0]) {
		m=i;
		break;
	}
	}
	temp=a[num1];             //交换两个点的值 
	a[num1]=a[m];
	a[m]=temp;
	//for(i=0;i<N;i++)
	//printf("%d",a[i]);
	//printf("\n");
	if(num1<N-2){
	for(i=N-1,n=0;i>num1;i--,n++){  //使j位置后面的数逆序存储 ???
		b[n]=a[i];
	} 
	for(i=0,n=num1+1;i<N-num1-1;i++,n++){	
		a[n]=b[i];
	}
	} 
	for(i=0;i<N;i++)
	printf("%d ",a[i]);
	printf("\n");
	}
 return 0;
}

/*思路
非递归算法
从右到左扫描数组， 每次拿两个相邻的数字比较，如果前者大于后者则继续
直到找到前者小于后者（递增）的两个数，前者是准备交换的数字，记住它的位置（交换点），
然后在它后面找到所有大于它的数中的最小的那个，与之交换位置，所得的新数组
在交换点后面所有的数字逆序排列，最终得到的就是全排列中的下一个。 



*/



