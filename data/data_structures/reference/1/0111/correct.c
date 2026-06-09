#include<stdio.h>
#include<string.h>
char str[12],temp[12];//tmpt用来输出全排列的每一个结果
int len;
int flag[12];  //用来判断str中的第i个位置字符是否进行了此次排列 
void dfs(int step){//当step=0,执行的dfs(0),选定了tmpt第一位字母，执行dfs(1),选定tmpt第二位字母，以此类推
	int i;
	if(step==len){ //只要执行的是dfs(step),tmpt的第step+1位的字母就被选定 
		temp[step]='\0';  
		for(i=0;i<len;i++){
			printf("%c ",temp[i]);
		}
		printf("\n");
	}
	for(i=0;i<len;i++){  
		if(flag[i]==0){    
			flag[i]=1;
			temp[step]=str[i]; //tmpt[step]的值由i和 flag[i]共同决定
			dfs(step+1);
			flag[i]=0;	//每一次dfs(step+1)调用完成后flag[i]被置为0，str[i]又回到了未被排序的状态 
		}
	}
}
int main(){
	int N;
	scanf("%d",&N);
	int i,j,k;
	for(i=0;i<N;i++){
		str[i]=i+1+'0';
	}
	len=strlen(str);
	dfs(0);

	return 0;
}


