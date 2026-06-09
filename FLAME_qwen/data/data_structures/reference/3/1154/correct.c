#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main(){
	char s[105];
	gets(s);
	int i,j,pos1=0,pos2;
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] == '.')
			pos1 = i;
	}
			
			//pos1是小数点的位置 
			if(pos1 ==1){//整数不大于10 
				if(s[0] == '0'){ //小于1的情况 
					for(j = 2; j < strlen(s);j ++){
						if(s[j] !='0'){                
							pos2 = j; //pos2是小数点后第一个非零数位置 
							break;
						}
					}
					if(pos2 == strlen(s) - 1){//小数点后都为0 
						printf("%ce-%d",s[pos2],pos2 - 1);
					}
					else{//需要输出小数点后的情况 
						printf("%c.",s[pos2]);
						for(j = pos2 + 1;s[j] != '\0';j ++)
							printf("%c",s[j]);
						printf("e-%d",pos2 - 1);
					}
								
				}	
				else{//整数部分大于1小于10 
					for(j = 0; j < strlen(s);j ++)
						printf("%c",s[j]);
					printf("e0"); 
				}
			}  
		else if( pos1 == 0)
		    puts(s);
		else if(pos1 > 1){
			printf("%c.",s[0]);
			for( j = 1; j <= pos1 - 1 ;j ++)
			    printf("%c",s[j]);
			for( j = pos1 + 1; s[j] != '\0'; j++)
			    printf("%c",s[j]);
			printf("e%d",pos1 - 1);
		}	
    return 0;
}

