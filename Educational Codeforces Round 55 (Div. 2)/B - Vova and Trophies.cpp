#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, Gcnt = 0, maxlen = 0, lastlen = 0, tmp = 0;
	char trophies[100001];
	scanf("%d %s", &n, trophies);
	for (int i = 0; i < n; i++) {
		if (trophies[i] == 'G') Gcnt++;
	}
	if (Gcnt <= 1 || Gcnt==n) { // G=0,1,n개
		printf("%d", Gcnt);
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (trophies[i] == 'G') {
			tmp++;
		}
		else {  //S가 연속으로 나오면 lastlen 0 됨
			lastlen = tmp;
			tmp = 0;
		}
		if (lastlen != 0 && Gcnt > lastlen + tmp) { // 옮길수 있는 G있다면
			maxlen = max(maxlen, lastlen + tmp + 1);
		}
		else maxlen = max(maxlen, lastlen + tmp);

		if (Gcnt > tmp) 
			maxlen = max(maxlen, tmp + 1);
	}

	printf("%d", maxlen);

	return 0;
}