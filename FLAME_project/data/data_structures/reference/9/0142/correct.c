#include<stdio.h>

struct duan {
	int x1;
	int y1;
	int x2;
	int y2;
};

void swap(struct duan *rhs,struct duan *lhs) {
	struct duan temp=*rhs;
	*rhs=*lhs;
	*lhs=temp;
}

int main() {
	struct duan v[105];
	int n,count=0,count0=0,i,j,k,i0,j0,l,tem,mode;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d%d%d%d",&v[i].x1,&v[i].y1,&v[i].x2,&v[i].y2);
	}
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(v[i].x1>v[j].x1)
				swap(&v[i],&v[j]);
		}
	}
	for(j=0; j<n; j++) {
			j0=j;
			for(k=0; k<n; k++) {
				if(j0!=k) {
					if((v[j0].x1==v[k].x1&&v[j0].y1==v[k].y1)||(v[j0].x2==v[k].x2&&v[j0].y2==v[k].y2)) {
						tem=v[k].x1;
						v[k].x1=v[k].x2;
						v[k].x2=tem;
						tem=v[k].y1;
						v[k].y1=v[k].y2;
						v[k].y2=tem;
					}
				}
			}}
	for(i=0; i<n; i++) {
		for(j=i; j<n; j++) {
			j0=j;
			for(k=0; k<n; k++) {
				if(j0!=k) {
					if(v[j0].x2==v[k].x1&&v[j0].y2==v[k].y1) {
						if(count0==0) {
							i0=j0;
						}
						count0++;
						j0=k;
						k=0;
					}

				}
			}
			if(count0>=count) {
				count=count0+1;
				l=i0;
				mode=0;
			}
			count0=0;
		}
	}
	for(i=0; i<n; i++) {
		for(j=i; j<n; j++) {
			j0=j;
			for(k=0; k<n; k++) {
				if(j0!=k) {
					if(v[j0].x1==v[k].x2&&v[j0].y1==v[k].y2) {
						if(count0==0) {
							i0=j0;
						}
						count0++;
						j0=k;
						k=0;
					}

				}
			}
			if(count0>=count) {
				count=count0+1;
				l=i0;
				mode=1;
			}
			count0=0;
		}
	}
	if(mode==0)
	printf("%d %d %d\n",count,v[l].x1,v[l].y1);
	else
	printf("%d %d %d\n",count,v[l].x2,v[l].y2);
}

