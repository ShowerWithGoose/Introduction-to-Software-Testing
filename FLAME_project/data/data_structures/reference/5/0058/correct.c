//两个一元多项式的相乘
#include <stdio.h>
#include <stdlib.h>
#define NUM 128

struct List1 {
	long coef;     //系数 
	long index;     //指数 ;
	struct List1* next;
}; //保存第一个多项式 

struct List2 {
	long coef;     //系数 
	long index;     //指数 ;
	struct List2* next;
};//保存第二个多项式

struct List3 {
	long coef;     //系数 
	long index;     //指数 ;
	struct List3* next;
};//保存多项式相乘的结果 

typedef struct List1 *pList1;
typedef struct List2 *pList2;
typedef struct List3 *pList3;

pList1 Creat1()  //把多项式存入链表，从输入的字符串中提取数字 
{
	char str[NUM]="",*pstr;
	int i,j,k,m,e10,digit,ndigit;
	long a[NUM],*pa;
	struct List1 *head1,*p1,*p11,*tt;	
	ndigit = 0;        /*ndigit代表有多少个整数*/
	i = 0;             /*代表字符串中的第几个字符*/
	j = 0;	      //连续输入的整数有几位，j 是"1"表示个位，"2"表示个位和十位，"3"表示个位、十位和百位，以此类推。 
	gets(str);   //输入第一个多项式字符串 
    pstr = &str[0];  //字符串首地址赋值 
                 //下面程序把输入的字符串中，含有的数字找出来 
	while(*(pstr + i) != '\0')  //判断字符串是否结束？ 
	{
	    if((*(pstr + i) >= '0') && (*(pstr + i) <= '9'))  //字符是否为：0 - 9 数字 
	       j++;                                    //如果判断是数字，j 就累加 
	    else
	    {
		    if (j > 0)  //遇到非数字情况时，判断之前是否有过数字，j>0 证明之前出现过数字 
	        {
			    digit = *(pstr + i - 1) - 48;     //把当前指针减1，即得到前一个数字的值(ASCⅡ)，这个值就是个位，赋予digit。 
	            k = 1;                   //K = 1 表示个位 
	            while (k < j)     //j>1表示含有两位以上的数，每循环一次 *10
	            {
				    e10 = 1;
	                for (m = 1; m <= k; m++)
	                    e10 = e10*10;                  //e10代表该位数所应乘的因子
	                digit = digit + (*(pstr + i - 1 - k) - 48) * e10;  //将该位数的数值\累加于digit
	                k++;                   //位数K自增
	            }
	            a[ndigit] = digit;       //将数值赋予数组a[NUM]				        
	            ndigit++;             //ndigit自增	                              
	            j = 0;                 //这一组数值已计算完成，j 就归零	
	        }
	    }
	    i++;                  //字符指针指向下一个地址 
	}	
	if (j > 0)               //此时指针已指到字符串结尾，判断之前是否有过数字，j>0 证明之前出现过数字   
	{
	    digit = *(pstr + i - 1) - 48;          //将个数位赋予digit
	    k = 1;
	    while (k < j)              // 将含有两位以上数的其它位的数值累加于digit
	    {
		    e10 = 1;
	        for (m = 1; m <= k; m++)
	            e10 = e10*10;             //e10代表位数所应乘的因子
	        digit = digit + (*(pstr+i-1-k)-48)*e10;  //将该位数的数值累加于digit
	        k++;                                //位数K自增
	    }
	    a[ndigit] = digit;            //将数值赋予数组a		    		                
	    ndigit++;	    
	    j = 0;
	}
    pa = &a[0];  //把存储数据的首地址赋给pa 
	p11 = p1 = (pList1)malloc(sizeof(struct List1));  //把新分配的内存地址赋给p1和p11 
	for (j = 0; j < ndigit/2; j++)     /*初始化数据*/
	{
		if (j == 0)  
	        head1= p1;	//把动态内存空间地址赋给链表头    		    			   
	    else 
		{
		    p11->next = p1; //把新开辟的地址赋给前一个链表 	
	    }
		p1->coef = *pa++;	//先赋值，再把指针指向下一个地址		
		p1->index = *pa; //赋值 
	    p11 = p1; 	//把当前地址赋给p11   	
		p1 = (pList1)malloc(sizeof(struct List1));	//把下一个分配的内存地址赋给p1 
		pa++;		//指针指向下一个地址	  		
	}
	p11->next = NULL; //链表结束标志 		
	return (head1);  //返回链表头地址 
}

