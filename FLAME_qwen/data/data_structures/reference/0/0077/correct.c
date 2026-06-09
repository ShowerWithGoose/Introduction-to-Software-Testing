#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
char s[100];
int judge(char s[],int i);
int main()
{
	int i,j;
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++){
		if(s[i]!='-')       //是字符，直接输出 
		printf("%c",s[i]);
		else{               //是扩展符 
			if(judge(s,i)==1){   //判断合法，可扩展 
				for(j=s[i-1]+1;j<s[i+1];j++)
				printf("%c",j);
			}
			else printf("-");   //不合法 
		}
	}

 return 0;
}
int judge(char s[],int i){
	if(s[i-1]<s[i+1] && islower(s[i-1])*islower(s[i+1]))
	return 1;
	
	else if(s[i-1]<s[i+1] && isdigit(s[i-1])*isdigit(s[i+1])) 
	return 1; 
	
	else if(s[i-1]<s[i+1] && isupper(s[i-1])*isupper(s[i+1]))
	return 1;
	
	else return 0;
}
/*分析问题：
1、输入的数据：长短未知，可能有多个"-"，
其中扩展符前后类别一致且后大于前的扩展，其他不合法的扩展符保留。
2、特例：
①合法：ABD-G-Jc-k22-9（G左右两边都有-，输出的G不能重复
②不合法：c-a、9-2、（前大于后，不行） 
2-D、c-G、 （类别不一致）
③一半一半：A-D7-3（第一个扩，第二个不动） 
3、思路： 从左到右顺序扫描，扫到的是字符自动输出，扫到的是-，则看是否合法，若合法则从此位开始输出到
-右边字符的前一位，若不合法则输出-。然后继续扫描，循环以上判断过程。时间复杂度O（n）。 
*/


