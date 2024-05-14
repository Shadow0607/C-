#include <stdio.h>
#include <stdlib.h>

int checkBingo(int board[9], int c[3]) {
    // 檢查行
    for (int i = 0; i <= 6; i += 3)
        if ((board[i] == c[0] || board[i] == c[1] || board[i] == c[2]) &&
            (board[i+1] == c[0] || board[i+1] == c[1] || board[i+1] == c[2]) &&
            (board[i+2] == c[0] || board[i+2] == c[1] || board[i+2] == c[2]))
            return 1;
    // 檢查列
    for (int i = 0; i < 3; i++)
        if ((board[i] == c[0] || board[i] == c[1] || board[i] == c[2]) &&
            (board[i+3] == c[0] || board[i+3] == c[1] || board[i+3] == c[2]) &&
            (board[i+6] == c[0] || board[i+6] == c[1] || board[i+6] == c[2]))
            return 1;
    // 檢查對角線
    if ((board[0] == c[0] || board[0] == c[1] || board[0] == c[2]) &&
        (board[4] == c[0] || board[4] == c[1] || board[4] == c[2]) &&
        (board[8] == c[0] || board[8] == c[1] || board[8] == c[2]))
        return 1;
    if ((board[2] == c[0] || board[2] == c[1] || board[2] == c[2]) &&
        (board[4] == c[0] || board[4] == c[1] || board[4] == c[2]) &&
        (board[6] == c[0] || board[6] == c[1] || board[6] == c[2]))
        return 1;
    // 若無獲勝則回傳0
    return 0;
}

int main() {
    int player1[9], player2[9], computer[3];
    int result1, result2;

    while (1) {
        for (int i = 0; i < 9; i++)
            if (scanf("%d", &player1[i]) != 1) return 0;
        for (int i = 0; i < 9; i++)
            if (scanf("%d", &player2[i]) != 1) return 0;
        for (int i = 0; i < 3; i++)
            if (scanf("%d", &computer[i]) != 1) return 0;
        
        int separator;
        scanf("%d", &separator); // 讀取0或-1來區分輸入案例
        
        result1 = checkBingo(player1, computer);
        result2 = checkBingo(player2, computer);
        
        if (result1 && !result2)
            printf("Player1 wins\n");
        else if (!result1 && result2)
            printf("Player2 wins\n");
        else
            printf("Draw\n");

        if(separator == -1) break; // 結束條件
    }
    return 0;
}
