#include <iostream>
#include <cmath>
#include "cTamGiac.h"
using namespace std;


cTamGiac::cTamGiac(){}

cTamGiac::~cTamGiac(){}

void cTamGiac::Nhap(){
    cout<< "\nNhap toa do diem A:\n";
    A.Nhap();
    cout<< "Nhap toa do diem B:\n";
    B.Nhap();
    cout<< "Nhap toa do diem C:\n";
    C.Nhap();
}

void cTamGiac::Xuat(){
    cout<<"A"; A.Xuat();
    cout<<", B"; B.Xuat();
    cout<<", C"; C.Xuat();
}

int cTamGiac::KTLoaiTamGiac(){ // 0: không phải tam giác, 1: đều, 2: cân, 3: vuông, 4: thường
    double AB= A.TinhKhoangCach(B);
    double BC= B.TinhKhoangCach(C);
    double AC= A.TinhKhoangCach(C);
    double eps= 1e-6; //epsilon: Độ sai số cho phép

    // 0: Kiểm tra hợp lệ
    if(AB+BC <= AC+eps || AB+AC <= BC+eps || BC+AC <= AB+eps )
        return 0;

    // 1: Đều
    if(fabs(AB-BC) < eps && fabs(BC-AC) < eps) // AB=BC && BC=AC => AB=BC=AC
        return 1;

    // 2: Cân
    if(fabs(AB-BC) < eps || fabs(BC-AC) < eps || fabs(AB-AC) < eps)
        return 2;

    // 3: Vuông
    double huyen= max(AB,max(BC,AC));
    if( fabs((AB*AB + BC*BC + AC*AC) - huyen*huyen*2) < eps)//Pitago
        return 3;

    // 4: Thường
    return 4;
}

double cTamGiac::TinhChuVi(){
    double AB= A.TinhKhoangCach(B);
    double BC= B.TinhKhoangCach(C);
    double AC= A.TinhKhoangCach(C);

    return AB+BC+AC;
}


double cTamGiac::TinhDienTich(){
    // Sabc=1/2 * |AB*AC| : diện tích tam giác abc=1/2 độ lớn tích có hướng 2 vector AB AC
    double xA= A.getX(), yA= A.getY();
    double xB= B.getX(), yB= B.getY();
    double xC= C.getX(), yC= C.getY();

    double s= 0.5 * fabs(xA * (yB - yC) + xB * (yC - yA) + xC * (yA - yB));
    return s;
}

void cTamGiac::TinhTien(double dx, double dy){ //(dx,dy) là vector tịnh tiến
    A.TinhTienDiem(dx,dy);
    B.TinhTienDiem(dx,dy);
    C.TinhTienDiem(dx,dy);
}

void cTamGiac::Quay(double degree){  // quay 1 góc alpha (đơn vị là độ)
    A.Quay(degree);
    B.Quay(degree);
    C.Quay(degree);
}
void cTamGiac::PhongTo_ThuNho(double k){ // Phóng to(hoặc thu nhỏ) k lần
    //phóng to tại chỗ sao cho trọng tâm không đổi,
    // thực hiện phép vị tự với tâm vị tự chính là trọng tâm của tam giác.

    // 1.Tính trọng tâm tam giác:
    double xG= (A.getX()+B.getX()+C.getX())/3.0;
    double yG= (A.getY()+B.getY()+C.getY())/3.0;

    //2.Phóng to từng điểm so với trọng tâm
    A.SetToaDo(xG + (A.getX()-xG)*k, yG + (A.getY()-yG)*k);
    B.SetToaDo(xG + (B.getX()-xG)*k, yG + (B.getY()-yG)*k);
    C.SetToaDo(xG + (C.getX()-xG)*k, yG + (C.getY()-yG)*k);
}



