#include<stdio.h>
#include<string.h>
int main()
{
 char ch[1000];
 char fh[10000];
 int num[1000],cnt_fh=1,cnt_num=0,cnt_jj=0,pos_jj[1000];	
 int i=0,j=0,len=0;
 fh[0]='+';
 while(fh[cnt_fh-1]!='='){
 scanf("%d", &num[cnt_num++]);
 char tmp_c;
 scanf("%c", &tmp_c);
 while(tmp_c==' ')
 	scanf("%c",&tmp_c);
    fh[cnt_fh++]=tmp_c;
 
 }          //存入符号和数字，并确定位置 
   
   
    for(i=0;i<cnt_fh;i++){
    	if(fh[i]=='+'||fh[i]=='-'){
    		pos_jj[cnt_jj++]=i;  		
		}
	}  
	pos_jj[cnt_jj]=cnt_fh-1;                                      //确定加减号的位置，数目
	
	
	
	int a,sum=0;
	for(i=0;i<cnt_jj;i++){
		a=num[pos_jj[i]];
		for(j=pos_jj[i]+1;j<pos_jj[i+1];j++){
			if(fh[j]=='*'){
				a*=num[j];
			}
			else if(fh[j]=='/'){
				a/=num[j];
			}
		}
		if(fh[pos_jj[i]]=='+'){
			sum+=a;
		}
		else if(fh[pos_jj[i]]=='-'){
			sum-=a;
		}
	}
	
	printf("%d", sum); 
 
    return 0;
}

