#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;

uint8_t THOAT = 1; 

class SinhVien
{
public:
    SinhVien();
    uint8_t ID;
    char TEN[20];
    char GIOI_TINH[4];
    uint8_t TUOI;
    double DIEM_TOAN;
    double DIEM_LY;
    double DIEM_HOA;
    double DIEM_TRUNG_BINH;
    char HOC_LUC[11];
};

SinhVien::SinhVien()
{
    static uint8_t id = 100; // 0x01 = 100
    SinhVien::ID = id;
    id++;
}

class Menu
{
public:
    Menu();
    vector<SinhVien> Database;
    void ThemSinhVien();
    void CapNhatThongTin();
    void XoaSinhVien();
    void TimKiemSinhVien();
    void HienThiDanhSach();
    void HienThi_1SV(uint8_t i);
    void Check_Diem();
    void SapXepTheoGPA();
};

void Menu::Check_Diem()
{

    int diem;
    do
    {
        scanf("%lf", &diem);
    } while (diem >= 0 && diem <= 10);
}

void Menu::ThemSinhVien()
{
    SinhVien sv;
    printf("THEM SINH VIEN\n");
    printf("Nhap Ten: ");
    scanf("%s", sv.TEN);
    printf("Gioi Tinh(Nam/Nu): ");
    scanf("%s", sv.GIOI_TINH);

    //-----------------------

    printf("Nhap Diem Toan: ");
    scanf("%lf", &sv.DIEM_TOAN);
    printf("Nhap Diem Ly: ");
    scanf("%lf", &sv.DIEM_LY);
    printf("Nhap Diem Hoa: ");
    scanf("%lf", &sv.DIEM_HOA);

    //------------------------
    // Tinh Diem Trung Binh

    sv.DIEM_TRUNG_BINH = (sv.DIEM_TOAN + sv.DIEM_HOA + sv.DIEM_LY) / 3;

    // Tinh Hoc Luc

    if (sv.DIEM_TRUNG_BINH >= 8)
    {
        strcpy(sv.HOC_LUC, "GIOI");
    }
    else if (sv.DIEM_TRUNG_BINH >= 6.5)
    {
        strcpy(sv.HOC_LUC, "KHA");
    }
    else if (sv.DIEM_TRUNG_BINH >= 5)
    {
        strcpy(sv.HOC_LUC, "TRUNG BINH");
    }
    else
    {
        strcpy(sv.HOC_LUC, "YEU");
    }

    Database.push_back(sv);
}



void Menu::HienThi_1SV(uint8_t i)
{

    printf("Sinh Vien %d:\n", i + 1);
    printf("Ten Sinh Vien: %s\n", Database[i].TEN);
    printf("Gioi Tinh: %s\n", Database[i].GIOI_TINH);

    printf("Diem Toan: %f\n", Database[i].DIEM_TOAN);
    printf("Diem Ly: %f\n", Database[i].DIEM_LY);
    printf("Diem Hoa: %f\n", Database[i].DIEM_HOA);
    printf("Diem Trung Binh: %f\n", Database[i].DIEM_TRUNG_BINH);

    printf("Hoc Luc: %s\n", Database[i].HOC_LUC);
}



void Menu::HienThiDanhSach()
{

    system("cls");
    printf("HIEN THI THONG TIN SINH VIEN\n");
    if (Database.empty() == true)
    {
        printf("ERROR!!!danh sach rong\n");
    }


    for (uint8_t i = 0; i < Database.size(); i++)
    {

        HienThi_1SV(i);
    }
    
}



void Menu::CapNhatThongTin()
{

    system("cls");

    printf("NHAP ID SINH VIEN CAN CAP NHAT\n");
    int id_capnhat = 0;
    scanf("%d", &id_capnhat);

    for (uint8_t i = 0; i < Database.size(); i++)
    {
        if (Database[i].ID == id_capnhat)
        {

            HienThi_1SV(i);
            printf("Moi ban nhap thong tin can thay doi\n");
            printf("Nhan 1: Cap Nhat Ten\n");
            printf("Nhan 2: Cap Nhat Gioi Tinh\n");
            printf("Nhan 3: Cap Nhat Diem Toan\n");
            printf("Nhan 4: Cap Nhat Diem Ly\n");
            printf("Nhan 5: Cap Nhat Hoa\n");
            printf("Nhan 6: Cap Nhat Tat Ca\n");
            printf("Nhan 7: Thoat\n");

            int key;
            scanf("%d", &key);
            switch (key)
            {

            case 1:
                printf("Ten cap nhat\n");
                scanf("%s", &Database[i].TEN);
                break;

            case 2:
                printf("Gioi tính cap nhat\n");
                scanf("%s", &Database[i].GIOI_TINH);
                break;

            case 3:
                printf("Diem toan cap nhat\n");
                scanf("%f", &Database[i].DIEM_TOAN);
                break;

            case 4:
                printf("Diem ly cap nhat\n");
                scanf("%f", &Database[i].DIEM_LY);
                break;
            case 5:
                printf("Diem hoa cap nhat\n");
                scanf("%f", &Database[i].DIEM_HOA);
                break;
            case 6:

                printf("Ten cap nhat\n");
                scanf("%s", &Database[i].TEN);
                printf("Gioi tính cap nhat\n");
                scanf("%s", &Database[i].GIOI_TINH);

                printf("Diem toan cap nhat\n");
                scanf("%f", &Database[i].DIEM_TOAN);
                printf("Diem ly cap nhat\n");
                scanf("%f", &Database[i].DIEM_LY);
                printf("Diem hoa cap nhat\n");
                scanf("%f", &Database[i].DIEM_HOA);
                break;

            case 7:
                break;
            default:
                printf("ERROR!!! Nhap sai, hay nhap lai");
                break;
            }
        }
        else
            printf("ERROR!!! ID KHONG KHOP\n");
    }
}



