///////////////////////////////////////////////////////////////////////////////////////////////
//현재코드를 컴파일에서 제외하기 위해 조건부 매크로를 사용하겠다.
#if 0
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//빌드 방법 :F11
int main(int argc, char *argv[]) {
	printf("helloworld");
	return 0;
}
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////
#if 0
//주소 이야기
//CPU가 메모리에 접근하기 위해 부여한 방번호
// 방번호는 0으로 시작하는 양의 정수
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	int age = 0 ;  //메모리 어딘가에 4바이트의 크기를 확보하고
				        //그곳의 이름을 age로 하겠다는 의미
                //char는 short보다 같거나 작고 int 는 short보다 가거나 크고, long은 int보다 같거나 크다
  //위 변수의 주소를 확인해 보쟝
  //변수의 주소를 얻는 방법 :&변수
  printf("%u\n", &age);//단항 연산자

	return 0;
}
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////
//함수 호출과 실제 인자 이야기
//포인터 변수 선언 방법
//타입 * 변수명
//포인터 변수 선언지 *기호 주위의 공백은
//포인터 선언에 아무런 영향을 미치지 않는다.
//int * a;
//int* a;
//int *a;
#if 0
#include <stdio.h>
#include <stdlib.h>

void initInt(int * n){
  //역참조 연산자 *포인터
  *n=0;
}

int main(int argc, char *argv[]){
	int age;
  //아래와 같이 변수의 값을 사용하여 호출하는 방식을
  //값에 의한 호출이라고 합니다.(call bt value)
  // initInt(age);

  //아래와 같이 주소를 사용하여 호출하는 방식을
  //역시 값에 의한 호출이라고 합니다.
  initInt(&age);

  printf("age = %d\n", age);
	return 0;
}
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////
#if 0
//다중 포인터의 의미
#include <stdio.h>
#include <stdlib.h>
//포인터: 일반적으로 다른 함수 안에 사용된 변수를 참조하기 위해 사용
//일중 포인터: 일반적으로 다른지역의 일반 변수를 참조하기 위해 사용
//이중 포인터: 일반적으로 다른지역의 일중 포인터를 참조하기 위해 사용
//삼중 포인터: 일반적으로 다른지역의 이중 포인터를 참조하기 위해 사용
void initInt(int *p){
  //역참조 연산자 *포인터
  *p=0;
}
void initPtr(int **p){
  //역참조 연산자 *포인터
  *p=0;
}
void initPPtr(int ***p){
  //역참조 연산자 *포인터
  *p=0;
}
int main(int argc, char *argv[]){
  //해당 변수의 타입을 알고 싶다면 변수 선언에서 변수명을 제거하면 됩니다.
	int n= -1234343;//쓰레기값
  int *ptr=&n;
  int **pptr = &ptr;

  initInt(&n);
  printf("n = %d\n", n);
  initPtr(&ptr);
  printf("ptr = %d\n", ptr);
  initPPtr(&pptr);
  printf("pptr = %d\n", pptr);
	return 0;
}
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
//사용자로부터 이름을 입력받는 코드를 생각해 봅시다.
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//연습문제
//getName 함수를 구현하여 pName에 입력된 이름을 저장해 보쟝
void getName(char** ppName){
  //사용자의 이름을 저장하는 임시버퍼를 사용합니다.
  char buf[4096];//버퍼의 크기는 2의 지수승 단위로 할당하는 것이 좋습니다.
  scanf("%s", buf);
  int len = strlen(buf);//문자열은 아스키 널로 끝나야한다.
  *ppName = malloc(sizeof(char)*(len+1));//메모리 할당에 실패하면 null
                        //ASCII NULL(\0)   //메모리 누수, memory leak
  strcpy(*ppName, buf);
}
int main(){
	printf("input name: ");
  char* pName;
  getName(&pName);
  printf("%s\n", pName);
  free(pName);
  return 0;
  //개발을 할때에는 확장성을 고려해야한다.
  //따라서 위의 코드는 '코드의 중복'이 발생하게 되면, 유지보수 증가 버그가 발생한다.
}
#endif
//////////////////////////////////////////////////////////////////////////////////////////////
#if 0
//포인터와 상수 이야기
#include <stdio.h>
//리터럴, 상수
int main(){
	int a=10;
	a=0;//변수 (값이 변하는 공간)
	//리터럴 (literal:값 그자체로 변하지 않는것)
	const int b = 20;
	// b=30;//논리적 상수서을 갖는 변수

	int *p = (int*)&b;
	*p = 0;
	printf("%d \n", b);
	return 0;
}
#endif

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
#if 0
#include<stdio.h>

