#include <stdio.h>
#include <string.h>

int main() {
    // Khai báo các biến
    char mssv[20];
    char hoTen[50];
    float diemToan, diemLy, diemHoa;
    float diemTB;

    // --- BƯỚC 1: NHẬP DỮ LIỆU ---
    printf("Nhap ma so sinh vien: ");
    scanf("%19s", mssv);
    
    // Xóa bộ nhớ đệm đầu vào
    while (getchar() != '\n'); 

    printf("Nhap ho va ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    hoTen[strcspn(hoTen, "\n")] = '\0'; // Xóa ký tự xuống dòng

    printf("Nhap diem Toan: ");
    scanf("%f", &diemToan);

    printf("Nhap diem Ly: ");
    scanf("%f", &diemLy);

    printf("Nhap diem Hoa: ");
    scanf("%f", &diemHoa);

    // --- BƯỚC 2: TÍNH TOÁN THEO CÔNG THỨC HỆ SỐ ---
    // Điểm Toán nhân hệ số 2, tổng hệ số là 4
    diemTB = (diemToan * 2 + diemLy + diemHoa) / 4;

    // --- BƯỚC 3: XUẤT DỮ LIỆU (Đúng định dạng mẫu) ---
    printf("\n-------------------------------\n");
    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n", hoTen);
    // %.2f để làm tròn đến 2 chữ số thập phân theo mẫu thông dụng
    printf("Diem Trung Binh: %.2f\n", diemTB); 

    return 0;
}