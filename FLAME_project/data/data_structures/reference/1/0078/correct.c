#include<stdio.h>
#include<string.h>

int a[15], b[15]={0}, n;
void qpl(int step){
	int i;  //为什么i必须在函数里定义一次   //从1开始 将其放在最前面 后面进行剩余数的全排列 实现递归
    if(step==n+1){        //输出前n个的全排列
        for(i=1;i<=n;i++) {
		 	printf("%d ",a[i]);
		}
        printf("\n");
        return;
    }                   //1 2 3 4  1243 1342 1324 1432 1423 2134 2143 2341 2314 2431 2413 3124
	for(i=1;i<=n;i++) {
    	if(b[i]==0){       // 判断
            a[step]=i;      // 第step位数字为第i个数字
			b[i]=1;        //该数字已使用 标记为1
            qpl(step+1);
            b[i]=0;     //将第i个数字收回
        }
	}
	return;
}
int main()
{
    scanf("%d", &n);
    qpl(1);
    return 0;
}




