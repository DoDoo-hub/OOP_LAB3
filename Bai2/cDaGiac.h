#ifndef CDAGIAC_H
#define CDAGIAC_H
#include <vector>
#include "cDiem.h"

class cDaGiac
{
    private:
        int N;
        std::vector<cDiem> dsDiem;
    public:
        cDaGiac();
        ~cDaGiac();

        void Nhap();
        void Xuat();
        double TinhChuVi();
        double TinhDienTich();
        void TinhTien(double dx, double dy); //(dx,dy) là vector tịnh tiến
        void Quay(double degree);  // quay 1 góc alpha(đơn vị độ)
        void PhongTo_ThuNho(double k);

};

#endif // CDAGIAC_H
