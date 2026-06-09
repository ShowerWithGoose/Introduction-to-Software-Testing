#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
int main()
{
    int n,a=1,b=1,c=1,d=1,e=1,f=1,g=1,h=1,i=1;
	scanf("%d",&n);
	if(n==1){
		printf("1");
	}
	if(n==2){
		printf("1 2\n2 1");
	}
	if(n==3){
		printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1");
	}
	if(n==4){
		for(a=1;a<=4;a++){
			for(b=1;b<=4;b++){
				if(b==a){
					continue;
				}
				for(c=1;c<=4;c++){
					if(c==a||c==b){
						continue;
					}
					for(d=1;d<=4;d++){
						if(d==a||d==b||d==c){
							continue;
						}
						printf("%d %d %d %d\n",a,b,c,d);
					}
				}
			}
		}
	}
	if(n==5){
		for(a=1;a<=5;a++){
			for(b=1;b<=5;b++){
				if(b==a){
					continue;
				}
				for(c=1;c<=5;c++){
					if(c==a||c==b){
						continue;
					}
					for(d=1;d<=5;d++){
						if(d==a||d==b||d==c){
							continue;
						}
						for(e=1;e<=5;e++){
							if(e==a||e==b||e==c|e==d){
								continue;
							}
							printf("%d %d %d %d %d\n",a,b,c,d,e);
						}
					}
				}
			}
		}
	}
	if(n==6){
		for(a=1;a<=6;a++){
			for(b=1;b<=6;b++){
				if(b==a){
					continue;
				}
				for(c=1;c<=6;c++){
					if(c==a||c==b){
						continue;
					}
					for(d=1;d<=6;d++){
						if(d==a||d==b||d==c){
							continue;
						}
						for(e=1;e<=6;e++){
							if(e==a||e==b||e==c|e==d){
								continue;
							}
							for(f=1;f<=6;f++){
								if(f==a||f==b||f==c||f==d||f==e){
									continue;
								}
								printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
							}
						}
					}
				}
			}
		}
	}
	if(n==7){
		for(a=1;a<=7;a++){
			for(b=1;b<=7;b++){
				if(b==a){
					continue;
				}
				for(c=1;c<=7;c++){
					if(c==a||c==b){
						continue;
					}
					for(d=1;d<=7;d++){
						if(d==a||d==b||d==c){
							continue;
						}
						for(e=1;e<=7;e++){
							if(e==a||e==b||e==c|e==d){
								continue;
							}
							for(f=1;f<=7;f++){
								if(f==a||f==b||f==c||f==d||f==e){
									continue;
								}
								for(g=1;g<=7;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f){
										continue;
									}
									printf("%d %d %d %d %d %d %d\n",a,b,c,d,e,f,g);
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==8){
		for(a=1;a<=8;a++){
			for(b=1;b<=8;b++){
				if(b==a){
					continue;
				}
				for(c=1;c<=8;c++){
					if(c==a||c==b){
						continue;
					}
					for(d=1;d<=8;d++){
						if(d==a||d==b||d==c){
							continue;
						}
						for(e=1;e<=8;e++){
							if(e==a||e==b||e==c|e==d){
								continue;
							}
							for(f=1;f<=8;f++){
								if(f==a||f==b||f==c||f==d||f==e){
									continue;
								}
								for(g=1;g<=8;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f){
										continue;
									}
									for(h=1;h<=8;h++){
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g){
											continue;
										}
										printf("%d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==9){
		for(a=1;a<=9;a++){
			for(b=1;b<=9;b++){
				if(b==a) continue;
				for(c=1;c<=9;c++){
					if(c==b||c==a) continue;
					for(d=1;d<=9;d++){
						if(d==a||d==b||d==c) continue;
						for(e=1;e<=9;e++){
							if(e==a||e==b||e==c||e==d) continue;
							for(f=1;f<=9;f++){
								if(f==a||f==b||f==c||f==d||f==e) continue;
								for(g=1;g<=9;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f) continue;
									for(h=1;h<=9;h++){
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
										for(i=1;i<=9;i++){
											if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue; 
												else{
													printf("%d %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i);	
											}
										}
									}			
								}
							}	
						}
					}			
				}
			}
		}
	}
	if(n==10){
		for(a=1;a<=9;a++){
		for(b=1;b<=9;b++){
				if(b==a) continue;
				for(c=1;c<=9;c++){
					if(c==b||c==a) continue;
					for(d=1;d<=9;d++){
						if(d==a||d==b||d==c) continue;
						for(e=1;e<=9;e++){
							if(e==a||e==b||e==c||e==d) continue;
							for(f=1;f<=9;f++){
								if(f==a||f==b||f==c||f==d||f==e) continue;
								for(g=1;g<=9;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f) continue;
									for(h=1;h<=9;h++){
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
										for(i=1;i<=9;i++){
											if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue; 
												else{
													printf("10 %d %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i);
											}
										}
									}			
								}
							}	
						}
					}			
				}
			}
		}
		for(a=1;a<=9;a++){
		 for(b=1;b<=9;b++){
				if(b==a) continue;
				for(c=1;c<=9;c++){
					if(c==b||c==a) continue;
					for(d=1;d<=9;d++){
						if(d==a||d==b||d==c) continue;
						for(e=1;e<=9;e++){
							if(e==a||e==b||e==c||e==d) continue;
							for(f=1;f<=9;f++){
								if(f==a||f==b||f==c||f==d||f==e) continue;
								for(g=1;g<=9;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f) continue;
									for(h=1;h<=9;h++){
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
										for(i=1;i<=9;i++){
											if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue; 
												else{
													printf("%d 10 %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i);
											}
										}
									}			
								}
							}	
						}
					}			
				}
			}
			for(b=1;b<=9;b++){
				if(b==a) continue;
				for(c=1;c<=9;c++){
					if(c==b||c==a) continue;
					for(d=1;d<=9;d++){
						if(d==a||d==b||d==c) continue;
						for(e=1;e<=9;e++){
							if(e==a||e==b||e==c||e==d) continue;
							for(f=1;f<=9;f++){
								if(f==a||f==b||f==c||f==d||f==e) continue;
								for(g=1;g<=9;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f) continue;
									for(h=1;h<=9;h++){
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
										for(i=1;i<=9;i++){
											if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue; 
												else{
													printf("%d %d 10 %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i);
											}
										}
									}			
								}
							}	
						}
					}			
				}
			}
		 for(b=1;b<=9;b++){
				if(b==a) continue;
				for(c=1;c<=9;c++){
					if(c==b||c==a) continue;
					for(d=1;d<=9;d++){
						if(d==a||d==b||d==c) continue;
						for(e=1;e<=9;e++){
							if(e==a||e==b||e==c||e==d) continue;
							for(f=1;f<=9;f++){
								if(f==a||f==b||f==c||f==d||f==e) continue;
								for(g=1;g<=9;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f) continue;
									for(h=1;h<=9;h++){
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
										for(i=1;i<=9;i++){
											if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue; 
												else{
													printf("%d %d %d 10 %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i);
											}
										}
									}			
								}
							}	
						}
					}			
				}
			}
			for(b=1;b<=9;b++){
				if(b==a) continue;
				for(c=1;c<=9;c++){
					if(c==b||c==a) continue;
					for(d=1;d<=9;d++){
						if(d==a||d==b||d==c) continue;
						for(e=1;e<=9;e++){
							if(e==a||e==b||e==c||e==d) continue;
							for(f=1;f<=9;f++){
								if(f==a||f==b||f==c||f==d||f==e) continue;
								for(g=1;g<=9;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f) continue;
									for(h=1;h<=9;h++){
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
										for(i=1;i<=9;i++){
											if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue; 
												else{
													printf("%d %d %d %d 10 %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i);
											}
										}
									}			
								}
							}	
						}
					}			
				}
			}
		 for(b=1;b<=9;b++){
				if(b==a) continue;
				for(c=1;c<=9;c++){
					if(c==b||c==a) continue;
					for(d=1;d<=9;d++){
						if(d==a||d==b||d==c) continue;
						for(e=1;e<=9;e++){
							if(e==a||e==b||e==c||e==d) continue;
							for(f=1;f<=9;f++){
								if(f==a||f==b||f==c||f==d||f==e) continue;
								for(g=1;g<=9;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f) continue;
									for(h=1;h<=9;h++){
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
										for(i=1;i<=9;i++){
											if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue; 
												else{
													printf("%d %d %d %d %d 10 %d %d %d %d\n",a,b,c,d,e,f,g,h,i);
											}
										}
									}			
								}
							}	
						}
					}			
				}
			}
			for(b=1;b<=9;b++){
				if(b==a) continue;
				for(c=1;c<=9;c++){
					if(c==b||c==a) continue;
					for(d=1;d<=9;d++){
						if(d==a||d==b||d==c) continue;
						for(e=1;e<=9;e++){
							if(e==a||e==b||e==c||e==d) continue;
							for(f=1;f<=9;f++){
								if(f==a||f==b||f==c||f==d||f==e) continue;
								for(g=1;g<=9;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f) continue;
									for(h=1;h<=9;h++){
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
										for(i=1;i<=9;i++){
											if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue; 
												else{
													printf("%d %d %d %d %d %d 10 %d %d %d\n",a,b,c,d,e,f,g,h,i);
											}
										}
									}			
								}
							}	
						}
					}			
				}
			}
		 for(b=1;b<=9;b++){
				if(b==a) continue;
				for(c=1;c<=9;c++){
					if(c==b||c==a) continue;
					for(d=1;d<=9;d++){
						if(d==a||d==b||d==c) continue;
						for(e=1;e<=9;e++){
							if(e==a||e==b||e==c||e==d) continue;
							for(f=1;f<=9;f++){
								if(f==a||f==b||f==c||f==d||f==e) continue;
								for(g=1;g<=9;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f) continue;
									for(h=1;h<=9;h++){
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
										for(i=1;i<=9;i++){
											if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue; 
												else{
													printf("%d %d %d %d %d %d 10 %d %d %d\n",a,b,c,d,e,f,g,h,i);
											}
										}
									}			
								}
							}	
						}
					}			
				}
			}
			for(b=1;b<=9;b++){
				if(b==a) continue;
				for(c=1;c<=9;c++){
					if(c==b||c==a) continue;
					for(d=1;d<=9;d++){
						if(d==a||d==b||d==c) continue;
						for(e=1;e<=9;e++){
							if(e==a||e==b||e==c||e==d) continue;
							for(f=1;f<=9;f++){
								if(f==a||f==b||f==c||f==d||f==e) continue;
								for(g=1;g<=9;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f) continue;
									for(h=1;h<=9;h++){
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
										for(i=1;i<=9;i++){
											if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue; 
												else{
													printf("%d %d %d %d %d %d %d 10 %d %d\n",a,b,c,d,e,f,g,h,i);
											}
										}
									}			
								}
							}	
						}
					}			
				}
			}
		 for(b=1;b<=9;b++){
				if(b==a) continue;
				for(c=1;c<=9;c++){
					if(c==b||c==a) continue;
					for(d=1;d<=9;d++){
						if(d==a||d==b||d==c) continue;
						for(e=1;e<=9;e++){
							if(e==a||e==b||e==c||e==d) continue;
							for(f=1;f<=9;f++){
								if(f==a||f==b||f==c||f==d||f==e) continue;
								for(g=1;g<=9;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f) continue;
									for(h=1;h<=9;h++){
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
										for(i=1;i<=9;i++){
											if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue; 
												else{
													printf("%d %d %d %d %d %d %d %d 10 %d\n",a,b,c,d,e,f,g,h,i);
											}
										}
									}			
								}
							}	
						}
					}			
				}
			}	
			for(b=1;b<=9;b++){
				if(b==a) continue;
				for(c=1;c<=9;c++){
					if(c==b||c==a) continue;
					for(d=1;d<=9;d++){
						if(d==a||d==b||d==c) continue;
						for(e=1;e<=9;e++){
							if(e==a||e==b||e==c||e==d) continue;
							for(f=1;f<=9;f++){
								if(f==a||f==b||f==c||f==d||f==e) continue;
								for(g=1;g<=9;g++){
									if(g==a||g==b||g==c||g==d||g==e||g==f) continue;
									for(h=1;h<=9;h++){
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
										for(i=1;i<=9;i++){
											if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue; 
												else{
													printf("%d %d %d %d %d %d %d %d %d 10\n",a,b,c,d,e,f,g,h,i);
											}
										}
									}			
								}
							}	
						}
					}			
				}
			}
		}
		}
	return 0;
}




