#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main(void) {

	int T; 
	char input[55] = { 0, };
	scanf("%d", &T);


	for (int i = 0, j = 0, k = 0; i < T; i++) {
		scanf("%s", input);
		char stack[55] = { 0, }; // �ʱ�ȭ(����)
		j = 0; // �ʱ�ȭ
		k = 0; // �ʱ�ȭ


		// ��ȣ ���� �Ǻ�
		for (; input[j] != 0; j++) {

			if (stack[k] == 0) {
				
				if (input[j] == ')') { // ����
					stack[k] = ')';
					break;
				}

				else
					stack[k] = input[j]; // ����
			}

			else {

				if (input[j] != stack[k]) {
					stack[k] = 0;
					if (k != 0) //����
						k--;
				}

				else
					stack[++k] = input[j];
			}
		}


		// �Ǻ� ��� ���
		if (stack[0] == 0)
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}