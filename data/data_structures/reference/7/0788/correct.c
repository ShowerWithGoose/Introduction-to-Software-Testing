#include<stdio.h>
#include<math.h>
int cmp(const void *a, const void *b){
	return ((int *)a)[0]>((int *)b)[0]?1:-1;
}
int tree[1000000],c[1000000],a,p=0,i,j,n,s[100000][2];
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		out0:
		out2:
		while(a<tree[p]){
			int t=p*2;
			if(c[t]==0){
				tree[t]=a;
				c[t]=1;
				goto out;
			}
			else if(a>=tree[p])
			goto out1;
			else{
				p=t;
				goto out0;
			}
		}
		out1:
		while(a>=tree[p]){
			int t=p*2+1;
			if(c[t]==0){
				tree[t]=a;
				c[t]=1;
				goto out;
			}
			else if(a<tree[p])
			goto out2;
			else{
				p=t;
				goto out0;
			}
		}
		out:p=1;
	}
	for(i=0;i<1000000;i++){
		if(c[i]==1&&c[2*i]==0&&c[2*i+1]==0){
			s[j][0]=tree[i];
			s[j++][1]=i;
		}
	}
	qsort(s,j,sizeof(s[0]),cmp);
	for(i=0;i<j;i++)
	printf("%d %d\n",s[i][0],(int)((double)log(s[i][1])/(double)log(2))+1);
} 

