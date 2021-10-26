#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main(void) {

	int T; 
	char input[55] = { 0, };
	scanf("%d", &T);


	for (int i = 0, j = 0, k = 0; i < T; i++) {
		scanf("%s", input);
		char stack[55] = { 0, }; // 초기화(수정)
		j = 0; // 초기화
		k = 0; // 초기화


		// 괄호 문장 판별
		for (; input[j] != 0; j++) {

			if (stack[k] == 0) {
				
				if (input[j] == ')') { // 수정
					stack[k] = ')';
					break;
				}

				else
					stack[k] = input[j]; // 수정
			}

			else {

				if (input[j] != stack[k]) {
					stack[k] = 0;
					if (k != 0) //수정
						k--;
				}

				else
					stack[++k] = input[j];
			}
		}


		// 판별 결과 출력
		if (stack[0] == 0)
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}