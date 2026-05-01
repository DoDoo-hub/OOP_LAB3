#ifndef CDSNHANVIEN_H
#define CDSNHANVIEN_H
#include <vector>
#include "cNhanVienSX.h"


class cDSNhanVien
{
    private:
        int N; //Số lượng nhân viên sx
        std::vector<cNhanVienSX> ds;
    public:
        cDSNhanVien();
        cDSNhanVien(int n);
        ~cDSNhanVien();

        void NhapDS();
        void XuatDS();
        cNhanVienSX TimLuongThapNhat();
        long long TinhTongLuong();
        cNhanVienSX TimTuoiCaoNhat();
        void SapXepTheoLuong();

};

#endif // CDSNHANVIEN_H
