#ifndef CDATHUC_H
#define CDATHUC_H
#include <vector>
#include "cDonThuc.h"

class cDaThuc
{
    private:
        int N;
        std::vector<cDonThuc> P;
    public:
        cDaThuc();
        cDaThuc(int bac);
        ~cDaThuc();
        void Nhap();
        void Xuat();
        long long TinhGiaTri(int x);
        cDaThuc TinhTong(const cDaThuc &B);
        cDaThuc TinhHieu(const cDaThuc &B);
};

#endif // CDATHUC_H
