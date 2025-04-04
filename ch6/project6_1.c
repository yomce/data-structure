#include <stdio.h>
#include <stdbool.h>            // 부울대수 리턴을 위한 헤더파일 정의
#include <stdlib.h>             // 함수종료(exit)을 위한 헤더파일 정의

#define Queue_size 10           // 스택 사이즈를 해당 크기로 초기화

//queue_data 구조체 정의, 구조체는 정수형인 data를 가지고 있다.
typedef struct Queue_data {
    int data;
}Queue_data;

Queue_data queue[Queue_size];   // Queue_size 크기 만큼의 queue 배열을 선언. 전역변수이다.
int front = 0;                 // 뒷 자리를 지킴. 전역 변수로 설정해준 front. 생성된지 제일 오래된 자료의 위치를 가리킨다. dequeue시 front는 +1 됨. 처음엔 -1로 초기화
int rear = 0;                  // 선두. 전역 변수로 설정해준 rear. 가장 최근에 enqueue된 위치이다. enqueue시 rear +1됨. 처음엔 -1로 초기화

// 함수 선언부
bool Queue_empty();
bool Queue_full();
void Queue_enqueue(int item);
int Queue_dequeue();
void print_queue(Queue_data* queue); // 큐을 출력하기 위한 편의 함수

// 함수 정의부
// 큐가 비었는지 검사한다. front와 rear위치가 같으면 빈 것이다 (중요)
bool Queue_empty() {
    if (front == rear)
        return true;
    else
        return false;
}

// 큐가 가득찼는지 판단한다. 원형 배열로 이루어진 큐이므로 조건식을 잘 보도록 하자.
bool Queue_full() {
    if (front == ((rear + 1) % Queue_size))
        return true;
    else
        return false;
}

// 
void Queue_enqueue(int item) {
    if (Queue_full()) {
        printf("큐가 가득차서 푸시할 수 없습니다.\n");
        exit(1);                // 함수 종료
    }
    rear = (rear + 1) % Queue_size;  // 원형 배열이므로 Queue_size 인덱스를 넘어가지 않음
    queue[rear].data = item;     // 바뀐 rear위치에 item 값 삽입
}

// top이 가리키는 위치의 스택 인덱스를 반환하며 top 위치를 -1 한다. 스택이 비었는지 검사 후 진행된다.
int Queue_dequeue() {
    if (Queue_empty()) {
        printf("큐가 비어있어 삭제할 수 없습니다.\n");
        exit(1);                // 함수 종료
    }
    front = (front + 1) % Queue_size;
    return queue[front].data;             // item 변수를 반환한다. pop되기 전의 top위치에 있던 data 값이다.
}

void print_queue(Queue_data* queue) {
    printf("===================================\n");
    if (Queue_empty())
        printf("큐가 초기 상태입니다.\n");
    for(int i = 0; i < Queue_size; i++) {
        if ((rear % Queue_size) == i)
            printf("[index: %d]의 data : %d <- rear의 위치입니다.\n", i, queue[i].data);
        else if (front % Queue_size == i)
            printf("[index: %d]의 data : %d <- front의 위치입니다.\n", i, queue[i].data);
        else
            printf("[index: %d]의 data : %d\n", i, queue[i].data);
    }
    printf("===================================\n");
}

int main(void) {
    // case 1. 빈 상태의 queue을 출력해본다.
    printf("case 1. 빈 상태의 queue을 출력해본다.\n");
    print_queue(queue);
    // case 2. 값을 하나 넣고 queue을 출력해본다
    printf("값을 하나(10) 넣고 print해본다.\n");
    Queue_enqueue(10);
    print_queue(queue);
    // case 3. 값을 3개 더 넣고(20,30,40) queue을 출력해본다.
    printf("값을 3개(20,30,40) 넣고 print해본다.\n");
    Queue_enqueue(20);
    Queue_enqueue(30);
    Queue_enqueue(40);
    print_queue(queue);
    // case 4. 값을 하나 빼고 queue을 출력해본다.
    printf("값을 하나 빼고 printf해본다.\n");
    printf("빠진 값 : %d\n", Queue_dequeue());
    print_queue(queue);
    return 0;
}
