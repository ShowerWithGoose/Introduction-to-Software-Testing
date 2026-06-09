#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
	char s[1000];
	gets(s);
	int len1=strlen(s);
	int i,j=0;
	int len=0;
	for(i=0;i<len1;i++){
		if(s[i]!=' '){
			s[j++]=s[i];
			len++;
		}
	}
			
	int y;
	int ret=0;
	int op[1000]={0};
	int n=0;
	char opt='+';
	for(y=0;y<len;y++){
		if(s[y]>='0'&&s[y]<='9'){
		ret=ret*10+s[y]-'0';	
		}
		if(s[y]<'0'||s[y]>'9'||y==len-1){
			switch (opt) {
                case '+':
                    op[++n] =ret;
                    break;
                case '-':
                    op[++n]=-ret;
                    break;
                case '*':
                    op[n] *=ret;
                    break;
                case '/':
                    op[n] /= ret;
                    break;
                default:
                    break;
            }
            opt=s[y];
            ret=0;
		}
	}
	int k;
	int r;
	for(k=0;k<=n;k++){
		r+=op[k];
	}
	printf("%d\n",r);
	return 0;
}

