#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)


// ����ü ����
typedef struct NODE {
	int rank;
	int name; // ����_3: ����� ��ġ(��ŷ)�� �̸� ����
	struct NODE* next;
} TEAM;


// ���� ��ȯ �Լ� (����_2)
int convert(char team[]) {
	int num = 0;
	for (int i = 1; team[i] != 0; i++) {
		num *= 10;
		num += (team[i] - '0');
	}
	return num;
}


int main(void) {

	//��ü �� ��(n) �� ��ü ��� ��(m)
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


	// ���Ḯ��Ʈ ����
	for (int i = 2; i <= n; i++) {
		new_node = (TEAM*)malloc(sizeof(TEAM));
		new_node->rank = i;
		new_node->name = i;
		new_node->next = NULL;
		cur->next = new_node;
		cur = new_node;
	}


	// ��� ����� ���� ��� ��ġ ����
	char winner[10] = { 0, };
	char loser[10] = { 0, };
	int winN, loseN;
	
	for (int j = 0; j < m; j++) {
		scanf("%s %s", winner, loser);

		winN = convert(winner); // ����_1: (atoi ��� �Ұ�/ �迭 ����)
		loseN = convert(loser);
		
		// winner�� ��ŷ(��ġ) �ľ�
		int winpos = 0;
		cur = head;
		while (cur != NULL) {
			if (cur->name == winN) {
				winpos = cur->rank;
				break;
			}
			else cur = cur->next;
		}

		// loser�� ��ŷ(��ġ) �ľ�
		int losepos = 0;
		cur = head;
		while (cur != NULL) {
			if (cur->name == loseN) {
				losepos = cur->rank;
				break;
			}

			else cur = cur->next;
		}

		if (winpos <= losepos) //����_4:
			continue;

		else {
			TEAM* ptr = head; // head ���� (loseN ã��)
			TEAM* temp = head; // head ���� (winN ã��)

			// head ������ �ʿ��� ���
			if (ptr->name == loseN) {
				head = head->next; // head ����
				while (temp != NULL) {
					if (temp->name == winN) {
						ptr->next = temp->next;
						temp->next = ptr;
						break;
					}

					else
						temp = temp->next; //����_2
				}
			}
			
			// head ������ �ʿ����� ���� ���
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
						prev = ptr; // ����_5
						ptr = ptr->next;
				}
			}
		}

		// ���� ���� �ݿ�
		cur = head;
		for (int i = 1; cur != NULL; i++) {
			cur->rank = i;
			cur = cur->next;
		}
	}


	// ��� ��� ���
	cur = head;
	while (cur != NULL) {
		printf("T%d ", cur->name);
		cur = cur->next;
	}

	return 0;
}