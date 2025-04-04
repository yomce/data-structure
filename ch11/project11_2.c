#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 두 요소를 교환하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 첫 번째 요소를 피벗으로 선택하는 퀵 분할 함수
int Quick_partition_first(int random_data[], int left, int right) {
    int low = left + 1;
    int high = right;
    int pivot = random_data[left];

    while (low <= high) {
        while (low <= high && random_data[high] > pivot) {
            high--;
        }
        while (low <= high && random_data[low] <= pivot) {
            low++;
        }
        if (low <= high) {
            swap(&random_data[low], &random_data[high]);
            low++;
            high--;
        }
    }
    swap(&random_data[left], &random_data[high]);
    return high;
}

// 마지막 요소를 피벗으로 선택하는 퀵 분할 함수
int Quick_partition_last(int random_data[], int left, int right) {
    swap(&random_data[left], &random_data[right]);
    return Quick_partition_first(random_data, left, right);
}

// 첫 번째, 중앙, 마지막 요소 중 중간 값을 피벗으로 선택하는 퀵 분할 함수
int Quick_partition_median(int random_data[], int left, int right) {
    int mid = left + (right - left) / 2;
    if (random_data[left] > random_data[mid])
        swap(&random_data[left], &random_data[mid]);
    if (random_data[left] > random_data[right])
        swap(&random_data[left], &random_data[right]);
    if (random_data[mid] > random_data[right])
        swap(&random_data[mid], &random_data[right]);
    swap(&random_data[mid], &random_data[left]);
    return Quick_partition_first(random_data, left, right);
}

// 퀵 정렬 함수
void Quick_sort(int random_data[], int left, int right, int (*partition)(int[], int, int)) {
    if (left < right) {
        int q = partition(random_data, left, right);
        Quick_sort(random_data, left, q - 1, partition);
        Quick_sort(random_data, q + 1, right, partition);
    }
}

// 배열을 출력하는 함수
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 0에서 9999 사이의 양의 정수 n개를 생성하는 함수
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }
}

// 메인 함수
int main() {
    srand(time(0)); // 랜덤 시드 설정
    int n;
    printf("배열의 크기를 입력하세요: ");
    scanf("%d", &n);
    int random_data[n];
    
    generateRandomArray(random_data, n);

    printf("원본 배열: \n");
    printArray(random_data, n);

    int data_first[n];
    int data_last[n];
    int data_median[n];

    // 원본 배열 복사
    for (int i = 0; i < n; i++) {
        data_first[i] = random_data[i];
        data_last[i] = random_data[i];
        data_median[i] = random_data[i];
    }

    // 첫 번째 값을 피벗으로 사용하여 정렬
    Quick_sort(data_first, 0, n - 1, Quick_partition_first);
    printf("첫 번째 값을 피벗으로 사용하여 정렬된 배열: \n");
    printArray(data_first, n);

    // 마지막 값을 피벗으로 사용하여 정렬
    Quick_sort(data_last, 0, n - 1, Quick_partition_last);
    printf("마지막 값을 피벗으로 사용하여 정렬된 배열: \n");
    printArray(data_last, n);

    // 중앙값을 피벗으로 사용하여 정렬
    Quick_sort(data_median, 0, n - 1, Quick_partition_median);
    printf("중앙값을 피벗으로 사용하여 정렬된 배열: \n");
    printArray(data_median, n);

    return 0;
}
