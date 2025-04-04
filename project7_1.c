#include <stdio.h>

void printArray(int A[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", A[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

void Btree_array(int A[], int i, int Max_node) {
    int index;

    // 조상 노드 출력
    index = i;
    printf("인덱스 %d의 조상 노드: ", i);
    while (index > 0) {
        printf("%d ", A[index]);
        index = index / 2;
    }
    printf("\n");
    
    // 왼쪽 자식 노드 출력
    index = i;
    printf("인덱스 %d의 왼쪽 자식 노드: ", i);
    while (index <= Max_node) {
        printf("%d ", A[index]);
        index = index * 2;
    }
    printf("\n");
}

int main() {
    // 예시 사용법
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // 완전 이진 트리를 나타내는 배열
    int size = sizeof(A) / sizeof(A[0]); // 배열의 크기
    int i = 5; // 인덱스 예시
    int Max_node = 9; // 전체 노드 수 예시

    printf("배열 A 출력: ");
    printArray(A, size);

    Btree_array(A, i, Max_node);
    
    return 0;
}
