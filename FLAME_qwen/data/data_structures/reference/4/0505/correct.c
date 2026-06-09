#include<stdio.h>
#include<string.h>
struct zi{
	char fu[1000];
	int cnt; //存字频 
}zi[10000],temp;

int main()
{ 
	int i=0,j=0,k=0,flag=1,len=0;     //flag要初始化为1 ？？？？？ 
	char ch[1000]={0},c;
	FILE *in;
	in=fopen("article.txt", "r");
	while((c=fgetc(in))!=EOF){
		if(c>='a'&&c<='z'){
			ch[i]=c;
			i++;
		}
		else if(c>='A'&&c<='Z'){
			c=c+'a'-'A';
			ch[i]=c;
			i++;
		}
		else{
     		if(strcmp(ch,"\0")!=0){              //防止    ch为空字符      eg: abcd  ef 读完abcd后，会进行空格符的读入，但是由于已经将ch清空故此时ch为空，若不加判断，会将空格符创为一个新单词 
			for(j=0;j<len;j++){  //len―>已经读入的不同单词的个数 
				if(strcmp(ch,zi[j].fu)==0){
					zi[j].cnt++;
					flag=0;
					break;
				}
				else{
					flag=1;   //1代表ch在之前未被读取过 
				}
			}                  //比较ch之前是否被读取过 
			
	        if(flag==1){
	        	strcpy(zi[len].fu,ch);
	        	zi[len].cnt=1;
	        	len++; 
			}                   //之前未有,就新建一个单词  	
	    for(k=0;k<100;k++){
	     	ch[k]='\0';
			}                 //初始化ch 
	        
	        i=0;
		}
	   
	} 
}
	for(i=0;i<len;i++){
		for(j=i;j<len;j++){
			if(strcmp(zi[i].fu,zi[j].fu)>0){
				temp=zi[i];
				zi[i]=zi[j];
				zi[j]=temp;
			}
		}
	}                    //冒泡排序 
	
	for(i=0;i<len;i++){
	    printf("%s %d\n", zi[i].fu, zi[i].cnt);
	}
	
	fclose(in);
}

