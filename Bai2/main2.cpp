#include <iostream>
#include <cmath>
#include <vector>
#include "cDaGiac.h"
using namespace std;

int main(){
    cDaGiac dg;

    cout<< "Nhap da giac:\n";
    dg.Nhap();
    cout<< "\nDa giac: ";
    dg.Xuat();

    cout<<"\n\nChu vi: "<<dg.TinhChuVi();
    cout<<"\n\nDien tich: "<<dg.TinhDienTich()<<endl;

    double dx,dy;
    cout<< "\nNhap vector tinh tien: ";
    cout<< "\nNhap dx: "; cin>>dx;
    cout<< "Nhap dy: "; cin>>dy;
    cout<< "Da giac sau khi tinh tien: ";
    dg.TinhTien(dx,dy);
    dg.Xuat();

    double degree;
    cout<< "\n\nNhap goc alpha(don vi do) de quay da giac: ";
    cin>>degree;
    cout<< "Da giac sau khi quay 1 goc alpha quanh goc toa do: ";
    dg.Quay(degree);
    dg.Xuat();

    double k;
    cout<< "\n\nThu phong da giac voi he so ti le k (k>1: Phong to, 0<k<1: Thu nho, k=1: Giu nguyen)";
    do{
        cout<< "\nNhap he so ti le k (k>0): ";
        cin>>k;
        if(k<=0)
            cout<< "He so phai lon hon 0. Hay nhap lai!\n";
    }while(k<=0);

    if(k>1){
        cout<<"Da giac sau khi phong to: ";
        dg.PhongTo_ThuNho(k);
        dg.Xuat();
    }
    else if(0<k && k<1){
        cout<<"Da giac sau khi thu nho: ";
        dg.PhongTo_ThuNho(k);
        dg.Xuat();
    }
    else {
        cout<<"k=1 nen da giac giu nguyen: ";
        dg.Xuat();
    }

    return 0;
}

