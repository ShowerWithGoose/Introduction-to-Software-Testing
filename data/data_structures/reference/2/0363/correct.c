#include <stdio.h>
#include <string.h>

char s[100010];
char ch[100010];
char a[100010];
int cnt;
int b[100010],num;
int main() {
	gets(s);
	int i,j=0,n;
	for(i=0;i<strlen(s);i++) {
		if(s[i]==' ') continue;
		ch[j++]=s[i];
	}
	ch[j]='\0';
//	printf("%s\n",ch);
	long long ans=0;
	int lst=-1;
	for(i=0;i<strlen(ch);i++) {
		if(ch[i]=='+' || ch[i]=='-' || ch[i]=='*' || ch[i]=='/' || ch[i]=='=') {
			a[++cnt]=ch[i];
			num++;
			for(j=lst+1;j<=i-1;j++) {
				b[num]=b[num]*10+(int)(ch[j]-'0');
			}
			lst=i;
		}
	}
	lst=0;
	a[0]='+';
//	for(i=1;i<=cnt;i++) {
//		printf("%c %d\n",a[i],b[i]);
//	}
	for(i=1;i<=cnt;i++) {
		if(a[i]=='+' || a[i]=='-' || a[i]=='=') {
			int val=0;
			val=b[lst+1];
			if(lst!=i-1) 
			for(j=lst+1;j<i;j++) {
				if(a[j]=='*') val=val*b[j+1];
				if(a[j]=='/') val=val/b[j+1];
			}
			if(a[lst]=='+') ans+=val;
			if(a[lst]=='-') ans-=val;
//			printf("%d\n",val);
			lst=i;
		}
	}
	printf("%lld",ans);
	return 0;
}

