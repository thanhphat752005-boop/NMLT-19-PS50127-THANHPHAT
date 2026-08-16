#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;

    do {
        // Hien thi Menu theo dung giao dien mau
        printf("+---------------------------------------------------+\n");
        printf("|             MENU CHUONG TRINH LAB 3               |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Chuc nang tinh hoc luc sinh vien               |\n");
        printf("| 2. Chuc nang giai phuong trinh bac hai            |\n");
        printf("| 3. Chuc nang tinh tien dien tieu thu hang thang   |\n");
        printf("| 4. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Chon chuc nang cua ban (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                float score;
                printf("\n--- CHUC NANG 1: TINH HOC LUC SINH VIEN ---\n");
                printf("Nhap diem so cua sinh vien (0.0 - 10.0): ");
                scanf("%f", &score);

                if (score < 0.0 || score > 10.0) {
                    printf("Diem so nhap vao khong hop le!\n");
                } else if (score >= 9.0) {
                    printf("Hoc luc Xuat sac.\n");
                } else if (score >= 8.0) {
                    printf("Hoc luc Gioi.\n");
                } else if (score >= 6.5) {
                    printf("Hoc luc Kha.\n");
                } else if (score >= 5.0) {
                    printf("Hoc luc Trung binh.\n");
                } else if (score >= 3.5) {
                    printf("Hoc luc Yeu.\n");
                } else {
                    printf("Hoc luc Kem.\n");
                }
                break;
            }
            
            case 2: {
                float a, b, c;
                printf("\n--- CHUC NANG 2: GIAI PHUONG TRINH BAC HAI ---\n");
                printf("Nhap vao 3 he so a, b, c: ");
                scanf("%f %f %f", &a, &b, &c);

                if (a == 0) {
                    if (b == 0) {
                        if (c == 0) {
                            printf("Phuong trinh co vo so nghiem.\n");
                        } else {
                            printf("Phuong trinh vo nghiem.\n");
                        }
                    } else {
                        printf("Phuong trinh co nghiem duy nhat x = %.2f\n", -c / b);
                    }
                } else {
                    float delta = (b * b) - (4 * a * c);
                    
                    if (delta < 0) {
                        printf("Phuong trinh vo nghiem.\n");
                    } else if (delta == 0) {
                        printf("Phuong trinh co nghiem kep x = %.2f\n", -b / (2 * a));
                    } else {
                        float x1 = (-b + sqrt(delta)) / (2 * a);
                        float x2 = (-b - sqrt(delta)) / (2 * a);
                        printf("Phuong trinh co 2 nghiem rieng biet:\n");
                        printf("x1 = %.2f\n", x1);
                        printf("x2 = %.2f\n", x2);
                    }
                }
                break;
            }
            
            case 3: {
                float kwh;
                float tongTien = 0.0;
                printf("\n--- CHUC NANG 3: TINH TIEN DIEN TIEU THU ---\n");
                printf("Nhap tong so kWh dien tieu thu trong thang: ");
                scanf("%f", &kwh);

                if (kwh < 0) {
                    printf("So kWh khong hop le! Vui long nhap so duong.\n");
                } else {
                    if (kwh <= 50) {
                        tongTien = kwh * 1678;
                    } 
                    else if (kwh <= 100) {
                        tongTien = (50 * 1678) + ((kwh - 50) * 1734);
                    } 
                    else if (kwh <= 200) {
                        tongTien = (50 * 1678) + (50 * 1734) + ((kwh - 100) * 2014);
                    } 
                    else if (kwh <= 300) {
                        tongTien = (50 * 1678) + (50 * 1734) + (100 * 2014) + ((kwh - 200) * 2536);
                    } 
                    else if (kwh <= 400) {
                        tongTien = (50 * 1678) + (50 * 1734) + (100 * 2014) + (100 * 2536) + ((kwh - 300) * 2834);
                    } 
                    else {
                        tongTien = (50 * 1678) + (50 * 1734) + (100 * 2014) + (100 * 2536) + (100 * 2834) + ((kwh - 400) * 2927);
                    }
                    
                    printf("Tong so tien dien can thanh toan la: %.0f VND\n", tongTien);
                }
                break;
            }

            case 4:
                printf("\nDa thoat chuong trinh.\n");
                break;
                
            default:
                printf("\nLua chon khong hop le. Vui long chon lai tu 1 den 4!\n");
                break;
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}