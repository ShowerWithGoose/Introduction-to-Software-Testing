 #include<stdio.h>
 #include<string.h>
 int main()
 {
 	char n[105];
 	gets(n);
 	int k,i=0;
 	k=strlen(n);
 	while(n[i]!='.'){
 		i++;
	 }
	 int p,d=0;
	 if(i!=1||i==1&&n[0]!='0'){
	 	for(p=i;p>1;p--){
	 		n[p]=n[p-1];
	 		n[p-1]='.';
	 		d++;
		 }
		 n[k]='e';
		 int a;
		 for(a=0;a<k+1;a++){
		 	printf("%c",n[a]);
		 }
		 printf("%d",d);	 
	 }
	 else if(i==1&&n[0]=='0'){
	 	for(p=i;n[p+1]=='0';p++){
	 		n[p]=n[p+1];
	 		n[p+1]='.';
	 		d++;
		 }
		 n[p]=n[p+1];
	 	 n[p+1]='.';
	 	 d++;
		 n[k]='e';
		 n[k+1]='-';
         int a;
		 for(a=p;a<k+2;a++){
		 	if(n[a]=='.'&&n[a+1]=='e'){
		 		printf("%c",n[a+1]);
		 		a++;
			 }else printf("%c",n[a]);
		 }
		 printf("%d",d);
	 }
	 return 0;
}
