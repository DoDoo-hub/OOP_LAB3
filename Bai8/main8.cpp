#include <iostream>
#include <vector>
#include "cDSNhanVien.h"
using namespace std;


int main(){

    //Nhập danh sách n nhân viên sản xuất
    int n;
    cout<<"Nhap so luong nhan vien san xuat: ";
    cin>>n;
    cDSNhanVien DS(n);

    cout<<"\nNhap danh sach nhan vien san xuat:\n";
    DS.NhapDS();


    //Xuất danh sách nhân viên dưới dạng danh sách
    cout<<"\nDanh sach nhan vien san xuat:\n";
    DS.XuatDS();

    // Tìm và xuất người đầu tiên lương thấp nhất
    cNhanVienSX nvMin= DS.TimLuongThapNhat();
    cout<<"\nNhan vien co luong thap nhat:\n";
    nvMin.Xuat();
    cout<<" | Luong: "<<nvMin.TinhLuong()<<" VND";

    //Tính tổng lương mà công ty phải trả
    long long tongLuong= DS.TinhTongLuong();
    cout<<"\n\nTong luong ma cong ty phai tra: ";
    cout<<tongLuong<<" VND";

    //Tìm và xuất người đầu tiên có tuổi cao nhất
    cNhanVienSX maxTuoi= DS.TimTuoiCaoNhat();
    cout<<"\n\nNhan vien co tuoi cao nhat:\n";
    maxTuoi.Xuat();

    //Sắp xếp danh sách nhân viên theo lương tăng dần
    DS.SapXepTheoLuong();
    cout<<"\n\nDanh sach nhan vien duoc sap xep tang dan theo luong:\n";
    DS.XuatDS();


    return 0;
}
