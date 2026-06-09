#include<stdio.h>
#include<string.h>
struct dxs{
	int xs1,xs2,xs3;
	int zs1,zs2,zs3;
}m[1050];
int main(){
	int i=0,j=0,k=0,n;
	int swap1,swap2;
	int cnt1=0,cnt2=0,cnt=0;
	for(i=0;;i++){
		scanf("%d%d",&m[i].xs1,&m[i].zs1);
		cnt1++;
		if(getchar()=='\n')
		break;
	}
	for(i=0;;i++){
		scanf("%d%d",&m[i].xs2,&m[i].zs2);
		cnt2++;
		if(getchar()=='\n')
		break;
	}
	for(i=0;i<cnt1;i++){
		for(j=0;j<cnt2;j++){
			m[k].xs3=m[i].xs1*m[j].xs2;
			m[k].zs3=m[i].zs1+m[j].zs2;
			k++;
		}
	}
	n=k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j) continue;
			else {
			if(m[i].zs3==m[j].zs3){
				m[i].xs3+=m[j].xs3;
				m[j].xs3=0;
				m[j].zs3=0;
			}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(m[i].zs3<m[j].zs3){
				swap1=m[i].xs3;
				swap2=m[i].zs3;
				m[i].xs3=m[j].xs3;
				m[i].zs3=m[j].zs3;
				m[j].xs3=swap1;
				m[j].zs3=swap2;
			}
		}
	}
	for(i=0;i<n;i++){
		if(m[i].xs3==0) continue;
		else if(m[i].xs3!=0){
			printf("%d %d ",m[i].xs3,m[i].zs3);
		}
	}
	return 0;
}

