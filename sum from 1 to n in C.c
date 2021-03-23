#include<stdio.h>
#include<time.h>

int sumAlgorithmA(int num)
{
    return num*(num + 1) / 2;
}
int sumAlgorithmB(int num)
{
    int sum = 0;
    int i;
    for (i = 1; i <= num; i++) {
        sum = sum + i;
    }
    return sum;
}

int sumAlgorithmC(int num)
{
    int sum = 0;
    int    i, j;
    for (i = 0; i <= num; i++) {
        for (j = 1; j <= i; j++) {
            sum = sum + 1;
        }
    }
    return sum;
}


void AlgorithmA(int n, int times) {
    int i;
    for (i = 0; i < times; i++)
        sumAlgorithmA(n);
}
void AlgorithmB(int n, int times) {
    int i;
    for (i = 0; i < times; i++)
        sumAlgorithmB(n);
}
void AlgorithmC(int n, int times) {
    int i;
    for (i = 0; i < times; i++)
        sumAlgorithmC(n);
}

void main()
{
    clock_t t0, t1, t2, t3;
    double dA, dB, dC;
    int i;

    printf("(1) 알고리즘 정확도 테스트\n");
    printf("AlgorithmA (7) = %d\n", sumAlgorithmA(7));
    printf("AlgorithmB (7) = %d\n", sumAlgorithmB(7));
    printf("AlgorithmC (7) = %d\n", sumAlgorithmC(7));

    printf("AlgorithmA (9) = %d\n", sumAlgorithmA(9));
    printf("AlgorithmB (9) = %d\n", sumAlgorithmB(9));
    printf("AlgorithmC (9) = %d\n", sumAlgorithmC(9));

    printf("\n(2) 알고리즘 실행 시간 비교: A - B - C\n");
    for (i = 1000; ; i += 100) {
        t0 = clock();
        AlgorithmA(i, 100);
        t1 = clock();
        AlgorithmB(i, 100);
        t2 = clock();
        AlgorithmC(i, 100);
        t3 = clock();
        dA = (double)(t1 - t0) / CLOCKS_PER_SEC;
        dB = (double)(t2 - t1) / CLOCKS_PER_SEC;
        dC = (double)(t3 - t2) / CLOCKS_PER_SEC;

        printf("%5d: \t", i);
        printf("AlgorithmA : %lf\t", dA);
        printf("AlgorithmB : %lf\t", dB);
        printf("AlgorithmC : %lf\n", dC);
        
        if (dC > 1.0) break;
    }

    printf("\n(3) 알고리즘 실행 시간 비교: A - B\n");
    for (i = 10000; ; i += 100000) {
        t0 = clock();
        AlgorithmA(i, 100);
        t1 = clock();
        AlgorithmB(i, 100);
        t2 = clock();
        dA = (double)(t1 - t0) / CLOCKS_PER_SEC;
        dB = (double)(t2 - t1) / CLOCKS_PER_SEC;
        printf("%5dk: \t", i / 1000);
        printf("AlgorithmA : %lf\t", dA);
        printf("AlgorithmB : %lf\n", dB);
        if (dB > 1.0) break;
    }
}
