#include <stdio.h>
#include <stdbool.h>            // 부울대수 리턴을 위한 헤더파일 정의
#include <stdlib.h>             // 함수종료(exit)을 위한 헤더파일 정의

#define Stack_size 10           // 스택 사이즈를 해당 크기로 초기화

//stack_data 구조체 정의, 구조체는 정수형인 data를 가지고 있다.
typedef struct stack_data {
    int data;
}stack_data;

stack_data stack[Stack_size];   // Stack_size 크기 만큼의 stack이라는 배열을 선언. 전역변수이다.
int top = -1;                   // 스택의 현재위치인 top은 초기에 -1로 할당한다. 전역변수이다.

// 함수 선언부
bool Stack_empty();
bool Stack_full();
void Stack_push(int item);
int Stack_pop();
void print_stack(stack_data* stack); // 스택을 출력하기 위한 편의 함수

// 함수 정의부
// 스택이 비었는지 검사한다. top이 -1을 가리킬 때 스택이 비어있다고 하며 true를 반환한다.
bool Stack_empty() {
    return top == -1;
}

// 스택이 가득찼는지 검사한다. top이 Stack_size-1과 값이 같으면 스택이 가득찼다고 하며 true를 반환한다.
bool Stack_full() {
    return top == Stack_size - 1;
}

// 스택에 인자 item을 넣고 top 위치를 +1 한다. 스택이 가득 찼는지 검사 후 진행된다.
void Stack_push(int item) {
    if (Stack_full()) {
        printf("배열이 가득차서 푸시할 수 없습니다.\n");
        exit(1);                // 함수 종료
    }
    top++;                      // top위치 +1한다.
    stack[top].data = item;     // 바뀐 top위치에 item 값 삽입
}

// top이 가리키는 위치의 스택 인덱스를 반환하며 top 위치를 -1 한다. 스택이 비었는지 검사 후 진행된다.
int Stack_pop() {
    if (Stack_empty()) {
        printf("배열이 비어있어 삭제할 수 없습니다.\n");
        exit(1);                // 함수 종료
    }
    int item = stack[top].data;     // top위치를 내리기 전, 미리 값을 item 변수에 저장한다.
    top--;                          // top위치를 -1한다.
    return item;                    // item 변수를 반환한다. pop되기 전의 top위치에 있던 data 값이다.
}

void print_stack(stack_data* stack) {
    printf("===================================\n");
    if (top == -1)
        printf("top이 초기위치(-1)을 가리키고 있습니다.\n");
    for(int i = 0; i < Stack_size; i++) {
        if (top == i)
            printf("[index: %d]의 data : %d <- top의 위치입니다.\n", i, stack[i].data);
        else
            printf("[index: %d]의 data : %d\n", i, stack[i].data);
    }
    printf("===================================\n");
}

int main(void) {
    // case 1. 빈 상태의 stack을 출력해본다.
    printf("case 1. 빈 상태의 stack을 출력해본다.\n");
    print_stack(stack);
    // case 2. 값을 하나 넣고 stack을 출력해본다
    printf("값을 하나(10) 넣고 print해본다.\n");
    Stack_push(10);
    print_stack(stack);
    // case 3. 값을 3개 더 넣고(20,30,40) stack을 출력해본다.
    printf("값을 3개(20,30,40) 넣고 print해본다.\n");
    Stack_push(20);
    Stack_push(30);
    Stack_push(40);
    print_stack(stack);
    // case 4. 값을 하나 빼고 stack을 출력해본다.
    printf("값을 하나 빼고 printf해본다.\n");
    printf("빠진 값 : %d\n", Stack_pop());
    print_stack(stack);
    // case 5. 값을 꽉 채워본다.
    printf("값을 꽉 채워본다.\n");
    Stack_push(40);
    Stack_push(50);
    Stack_push(60);
    Stack_push(70);
    Stack_push(80);
    Stack_push(90);
    Stack_push(100);
    print_stack(stack);
    // case 6. 하나 더 채워 종료 시켜본다.
    // printf("값을 하나 더 채워 함수를 종료시켜본다.\n");
    // Stack_push(110);
    // case 7. 반대로 10개를 모두 지운다.
    Stack_pop();
    Stack_pop();
    Stack_pop();
    Stack_pop();
    Stack_pop();
    Stack_pop();
    Stack_pop();
    Stack_pop();
    Stack_pop();
    Stack_pop();
    print_stack(stack);
    // case 8. 하나 더 지우게 하여 Empty에 걸리게 한다.
    Stack_pop();
    return 0;
}
