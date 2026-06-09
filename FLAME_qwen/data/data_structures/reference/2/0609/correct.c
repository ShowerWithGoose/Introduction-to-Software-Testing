#include<stdio.h>
#include<string.h>
char a[1000010];
long long tp[100010];
int cnt1=0,cnt2=0;
char cal[100010];
long long read (int p){
	long long ans =0 ;
	while (a[p]>='0'&&a[p]<='9'){
		ans =ans*10+a[p]-'0';
		p++;
	}
	return ans;
}
int main (){
//	srand (time(0));
	gets(a+1);
	int n=strlen(a+1);
	for (int i=1;i<=n;i++){
		if (a[i]==' ') continue;
		if (a[i]>='0'&&a[i]<='9'){
			long long ans =0 ;
			while (a[i]>='0'&&a[i]<='9'){
			ans =ans*10+a[i]-'0';
			i++;
			}
			i--;
			tp[++cnt1]=ans;
			//continue;
		}else{
			cal[++cnt2]=a[i];
		}
	}
	cal[0]='+';
	long long tmp=0;
	int pp=1;
	for (int i=0;i<=cnt2;i++){
		if (cal[i]=='+'||cal[i]=='-'){
			char ch1=cal[i];
			long long t1=tp[pp++];
			i++;
			while (cal[i]=='*'||cal[i]=='/'){
				if (cal[i]=='*'){
					t1=tp[pp++]*t1;
				}else{
					t1=t1/tp[pp++];
				}
				i++;
			}
			if (ch1=='+'){
				tmp+=t1;
			}else{
				tmp-=t1;
			}
			i--;
		}
	}

	printf("%lld",tmp);
	return 0;
}
