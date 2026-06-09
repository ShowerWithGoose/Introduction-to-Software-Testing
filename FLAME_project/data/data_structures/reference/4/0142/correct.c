#include<stdio.h>
#include<string.h>

struct Chuan {
	char c[200];
	int t;
};
void swap(struct Chuan *t1,struct Chuan *t2) {
	struct Chuan t=*t1;
	*t1=*t2;
	*t2=t;
}

int main() {
	FILE *fp;
	fp=fopen("article.txt","r");
	if(fp==NULL) {
		perror("Can&rsquo;t open article.txt!");
		return -1;
	}
	struct Chuan chu[500];
	char del= {0};
	int i=0,i0,j,j0,r,l,l0,k,n,t0;
	while(fscanf(fp,"%s",chu[i].c)!=EOF) {
		chu[i].t=0;
		i++;
		i0=i;
	}
	j0=i0;
	for(i=0; i<j0; i++) {
		k=strlen(chu[i].c);
		for(j=0; j<k; j++) {
			if(chu[i].c[j]<65||(chu[i].c[j]>90&&chu[i].c[j]<97)||chu[i].c[j]>122) {
				for(n=j+1; n<k; n++) {
					if((chu[i].c[n]>=65&&chu[i].c[n]<=90)||(chu[i].c[n]>=97&&chu[i].c[n]<=122)) {
						chu[i0].c[l0]=chu[i].c[n];
						chu[i].c[n]=0;
						l0++;
					} else
						break;
				}
			}
			if(l0!=0) {
				l0=0;
				i0++;
				j=n-1;
			}
		}
	}
	for(i=0; i<i0; i++) {
		k=strlen(chu[i].c);
		t0=0;
		for(j=0; j<k; j++) {
			if(chu[i].c[j]<65||(chu[i].c[j]>90&&chu[i].c[j]<97)||chu[i].c[j]>122)
				t0++;
			else
				break;
		}
		for(j=0; j<k; j++) {
			if(chu[i].c[j]<65||(chu[i].c[j]>90&&chu[i].c[j]<97)||chu[i].c[j]>122)
				chu[i].c[j]=0;
			chu[i].c[j]=chu[i].c[j+t0];
		}
	}
	for(i=0; i<i0; i++) {
		if(*chu[i].c!=del) {
			k=strlen(chu[i].c);
			for(j=0; j<k; j++) {
				if(chu[i].c[j]<=90&&chu[i].c[j]>=65)
					chu[i].c[j]+=' ';
			}
		}
	}
	for(i=0; i<i0; i++) {
		for(j=i+1; j<i0; j++) {
			r=strcmp(chu[i].c,chu[j].c);
			if(r==0) {
				chu[i].t++;
				*chu[j].c=del;
			}
		}
	}

	for(i=0; i<i0; i++) {
		for(j=i+1; j<i0; j++) {
			if(*chu[i].c!=del) {
				l=0;
				if(chu[i].c[l]>chu[j].c[l])
					swap(&chu[i],&chu[j]);
				else if(chu[i].c[l]==chu[j].c[l]) {
					for(l=0; chu[i].c[l]==chu[j].c[l]&&chu[i].c[l]!=0&&chu[j].c[l]!=0; l++);
					if(chu[i].c[l]>chu[j].c[l])
						swap(&chu[i],&chu[j]);
				}
			}
		}
	}
	for(i=0; i<i0; i++) {
		if((chu[i].c[0]>=65&&chu[i].c[0]<=90)||(chu[i].c[0]>=97&&chu[i].c[0]<=122))
			printf("%s %d\n",chu[i].c,chu[i].t+1);
	}
	fclose(fp);
}

