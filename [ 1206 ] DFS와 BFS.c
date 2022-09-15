#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)


// 인접 행렬 생성 함수
int* Graph(int N, int M){

    // 인접 행렬 선언 및 초기화
    int *matrix = (int*)malloc(sizeof(int)*(N*N)); 
    for (int i = 0; i < N*N; i++)
        memset(matrix + i, 0, sizeof(int));

    // 인접 행렬 내부 값 할당
    for (int i = 0 ; i < M; i++){
        int tempB, tempE;
        scanf("%d", &tempB); // 간선의 출발점
        scanf("%d", &tempE); // 간선의 도착점
        *(matrix + N *(tempB-1) + (tempE - 1)) = 1;
        *(matrix + N * (tempE - 1) + (tempB - 1)) = 1;
    }
    return matrix;
}


// DFS (깊이 우선 탐색) 함수
void DFS (int cur, int n, int* matrix, int* visited){      
    
    printf("%d ", cur);

    *(visited + (cur-1)) = 1; // 현재 방문 노드 체크
    for(int i = 0; i < n; i++){ // 모든 인접 노드 체크
         if (((*(matrix + n*(cur - 1) + i)) == 1) && (*(visited + i) == 0)){ // 인접 및 미방문 노드 체크
            DFS(i + 1, n, matrix, visited);
        }
    }
}


// BFS (너비 우선 탐색) 함수
void BFS(int cur, int n, int* matrix, int* visited, int* queue) {
    int front = 0, rear = 0, temp;

    printf("%d ", cur);
    *queue = cur;
    rear++;
    *(visited + (cur - 1)) = 1; // 현재 방문 노드 체크

    while (front < rear) {
        temp = *(queue + front); // 
        front++;

        for (int i = 0; i < n; i++) { // 한 레벨이 한 사이클
            if (((*(matrix + n * (temp - 1) + i)) == 1) && (*(visited + i) == 0)) {  // 인접 및 미방문 노드 체크
                printf("%d ", i + 1);
                *(queue + rear) = i + 1; //
                rear++;
                *(visited + i) = 1;
            }
        }
    }
}


int main(void) {

    // 변수 선언
    int N, M, V;
    
    scanf("%d", &N); // 정점 개수
    scanf("%d", &M); // 간선 개수
    scanf("%d", &V); // 출발 정점

    int* matrix = Graph(N, M); // 인접 행렬 생성
    int* visited = (int*)malloc(sizeof(int) * N); // 방문 여부 확인
    int* queue = (int*)malloc(sizeof(int) * N); // BFS 보조 큐
   
    for (int i = 0; i < N; i++)
        memset(visited + i, 0, sizeof(int));
    DFS(V, N, matrix, visited);
    printf("\n");

    for (int i = 0; i < N; i++)
        memset(visited + i, 0, sizeof(int));
    BFS(V, N, matrix, visited, queue);

    free(matrix);
    free(visited);
    free(queue);

    return 0;
}