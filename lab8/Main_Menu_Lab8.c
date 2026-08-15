#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ===================== KHAI BÁO CẤU TRÚC =====================
struct SinhVien {
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};

// ================== NGUYÊN MẪU HÀM (PROTOTYPES) ==================
void nhapXuatSinhVien(struct SinhVien mangSV[], int *n);
void sapXepSinhVien(struct SinhVien mangSV[], int n);
void timKiemSinhVien(struct SinhVien mangSV[], int n);
void xuatHocBong(struct SinhVien mangSV[], int n);

// ======================= CHƯƠNG TRÌNH CHÍNH =======================
int main() {
    struct SinhVien mangSV[100];
    int n = 0;
    int choice;

    do {
        printf("\n+---------------------------------------------------+\n");
        printf("|         HE THONG QUAN LY SINH VIEN (LAB 8)        |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Nhap va Xuat danh sach sinh vien               |\n");
        printf("| 2. Sap xep sinh vien theo diem TB tang dan        |\n");
        printf("| 3. Tim kiem sinh vien theo Ma so sinh vien (MSSV) |\n");
        printf("| 4. Xuat danh sach sinh vien dat Hoc bong (>= 8.0) |\n");
        printf("| 5. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &choice);
        
        // Xóa bộ nhớ đệm sau khi nhập số để không bị trôi lệnh nhập chuỗi
        while (getchar() != '\n');

        switch(choice) {
            case 1:
                nhapXuatSinhVien(mangSV, &n);
                break;
            case 2:
                sapXepSinhVien(mangSV, n);
                break;
            case 3:
                timKiemSinhVien(mangSV, n);
                break;
            case 4:
                xuatHocBong(mangSV, n);
                break;
            case 5:
                printf("\nThoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon lai!\n");
        }
    } while(choice != 5);

    return 0;
}

// ======================== CHI TIẾT CÁC HÀM ========================

// Chức năng 1: Nhập và Xuất danh sách sinh viên
void nhapXuatSinhVien(struct SinhVien mangSV[], int *n) {
    printf("\nNhap so luong sinh vien: ");
    scanf("%d", n);
    while (getchar() != '\n');

    // Nhập thông tin
    for (int i = 0; i < *n; i++) {
        printf("\n--- Nhap thong tin sinh vien thu %d ---\n", i + 1);
        
        printf("MSSV: ");
        fgets(mangSV[i].mssv, sizeof(mangSV[i].mssv), stdin);
        mangSV[i].mssv[strcspn(mangSV[i].mssv, "\n")] = 0; // Xóa ký tự xuống dòng

        printf("Ho va ten: ");
        fgets(mangSV[i].tenSV, sizeof(mangSV[i].tenSV), stdin);
        mangSV[i].tenSV[strcspn(mangSV[i].tenSV, "\n")] = 0;

        printf("Nganh hoc: ");
        fgets(mangSV[i].nganhHoc, sizeof(mangSV[i].nganhHoc), stdin);
        mangSV[i].nganhHoc[strcspn(mangSV[i].nganhHoc, "\n")] = 0;

        printf("Diem trung binh: ");
        scanf("%f", &mangSV[i].diemTB);
        while (getchar() != '\n'); 
    }

    // Xuất thông tin dưới dạng bảng
    printf("\n============================ DANH SACH SINH VIEN ============================\n");
    printf("%-15s | %-25s | %-20s | %-10s\n", "MSSV", "Ho va Ten", "Nganh Hoc", "Diem TB");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < *n; i++) {
        printf("%-15s | %-25s | %-20s | %-10.2f\n", 
            mangSV[i].mssv, mangSV[i].tenSV, mangSV[i].nganhHoc, mangSV[i].diemTB);
    }
}

// Chức năng 2: Sắp xếp sinh viên theo Điểm trung bình tăng dần
void sapXepSinhVien(struct SinhVien mangSV[], int n) {
    if (n == 0) {
        printf("\nDanh sach hien dang trong!\n");
        return;
    }

    struct SinhVien temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mangSV[i].diemTB > mangSV[j].diemTB) {
                // Hoán đổi 2 struct
                temp = mangSV[i];
                mangSV[i] = mangSV[j];
                mangSV[j] = temp;
            }
        }
    }

    printf("\n================ DANH SACH SINH VIEN SAU KHI SAP XEP TANG DAN ================\n");
    printf("%-15s | %-25s | %-20s | %-10s\n", "MSSV", "Ho va Ten", "Nganh Hoc", "Diem TB");
    printf("------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-15s | %-25s | %-20s | %-10.2f\n", 
            mangSV[i].mssv, mangSV[i].tenSV, mangSV[i].nganhHoc, mangSV[i].diemTB);
    }
}

// Chức năng 3: Tìm kiếm sinh viên theo MSSV
void timKiemSinhVien(struct SinhVien mangSV[], int n) {
    if (n == 0) {
        printf("\nDanh sach hien dang trong!\n");
        return;
    }

    char mssvTim[50];
    printf("\nNhap MSSV can tim: ");
    fgets(mssvTim, sizeof(mssvTim), stdin);
    mssvTim[strcspn(mssvTim, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(mangSV[i].mssv, mssvTim) == 0) {
            if (found == 0) {
                printf("\n========================= THONG TIN SINH VIEN TIM THAY =========================\n");
                printf("%-15s | %-25s | %-20s | %-10s\n", "MSSV", "Ho va Ten", "Nganh Hoc", "Diem TB");
                printf("--------------------------------------------------------------------------------\n");
            }
            printf("%-15s | %-25s | %-20s | %-10.2f\n", 
                mangSV[i].mssv, mangSV[i].tenSV, mangSV[i].nganhHoc, mangSV[i].diemTB);
            found = 1;
        }
    }

    if (found == 0) {
        printf("\nKhong tim thay sinh vien co MSSV nay!\n");
    }
}

// Chức năng 4: Xuất danh sách sinh viên đạt Học bổng
void xuatHocBong(struct SinhVien mangSV[], int n) {
    if (n == 0) {
        printf("\nDanh sach hien dang trong!\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (mangSV[i].diemTB >= 8.0) {
            if (found == 0) {
                printf("\n=================== DANH SACH SINH VIEN DAT HOC BONG (>= 8.0) ===================\n");
                printf("%-15s | %-25s | %-20s | %-10s\n", "MSSV", "Ho va Ten", "Nganh Hoc", "Diem TB");
                printf("---------------------------------------------------------------------------------\n");
            }
            printf("%-15s | %-25s | %-20s | %-10.2f\n", 
                mangSV[i].mssv, mangSV[i].tenSV, mangSV[i].nganhHoc, mangSV[i].diemTB);
            found = 1;
        }
    }

    if (found == 0) {
        printf("\nKhong co sinh vien nao dat hoc bong (Diem TB >= 8.0)!\n");
    }
}