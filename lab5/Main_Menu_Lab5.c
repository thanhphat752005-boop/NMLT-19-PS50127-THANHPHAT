#include <stdio.h>
#include <math.h>

// ==========================================
// KHAI BÁO NGUYÊN MẪU HÀM (FUNCTION PROTOTYPES)
// ==========================================
int findMax(int a, int b, int c);
int checkYear(int year);
void swap(int *a, int *b);
void checkTriangle(float a, float b, float c);

// ==========================================
// CHƯƠNG TRÌNH CHÍNH (MAIN FUNCTION)
// ==========================================
int main() {
    int choice;
    
    do {
        // Hien thi Menu
        printf("\n+---------------------------------------------------+\n");
        printf("|             MENU CHUONG TRINH LAB 5               |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Tim gia tri lon nhat trong 3 so                |\n");
        printf("| 2. Kiem tra Nam nhuan                             |\n");
        printf("| 3. Hoan vi 2 so (Su dung Con tro)                 |\n");
        printf("| 4. Kiem tra & Phan loai Tam giac                  |\n");
        printf("| 5. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int a, b, c;
                printf("\n--- CHUC NANG 1: TIM MAX ---\n");
                printf("Nhap vao 3 so nguyen (a b c): ");
                scanf("%d %d %d", &a, &b, &c);
                int max = findMax(a, b, c);
                printf("Gia tri lon nhat la: %d\n", max);
                break;
            }
            case 2: {
                int year;
                printf("\n--- CHUC NANG 2: KIEM TRA NAM NHUAN ---\n");
                printf("Nhap nam can kiem tra: ");
                scanf("%d", &year);
                if (checkYear(year) == 1) {
                    printf("Nam %d la Nam nhuan\n", year);
                } else {
                    printf("Nam %d la Nam khong nhuan\n", year);
                }
                break;
            }
            case 3: {
                int x, y;
                printf("\n--- CHUC NANG 3: HOAN VI ---\n");
                printf("Nhap gia tri a: ");
                scanf("%d", &x);
                printf("Nhap gia tri b: ");
                scanf("%d", &y);
                
                printf("=> Truoc khi hoan vi: a = %d, b = %d\n", x, y);
                swap(&x, &y); // Truyen dia chi cua 2 bien vao ham
                printf("=> Sau khi hoan vi: a = %d, b = %d\n", x, y);
                break;
            }
            case 4: {
                float a, b, c;
                printf("\n--- CHUC NANG 4: PHAN LOAI TAM GIAC ---\n");
                printf("Nhap chieu dai 3 canh (a b c): ");
                scanf("%f %f %f", &a, &b, &c);
                checkTriangle(a, b, c);
                break;
            }
            case 5:
                printf("\nDa thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon tu 1 den 5!\n");
        }
    } while (choice != 5);

    return 0;
}

// ==========================================
// CHI TIẾT CÁC HÀM CHỨC NĂNG
// ==========================================

// Chuc nang 1: Tim gia tri lon nhat trong 3 so nguyen
int findMax(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

// Chuc nang 2: Kiem tra nam nhuan
int checkYear(int year) {
    // Nam nhuan: Chia het cho 400 HOAC (chia het cho 4 nhung khong chia het cho 100)
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return 1; // True
    }
    return 0; // False
}

// Chuc nang 3: Hoan vi 2 so su dung con tro (Pass by Reference)
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Chuc nang 4: Kiem tra va phan loai tam giac
void checkTriangle(float a, float b, float c) {
    // Kiem tra dieu kien la tam giac
    if (a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a)) {
        
        // Dung bien tam thoi (Sai so) cho viec tinh toan kieu float
        // Co the dung toan tu == cho cac bai lab co ban, nhung voi tam giac vuong nen dung khoang dung sai (epsilon) de ket qua chinh xac nhat voi so thuc
        float epsilon = 0.0001; 
        
        int isEquilateral = (fabs(a - b) < epsilon && fabs(b - c) < epsilon);
        int isIsosceles = (fabs(a - b) < epsilon || fabs(a - c) < epsilon || fabs(b - c) < epsilon);
        int isRight = (fabs(a*a + b*b - c*c) < epsilon || 
                       fabs(a*a + c*c - b*b) < epsilon || 
                       fabs(b*b + c*c - a*a) < epsilon);

        // Phan loai
        if (isEquilateral) {
            printf("Day la tam giac deu.\n");
        } else if (isRight && isIsosceles) {
            printf("Day la tam giac vuong can.\n");
        } else if (isRight) {
            printf("Day la tam giac vuong.\n");
        } else if (isIsosceles) {
            printf("Day la tam giac can.\n");
        } else {
            printf("Day la tam giac thuong.\n");
        }
    } else {
        printf("Day khong phai la 3 canh cua mot tam giac.\n");
    }
}