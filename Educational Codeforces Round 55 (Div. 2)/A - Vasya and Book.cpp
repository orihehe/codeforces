#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int t, n, x, y, d, fcnt, bcnt;
	scanf("%d", &t);
	while (t--) {
		fcnt = 0; bcnt = 0;
		scanf("%d %d %d %d", &n, &x, &y, &d);
		if (x == y) {
			printf("0\n");
			continue;
		}
		if (abs(x-y)%d==0) {
			printf("%d\n", abs((x - y)/d));
			continue;
		}
		// 처음or끝 지점까지 가서 페이지 찾아야할때
		if ((n - y) % d == 0) { //끝에서
			fcnt += (n - x + d - 1) / d; // 현재에서 n까지 갈때
			fcnt += (n - y) / d;
		}
		if ((y - 1) % d == 0) { // 앞에서
			bcnt += (x - 1 + d - 1) / d; // 현재에서 1까지 갈때
			bcnt += (y - 1) / d;
		}
		if (fcnt == 0 && bcnt == 0) {
			printf("-1\n");
		}
		else if(fcnt==0){
			printf("%d\n", bcnt);
		}
		else if (bcnt == 0) {
			printf("%d\n", fcnt);
		}
		else printf("%d\n", min(bcnt, fcnt));
	}

	return 0;
}