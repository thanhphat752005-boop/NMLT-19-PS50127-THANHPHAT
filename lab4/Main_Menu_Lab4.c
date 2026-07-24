#include <stdio.h>

int main() {
    int choice;
    
    do {
        // Giao diện Menu
        printf("\n+---------------------------------------------------+\n");
        printf("|             MENU CHUONG TRINH LAB 4               |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Tinh trung binh tong cac so chia het cho 2     |\n");
        printf("| 2. Kiem tra So nguyen to                          |\n");
        printf("| 3. Kiem tra So chinh phuong                       |\n");
        printf("| 4. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-4): ");
        scanf("%d", &choice);
        
        // Xử lý các chức năng
        switch (choice) {
            case 1: {
                int min, max;
                int sum = 0, count = 0;
                
                printf("\n--- Chuc nang 1: Tinh trung binh ---\n");
                printf("Nhap gia tri min: ");
                scanf("%d", &min);
                printf("Nhap gia tri max: ");
                scanf("%d", &max);
                
                if (min > max) {
                    printf("Loi: min khong duoc lon hon max!\n");
                } else {
                    for (int i = min; i <= max; i++) {
                        if (i % 2 == 0) {
                            sum += i;
                            count++;
                        }
                    }
                    
                    if (count == 0) {
                        printf("Khong co so nao chia het cho 2 trong khoang [%d, %d].\n", min, max);
                    } else {
                        float trungBinh = (float)sum / count;
                        printf("Trung binh cong cac so chia het cho 2 la: %.2f\n", trungBinh);
                    }
                }
                break;
            }
            
            case 2: {
                int x;
                int isPrime = 1; // Giả sử ban đầu là số nguyên tố (1: Đúng, 0: Sai)
                
                printf("\n--- Chuc nang 2: Kiem tra So nguyen to ---\n");
                printf("Nhap vao so nguyen x: ");
                scanf("%d", &x);
                
                if (x < 2) {
                    isPrime = 0;
                } else {
                    for (int i = 2; i < x; i++) {
                        if (x % i == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                }
                
                if (isPrime == 1) {
                    printf("%d la so nguyen to.\n", x);
                } else {
                    printf("%d khong phai la so nguyen to.\n", x);
                }
                break;
            }
            
            case 3: {
                int x;
                int isSquare = 0; // Giả sử ban đầu không phải số chính phương (1: Đúng, 0: Sai)
                
                printf("\n--- Chuc nang 3: Kiem tra So chinh phuong ---\n");
                printf("Nhap vao so nguyen x: ");
                scanf("%d", &x);
                
                // Thuật toán: duyệt i từ 1 đến x
                for (int i = 1; i <= x; i++) {
                    if (i * i == x) {
                        isSquare = 1;
                        break; // Thoát vòng lặp sớm
                    }
                }
                
                // Bổ sung thêm trường hợp x = 0 (0 cũng là số chính phương)
                if (x == 0) {
                    isSquare = 1;
                }
                
                if (isSquare == 1) {
                    printf("%d la so chinh phuong.\n", x);
                } else {
                    printf("%d khong phai la so chinh phuong.\n", x);
                }
                break;
            }
            
            case 4:
                printf("\nDang thoat chuong trinh...\n");
                break;
                
            default:
                printf("\nChon khong hop le! Vui long chon tu 1 den 4.\n");
                break;
        }
        
    } while (choice != 4);
    
    return 0;
}