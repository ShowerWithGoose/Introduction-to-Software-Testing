#include<stdio.h>
#include<string.h>
#include<math.h>
int havechengchu(char d[]);
int calcu();
char *p;

int main(){
	int i,j,ans=0;
	char str[1000],t[1000]={0};
	gets(str);
	t[0]='+';
	for(i=0,j=1;str[i]!='=';i++){//录入数据，剔除空格
		if(str[i]!=' '){
			t[j]=str[i];
			j++;
		}	
	}
	p=t;
	while((*p)!='\0'){//遍历一轮，做第一层的加减法
		if((*p)=='+')
			ans = ans+calcu();
		else if((*p)=='-')
			ans = ans-calcu();
	}
	printf("%d",ans);
	return 0;
}

int havechengchu(char d[]){
	int i,l;
	l=strlen(d);
	for(i=0;i<l;i++){
		if(d[i]=='*' || d[i]=='/'){
			return 1;
		}
	}
	return 0;
}

int calcu(){
	char a[1000]={0},b[1000]={0},temp[1000]={0};
	char *q,c;
	int l,ll,ans=0,num=0;
	int i,j;
	sscanf(p,"%[+--]%[^+--]",&c,a);
	l=strlen(a);
	if(havechengchu(a)){//有乘除号则计算项内连乘除
		ans=1;
		b[0]='*';
		q=b;
		strcat(b,a);
		
 		while((*q)!='\0'){
			sscanf(q,"%[*-/]%[0-9]",&c,temp);
			ll=strlen(temp);
			for(i=ll-1,j=1;i>=0;i--,j++)
				num = num + (temp[i]-'0')*pow(10,j-1);
			if(c=='/')
				ans=ans/num;
			else if(c=='*')
				ans=ans*num;
			q=q+ll+1;
			num=0;
		}
		p=p+l+1;
		return ans;
	}
	else{//否则做项内数十进制转换
		ans=0;
		for(i=l-1,j=1;i>=0;i--,j++){
			ans = ans + (a[i]-'0')*pow(10,j-1);
		}
		p=p+l+1;
		return ans;
	}

}
