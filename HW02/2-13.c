#include <stdio.h>

unsigned long long countWays(int n) {
    unsigned long long ways[71] = {0}; // 由於 K < 70，我們需要一個到 70 的陣列
    // 基礎情況
    ways[0] = 1; // 到達第0階（不動）也算一種方式
    ways[1] = 1; // 到達第1階有1種方式
    ways[2] = 2; // 到達第2階有2種方式
    ways[3] = 4; // 到達第3階有4種方式

    // 填充陣列
    for(int i = 4; i <= n; i++) {
        ways[i] = ways[i-1] + ways[i-2] + ways[i-3];
    }

    return ways[n];
}

int main() {
    int K;
    scanf("%d", &K);
    printf("%llu\n", countWays(K));
    return 0;
}