pList2 Creat2()  //把多项式存入链表 
{
    char str[NUM]="",*pstr;
	int i,j,k,m,e10,digit,ndigit;
	struct List2 *head2,*p2,*p22,*tt;  //;
	long a[NUM],*pa;                   /*指针pa置于 a 数组首地址*/
	ndigit = 0;        /*ndigit代表有多少个整数*/
	i = 0;             /*代表字符串中的第几个字符*/
	j = 0;	
	gets(str);   //输入第一个多项式
    pstr = &str[0];
	while(*(pstr+i) != '\0')  //判断字符串是否完成？ 
	{
	    if((*(pstr+i) >= '0') && (*(pstr+i) <= '9'))  //是否为数字？ 
	       j++;
	    else
	    {
		    if (j > 0)
	        {
			    digit = *(pstr+i-1)-48;          //将个数位赋予digit
	            k=1;
	            while (k<j)        //将含有两位以上数的其它位的数值累计于digit
	            {
				    e10 = 1;
	                for (m = 1; m <= k; m++)
	                    e10 = e10*10;                    //e10代表该位数所应乘的因子
	                digit = digit+(*(pstr+i-1-k)-48)*e10;   //将该位数的数值\累加于digit
	                k++;                   //位数K自增
	            }
	            a[ndigit] = digit;               //将数值赋予数组a
	            ndigit++;	                                
	            j = 0;
	        }
	    }
	    i++;
	}	
	if (j > 0)                    //以数字结尾字符串的最后一个数据
	{
	    digit = *(pstr+i-1)-48;          //将个数位赋予digit
	    k = 1;
	    while (k<j)          ///将含有两位以上数的其它位的数值累加于digit
	    {
		    e10=1;
	        for (m = 1; m <= k; m++)
	            e10 = e10*10;            //e10代表位数所应乘的因子
	        digit = digit+(*(pstr+i-1-k)-48)*e10;  //将该位数的数值累加于digit
	        k++;                               //位数K自增
	    }
	    a[ndigit]=digit;                 //将数值赋予数组
	    ndigit++;
	    j = 0;
	}
    pa = &a[0];  //把存储数据的首地址赋给pa 
	p22 = p2 = (pList2)malloc(sizeof(struct List2));
	for (j = 0;j < ndigit/2; j++)     /*初始化数据*/
	{
		if (j==0)
	        head2 = p2;	//把动态内存空间地址赋给链表头    		    			   
	    else 
		{
		    p22->next = p2; //把新开辟的地址赋给前一个链表 	
	    }
		p2->coef = *pa++;		
		p2->index = *pa;		
	    p22 = p2; 	//把当前地址赋给p22   
	    p2 = (pList2)malloc(sizeof(struct List2));
	    pa++;
	}
    p22->next=NULL; //链表结束标志	
	return (head2);  //返回链表头地址 	
}

pList3 PolyMult(pList1 P1, pList2 P2)  //多项式相乘,存入链表3 
{
	struct List1 *t1;
	struct List2 *t2;
	struct List3 *pf3,*t3,*head,*tt;
	int i = 0; 
	
	if (!P1 || !P2) return NULL;  //判断是否空的链表？ 	    

	t1 = P1;   //把链表头地址赋值 
	t2 = P2;  //把链表头地址赋值 
	while (t1 != NULL)  //判断是否到尾
	{
		t2 = P2;  //重新开始，把链表头地址赋值t2 
		while (t2 != NULL)  //判断是否到尾 
		{
			t3 = (pList3)malloc(sizeof(struct List3));
		    if (i == 0)  head = t3; //链表头赋值 
		    else pf3->next = t3;			
			t3->coef = t1->coef * t2->coef;   //系数相乘
			t3->index = t1->index + t2->index; //指数相加 
			pf3 = t3;                      //把当前地址赋给pf3 
			t2 = t2->next;	      //指向下一个地址 	
			i = 1;				
		}
		t1 = t1->next;           //指向下一个地址 	
	}
	pf3->next = NULL;          //结束标志 
// 	printf("\n",i);  	    
	return head;
}

void SortPrint(pList3 P3) //链表3重新排序 
{
	struct List3 *t3,*t4,*temp,*head,*tt;
	int co = 0,in = 0;	
		
	if (!P3) return;
	
	t3 = head = P3;  //保存链表头地址 
	while (t3 != NULL) //合并同类项 
	{
		t4 = t3->next;		
	    while (t4 != NULL)		
	    {
            if(t3->index == t4->index)  //指数是否相等 
            {   
			    t3->coef = t3->coef + t4->coef;   //系数相加 
			    if(t4->next != NULL)  //是否到尾部				
				{
					temp = t4->next; //把下一个结点地址赋值 
				    t4->coef = temp->coef;  //下一个结点数据赋值给 t4 
				    t4->index = temp->index; 
				    t4->next = temp->next;	
				}   							    		  								
		    }				    	
			t4 = t4->next;
		}
		t3 = t3->next;
	}	
	t3 = head; 			   		
	while (t3 != NULL) //按照指数从高到低排序 
	{
		t4 = t3->next;		
	    while (t4 != NULL)		
	    {
            if(t3->index < t4->index)  //比较指数大小 
            {   
				co = t4->coef;  // 内容交换 地址不变 
				in = t4->index; 
				t4->coef = t3->coef; 
				t4->index = t3->index;	   							    		  								
				t3->coef = co; 
				t3->index = in; 				
		    }				    	
			t4 = t4->next;
		}
		t3 = t3->next;		
	}	
	t3 = head; 	//赋值链表头地址 
	while (t3 != NULL)
	{
         printf("%ld %ld ", t3->coef, t3->index);   //最后输出结果          
         t3 = t3->next; 
	}   	
	return;
}

int main()
{
	struct List1 *p1;	
	struct List2 *p2;
	struct List3 *p3;	
	p1 = Creat1(); //存入链表1	 	  	
	p2 = Creat2(); //存入链表2 	
    p3 = PolyMult(p1, p2); //相乘后存入链表3
	SortPrint(p3); //链表3排序 	
	return 0;
}


