#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct lln{
		int item;
		struct lln *pnext;
}llist;
char s[100000],cul[1000];
int main()
{
	int num[1000]={0};
	 
	gets(s);
	int i,j,k,ans=0;
	for(i=j=0;i<strlen(s);i++){
		if(s[i]!=32){
			s[j] = s[i]; j++;}
	}
	for(i=0,k=0;i<j;i++){
		if(s[i]>='0' && s[i]<='9'){
			num[k] *= 10;
			num[k] += s[i]-'0';
		}
		else{
			if(s[i]!='=') 
			cul[k] = s[i];
			switch(cul[k-1]){
				case'*': {
					num[k-1] *= num[k];
					num[k]=0;
					cul[k-1] = cul[k];
					k--;
					break;
				}
				case'/': {
					num[k-1] /= num[k];
					num[k]=0;
					cul[k-1] = cul[k];
					k--;
					break;
				}
				default: break;
			}
			k++;
		}
	}
	ans=num[0];
	for(i=0;i<k-1;i++){
		if(cul[i]=='+')
			ans += num[i+1];
		else
			ans -= num[i+1];
	}
	printf("%d",ans);
    return 0;
}

