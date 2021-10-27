#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)


// 구조체 생성
typedef struct NODE {
	int rank;
	int name; // 수정_3: 노드의 위치(랭킹)와 이름 별개
	struct NODE* next;
} TEAM;


// 팀명 변환 함수 (수정_2)
int convert(char team[]) {
	int num = 0;
	for (int i = 1; team[i] != 0; i++) {
		num *= 10;
		num += (team[i] - '0');
	}
	return num;
}


int main(void) {

	//전체 팀 수(n) 및 전체 경기 수(m)
	int n, m;
	scanf("%d %d", &n, &m);

	TEAM* head = NULL;
	TEAM* cur = NULL;
	TEAM* new_node = NULL;

	head = (TEAM*)malloc(sizeof(TEAM));
	head->rank = 1;
	head->name = 1;
	head->next = NULL;
	cur = head;


	// 연결리스트 생성
	for (int i = 2; i <= n; i++) {
		new_node = (TEAM*)malloc(sizeof(TEAM));
		new_node->rank = i;
		new_node->name = i;
		new_node->next = NULL;
		cur->next = new_node;
		cur = new_node;
	}


	// 경기 결과에 따른 노드 위치 변경
	char winner[10] = { 0, };
	char loser[10] = { 0, };
	int winN, loseN;
	
	for (int j = 0; j < m; j++) {
		scanf("%s %s", winner, loser);

		winN = convert(winner); // 수정_1: (atoi 사용 불가/ 배열 주의)
		loseN = convert(loser);
		
		// winner의 랭킹(위치) 파악
		int winpos = 0;
		cur = head;
		while (cur != NULL) {
			if (cur->name == winN) {
				winpos = cur->rank;
				break;
			}
			else cur = cur->next;
		}

		// loser의 랭킹(위치) 파악
		int losepos = 0;
		cur = head;
		while (cur != NULL) {
			if (cur->name == loseN) {
				losepos = cur->rank;
				break;
			}

			else cur = cur->next;
		}

		if (winpos <= losepos) //수정_4:
			continue;

		else {
			TEAM* ptr = head; // head 복제 (loseN 찾기)
			TEAM* temp = head; // head 복제 (winN 찾기)

			// head 변경이 필요한 경우
			if (ptr->name == loseN) {
				head = head->next; // head 변경
				while (temp != NULL) {
					if (temp->name == winN) {
						ptr->next = temp->next;
						temp->next = ptr;
						break;
					}

					else
						temp = temp->next; //수정_2
				}
			}
			
			// head 변경이 필요하지 않은 경우
			else {
				// loseN
				TEAM* prev = NULL;
				while (ptr != NULL) {
					if (ptr->name == loseN) {
						// winN
						while (temp != NULL) {
							if (temp->name == winN) {
								prev->next = ptr->next;
								ptr->next = temp->next;
								temp->next = ptr;
								break;
							}
							else
								temp = temp->next;
						}
						break;
					}
					else
						prev = ptr; // 수정_5
						ptr = ptr->next;
				}
			}
		}

		// 순위 변동 반영
		cur = head;
		for (int i = 1; cur != NULL; i++) {
			cur->rank = i;
			cur = cur->next;
		}
	}


	// 경기 결과 출력
	cur = head;
	while (cur != NULL) {
		printf("T%d ", cur->name);
		cur = cur->next;
	}

	return 0;
}