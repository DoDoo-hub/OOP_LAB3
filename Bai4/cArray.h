#ifndef CARRAY_H
#define CARRAY_H

#include <vector>

class cArray
{
    private:
        int N;
        std::vector<int> arr;
        int Partition(int low, int high, bool tangDan);
    public:
        cArray();
        cArray(int n, std::vector<int> a);
        cArray(const cArray &a);
        ~cArray();
        void TaoNgauNhien(int n);
        void Nhap(int n);
        void Xuat();
        int CountX(int x);
        bool TangDan();
        int PhanLeNhoNhat();
        int TimSoNguyenToLonNhat();
        void QuickSort(int low, int high, bool tangDan);

};

#endif // CARRAY_H
