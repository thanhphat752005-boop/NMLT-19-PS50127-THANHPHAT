#include <stdio.h>

// Định nghĩa hằng số PI theo yêu cầu
#define PI 3.14159

int main() {
    // Khai báo biến cho hình chữ nhật và hình tròn
    double chieu_dai, chieu_rong;
    double ban_kinh;

    printf("====================================\n");
    printf("     CHUONG TRINH TINH HINH HOC     \n");
    printf("====================================\n\n");

    // 1. XỬ LÝ HÌNH CHỮ NHẬT
    printf("--- 1. Hinh Chu Nhat ---\n");
    printf("Nhap chieu dai: ");
    if (scanf("%lf", &chieu_dai) != 1 || chieu_dai <= 0) {
        printf("Chieu dai khong hop le!\n");
        return 1;
    }
    
    printf("Nhap chieu rong: ");
    if (scanf("%lf", &chieu_rong) != 1 || chieu_rong <= 0) {
        printf("Chieu rong khong hop le!\n");
        return 1;
    }

    double chu_vi_hcn = 2 * (chieu_dai + chieu_rong);
    double dien_tich_hcn = chieu_dai * chieu_rong;

    printf("=> Chu vi HCN: %.2lf\n", chu_vi_hcn);
    printf("=> Dien tich HCN: %.2lf\n\n", dien_tich_hcn);


    // 2. XỬ LÝ HÌNH TRÒN
    printf("--- 2. Hinh Tron ---\n");
    printf("Nhap ban kinh: ");
    if (scanf("%lf", &ban_kinh) != 1 || ban_kinh <= 0) {
        printf("Ban kinh khong hop le!\n");
        return 1;
    }

    double chu_vi_tron = 2 * PI * ban_kinh;
    double dien_tich_tron = PI * ban_kinh * ban_kinh;

    printf("=> Chu vi Hinh Tron: %.5lf\n", chu_vi_tron);
    printf("=> Dien tich Hinh Tron: %.5lf\n", dien_tich_tron);
    printf("====================================\n");

    return 0;
}