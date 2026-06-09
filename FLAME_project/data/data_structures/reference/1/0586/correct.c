#include <stdio.h>
#include <string.h>

int main() {
	int a, b1, b2, b3, b4, b5, b6, b7, b8, b9;
	scanf("%d", &a);
	if (a == 1)
		printf("1");
	else if (a == 2)
		printf("1 2\n2 1");
	else if (a == 3)
		for (b1 = 1; b1 <= 3; b1++) {
			for (b2 = 1; b2 <= 3; b2++)
				for (b3 = 1; b3 <= 3; b3++) {
					if (b1 != b2 && b2 != b3 && b1 != b3)
						printf("%d %d %d\n", b1, b2, b3);
				}
		} else if (a == 4)
		for (b1 = 1; b1 <= 4; b1++) {
			for (b2 = 1; b2 <= 4; b2++)
				for (b3 = 1; b3 <= 4; b3++)
					for (b4 = 1; b4 <= 4; b4++) {
						if (b1 != b2 && b2 != b3 && b1 != b3 && b1 != b4 && b2 != b4 && b3 != b4)
							printf("%d %d %d %d\n", b1, b2, b3, b4);
					}
		} else if (a == 5)
		for (b1 = 1; b1 <= 5; b1++) {
			for (b2 = 1; b2 <= 5; b2++)
				for (b3 = 1; b3 <= 5; b3++)
					for (b4 = 1; b4 <= 5; b4++)
						for (b5 = 1; b5 <= 5; b5++) {
							if (b1 != b2 && b2 != b3 && b1 != b3 && b1 != b4 && b2 != b4 && b3 != b4 && b1 != b5 && b2 != b5 && b3 != b5
							        && b4 != b5)
								printf("%d %d %d %d %d\n", b1, b2, b3, b4, b5);
						}
		} else if (a == 6)
		for (b1 = 1; b1 <= 6; b1++) {
			for (b2 = 1; b2 <= 6; b2++)
				for (b3 = 1; b3 <= 6; b3++)
					for (b4 = 1; b4 <= 6; b4++)
						for (b5 = 1; b5 <= 6; b5++)
							for (b6 = 1; b6 <= 6; b6++) {
								if (b1 != b2 && b2 != b3 && b1 != b3 && b1 != b4 && b2 != b4 && b3 != b4 && b1 != b5 && b2 != b5 && b3 != b5
								        && b4 != b5 && b1 != b6 && b2 != b6 && b3 != b6 && b4 != b6 && b5 != b6)
									printf("%d %d %d %d %d %d\n", b1, b2, b3, b4, b5, b6);
							}
		} else if (a == 7)
		for (b1 = 1; b1 <= 7; b1++) {
			for (b2 = 1; b2 <= 7; b2++)
				for (b3 = 1; b3 <= 7; b3++)
					for (b4 = 1; b4 <= 7; b4++)
						for (b5 = 1; b5 <= 7; b5++)
							for (b6 = 1; b6 <= 7; b6++)
								for (b7 = 1; b7 <= 7; b7++) {
									if (b1 != b7 && b2 != b7 && b3 != b7 && b4 != b7 && b6 != b7 && b5 != b7 && b1 != b2 && b2 != b3 && b1 != b3
									        && b1 != b4 && b2 != b4 && b3 != b4 && b1 != b5 && b2 != b5 && b3 != b5 && b4 != b5 && b1 != b6 && b2 != b6 && b3 != b6
									        && b4 != b6 && b5 != b6)
										printf("%d %d %d %d %d %d %d\n", b1, b2, b3, b4, b5, b6, b7);
								}
		} else if (a == 8)
		for (b1 = 1; b1 <= 8; b1++) {
			for (b2 = 1; b2 <= 8; b2++)
				for (b3 = 1; b3 <= 8; b3++)
					for (b4 = 1; b4 <= 8; b4++)
						for (b5 = 1; b5 <= 8; b5++)
							for (b6 = 1; b6 <= 8; b6++)
								for (b7 = 1; b7 <= 8; b7++)
									for (b8 = 1; b8 <= 8; b8++) {
										if (b1 != b8 && b2 != b8 && b3 != b8 && b4 != b8 && b5 != b8 && b6 != b8 && b7 != b8 && b1 != b7 && b2 != b7
										        && b3 != b7 && b4 != b7 && b6 != b7 && b5 != b7 && b1 != b2 && b2 != b3 && b1 != b3 && b1 != b4 && b2 != b4 && b3 != b4
										        && b1 != b5 && b2 != b5 && b3 != b5 && b4 != b5 && b1 != b6 && b2 != b6 && b3 != b6 && b4 != b6 && b5 != b6)
											printf("%d %d %d %d %d %d %d %d\n", b1, b2, b3, b4, b5, b6, b7, b8);
									}
		} else if (a == 9)
		for (b1 = 1; b1 <= 9; b1++) {
			for (b2 = 1; b2 <= 9; b2++)
				for (b3 = 1; b3 <= 9; b3++)
					for (b4 = 1; b4 <= 9; b4++)
						for (b5 = 1; b5 <= 9; b5++)
							for (b6 = 1; b6 <= 9; b6++)
								for (b7 = 1; b7 <= 9; b7++)
									for (b8 = 1; b8 <= 9; b8++)
										for (b9 = 1; b9 <= 9; b9++) {
											if (b1 != b9 && b2 != b9 && b3 != b9 && b4 != b9 && b5 != b9 && b6 != b9 && b7 != b9 && b8 != b9 && b1 != b8
											        && b2 != b8 && b3 != b8 && b4 != b8 && b5 != b8 && b6 != b8 && b7 != b8 && b1 != b7 && b2 != b7
											        && b3 != b7 && b4 != b7 && b6 != b7 && b5 != b7 && b1 != b2 && b2 != b3 && b1 != b3 && b1 != b4 && b2 != b4 && b3 != b4
											        && b1 != b5 && b2 != b5 && b3 != b5 && b4 != b5 && b1 != b6 && b2 != b6 && b3 != b6 && b4 != b6 && b5 != b6)
												printf("%d %d %d %d %d %d %d %d %d\n", b1, b2, b3, b4, b5, b6, b7, b8, b9);
										}
		}
	return 0;
}


