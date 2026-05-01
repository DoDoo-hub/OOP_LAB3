#ifndef CTAMGIAC_H
#define CTAMGIAC_H

#include "cDiem.h"

class cTamGiac
{
    private:
        cDiem A;
        cDiem B;
        cDiem C;
    public:
        cTamGiac();
        ~cTamGiac();

        void Nhap();
        void Xuat();
        int KTLoaiTamGiac(); // 0: thường, 1: vuông, 2: cân, 3: đều
        double TinhChuVi();
        double TinhDienTich();
        void TinhTien(double dx, double dy); //(dx,dy) là vector tịnh tiến
        void Quay(double degree);  // quay 1 góc alpha(đơn vị độ)
        void PhongTo_ThuNho(double k);

};

#endif // CTAMGIAC_H
