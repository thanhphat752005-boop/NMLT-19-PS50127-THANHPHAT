#include <stdio.h>

// ==========================================
// KHAI BÁO CÁC NGUYÊN MẪU HÀM (PROTOTYPES)
// ==========================================
void tinhTrungBinhCong(int a[], int n);
void timMaxMin(int a[], int n);
void sapXepGiamDan(int a[], int n);
void maTranBinhPhuong(int row, int col);
void xuatSoLeMaTran(int row, int col);

// ==========================================
// HÀM MAIN - ĐIỀU KHIỂN MENU
// ==========================================
int main() {
    int choice;
    int n, row, col;

    do {
        // Hien thi Menu
        printf("\n+---------------------------------------------------+\n");
        printf("|             MENU CHUONG TRINH LAB 6               |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Tinh trung binh tong so chia het cho 3 va 5    |\n");
        printf("| 2. Tim gia tri Lon nhat va Nho nhat trong Mang    |\n");
        printf("| 3. Sap xep Mang theo thu tu Giam dan              |\n");
        printf("| 4. Ma tran binh phuong (Mang 2 chieu)             |\n");
        printf("| 5. Loc va xuat vi tri cac So le trong Ma tran     |\n");
        printf("| 6. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("\n--- CHUC NANG 1 ---\n");
                printf("Nhap so luong phan tu mang: "); 
                scanf("%d", &n);
                int a1[n];
                for(int i = 0; i < n; i++) {
                    printf("a[%d] = ", i);
                    scanf("%d", &a1[i]);
                }
                tinhTrungBinhCong(a1, n);
                break;
            }
            case 2: {
                printf("\n--- CHUC NANG 2 ---\n");
                printf("Nhap so luong phan tu mang: "); 
                scanf("%d", &n);
                int a2[n];
                for(int i = 0; i < n; i++) {
                    printf("a[%d] = ", i);
                    scanf("%d", &a2[i]);
                }
                timMaxMin(a2, n);
                break;
            }
            case 3: {
                printf("\n--- CHUC NANG 3 ---\n");
                printf("Nhap so luong phan tu mang: "); 
                scanf("%d", &n);
                int a3[n];
                for(int i = 0; i < n; i++) {
                    printf("a[%d] = ", i);
                    scanf("%d", &a3[i]);
                }
                sapXepGiamDan(a3, n);
                break;
            }
            case 4: {
                printf("\n--- CHUC NANG 4 ---\n");
                printf("Nhap so hang cua ma tran: "); scanf("%d", &row);
                printf("Nhap so cot cua ma tran: "); scanf("%d", &col);
                maTranBinhPhuong(row, col);
                break;
            }
            case 5: {
                printf("\n--- CHUC NANG 5 ---\n");
                printf("Nhap so hang cua ma tran: "); scanf("%d", &row);
                printf("Nhap so cot cua ma tran: "); scanf("%d", &col);
                xuatSoLeMaTran(row, col);
                break;
            }
            case 6:
                printf("\nThoat chuong trinh. Chuc ban code vui ve!\n");
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon lai tu 1 den 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// ==========================================
// ĐỊNH NGHĨA CÁC HÀM XỬ LÝ
// ==========================================

// Chuc nang 1: Tinh trung binh tong cac so chia het cho 3 va 5
void tinhTrungBinhCong(int a[], int n) {
    int tong = 0;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] % 3 == 0 && a[i] % 5 == 0) {
            tong += a[i];
            count++;
        }
    }
    
    if (count == 0) {
        printf("-> Khong tim thay so nao chia het cho ca 3 va 5 trong mang.\n");
    } else {
        float trungBinh = (float)tong / count;
        printf("-> Trung binh cong cac so chia het cho 3 va 5 la: %.2f\n", trungBinh);
    }
}

// Chuc nang 2: Tim Max va Min
void timMaxMin(int a[], int n) {
    if (n <= 0) return;
    
    int max = a[0];
    int min = a[0];
    
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }
    
    printf("-> Gia tri Lon nhat (Max): %d\n", max);
    printf("-> Gia tri Nho nhat (Min): %d\n", min);
}

// Chuc nang 3: Sap xep mang giam dan
void sapXepGiamDan(int a[], int n) {
    // Thuat toan Interchange Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    printf("-> Mang sau khi sap xep giam dan:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
}

// Chuc nang 4: Ma tran binh phuong (Mang 2 chieu)
void maTranBinhPhuong(int row, int col) {
    int a[row][col];
    
    printf("Nhap cac phan tu cho ma tran (%dx%d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("-> Ma tran binh phuong (tung phan tu):\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", a[i][j] * a[i][j]);
        }
        printf("\n"); // Xuong dong khi het 1 hang
    }
}

// Chuc nang 5: Loc va xuat vi tri cac so le trong ma tran
void xuatSoLeMaTran(int row, int col) {
    int a[row][col];
    
    printf("Nhap cac phan tu cho ma tran (%dx%d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("-> Cac so le trong ma tran va vi tri:\n");
    int found = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (a[i][j] % 2 != 0) {
                printf("Phan tu le tai a[%d][%d] = %d\n", i, j, a[i][j]);
                found = 1;
            }
        }
    }
    
    if (found == 0) {
        printf("Khong co so le nao trong ma tran.\n");
    }
}