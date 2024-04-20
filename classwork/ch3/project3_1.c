//3.1 연결리스트를 만들어보자
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node;

// 선언부
Node* List_Create(int* array, int n);
Node* List_Insert(Node* head, int item, int position);
Node* List_Delete(Node* head, int item);

// 정의부
// 1. 역순으로 연결리스트를 구성하는 List_Create 함수
Node* List_Create(int* array, int n) {
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = array[i];
        newNode->link = head;
        head = newNode;
    }
    return head;
}

// 2. p번째 인덱스에 item data를 삽입하는 List_Insert 함수
Node* List_Insert(Node* head, int item, int position){
    Node* temp = head;
    for (int i=0; i < position-1; i++){
        temp = temp->link;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->link = temp->link;
    temp->link = newNode;

    return head;
}

// 3. 주어진 값과 일치하는 노드를 제거하는 List_Delete 함수
Node* List_Delete(Node* head, int item){
    Node* previous = head;
    Node* removed = head;

    // head가 null 포인터를 가리킬 때, NULL을 리턴. 즉 리스트 데이터가 없는경우이다.
    if (head == NULL){
        return NULL;
    }
    int count = 0;
    while(removed){
        count++;
        if(removed->data == item)
            break;
        previous = removed;
        removed = removed->link;
    }
    // 첫번쨰 노드일 경우
    if (count == 1)
        head = head->link;
    else
        previous->link = removed->link;
    
    // 필요없으므로 동적할당해제
    free(removed);

    if(previous->link == NULL)
        // 삭제할 데이터가 존재하지 않는 경우에, NULL 을 반환함.
        return NULL;
    else
        return head;
}

// 4. 출력 확인용 함수
void Print_Liked_List(Node* head) {
    Node* iter = head;
    int i = 0;
    while (iter != NULL) {
        printf("%d", iter->data);
        iter = iter->link;
        if (iter != NULL) printf(" -> ");
        i++;
    }
    printf("\n");
}

int main(void) {
    int A[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};    // 배열 선언
    Node* head = NULL;
    
    // 1. 배열에 저장된 데이터를 연결리스트로 구성
    head = List_Create(A, 10);  // 행렬A와 A의 길이가 입력이 됨.
    printf("첫번째 수행결과: ");
    Print_Liked_List(head);
    // 2. 5번째 위치한 노드에 55데이터 추가
    head = List_Insert(head, 55, 5);
    printf("두번째 수행결과: ");
    Print_Liked_List(head);
    // 3. 70값을 갖는 노드 제거
    head = List_Delete(head, 70);
    printf("세번째 수행결과: ");
    Print_Liked_List(head);
    // 4. 10값을 갖는 노드(첫번째) 제거
    head = List_Delete(head, 10);
    printf("네번째 수행결과: ");
    Print_Liked_List(head);
    // 5. 존재하지 않느 노드
    head = List_Delete(head, 2230);
    printf("다섯번째 수행결과: ");
    Print_Liked_List(head);
    return 0;
}