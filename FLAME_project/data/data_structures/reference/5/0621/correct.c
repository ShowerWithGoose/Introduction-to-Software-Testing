#include<stdio.h>
#include<stdlib.h>
	struct multi{
	long long c;
	long long p;
}a[2005],b[2005],ans[2005],temp,h;
/*void bubble(int n, struct multi a, struct multi temp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (a[i].p>a[j].p)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    }
}*/
int cmp(const void*p1,const void *p2){
	struct multi *a=(struct multi*)p1;
	struct multi *b=(struct multi*)p2;
	return b->p-a->p;
}

	int main(){
	char ch='0';
	int i=0,j=0,k=0,lena,lenb;
	while(ch!='\n'){
		scanf("%lld %lld",&a[i].c,&a[i].p);
		i++;
		ch=getchar();
	}
	ch='0';
	while(ch!='\n'){
		scanf("%lld %lld",&b[j].c,&b[j].p);
		j++;
		ch=getchar();
	}
	lena=i,lenb=j;
	qsort(a,lena,sizeof(h),cmp);qsort(b,lenb,sizeof(h),cmp);
	for(i=0;i<lena;i++){
		for(j=0;j<lenb;j++){
			ans[k].c=a[i].c*b[j].c;
			ans[k].p=a[i].p+b[j].p;
			k++;
		}
	}
	qsort(ans,k,sizeof(h),cmp);
	for(i=0;i<k;i++){
		if(ans[i-1].p==ans[i].p){
			ans[i].c+=ans[i-1].c;
			ans[i-1].c=0;
		}
	}
	qsort(ans,k,sizeof(h),cmp);
	for(i=0;i<k;i++){
		if(ans[i].c!=0) printf("%lld %lld ",ans[i].c,ans[i].p);
	}
	return 0;
}

