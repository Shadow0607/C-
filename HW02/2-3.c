#include <stdio.h> // 包含標準輸入輸出庫的頭文件
#include <stdlib.h> // 包含標準庫函數的頭文件
#include <string.h> // 包含字符串處理函數的頭文件

#define MAX_ITEMS 20 // 定義最大商品數量為20
#define MAX_TRANSACTIONS 1000 // 定義最大交易數量為1000

int main() { // 主函數入口
    int transactions[MAX_TRANSACTIONS][MAX_ITEMS] = {0}; // 定義二維數組transactions，記錄每筆交易中商品的購買情況，初始值為0
    int count[MAX_ITEMS][MAX_ITEMS] = {0}; // 定義二維數組count，記錄每對商品的共同購買次數，初始值為0
    int numTransactions; // 記錄交易數量

    // 讀取購買數據
    printf("請輸入交易數量: "); // 提示用戶輸入交易數量
    scanf("%d", &numTransactions); // 讀取用戶輸入的交易數量

    // 處理每一筆交易
    for (int i = 0; i < numTransactions; ++i) { // 遍歷每一筆交易
        char transactionInput[MAX_ITEMS * 3]; // 定義字符數組transactionInput，用於存儲每筆交易的輸入數據
        printf("請輸入第%d筆交易: ", i + 1); // 提示用戶輸入第幾筆交易
        scanf("%s", transactionInput); // 讀取用戶輸入的交易數據

        // 解析交易中的商品編號
        char *token = strtok(transactionInput, ","); // 使用逗號分割輸入字符串
        while (token != NULL) { // 循環直到token為NULL
            int item = atoi(token); // 將字符串轉換為整數，得到商品編號
            transactions[i][item - 1] = 1; // 標記商品被購買，數組下標從0開始，而商品編號從1開始，故需減1
            token = strtok(NULL, ","); // 繼續解析下一個商品編號
        }
    }

    // 統計每對商品的共同購買次數
    for (int i = 0; i < numTransactions; ++i) { // 遍歷每一筆交易
        for (int j = 0; j < MAX_ITEMS - 1; ++j) { // 遍歷商品編號
            if (transactions[i][j] == 1) { // 如果商品被購買
                for (int k = j + 1; k < MAX_ITEMS; ++k) { // 繼續遍歷後面的商品
                    if (transactions[i][k] == 1) { // 如果另一個商品也被購買
                        count[j][k]++; // 共同購買次數加1
                    }
                }
            }
        }
    }

    // 尋找共同購買次數最多的商品對
    int maxCount = 0; // 初始化最大共同購買次數為0
    int item1 = 0, item2 = 0; // 記錄共同購買次數最多的商品編號
    for (int i = 0; i < MAX_ITEMS - 1; ++i) { // 遍歷商品編號
        for (int j = i + 1; j < MAX_ITEMS; ++j) { // 繼續遍歷後面的商品編號
            if (count[i][j] > maxCount) { // 如果找到共同購買次數更多的商品對
                maxCount = count[i][j]; // 更新最大共同購買次數
                item1 = i + 1; // 更新商品編號
                item2 = j + 1;
            }
        }
    }

    // 輸出結果
    printf("%d,%d,%d\n", item1, item2, maxCount); // 輸出共同購買次數最多的商品對以及出現次數

    return 0; // 返回程序執行成功
}
