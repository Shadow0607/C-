#include <stdio.h>

int main(void) {
    char operation;
    float a_balance = 0, b_balance = 0;
    float amount;
    char selected_account = 'A'; // 預設選擇A帳戶

    while(1) {
        scanf(" %c", &operation); // 讀取操作指令，前面的空格是為了跳過任何的空白字符

        if(operation == 'e') {
            break; // 結束程式
        }

        switch(operation) {
            case 'a':
                printf("Select A\n");
                selected_account = 'A';
                break;
            case 'b':
                printf("Select B\n");
                selected_account = 'B';
                break;
            case 'v':
                if(selected_account == 'A') {
                    printf("A:%.2f\n", a_balance);
                } else {
                    printf("B:%.2f\n", b_balance);
                }
                break;
            case 'w':
                scanf("%f", &amount);
                if(selected_account == 'A') {
                    a_balance -= amount;
                    printf("A:Withdraw,%.2f\n", a_balance);
                } else {
                    b_balance -= amount;
                    printf("B:Withdraw,%.2f\n", b_balance);
                }
                break;
            case 's':
                scanf("%f", &amount);
                if(selected_account == 'A') {
                    a_balance += amount;
                    printf("A:Deposit,%.2f\n", a_balance);
                } else {
                    b_balance += amount;
                    printf("B:Deposit,%.2f\n", b_balance);
                }
                break;
            case 'p':
                if(a_balance + b_balance == 0) {
                    printf("A:0%%,B:0%%\n");
                } else {
                    float a_percentage = (a_balance / (a_balance + b_balance)) * 100;
                    float b_percentage = (b_balance / (a_balance + b_balance)) * 100;
                    printf("A:%.0f%%,B:%.0f%%\n", a_percentage, b_percentage);
                }
                break;
            default:
                printf("Invalid operation\n");
        }
    }

    return 0;
}
