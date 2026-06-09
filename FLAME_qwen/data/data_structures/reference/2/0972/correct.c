#include<stdio.h>
#include<string.h>
int b[100]={0};

int main(){
    char s[100],a[100],c[100];
    int i,j=0;
    int sum=0;
    int tmp1=0,tmp2=0,k=1,cmp=0;
    gets(s);
    int len1=strlen(s);
    for(i=0;i<=len1;i++){
        if(s[i]!=' '){
            a[j]=s[i];
            j++;
        }
    }
//     printf("%s\n",a);
    int len2=strlen(a);
//    printf("%d\n",len2);
    for(i=0;i<len2;i++){
        if(a[i]=='-'||a[i]=='+'||a[i]=='*'||a[i]=='/'||a[i]=='='){
            c[tmp2]=a[i];
            tmp2++;
        }
        else{
                b[tmp1]=b[tmp1]*10+a[i]-'0';
                
                if(a[i+1]=='-'||a[i+1]=='+'||a[i+1]=='*'||a[i+1]=='/'||a[i+1]=='='){
                    tmp1++;
                    }
            }
        }
//	printf("%s %d %d\n",c,tmp1,tmp2);
//	for(i=0;i<tmp1;i++){
//		printf("%d ",b[i]);
//	}
    for(i=0;i<tmp2;i++){
    	if(c[i]=='*'){
    		b[i]=b[i]*b[i+1];
    		tmp1--;
    		for(j=i;j<tmp1;j++){
    			b[j+1]=b[j+2];
    			c[j]=c[j+1];
			}
			i--;
		}
		else if(c[i]=='/'){
    		b[i]=b[i]/b[i+1];
    		tmp1--;
    		for(j=i;j<tmp1;j++){
    			b[j+1]=b[j+2];
				c[j]=c[j+1];	
		}
			i--;
		}
	}
//	for(i=0;i<tmp1;i++){
//		printf("%d%c",b[i],c[i]);}
//		printf("%s\n",c);
//	printf("%d %d\n",tmp1,tmp2);
	sum=b[0];
    for(i=0;i<tmp1;i++){
    	if(c[i]=='+'){
    		sum+=b[i+1];
    		
		}
		else if(c[i]=='-'){
			sum-=b[i+1];
		}
		
	}
	 printf("%d",sum);
    return 0;
}
//5+4*3/2-1=

