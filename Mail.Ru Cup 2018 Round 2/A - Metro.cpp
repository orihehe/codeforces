#include <cstdio>
using namespace std;

int main()
{
	int s, n, arr[2][1001], st = 0;
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[0][i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[1][i]);
	}
	if (arr[0][1] == 0) {
		printf("NO");
		return 0;
	}
	if (arr[0][s] == 1) {
		printf("YES");
		return 0;
	}
	else {
		if (arr[1][s] != 1) {
			printf("NO");
			return 0;
		}
		for (int i = s; i <= n; i++) {
			if (arr[0][i] == 1 && arr[1][i] == 1) {
				st = 1;
				break;
			}
		}
		if (st == 1) {
			printf("YES");
		}
		else printf("NO");
	}

	return 0;
}