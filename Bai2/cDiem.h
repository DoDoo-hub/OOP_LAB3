#ifndef CDIEM_H
#define CDIEM_H


class cDiem
{
    private:
        double x;
        double y;
    public:
        cDiem();
        ~cDiem();

        void Nhap();
        void Xuat();
        double getX();
        double getY();
        void SetToaDo(double nX, double nY);
        double TinhKhoangCach(cDiem B); // Tính khoảng cách giữa 2 điểm
        void TinhTienDiem(double dx, double dy);  //(dx,dy) là vector tịnh tiến
        void Quay(double degree); // Quay 1 điểm quanh góc tọa độ O(0,0) 1 góc alpha(tính theo độ)

};

#endif // CDIEM_H





