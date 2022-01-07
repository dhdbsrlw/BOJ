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
	
	// 트리의 마지막 노드에 저장
	heapTree[++hSize] = x; 

	// 최대힙 정렬
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
		// 가장 큰 수 제거 (최대 힙의 첫번째 노드)
		printf("%d\n", heapTree[1]);
		heapTree[1] = heapTree[hSize];
		heapTree[hSize--] = 0;

		// 최대 힙 정렬
		for (int i = 1; i * 2 <= hSize; ) {

			// 정렬 필요 없는 경우
			if (heapTree[i] >= heapTree[i * 2] && heapTree[i] >= heapTree[i * 2 + 1])
				break;

			// 정렬 필요 있는 경우
			else if (heapTree[i * 2] > heapTree[i * 2 + 1]) {
				swap(i * 2, i);
				i = i * 2; // 핵심 (낮은 idx부터 큰 수가 채워져야 한다.)
			}
			else {
				swap(i * 2 + 1, i);
				i = i * 2 + 1; // 핵심 (낮은 idx부터 큰 수가 채워져야 한다.)
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