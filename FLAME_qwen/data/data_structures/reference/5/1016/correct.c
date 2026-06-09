#include <stdio.h>
#include <string.h>
struct x1{
	long long xishu;
	long long zhishu;
}x1[100];
struct x2{
	long long xishu;
	long long zhishu;
}x2[100];
struct ans{
	long long xishu;
	long long zhishu;
}ans[10000];
void paixu(int num,struct ans ans[10000]){
	long long p,q;
	int i,j;
	for(i=0;i<num;i++){
		for(j=i+1;j<num;j++){
			if(ans[j].zhishu>=ans[i].zhishu){
				p=ans[i].zhishu;
				ans[i].zhishu=ans[j].zhishu;
				ans[j].zhishu=p;
				q=ans[i].xishu;
				ans[i].xishu=ans[j].xishu;
				ans[j].xishu=q;
			}
		}
	}
}
int main()
    {
    	int i=0,j=0,m=0,num1,num2,num;
    	long long a[10000]={0},b[10000]={0};
        char s[10000],ch[10000];
        gets(s);
        //while(s[i]!='\n'){
        //	if(s[i]!=' '){
        //		a[j]=10*a[j]+(s[i]-'0');
        //		i++;
		//	}
		//	else{
		//		i++;
		//		j++;
		//	}
		//}
		//num1=(j+1)/2;
		//i=0;
		//for(j=0;j<num1;j++){
		    //x1[j].xishu =a[i];
	        //x1[j].zhishu =a[i+1];
	      //  i=i+2;
		//}
	//	for(i=0;i<2*num1;i++) printf("%d ",a[i] );
	    for(i=0;i<strlen(s);i++){
	    	if(s[i]>='0'&&s[i]<='9') a[j]=a[j]*10+(s[i]-'0');
	    	else j++;
		}
		num1=(j+1)/2;
		i=0;
		for(j=0;j<num1;j++){
		    x1[j].xishu =a[i];
	        x1[j].zhishu =a[i+1];
	        i=i+2;
		}
		i=0;
		j=0;
		gets(ch);
		for(i=0;i<strlen(ch);i++){
	    	if(ch[i]>='0'&&ch[i]<='9') b[j]=b[j]*10+(ch[i]-'0');
	    	else j++;
		}
		num2=(j+1)/2;
		i=0;
		for(j=0;j<num2;j++){
		    x2[j].xishu =b[i];
	        x2[j].zhishu =b[i+1];
	        i=i+2;
		}
		i=0;
		j=0;
        /*while(ch[i]!='\n'){
        	if(ch[i]!=' '){
        		b[j]=10*b[j]+(ch[i]-'0');
        		i++;
			}
			else{
				i++;
				j++;
			}
		}
		num2=(j+1)/2;
		i=0;
		for(j=0;j<num2;j++){
		    x2[j].xishu =b[i];
	        x2[j].zhishu =b[i+1];
	        i=i+2;
		}*/
		//for(i=0;i<num1;i++) printf("%lld %lld ",x1[i].xishu ,x1[i].zhishu );
		//for(i=0;i<num2;i++) printf("%lld %lld ",x2[i].xishu,x2[i].zhishu  );
		for(i=0;i<num1;i++){
			for(j=0;j<num2;j++){
				ans[m].xishu=x1[i].xishu*x2[j].xishu;
				ans[m].zhishu=x1[i].zhishu+x2[j].zhishu;
				m++;
			}
		}
		num=m;
		paixu(num,ans);
		for(i=0;i<num;i++){
			for(j=i+1;j<num;j++){
				if(ans[i].zhishu==ans[j].zhishu&&ans[i].xishu!=0){
					ans[i].xishu=ans[i].xishu+ans[j].xishu;
					ans[j].xishu=0;
				}
			}
		}
		for(i=0;i<num;i++){
			if(ans[i].xishu!=0) printf("%lld %lld ",ans[i].xishu,ans[i].zhishu);
		}
		return 0;
	}

