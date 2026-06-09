#include<stdio.h>
#include<string.h>
#include<math.h>
int l(int a){ return ((a+1)*2-1);}
int r(int a){ return ((a+1)*2);} 
int l_(int a){ return ((a+1)/2-1);}
int r_(int a){ return (a/2-1);}
int p(int v){
	int i,s=1;
	for(i=1;i<=v;i++){
		s=s*2;
	}
	return s;
}
int main(){
	int n,i,j,k,v,u;
	int tree[1000],du[1000],du1[1000];
	for(i=0;i<1000;i++){
		tree[i]=-1;
		du[i]=0;
		du1[i]=0;
	}
	int num[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	tree[0]=num[0];
	for(i=1;i<n;i++){
		k=0;
		while(tree[k]!=-1){
			if(num[i]<tree[k]){
				k=l(k);
			}
			else{
				k=r(k);
			}
			du[i]++;
		}
		tree[k]=num[i];
		du1[k]=du[i];
	}
	int flag=0;
	for(i=0;i<1000;i++){
		if(du1[flag]<du1[i]){
			flag=i;
		}
	}
	
	int a1[1000],b1[1000],a2[1000],b2[1000];
	int a=0,b=0;
	
	for(v=0;;v++){
		if(flag>=(p(v)-1)&&flag<=(p(v+1)-2)) break;
	}
	for(i=p(v)-1;i<=p(v+1)-2;i++){
		if(tree[i]!=-1){
			a1[a++]=tree[i];b1[b++]=du1[i]+1;
			//printf("%d %d\n",tree[i],du1[i]+1);
		}
		else{
			if(i%2==0&&tree[i-1]!=-1)  continue;
			else if(i%2!=0&&tree[i+1]!=-1)  continue;
		    else{
			    u=i;
		    	while(1){
		    	   if(u%2==0){
		    		  u=r_(u);
		    	   }
		    	   else{
		    		  u=l_(u);
		    	   }
		    	   if(tree[u]!=-1) break;
		    	   
		        }
		        if(tree[l(u)]==-1&&tree[r(u)]==-1) {
		          	a1[a++]=tree[u];b1[b++]=du1[u]+1;
		          }
		        //printf("%d %d\n",tree[u],du1[u]+1);
		        i=i+1;
		    } 
		}
	}
	//È¥ÖØ
	int w1=0,w2=0;
	int c1[1000];
	for(i=0;i<1000;i++) c1[i]=0;
	for(i=0;i<1000;i++){
		for(j=i+1;j<a;j++){
			if(a1[j]==a1[i]&&b1[j]==b1[i]){
				c1[j]=1;
			}
		}
	} 
	for(i=0;i<1000;i++){
		if(c1[i]==0){
			a2[w1++]=a1[i];
			b2[w2++]=b1[i];
		}
	}
	for(i=0;i<1000;i++){
		if(b2[i]!=0) printf("%d %d\n",a2[i],b2[i]);
	}
}