int main(int argc, char const *argv[]) {
	// int i=0;
	// int *p = &i;//포인터(pointer to integer)
	// *p=10;//OK, 대상체는 변수
	// p=0;//OK, 포인터는 변수

	// int i = 0;
	// //선언된 포인터에 대하여 변수명을 제거하면
	// //대상체의 타입을 의미합니다.
	// const int *p = &i;//상수지시 포인터 (pointer to constant)
	// // *p=10;//ERROR 대상체는 상수
	// p=0;//OK, 포인터는 변수

	// int i = 0;
	// int* const p = &i;//상수포인터(constant pointer to)
	// *p=10;//ok 대상체는 변수
	// // p=0;//ERROR 포인터는 상수

	// int i = 0;
	// int const * p = &i;//상수지시 포인터(pointer to constant)
	// // *p=10;//error, 대상체는 상수
	// p=0;//OK 포인터는 변수
	//포인터 지시자 기준으로 const가 왼쪽으로 있으면 대상체가 상수 나자신 수정가능
	//포인자 지시자 기분으로 const가 오른쪽에 있으면 대상체가 변수 나자신 수정불가

	//정리
	//포인터기호를 중심으로 *가
	//왼쪽에 있으면 대상체가 상수화
	//오른쪽에 있으면 포인터가 상수화


	int i=0;
	const int * cosnt p = &i;//상수 지시 상수포인터 (constant pointer to constant);
	*p=0;//ERROR 대상체도 상수
	p=0;//ERROR 포인터도 상수
	return 0;
}
#endif
//////////////////////////////////////////////////////////////////////////////////////////////

#if 0
#include <stdio.h>

int main(int argc, char const *argv[]) {
	// int i=0;
	// int *pI=0;
	//
	// float f = 0;
	// float *pF=0;
	//
	// double d = 0;
	// double *pD=0;

	//포인터 변수에서 포인터 타입의 의미
	//컴파일러에게 대상체의 크기(offset) 정보를 알려주기 위함

	// int x = 300;
	// char * p = &x;
	// printf("%d\n", *p);//300이 아닌 44로 찍힌다.//엔디언 살펴보기/little endian

	//2byte 이상의 변수를 선언합니다.
	//little or big  인지 확인하는 방법
	unsigned int x = 1;//0x00000001
	unsigned char *p = (unsigned char *)&x;
	if(*p == 1){
		printf("little");
	}
	else{
		printf("big");
	}

	return 0;
}
#endif
//////////////////////////////////////////////////////////////////////////////////////////////
//배열:동일한 타입의 원소 또는 객체가 연속되어 있는 메모리 공간을 의미
//(원소와 원소 사이에는 갭gap이 없음
//->선형구조
//
//배열의 선언:타입 배열명[크기]
//크기가 N일때 마지막 원소의 인덱스 값은 N-1 이다.

//배열의 포인터 선언
#include <stdio.h>
int main(int argc, char const *argv[]) {
	//배열의 선언 : 타입 배열명 [크기];
	int arr[3];

	//배열명의 의미: 첫번째 원소의 시작 주소를 의미하는 상수 포인터
	//arr = 0;//error
	printf("%d\n", arr);
	printf("%d\n", &arr);

	//배열 포인터 선언
	int *p1 = arr;
	int *p2 = &arr;
	printf("%d\n", p1);
	printf("%d\n", p2);

	printf("sizeof(arr) %u\n", sizeof arr);//배열의 타입 int[3] ->12bytes
	//배열의 이름을 단독으로 사용할 경우, 첫번째 원소의 포인터로 해석.
	//예외) sizeof 연산자, &연산자를 사용할때
	//arr 배열의 시작주소, 첫번째 원소
 // int((%int)[3]=arr;
	//배열푕인터(pointer tp array): 배열 전체를 가리키는 포링터(int[2] *Arr - >tinr;=>tinr aFrr[3];
	// int(&aPpdreea
	return 0;
}
