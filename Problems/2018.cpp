#include<stdio.h>
using namespace std;
int N;
int cnt;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		if (i % 2 != 0) {//Ȧ��
			if (N%i == 0 && N / i - i / 2 > 0) {
				cnt++;
			}
		}
		else {//¦��
			if (N%i == i / 2 && N / i - i / 2 >= 0) {
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}