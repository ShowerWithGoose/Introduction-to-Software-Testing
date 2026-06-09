
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include <stdio.h>
struct Line{
		int xi;
		int zhi;
	};
	struct Line line1[200];
	struct Line line2[200];
	struct Line lined[200];
	int geturn(char s[],struct Line linex[]);
	void num(struct Line a[],int size);
int main(){
	char c;
	int i=0;
	int j=0;
	int x=0;
	char s1[200],s2[200];
	gets(s1);
	gets(s2);
	int len1,len2;
	len1=geturn(s1,line1);
	len2=geturn(s2,line2);
	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++){
			lined[x].xi=line1[i].xi*line2[j].xi;
			lined[x].zhi=line1[i].zhi+line2[j].zhi;
			x++;
		}
	}
	int len3;
	len3=x;
	num(lined,len3);
	for(i=0;i<len3-1;i++){
		for(j=i+1;j<len3;j++){
			if(lined[i].zhi==lined[j].zhi){
				lined[i].xi=lined[i].xi+lined[j].xi;
				lined[j].xi=0;
			}
		}
	}
    num(lined,len3);
    for(i=0;i<len3;i++){
    	if(lined[i].xi==0){
    		continue;
		}else{
			printf("%d %d ",lined[i].xi,lined[i].zhi);
		}
	}
    return 0;
}
int geturn(char s[],struct Line linex[]){
	int i=0;
	int j=0;
	int num=0;
	int cnt=0;
	for(i=0;s[i]!='\0';i++){
		num=0;
		while(s[i]!=' '&&s[i]!='\0'){
			num=num*10+s[i]-'0';
			i++;
		}
		if(cnt%2==0){
			linex[j].xi=num;
			cnt++;
		}else{
			linex[j].zhi=num;
			cnt++;
			j++;
		}
	}
	return j;
}
void num(struct Line a[],int size){
	int i=0,j=0;
	int hold=0;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-1-i;j++){
			if (a[j].zhi<a[j+1].zhi){
				hold=a[j].zhi;
				a[j].zhi=a[j+1].zhi;
				a[j+1].zhi=hold;
				hold=a[j].xi;
				a[j].xi=a[j+1].xi;
				a[j+1].xi=hold;
			}
		}
	}
	return ;
}


