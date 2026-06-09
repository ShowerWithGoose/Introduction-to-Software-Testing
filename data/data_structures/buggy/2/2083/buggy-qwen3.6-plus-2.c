#include<stdio.h>
#include<string.h>
#include<math.h>
int t[1000];
char p[1000];
int main (){
    char s[1000];
    
    int i,j,a=0,b=0,c=0,d=0,e=0,x=0,y=0,z=0,m=0,l,h=0,u,v,as;
    gets(s); // @@ gets() is removed in C11 standard, causing compilation errors; use fgets() instead.
    for(i=j=0;s[i]!='\0';i++){
        
        if(s[i]=='+'){
        a++;
        p[h]='+';
        h++;
    }
        if(s[i]=='-')
        {
        b++;
        p[h]='-';
        h++;
    }
        if(s[i]=='*')
        {
        c++;
        p[h]='*';
        h++;
    }
        if(s[i]=='/'){
        d++;
        p[h]='/';
        h++;
    }
        if(s[i]!=32)
            s[j++]=s[i];
}
        s[j]='\0';
        p[h]='\0';
        printf("%s\n",s);
        e=a+b+c+d;//有e+1个数
        for( l=0;s[l]!='\0';l++){
            if(s[l]=='+'||s[l]=='-'||s[l]=='*'||s[l]=='/'){
                m=l;
                break;
            }
        }
        for(m=m-1;m>=0;m--){
            x=s[m]-'0';
            y=pow(10,z); // @@ pow() returns double, implicit conversion to int causes precision loss and is inefficient.
            z++;
            t[0]+=y*x;
        }
        z=0;
        for(int p=j;p>=l;p--){ // @@ Variable 'p' redeclared here shadows the global array 'p', causing a compilation error.
            if(s[p]!='+'&&s[p]!='-'&&s[p]!='*'&&s[p]!='/'&&s[p]!='='){
                x=s[p]-'0';
                y=pow(10,z);
                z++;
                t[e+1]+=y*x; // @@ Index 'e+1' is incorrect as 'e' is modified inside the loop, leading to out-of-bounds access.
            }
                else
                {
                e--;
                z=0;
            }
        }
        for(int w=0;w<h;w++){
            if(p[w]=='*'||p[w]=='/'){
                if(p[w]=='*'){
                    t[w+1]=t[w]*t[w+1];
                    t[w]=20245986; // @@ Using a magic number to mark processed elements is unsafe and can conflict with valid results.
                }
                if(p[w]=='/'){
                    t[w+1]=t[w]/t[w+1];
                    t[w]=20245986;
                }
            }
        }
        for( u=0,v=0;u<a+b+c+d+1;u++){
            if(p[u]!='*'&&p[u]!='/')
            p[v++]=p[u];
        
        
}
    for( u=0,v=0;u<a+b+c+d+1;u++){
            if(t[u]!=20245986)
            t[v++]=t[u];
        
        
}
p[v]='\0';

        for( as=0;as<a+b+1;as++){ // @@ Loop bound 'a+b+1' does not match the actual number of remaining operators, causing out-of-bounds access.
            if(p[as]=='+'){
                t[as+1]=t[as]+t[as+1];
                
            }
            if(p[as]=='-'){
                t[as+1]=t[as]-t[as+1];
            }
        }
        printf("%d",t[a+b]); // @@ The final result index is incorrect due to flawed accumulation logic and index shifting.
    
}