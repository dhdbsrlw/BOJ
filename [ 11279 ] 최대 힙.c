#include <stdio.h>
#pragma warning(disable:4996)

int heapTree[100005];
int hSize;

void swap(int i, int j) {

	int tmp = heapTree[i];
	heapTree[i] = heapTree[j];
	heapTree[j] = tmp;
}

void push(int x) {
	
	// Ʈ���� ������ ��忡 ����
	heapTree[++hSize] = x; 

	// �ִ��� ����
	for (int i = hSize; i > 1; i /= 2) {
		if (heapTree[i] > heapTree[i / 2])
			swap(i / 2, i);
		else
			break;
	}
}

void pop(int x) {
	
	if (heapTree[1] == 0)
		printf("%d\n", 0);

	else {
		// ���� ū �� ���� (�ִ� ���� ù��° ���)
		printf("%d\n", heapTree[1]);
		heapTree[1] = heapTree[hSize];
		heapTree[hSize--] = 0;

		// �ִ� �� ����
		for (int i = 1; i * 2 <= hSize; ) {

			// ���� �ʿ� ���� ���
			if (heapTree[i] >= heapTree[i * 2] && heapTree[i] >= heapTree[i * 2 + 1])
				break;

			// ���� �ʿ� �ִ� ���
			else if (heapTree[i * 2] > heapTree[i * 2 + 1]) {
				swap(i * 2, i);
				i = i * 2; // �ٽ� (���� idx���� ū ���� ä������ �Ѵ�.)
			}
			else {
				swap(i * 2 + 1, i);
				i = i * 2 + 1; // �ٽ� (���� idx���� ū ���� ä������ �Ѵ�.)
			}
		}
	}
}

int main(void) {

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {

		int num;
		scanf("%d", &num);
		
		if (num != 0) push(num);
		else pop(num);
	}
	return 0;
}