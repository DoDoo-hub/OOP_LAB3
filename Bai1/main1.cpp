#include <iostream>
#include <cmath>
#include "cTamGiac.h"
using namespace std;

int main(){
    cTamGiac tg;
    cout<< "Nhap tam giac:\n";
    tg.Nhap();
    cout<< "\nTam giac: ";
    tg.Xuat();

    cout<< "\n\nLoai tam giac: ";
    int loai= tg.KTLoaiTamGiac();
    switch(loai){
    case 0:
        cout<< "Khong phai tam giac.\n";
        break;
    case 1:
        cout<< "Tam giac deu.\n";
        break;
    case 2:
        cout<< "Tam giac can.\n";
        break;
    case 3:
        cout<< "Tam giac vuong.\n";
        break;
    case 4:
        cout<< "Tam giac thuong.\n";
        break;
    }
    if(loai==0) return 0;//không phải tam giác, kết thúc chương trình

    cout<< "\nChu vi tam giac: "<<tg.TinhChuVi();
    cout<< "\n\nDien tich tam giac: "<<tg.TinhDienTich();

    double dx,dy;
    cout<< "\n\nNhap vector tinh tien: ";
    cout<< "\nNhap dx: "; cin>>dx;
    cout<< "Nhap dy: "; cin>>dy;
    cout<< "Tam giac sau khi tinh tien: ";
    tg.TinhTien(dx,dy);
    tg.Xuat();

    double degree;
    cout<< "\n\nNhap goc alpha(don vi do) de quay tam giac: ";
    cin>>degree;
    cout<< "Tam giac sau khi quay 1 goc alpha quanh goc toa do: ";
    tg.Quay(degree);
    tg.Xuat();

    double k;
    cout<< "\n\nThu phong tam giac voi he so ti le k (k>1: Phong to, 0<k<1: Thu nho, k=1: Giu nguyen)";
    do{
        cout<< "\nNhap he so ti le k (k>0): ";
        cin>>k;
        if(k<=0)
            cout<< "\nHe so phai lon hon 0. Hay nhap lai!\n";
    }while(k<=0);

    if(k>1){
        cout<<"Tam giac sau khi phong to: ";
        tg.PhongTo_ThuNho(k);
        tg.Xuat();
    }
    else if(0<k && k<1){
        cout<<"Tam giac sau khi thu nho: ";
        tg.PhongTo_ThuNho(k);
        tg.Xuat();
    }
    else {
        cout<<"k=1 nen tam giac giu nguyen: ";
        tg.Xuat();
    }

    return 0;
}

