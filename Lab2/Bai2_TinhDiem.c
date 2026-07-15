#include <stdio.h>

int main() {
    // Khai báo biến kiểu float để nhập được cả điểm số thập phân (ví dụ: 7.5, 8.2)
    float toan, ly, hoa;
    float diemTB;

    // Nhập dữ liệu từ bàn phím
    printf("Nhap diem mon Toan: ");
    scanf("%f", &toan);

    printf("Nhap diem mon Ly: ");
    scanf("%f", &ly);

    printf("Nhap diem mon Hoa: ");
    scanf("%f", &hoa);

    // Áp dụng kỹ thuật ép kiểu (float) để đảm bảo phép chia ra kết quả số thập phân chính xác
    diemTB = (float)(toan * 3 + ly * 2 + hoa) / 6;

    // Hiển thị kết quả làm tròn 2 chữ số sau dấu phẩy bằng định dạng %.2f
    printf("\n--- Ket qua ---\n");
    printf("Diem trung binh cua ban la: %.2f\n", diemTB);

    return 0;
}