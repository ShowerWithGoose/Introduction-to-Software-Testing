#pragma warning(disable : 4996)
#include <stdio.h>

int solve(int iData_1, int iData_2, char op) {
	if (op == '+')
		return iData_1 + iData_2;
	if (op == '-')
		return iData_1 - iData_2;
	if (op == '*')
		return iData_1 * iData_2;
	if (op == '/')
		return iData_1 / iData_2;
}

int GetData() {
	int data = 0;
	scanf("%d\n", &data);
	return data;
}

int GetOp() {
	char op;
	scanf("%c", &op);
	return op;
}

int main() {

	int num[2];
	char oc[1];

	num[0] = GetData();
	oc[0] = GetOp();

	if (oc[0] != '=')
		num[1] = GetData();
	while (oc[0] != '=') {
		if (oc[0] == '*' || oc[0] == '/') {
			num[0] = solve(num[0], num[1], oc[0]);
			oc[0] = GetOp();
			if (oc[0] != '=')
				num[1] = GetData();
		} else {
			char op = GetOp();
			if (op == '+' || op == '-' || op == '=') {
				num[0] = solve(num[0], num[1], oc[0]);
				oc[0] = op;
				if (op != '=') 
					num[1] = GetData();
			}
			else if (op == '=')
				oc[0] = op;
			else {
				int data = GetData();
				num[1] = solve(num[1], data, op);
			}
		}
	}
	printf("%d", num[0]);
	return 0;
}
