
#include <stdio.h>

// ��ũ�� �ȿ��� ���� �����ڿ� ���� �����ڸ� ����Ͻø� �ȵ˴ϴ�.
// �̴� ������ �����Դϴ�.
#define SQR(x)	((x)*(x))

// �ζ��� �Լ�: �Լ� ȣ���� �ڵ忡 �Լ� ȣ�� ���ɾ�(call)�� �ƴ�
// �Լ��� ���� �ڵ�� ġȯ(inlining)�Ǵ� �Լ�
// �̴� C99���� ǥ������ ä�õ� �������� C++���� ������ �Խ��ϴ�.
inline int sqr(int x) { return x * x; }

// �ζ��� ������ ����ȭ �����̹Ƿ� ����ȭ �ɼ��� ������� ������ �������� �ʽ��ϴ�.

int main() {
	int x = 2;
	// int n = SQR(++x);	// ((++x)*(++x))
	int n = sqr(++x);
	printf("%d\n", n);
}