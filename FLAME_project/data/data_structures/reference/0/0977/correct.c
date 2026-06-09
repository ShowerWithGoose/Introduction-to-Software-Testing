//扩展字符A 
/*从键盘输入包含扩展符'-'的字符串，将其扩展为等价
的完整字符，例如将a-d扩展为abcd，并输出扩展后的
字符串。
要求：只处理[a-z]、[A-Z]、[0-9]范围内的字符扩展，
即只有当扩展符前后的字符同时是小写字母、大写字母
或数字，并且扩展符后的字符大于扩展符前的字符时
才进行扩展，其它情况不进行扩展，原样输出。
例如：a-R、D-e、0-b、4-B等字符串都不进行扩展。*/
#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	char in[100];
	char A[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char a[]="abcdefghijklmnopqrstuvwxyz";
	char num[]="0123456789";
	int i,j,k;
	scanf("%s",in);
	int len=strlen(in);
	for(i=0;i<len;i++){
		if(in[i+1]!='-'){
			printf("%c",in[i]);
		}
		if(in[i+1]=='-'){
			if(in[i]<in[i+2]&&(in[i]<='z'&&in[i]>='a'&&in[i+2]<='z'&&in[i+2]>='a')){
				for(a[j]=in[i];a[j]<in[i+2];a[j]++){
					printf("%c",a[j]);
				}
				i=i+1;
			}
			else if(in[i]<in[i+2]&&(in[i]<='Z'&&in[i]>='A'&&in[i+2]<='Z'&&in[i+2]>='A')){
					for(A[j]=in[i];A[j]<in[i+2];A[j]++){
					printf("%c",A[j]);
				}
				i=i+1;
			}
			else if(in[i]<in[i+2]&&(in[i]<='9'&&in[i]>='0'&&in[i+2]<='9'&&in[i+2]>='0')){
					for(num[j]=in[i];num[j]<in[i+2];num[j]++){
					printf("%c",num[j]);
				}
				i=i+1;
			}
			else if(in[i]>=in[i+2]||!((in[i]<='z'&&in[i]>='a'&&in[i+2]<='z'&&in[i+2]>='a')&&(in[i]<='Z'&&in[i]>='A'&&in[i+2]<='Z'&&in[i+2]>='A')&&(in[i]<='9'&&in[i]>='0'&&in[i+2]<='9'&&in[i+2]>='0'))){
				printf("%c",in[i]);
			}
		}
	}
	return 0;
}










