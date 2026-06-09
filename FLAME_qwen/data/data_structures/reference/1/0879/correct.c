#include <stdio.h>
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();
void f7();
void f8();
void f9();
void f10();
int main()
{
	int n;
	scanf("%d",&n);
	switch (n)
	{
		case 1: f1();break;
		case 2: f2();break;
		case 3: f3();break;
		case 4: f4();break;
		case 5: f5();break;
		case 6: f6();break;
		case 7: f7();break;
		case 8: f8();break;
		case 9: f9();break;
		case 10: f10();break;
		default : break;
	}
} 
void f1()
{
	printf("1");
}
void f2()
{
	printf("1 2\n2 1");
}
void f3()
{
	printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1");
}
void f4()
{
	int a[4];
	for(a[0] = 1; a[0] < 5; a[0]++)
	{
		for(a[1] = 1; a[1] < 5; a[1]++)
			{
				if(a[1] == a[0])
				{
					continue;
				}
				for(a[2] = 1; a[2] < 5; a[2]++)
					{
						if(a[2] == a[1] || a[2] == a[0])
						{
							continue;
						}
						for(a[3] = 1; a[3] < 5; a[3]++)
							{
								if(a[3] == a[1] || a[3] == a[0] || a[3] == a[2])
								{
									continue;
								}
								printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
							}
					}
			}
	}		
}
void f5()
{
	int a[5];
	for(a[0] = 1; a[0] < 6; a[0]++)
	{
		for(a[1] = 1; a[1] < 6; a[1]++)
			{
				if(a[1] == a[0])
				{
					continue;
				}
				for(a[2] = 1; a[2] < 6; a[2]++)
					{
						if(a[2] == a[1] || a[2] == a[0])
						{
							continue;
						}
						for(a[3] = 1; a[3] < 6; a[3]++)
							{
								if(a[3] == a[1] || a[3] == a[0] || a[3] == a[2])
								{
									continue;
								}
								for(a[4] = 1; a[4] < 6; a[4]++)
									{
										if(a[4] == a[0] || a[4] == a[1] || a[4] == a[2] || a[4] == a[3])
										{
											continue;
										}
										printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
									}
							}
					}
			}
	}	
}
void f6()
{
	int a[6];
	for(a[0] = 1; a[0] < 7; a[0]++)
	{
		for(a[1] = 1; a[1] < 7; a[1]++)
			{
				if(a[1] == a[0])
				{
					continue;
				}
				for(a[2] = 1; a[2] < 7; a[2]++)
					{
						if(a[2] == a[0] || a[2] == a[1])
						{
							continue;
						}
						for(a[3] = 1; a[3] < 7; a[3]++)
							{
								if(a[3] == a[1] || a[3] == a[0] || a[3] == a[2])
								{
									continue;
								}
								for(a[4] = 1; a[4] < 7; a[4]++)
									{
										if(a[4] == a[1] || a[4] == a[0] || a[4] == a[2] || a[4] == a[3])
										{
											continue;
										}
										for(a[5] = 1; a[5] < 7; a[5]++)
											{
												if(a[5] == a[0] || a[5] == a[1] || a[5] == a[2] || a[5] == a[3] || a[5] == a[4])
												{
													continue;
												}
												printf("%d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5]);
											}
									}
							}
					}
			}
	}
}
void f7()
{
	int a[7];
	for(a[0] = 1; a[0] < 8; a[0]++)
	{
		for(a[1] = 1; a[1] < 8; a[1]++)
			{
				if(a[1] == a[0])
				{
					continue;
				}
				for(a[2] = 1; a[2] < 8; a[2]++)
					{
						if(a[2] == a[0] || a[2] == a[1])
						{
							continue;
						}
						for(a[3] = 1; a[3] < 8; a[3]++)
							{
								if(a[3] == a[1] || a[3] == a[0] || a[3] == a[2])
								{
									continue;
								}
								for(a[4] = 1; a[4] < 8; a[4]++)
									{
										if(a[4] == a[1] || a[4] == a[0] || a[4] == a[2] || a[4] == a[3])
										{
											continue;
										}
										for(a[5] = 1; a[5] < 8; a[5]++)
											{
												if(a[5] == a[0] || a[5] == a[1] || a[5] == a[2] || a[5] == a[3] || a[5] == a[4])
												{
													continue;
												}
												for(a[6] = 1; a[6] < 8; a[6]++)
												{
													if(a[6] == a[0] || a[6] == a[1] || a[6] == a[2] || a[6] == a[3] || a[6] == a[4] || a[6] == a[5])
													{
														continue;
													}
													printf("%d %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6]);
												}
											}
									}
							}
					}
			}
	}	
}
void f8()
{
	int a[8];
	for(a[0] = 1; a[0] < 9; a[0]++)
	{
		for(a[1] = 1; a[1] < 9; a[1]++)
			{
				if(a[1] == a[0])
				{
					continue;
				}
				for(a[2] = 1; a[2] < 9; a[2]++)
					{
						if(a[2] == a[0] || a[2] == a[1])
						{
							continue;
						}
						for(a[3] = 1; a[3] < 9; a[3]++)
							{
								if(a[3] == a[1] || a[3] == a[0] || a[3] == a[2])
								{
									continue;
								}
								for(a[4] = 1; a[4] < 9; a[4]++)
									{
										if(a[4] == a[1] || a[4] == a[0] || a[4] == a[2] || a[4] == a[3])
										{
											continue;
										}
										for(a[5] = 1; a[5] < 9; a[5]++)
											{
												if(a[5] == a[0] || a[5] == a[1] || a[5] == a[2] || a[5] == a[3] || a[5] == a[4])
												{
													continue;
												}
												for(a[6] = 1; a[6] < 9; a[6]++)
												{
													if(a[6] == a[0] || a[6] == a[1] || a[6] == a[2] || a[6] == a[3] || a[6] == a[4] || a[6] == a[5])
													{
														continue;
													}
													for(a[7] = 1; a[7] < 9; a[7]++)
													{
														if(a[7] == a[0] || a[7] == a[1] || a[7] == a[2] || a[7] == a[3] || a[7] == a[4] || a[7] == a[5] || a[7] == a[6])
														{
															continue;
														}
														printf("%d %d %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);	
													}
												}
											}
									}
							}
					}
			}
	}
}
void f9()
{
	int a[9];
	for(a[0] = 1; a[0] < 10; a[0]++)
	{
		for(a[1] = 1; a[1] < 10; a[1]++)
			{
				if(a[1] == a[0])
				{
					continue;
				}
				for(a[2] = 1; a[2] < 10; a[2]++)
					{
						if(a[2] == a[0] || a[2] == a[1])
						{
							continue;
						}
						for(a[3] = 1; a[3] < 10; a[3]++)
							{
								if(a[3] == a[1] || a[3] == a[0] || a[3] == a[2])
								{
									continue;
								}
								for(a[4] = 1; a[4] < 10; a[4]++)
									{
										if(a[4] == a[1] || a[4] == a[0] || a[4] == a[2] || a[4] == a[3])
										{
											continue;
										}
										for(a[5] = 1; a[5] < 10; a[5]++)
											{
												if(a[5] == a[0] || a[5] == a[1] || a[5] == a[2] || a[5] == a[3] || a[5] == a[4])
												{
													continue;
												}
												for(a[6] = 1; a[6] < 10; a[6]++)
												{
													if(a[6] == a[0] || a[6] == a[1] || a[6] == a[2] || a[6] == a[3] || a[6] == a[4] || a[6] == a[5])
													{
														continue;
													}
													for(a[7] = 1; a[7] < 10; a[7]++)
													{
														if(a[7] == a[0] || a[7] == a[1] || a[7] == a[2] || a[7] == a[3] || a[7] == a[4] || a[7] == a[5] || a[7] == a[6])
														{
															continue;
														}
														for(a[8] = 1; a[8] < 10; a[8]++)
														{
															if(a[8] == a[0] || a[8] == a[1] || a[8] == a[2] || a[8] == a[3] || a[8] == a[4] || a[8] == a[5] || a[8] == a[6] || a[8] == a[7])
															{
																continue;
															}	
															printf("%d %d %d %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);	
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
void f10()
{
	int a[10];
	for(a[0] = 1; a[0] < 11; a[0]++)
	{
		for(a[1] = 1; a[1] < 11; a[1]++)
			{
				if(a[1] == a[0])
				{
					continue;
				}
				for(a[2] = 1; a[2] < 11; a[2]++)
					{
						if(a[2] == a[0] || a[2] == a[1])
						{
							continue;
						}
						for(a[3] = 1; a[3] < 11; a[3]++)
							{
								if(a[3] == a[1] || a[3] == a[0] || a[3] == a[2])
								{
									continue;
								}
								for(a[4] = 1; a[4] < 11; a[4]++)
									{
										if(a[4] == a[1] || a[4] == a[0] || a[4] == a[2] || a[4] == a[3])
										{
											continue;
										}
										for(a[5] = 1; a[5] < 11; a[5]++)
											{
												if(a[5] == a[0] || a[5] == a[1] || a[5] == a[2] || a[5] == a[3] || a[5] == a[4])
												{
													continue;
												}
												for(a[6] = 1; a[6] < 11; a[6]++)
												{
													if(a[6] == a[0] || a[6] == a[1] || a[6] == a[2] || a[6] == a[3] || a[6] == a[4] || a[6] == a[5])
													{
														continue;
													}
													for(a[7] = 1; a[7] < 11; a[7]++)
													{
														if(a[7] == a[0] || a[7] == a[1] || a[7] == a[2] || a[7] == a[3] || a[7] == a[4] || a[7] == a[5] || a[7] == a[6])
														{
															continue;
														}
														for(a[8] = 1; a[8] < 11; a[8]++)
														{
															if(a[8] == a[0] || a[8] == a[1] || a[8] == a[2] || a[8] == a[3] || a[8] == a[4] || a[8] == a[5] || a[8] == a[6] || a[8] == a[7])
															{
																continue;
															}	
															for(a[9] = 1; a[9] < 11; a[9]++)
															{
																if(a[9] == a[0] || a[9] == a[1] || a[9] == a[2] || a[9] == a[3] || a[9] == a[4] || a[9] == a[5] || a[9] == a[6] || a[9] == a[7] || a[9] == a[8])
																{
																	continue;
																}
																printf("%d %d %d %d %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
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



