#include<stdio.h>
#include<vector>
using namespace std;
int A, B,num;
int x[100001];//�Ҽ� 0�̸� �Ҽ�, 1�̸� x
int y[100001];//���μ� ���� ����
vector<int> v;
int go(int k) {//��������� ���ϱ�
	int ans = 0;
	for (int i = 2; i*i < 100001; i++) {
		if (k == 1) {
			return ans;
		}
		if (x[i] == 1) continue;
		while (1) {
			if (k%i == 0) {
				ans++;
				k /= i;
			}
			else {
				break;
			}
		}
	}
}
int main() {
	scanf("%d %d", &A, &B);
	x[0] = 1; x[1] = 1;
	for (int i = 2; i*i < 100001; i++) {
		if (x[i] == 0) {
			for (int j = i * i; j < 100001; j += i) {
				x[j] = 1;
			}
		}
	}//�Ҽ����ϱ�
	for (int i = A; i <= B; i++) {
		if (x[go(i)] == 0) {
			num++;
		}
	}
	printf("%d", num);
}