#include <iostream>
#include <vector>
#include <algorithm>
#include "cDSNhanVien.h"
using namespace std;


cDSNhanVien::cDSNhanVien():N(0){ds.clear();}

cDSNhanVien::cDSNhanVien(int n):N(n){}

cDSNhanVien::~cDSNhanVien(){}

void cDSNhanVien::NhapDS(){
    ds.resize(N);
    for(int i=0;i<N;i++){
        cout<<"\nNhap du lieu cua nhan vien san xuat thu "<<i+1<<": \n";
        ds[i].Nhap();
    }
}

void cDSNhanVien::XuatDS(){
    cout<<"STT\t|"<<"ID\t\t|"<<"Ho ten\t\t|";
    cout<<"Ngay sinh\t|"<<"So SP\t|"<<"Don gia\t"<<endl;

    for(int i=0;i<N;i++){
        cout<<i+1<<".\t|";
        ds[i].Xuat();
        cout<<endl;
    }
}

//Tìm NV đầu tiên có lương thấp nhất
cNhanVienSX cDSNhanVien::TimLuongThapNhat(){
    cNhanVienSX minNV=ds[0];
    for(int i=0;i<N;i++){
        if(ds[i].TinhLuong()<minNV.TinhLuong())
            minNV=ds[i];
    }
    return minNV;
}

long long cDSNhanVien::TinhTongLuong(){
    long long kq=0;
    for(int i=0;i<N;i++)
        kq+= ds[i].TinhLuong();
    return kq;
}

//Hàm phụ để xác định A có già hơn B?
bool GiaHon(const sDate &A, const sDate &B){
    if(A.nam!=B.nam) return A.nam<B.nam;
    if(A.thang!=B.thang) return A.thang<B.thang;
    if(A.ngay!=B.ngay) return A.ngay<B.ngay;
    return false;//Nếu ngày sinh bằng nhau thì A không già hơn B
}
//Tìm NV đầu tiên có tuổi cao nhất(tính cả ngày, tháng, năm)
cNhanVienSX cDSNhanVien::TimTuoiCaoNhat(){
    cNhanVienSX maxTuoi= ds[0];

    for(int i=1;i<N;i++){
        // Gọi hàm phụ để so sánh
        if( GiaHon(ds[i].getNgaySinh(),maxTuoi.getNgaySinh()) )
            maxTuoi=ds[i];
    }
    return maxTuoi;
}


// Hàm phụ định nghĩa quy tắc so sánh
bool soSanhLuong(cNhanVienSX A, cNhanVienSX B){
    return A.TinhLuong() < B.TinhLuong();
}
//Sắp xếp ds nhân viên sx tăng dần theo lương
void cDSNhanVien::SapXepTheoLuong(){
    //Dùng hàm sort với quy tắc so sánh đã định nghĩa
    sort(ds.begin(),ds.end(),soSanhLuong);
}




