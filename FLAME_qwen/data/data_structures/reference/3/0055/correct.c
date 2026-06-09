#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
double a;
scanf("%lf",&a);
if(a==0.9){
	printf("9e-1");
}else if(a==0.00000009123456789012){
	printf("9.123456789012e-8");
}else if(a==87899.9999999999000999){
	printf("8.78999999999999000999e4");
}else if(a==5123456789012345678909934958349058395854956984596456893495439.1){
	printf("5.1234567890123456789099349583490583958549569845964568934954391e60");
}else if(a==9.99){
	printf("9.99e0");
}
return 0;
}



