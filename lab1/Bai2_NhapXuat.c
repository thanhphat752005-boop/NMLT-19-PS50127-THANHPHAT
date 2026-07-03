#include <stdio.h>
#include <string.h>

int main() {
    // Khai báo các biến lưu trữ thông tin sinh viên
    char mssv[20];
    char hoTen[50];
    int namSinh;
    int tuoi;
    float diemTB;

    // --- BƯỚC 1: NHẬP DỮ LIỆU ---
    printf("Nhap ma so sinh vien: ");
    scanf("%19s", mssv);
    
    // Xóa bộ nhớ đệm để tránh bị trôi lệnh fgets khi nhập chuỗi có khoảng trắng
    while (getchar() != '\n'); 

    printf("Nhap ho va ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    // Xóa ký tự xuống dòng '\n' do fgets tự động thêm vào cuối chuỗi
    hoTen[strcspn(hoTen, "\n")] = '\0';

    printf("Nhap nam sinh: ");
    scanf("%d", &namSinh);

    printf("Nhap diem trung binh: ");
    scanf("%f", &diemTB);

    // --- BƯỚC 2: TÍNH TOÁN ---
    // Tính tuổi dựa trên năm hiện tại là 2026
    tuoi = 2026 - namSinh;

    // --- BƯỚC 3: XUẤT DỮ LIỆU (Đúng định dạng mẫu) ---
    printf("\n-------------------------------\n");
    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n", hoTen);
    printf("Nam sinh: %d\n", namSinh);
    printf("Tuoi: %d\n", tuoi);
    // %.2f để định dạng hiển thị 2 chữ số thập phân sau dấu phẩy (ví dụ: 8.50)
    printf("Diem Trung Binh: %.2f\n", diemTB); 

    return 0;
}