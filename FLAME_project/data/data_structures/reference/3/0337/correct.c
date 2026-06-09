#include <stdio.h>
#include <string.h>

/*  */

//注意：字符数100以内 
//转换思想：字符串 

//步骤1：读入
//步骤二：找第一个非零数字字符 ，与小数点所在位置作差 
 
 

int main(){
	char s_0[150]={"\0"};//record by "i_0"
	char s_1[150]={"\0"};//record by "i_1"
	
	gets(s_0);
	
	int i = strlen(s_0) - 1;
	int j_p;// for point
	int j_1;// for ~0
	for(;i>=0;i--){
		if(s_0[i] == '.') j_p = i;
		if(s_0[i]>'0'&&s_0[i]<='9') j_1 = i;
	}
		
	i = strlen(s_0) - 1;
	int e = j_p - j_1;
	int i_1 = 0;
	s_1[i_1++] = s_0[j_1++];
	if(i-j_1>=1) s_1[i_1++] = '.';//如果数字字符多于1个，加点 
	if(e > 0){
		e -= 1;
		for(;j_1<=i;j_1++)
			if(s_0[j_1] != '.') s_1[i_1++] = s_0[j_1];
	} 
	else
		for(;j_1<=i;j_1++) s_1[i_1++] = s_0[j_1];
	
	
	printf("%se%d",s_1,e); 
	
	
	return 0; 
}



