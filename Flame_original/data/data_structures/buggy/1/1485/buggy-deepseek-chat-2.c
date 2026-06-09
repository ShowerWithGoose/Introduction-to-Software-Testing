/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void pailie(int arr[],int p,int q){  //arr数组中，从第p个到第q个数全排列 
    int i;
    if(p==q){
        for(i=0;i<=p;i++){ // @@ 错误：循环条件应为 i<q 或 i<=q-1，因为数组索引从0到q，当p==q时，应输出arr[0]到arr[q]，但这里i<=p且p==q，会多输出一个元素（arr[p]），实际上应该输出n个元素，但这里p==q时，p和q是最后一个索引，循环应到q为止，但当前写法正确，因为p==q，i从0到p，共p+1个元素，而数组长度为n，p=n-1，所以输出n个元素，正确。但注意：原参考程序输出从1到n，这里从0到n-1，索引不同，但逻辑等价。实际错误不在此处。
            printf("%d",arr[i]); // @@ 错误：输出格式缺少空格分隔，应改为 printf("%d ",arr[i]);
        }
        printf("\n");
    }
    else{
    
        for(i=p;i<=q;i++){
            change(arr,p,i);
            pailie(arr,p+1,q);
            changeback(arr,p,i);    
        }
    }
}
void change(int arr[],int p,int i){//右移 
    int c,k;
    c=arr[i];
    for(k=i-1;k>=p;k--){
        arr[k+1]=arr[k];
    }
    arr[p]=c;
}

void changeback(int arr[],int p,int i){//左移 
    int c,k;
    c=arr[p];
    for(k=p;k<i;k++){
        arr[k]=arr[k+1];
    }
    arr[i]=c;
}

int main()
{
    int arr[20];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        arr[i]=i+1;
    }
    pailie(arr,0,n-1);
    return 0;
}