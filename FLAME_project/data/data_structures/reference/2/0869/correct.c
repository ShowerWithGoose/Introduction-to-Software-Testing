#include<stdio.h>
#include<string.h>
int  readnum();
char readop();
int main(){
	int a[3]={0};
	char op[2]="";
	a[0]=readnum();
	op[0]=readop();
	if(op[0]=='='){
		printf("%d",a[0]);
		return 0;
	}
	a[1]=readnum();
	op[1]=readop();
	if(op[1]=='='){
		if(op[0]=='+'){
			printf("%d",a[0]+a[1]);
			return 0;
		}
		if(op[0]=='-'){
			printf("%d",a[0]-a[1]);
			return 0;
		}
		if(op[0]=='*'){
			printf("%d",a[0]*a[1]);
			return 0;
		}
		if(op[0]=='/'){
			printf("%d",a[0]/a[1]);
			return 0;
		}
	}
	else
		a[2]=readnum();
	while(op[0]!='='){
		if(op[0]=='*'||op[0]=='/'){
			if(op[1]!='='){
				if(op[0]=='*'){
					a[0]=a[0]*a[1];
					a[1]=a[2];
					op[0]=op[1];
					op[1]=readop();
					if(op[1]!='='){
						a[2]=readnum();
					}
					else
						goto step1;
				}
				else if(op[0]=='/'){
					a[0]=a[0]/a[1];
					a[1]=a[2];
					op[0]=op[1];
					op[1]=readop();
					if(op[1]!='='){
						a[2]=readnum();
					}
					else
						goto step1;
				}
			}
			else if(op[1]=='='){
				if(op[0]=='*'){
					printf("%d",a[0]*a[1]);
					return 0;
				}
				if(op[0]=='/'){
					printf("%d",a[0]/a[1]);
					return 0;
				}
			}
		}
		else if(op[0]=='+'||op[0]=='-'){
			if(op[1]=='*'){
				a[1]=a[1]*a[2];
				op[1]=readop();
				if(op[1]!='='){
						a[2]=readnum();
					}
					else
						goto step1;
			}
			else if(op[1]=='/'){
				a[1]=a[1]/a[2];
				op[1]=readop();
				if(op[1]!='='){
						a[2]=readnum();
					}
					else
						goto step1;
			}
			else if(op[1]=='+'||op[1]=='-'){
				if(op[0]=='+'){
					a[0]=a[0]+a[1];
				}
				if(op[0]=='-'){
					a[0]=a[0]-a[1];
				}
				a[1]=a[2];
				op[0]=op[1];
				op[1]=readop();
				if(op[1]!='='){
						a[2]=readnum();
					}
					else
						goto step1;
			}
			else if(op[1]=='='){
				if(op[0]=='+'){
					printf("%d",a[0]+a[1]);
					return 0;
				}
				if(op[0]=='-'){
					printf("%d",a[0]-a[1]);
					return 0;
				}
			}
		}
	}
	step1: if(op[1]=='='){
		if(op[0]=='+'){
			printf("%d",a[0]+a[1]);
			return 0;
		}
		if(op[0]=='-'){
			printf("%d",a[0]-a[1]);
			return 0;
		}
		if(op[0]=='*'){
			printf("%d",a[0]*a[1]);
			return 0;
		}
		if(op[0]=='/'){
			printf("%d",a[0]/a[1]);
			return 0;
		}
	}
	return 0;
}
int readnum(){
	int a;
	scanf(" %d",&a);
	return a;
}
char readop(){
	char op;
	scanf(" %c",&op);
	return op;
}

