#include <stdio.h>
#define ARR_MAX (4096)

int print_arr(const int * arr, size_t len){
    //여기서, size 가 -1이 들어오며 41억이기에 체크하장
    //배열에서 크기를 나타내는 인자가 유효한 범위 안에 있음을 보장하는 것이 좋습니다.
    if (arr == NULL || len > ARR_MAX){
        return -1;
    }

    for (int i = 0; i < len; ++i) {
        printf("%d", arr[i]);
    }
    return 0;
}
int main() {
    int arr[]={1,2,3,4,5};

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        printf("%d", arr[i]);
    }
    printf("꾸\n");
    print_arr(arr, 5);
    return 0;
}
