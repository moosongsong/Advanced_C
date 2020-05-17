//2차원 배열: 원소가 1차원 배열인 1차원 배열
//N차원 배열: 원소가 N-1차원의 배열을 갖는 1차원배열
#if 0
#include<stdio.h>
int main(int argc, char const *argv[]) {
  int arr1[3] = {1,2,3};
  int* pAry1 = arr1;

  int arr2[2][3] = {{1,2,3},{4,5,6}};
  int (*pAry2)[3]=arr2;//포인터 변수가 되도록 하려면 *먼저 해석되게 해야한다.
  return 0;
}
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////

//포인터의 산술연산1
#if 0
#include<stdio.h>
int main(int argc, char const *argv[]) {
  int *p, *q;
  p=0;
  q=0;

  //q+p;
  //포인터 + 포인터 = 가능?->에러ERROR
  //원래는 포인터 끼리의 덧셈이 가능하나, 컴파일러가 막아버렸다. 왜? 운영체제 내에서 다른 영역을 건들수 있기 때문

  //q-p;
  //그러나 빼기는 가능하다->변위
  //즉 거리(정수)를 구할 수 있기 때문에, 사용이 용이하다.

  //p*q;
  //잘못된 메모리 참조로 인해서 프로세스 중단이되기 때문에 불가능하다.error

  //p/q;
  //의미가 저언혀 없다.error

  //p+1;
  //유의미하다.
  //포인터 + 정수 = 포인터

  //p-1;
  //포인터 - 정수 =포인터

  //p*1;
  //포인터 * 정수 =에러

  //p/1;
  //포인터 / 정수 =에러

  //결론: 포인터는 제한적인 산술 연산이 가능하다.
  return 0;
}
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////

//포인터의 산술연산2
//ppt 자료 참고
#if 0
#include<stdio.h>
int main(int argc, char const *argv[]) {
  int i=0;
  printf("%d\n", i+1);

  //포인터와 정수의 연산 결과는 대상체 크기의 배수 만큼 계산됩니다.
  int*p=0;
  printf("%d\n", p+1);//p + (sizeof(*p)*1)

  int arr[6]={1,2,3,4,5,6};
  for (size_t i = 0; i < 6; i++) {
    printf("%d\n", *(arr+i));
  }
  return 0;
}
#endif
#if 0
#include<stdio.h>
int main(int argc, char const *argv[]) {
  int arr[2][3]={{1,2,3},{4,5,6}};
  int(*p)[3]=0;
  printf("%d\n",p+1);//12

  printf("arr[1][2]=%d\n", arr[1][2]);
  printf("arr[1][2]=%d\n", (*(arr+1))[2]);
  printf("arr[1][2]=%d\n", *(*(arr+1)+2));
  return 0;
}
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////

//2차원 배열의 동적할당
#if 0
#include<stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  int arr[2][3];
  int(*p)[3] = malloc(sizeof(int)*3*4);

  int ** t = malloc(sizeof(int*)*3);
  for (size_t i = 0; i < 3; i++) {
    t[i]=malloc(sizeof(int)*4);
  }
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 4; j++) {
      t[i][j]=i+j;
      p[i][j]=i+j;
    }
  }
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 4; j++) {
      printf("%d\t", t[i][j]);
      printf("%d\t", p[i][j]);
    }
    printf("\n");
  }
  for (size_t i = 0; i < 3; i++) {
    free(t[i]);
  }
  free(t);
  free(p);
  return 0;
}
#endif

/////////////////////////////////////////////////////////////////////////////////////////////

//사용자의 이름을 입력받는 코드를 생각해보자
#if 0
#include <stdio.h>
int main(int argc, char const *argv[]) {
  //대용량의 자료구조를 스택에 저장했다는 단점이 있다.
  char name[3][32];
  for (size_t i = 0; i < 3; i++) {
    printf("input name:");
    scanf("%s", name[i]);

  }
  for (size_t i = 0; i < 3; i++) {
    printf("%s\n", name[i]);
  }
  return 0;
}
#endif

///////////////////////////////////////////////////////////////////////////////////////////////

//이전 코드는 대용량의 자료구조를 스택에 생성한다는 단점이 있다.
//이제 이 데이터를 힙에 생성합니다.
#if 0
#include <stdio.h>
int main(int argc, char const *argv[]) {
  char ** name = malloc(sizeof(char*)*3);
  // char (*name)[32]=malloc(sizeof(char)*3*32);
  for (size_t i = 0; i < 3; i++) {
    printf("input name:");
    scanf("%s", name[i]);
    name[i]= malloc(sizeof(char)*32);
  }

  for (size_t i = 0; i < 3; i++) {
    printf("input name:");
    scanf("%s", name[i]);

  }
  for (size_t i = 0; i < 3; i++) {
    printf("%s\n", name[i]);
  }
  free(name);
  return 0;
}
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//이전 코드는 힙메모리에 대하여 낭비가 발생한다.
//이를 해결하기 위해 문자열 포인터를 사용한다.
//톱니형 배열
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[]) {
  char buf[32];
  char ** name = malloc(sizeof(char*)*3);
  // char (*name)[32]=malloc(sizeof(char)*3*32);
  for (size_t i = 0; i < 3; i++) {
    printf("input name:");
    scanf("%s", buf);
    name[i]= malloc(sizeof(char)*(strlen(buf)+1));
    strcpy(name[i], buf);
  }
  for (size_t i = 0; i < 3; i++) {
    printf("%s\n", name[i]);
  }
  //메모리의 헤제는 반드시 생성의 역순으로 해제해야합니다.
  for (size_t i = 0; i < 3; i++) {
      free(name[i]);
  }
  free(name);
  return 0;
}
