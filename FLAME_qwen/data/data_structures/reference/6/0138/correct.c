#include<time.h>
#include<math.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define eps 1e-5
//注意flag和qsort的组合用法（用结构体套flag）
//break和continue的深思熟虑
//freopen 不是万能的
///////结构体数组作为函数参数来传递时  并不是像普通数组一样作为地址    这点一定注意
//循环时的数组下标 和自加的顺序 一定不要弄错
///传递的地址在函数中操作时：1.在给定的地址对应的内存单元上操作 2.在函数中用新指针但是操作中未涉及对指针对应的地址的数据操作则相当于跨函数的无效操作
///有关双变量i j 的搜索一定要注意i和j的两种情况都要跟进
struct aaa{
		int a[10000];
		int top;
	}s; 
int main()
{
	
	int op,data,k=0,flag=0;
	s.top=-1;
	while(scanf("%d",&op))
	{
		if(op==-1) break;
		if(op==0)
		{
			if(s.top==-1) printf("error ");
			else {
				printf("%d ",s.a[s.top]);
				s.top--;
			}
			
		}
		
		if(op==1)
		{
			scanf("%d",&data);
			if(s.top==99)
			{
				printf("error ");
				flag=1;
			}
		else 
			{
				s.top++;
				s.a[s.top]=data;
			}
			
			
		}
		
	}
	return 0;
	
	
	
	
//	return 0;
}


