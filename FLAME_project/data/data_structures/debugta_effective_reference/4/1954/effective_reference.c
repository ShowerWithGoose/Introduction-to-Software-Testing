#include<stdio.h>
#include<string.h>
#include<math.h>

struct mode{
    	char s[100];
    	int cs;
	};
    typedef struct mode dccs;
    dccs w[1005];
        char ch,gh[100];
int cmp(dccs*,dccs*);
int main(){
    
    FILE *in;

    int n,k=0,i,op=0,flag=0,num;
    in=fopen("article.txt","r");
    while(fscanf(in,"%c",&ch)!=EOF){
    	if(flag==0&&((ch<=90&&ch>=65)||(ch<=122&&ch>=97))){
    		flag=1;
    		k=0;
    		if(ch<=90&&ch>=65){
    			ch=ch+32;
			}
		gh[k]=ch;	
		continue;
		}
		if(flag==1&&((ch<=90&&ch>=65)||(ch<=122&&ch>=97))){
			k++;
			if(ch<=90&&ch>=65){
				ch=ch+32;
			}
			gh[k]=ch;
			continue;
		}
		if((ch<=64||(ch>=91&&ch<=96)||ch>=123)&&(flag==1)){
			flag=0;
			num=0;
			for(i=1;i<=op;i++){
				if(strcmp(w[i].s,gh)==0){
					num=1;
					break;
				}
			}
			if(num==1){
				w[i].cs++;
			}
			else{
				op++;
				w[op].cs++;
				strcpy(w[op].s,gh);
				
			}
			memset(gh,0,99);
			continue;
		}
		
	}
	qsort(w+1,op,104,cmp);
	for(k=1;k<=op;k++){
		printf("%s %d\n",w[k].s,w[k].cs);
		
	}
	fclose(in);
	return 0;
} 
int cmp(dccs *s1,dccs *s2){
	if(strcmp(s1->s,s2->s)>0){
		return 1;
	}
	else{
		return -1;
	}
} 

