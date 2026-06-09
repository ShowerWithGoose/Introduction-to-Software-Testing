#include<stdio.h>
#include<string.h>

void string_extract_int(char *str,int numbers[]);

int calculate1(int p,int numbers2[],char cal2[]){
	int k;
	for(k=0;k<p-1;k++){
		if(cal2[k]=='+')numbers2[k+1]=numbers2[k]+numbers2[k+1];
		if(cal2[k]=='-')numbers2[k+1]=numbers2[k]-numbers2[k+1];
		
	}
	return 0;
}

int calculate2(int p,int numbers2[],char cal2[]){
	int k;
	for(k=0;k<p-1;k++){
		if(cal2[k]=='*')numbers2[k+1]=numbers2[k]*numbers2[k+1];
		if(cal2[k]=='/')numbers2[k+1]=numbers2[k]/numbers2[k+1];
		
	}
	return 0;
}

int  calc(char s){
	if(s=='+'||s=='-'||s=='*'||s=='/'||s=='=')
    return 1;
	return 0;	
} 

int main(){
	int i,j,k;
	int len1,len2;
	char string[1000];
    gets(string);
    len1 = strlen(string);
	char *str=string;
	int numbers1[100] = {0};
	int numbers2[100]={0};
	char cal1[100],cal2[100];
	string_extract_int(str,numbers1);
    for(i=0,j=0;i<len1;i++){
    	if(calc(string[i])==1)
    	{
    		cal1[j]=string[i];
			j++;
    	}
    }
    len2=strlen(cal1);
    if(cal1[0]=='='){//500 = 
    	printf("%d",numbers1[0]);
    	return 0;
    }
    int p=0;
    /*/for(i=0;i<len2;i++){//乘除运算 
    	if(cal1[i]=='*'){
    	   numbers1[i+1]=numbers1[i]*numbers1[i+1];	
        }
     }
     for(i=0;i<len2;i++){//乘除运算 
    	if(cal1[i]=='/'){
    	   numbers1[i+1]=numbers1[i]/numbers1[i+1];	
        }
     }*/
     calculate2(len2,numbers1,cal1);
     for(i=0;i<len2;i++){//计入加减 
     	if(cal1[i]=='+'||cal1[i]=='-'||cal1[i]=='='){
     		cal2[p]=cal1[i];numbers2[p]=numbers1[i];
			 p++;
     	 }
     }
    
    if(p==0){//纯乘 
       printf("%d",numbers1[len2-1]);
    	return 0;
    }
    
    //加减运算 
	calculate1(p,numbers2,cal2);
	//for(i=0;i<len2;i++)printf("%c ",cal1[i]);
	//for(i=0;i<len2;i++)printf("%d ",numbers1[i]);
    //for(i=0;i<p;i++)printf("%c ",cal2[i]);
    //printf("%d\n",p);
    //for(i=0;i<p;i++)printf("%d ",numbers2[i]);
    printf("%d",numbers2[p-1]);
    //puts(string);
	return 0;
}

void string_extract_int(char *str,int numbers[]){
	int n = 0;
	int temp = 0;
	int k;
	for(k=0;k<strlen(str);k++){
		if(str[k] >= '0' && str[k] <= '9'){
			temp++;
			if(str[k+1] > '9' || str[k+1] < '0'){
				numbers[n++] = atoi(str+k-temp+1);//转化数字 
				temp = 0;
			}
		}
	}
	return 0;
}


