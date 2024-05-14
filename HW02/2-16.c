#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IPS 100 // 假定最多只處理100個IP地址

typedef struct {
    int segment1;
    int segment2;
    char nickname[50];
} IPAddress;

int main(void) {
    IPAddress ips[MAX_IPS];
    char input[100];
    int count = 0, i, j;
    int seg1, seg2, seg3, seg4;
    char nickname[50];
    int errorFlag = 0;

    // 讀取輸入
    while (1) {
        scanf("%d.%d.%d.%d,%49s", &seg1, &seg2, &seg3, &seg4, nickname);
        if (seg1 == 0 && seg2 == 0 && seg3 == 0 && strcmp(nickname, "none") == 0) break; // 結束輸入
        if (seg1 > 255 || seg2 > 255 || seg3 > 255 || seg4 > 255) { // 檢查不合法IP
            printf("machine %s is error ip\n", nickname);
            errorFlag = 1;
            continue;
        }
        ips[count].segment1 = seg1;
        ips[count].segment2 = seg2;
        strcpy(ips[count].nickname, nickname);
        count++;
    }

    // 處理並輸出同一網段的IP
    for (i = 0; i < count; i++) {
        if (!errorFlag) { // 只有在沒有錯誤的情況下才處理
            printf("machines");
            int first = 1; // 用於追蹤是否為同網段的第一個IP
            for (j = i + 1; j < count; j++) {
                if (ips[i].segment1 == ips[j].segment1 && ips[i].segment2 == ips[j].segment2) {
                    if (first) {
                        printf(" %s", ips[i].nickname);
                        first = 0;
                    }
                    printf(", %s", ips[j].nickname);
                    strcpy(ips[j].nickname, ""); // 清除已處理的昵稱，避免重複輸出
                }
            }
            if (!first) { // 如果發現有同網段的IP
                printf(" are on the same local network.\n");
            }
        }
    }

    return 0;
}
