#include<stdio.h>
char aa[4000000][10];
int f[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
int main(){
    //freopen("data.out.txt","w",stdout);
	int n;
	int b,c,d,e,g,i;
	scanf("%d",&n);
	aa[0][0]='1';
	for(i=1;i<n;i++){//zong
		for(b=0;b<=i;b++){//cpy
			for(d=b*f[i];d<(b+1)*f[i];d++){//lie
				for(c=0;c<i;c++){//hang
					aa[d+f[i]][c]=aa[d][c];
					if(aa[d][c]>b+'0')aa[d][c]++;
				}
				aa[d][c]=b+'1';
			}
		}
			//cpy(aa[0][0],aa[i!*k][0]);
			//>=j,++,b j;
		}
	for(e=0;e<f[n];e++){
		for(g=n-1;g>=0;g--){
			if(aa[e][g]=='9'+1)printf("10 ");
			else	printf("%c ",aa[e][g]);
		}
		putchar(10);	
	}
	//fclose(stdout); 
	return 0;
}



