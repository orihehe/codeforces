/*
1<=i<=n, 1<=n<=2000
i번째 수가 i-1보다 작으면 오름차순이 불가능하다.
i번째 수가 i+1번째 수보다 커도 안된다. 그렇다고 모듈러를 하면 연산횟수가 많아진다.
연산은 n+1번까지만 허용된다.
그래서 수열을 아예 어떤 수로 만들지 정했다. i번째 수는 i가 되도록하고, 뒤의 수를 변경하면
앞에있는 수들이 영향을 받으므로 뒤에서부터 수를 만들어준다.
모듈러 연산을 마지막에 한 번 해줄 건데 어디까지, 어떤수(x)로 할지 저장해둔다.
만약 현재 수가 i보다 작다면 i값으로 만들어 주는 연산을 해준다.
만약 현재 수가 i보다 크다면 저장된 x로 모듈러연산을 했을 때 i값이 나올 값을 더해준다.
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int arr[2001];
int opp[2001][3];
int optop = 0;
void op(int w, int idx, int x) {
	if (w == 1) {
		for (int i = 1; i <= idx; i++) {
			arr[i] += x;
		}
	}
	else if (w == 2) {
		for (int i = 1; i <= idx; i++) {
			arr[i] %= x;
		}
	}
	opp[optop][0] = w;
	opp[optop][1] = idx;
	opp[optop++][2] = x;
}

int main() {
	int n, cnt = 0, modidx, x;
	scanf("%d", &n);
	modidx = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = n; i >= 1; i--) {
		if (arr[i] < i) {
			op(1, i, i - arr[i]);
			cnt++;
			if (modidx == 0) {
				modidx = i;
				x = i + 1;
			}
		}
		else if (arr[i] > i) {
			if (modidx == 0) {
				modidx = i;
				x = i + 1;
			}
			int t = 1;
			while (arr[i] > x*t + i) {
				t++;
			}
			op(1, i, x*t + i - arr[i]);
			cnt++;
		}
	}
	if (modidx != 0) {
		cnt++;
		op(2, modidx, x);
	}

	printf("%d\n", cnt);
	for (int i = 0; i < optop; i++) {
		printf("%d %d %d\n", opp[i][0], opp[i][1], opp[i][2]);
	}

	return 0;
}