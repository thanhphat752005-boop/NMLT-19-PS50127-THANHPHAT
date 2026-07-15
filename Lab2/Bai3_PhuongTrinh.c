#include <stdio.h>

int main() {
    float a, b, x;

    // Nhập hệ số a và b
    printf("Nhap he so a: ");
    scanf("%f", &a);
    
    printf("Nhap he so b: ");
    scanf("%f", &b);

    // Tính nghiệm x (do đề bài giả định a luôn khác 0 nên không cần xét điều kiện a = 0)
    x = -b / a;

    // Xuất kết quả
    printf("Nghiem cua phuong trinh la: x = %.2f\n", x);

    return 0;
}