void Menu::XoaSinhVien()
{
    system("cls");
    printf("NHAP ID SINH VIEN CAN XOA\n");
    int id_xoa = 0;
    scanf("%d", &id_xoa);

    for (uint8_t i = 0; i < Database.size(); i++)
    {
        if (Database[i].ID == id_xoa)
        {
            Database.erase(Database.begin() + i);
        }
    }
}

void Menu::TimKiemSinhVien(){

    system("cls");
    printf("NHAP TEN SINH VIEN CAN TIM\n\n");
    char ten_cantim[20];
    scanf("%c", &ten_cantim);

    for (uint8_t i = 0; i < Database.size(); i++){
        if(Database[i].TEN == ten_cantim){
            HienThi_1SV(i);
        }else printf("ERROR!!! ten nhap khong chinh xac\n");
    }

}

void Menu::SapXepTheoGPA(){

    system("cls");
    for(uint8_t i = 0; i < Database.size() - 1 ; i++){
        for(uint8_t j = i + 1; j < Database.size(); j++){
            if(Database[i].DIEM_TRUNG_BINH < Database[j].DIEM_TRUNG_BINH){
                
                SinhVien temp;
                temp = Database[i];
                Database[i] = Database[j];
                Database[j] = temp;

                
            }
        }

    
    }

    HienThiDanhSach();

}



Menu::Menu()
{
    int THOAT = 1;
    while(THOAT){

        int phim;
        printf("Nhap chuong trinh ban muon\n");
        printf("Nhan 1: Them Sinh Vien\n");
        printf("Nhan 2: Cap Nhat Sinh Vien Boi ID\n");
        printf("Nhan 3: Xoa Sinh Vien Boi ID\n");
        printf("Nhan 4: Tim Kiem Sinh Vien Theo Ten\n");
        printf("Nhan 5: Sap Xep Sinh Vien Theo DTB_GPA\n");
        printf("Nhan 6: Sap Xep Sinh Vien Theo Ten\n");
        printf("Nhan 7: Hien Thi Danh Sach\n");
        printf("Nhan 8: De thoat chuong trinh\n");
        
        scanf("%d", &phim);
        int check = 1;

        switch (phim)
        {
        case 1:
                        
            ThemSinhVien();

            while (check)
            {           
                                         
                printf("Nhan 1: De tiep tuc \n");
                printf("Nhan 2: Quay lai Menu\n");
                scanf("%d", &phim);
                
                switch (phim)
                {
                case 1:
                    ThemSinhVien();
                    break;
                case 2:
                    check = 0;
                    break;

                default:
                    printf("ERROR!!! nhap sai, hay nhap lai\n\n");
                    break;
                }
            }
            check = 1;           
            break;

         
        case 2:
            CapNhatThongTin();
            printf("Nhan 1 Quay lai Menu\n");
            scanf("%d", &phim);
            break;

        case 3:
            XoaSinhVien();
            printf("Nhan 1 Quay lai Menu\n");
            scanf("%d", &phim);
            break;

        case 4:
            TimKiemSinhVien();
            printf("Nhan 1 Quay lai Menu\n");
            scanf("%d", &phim);
            break;

        case 5:
            SapXepTheoGPA();
            printf("Nhan 1 Quay lai Menu\n");
            scanf("%d", &phim);
            break;

        case 7:
            HienThiDanhSach();
            printf("Nhan 1 Quay lai Menu\n");
            scanf("%d", &phim);
            break;

        case 8:
            THOAT = 0;
            break;

            
        default:
            printf("----------ERROR!!! Nhap sai, vui long nhap lai--------------\n");
            break;
    }
    
}

    printf("END");

}

    

int main(int argc, char const *argv[]){

    
    Menu mn;

    return 0;
}
