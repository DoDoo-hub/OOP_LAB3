#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H


struct sDate {
    int ngay, thang, nam;
};

class cNhanVienSX
{
    private:
        std::string ID, HoTen;
        sDate NgaySinh;
        int SoSanPham, DonGia;
    public:
        cNhanVienSX();
         ~cNhanVienSX();

        void Nhap();
        void Xuat();
        int TinhLuong();

        //Hàm getter và setter
        std::string getID();
        std::string getHoten();
        sDate getNgaySinh();
        int getSoSanPham();
        int getDonGia();

        void setID(std::string id);
        void setHoten(std::string ten);
        void setNgaySinh(sDate ns);
        void setSoSanPham(int ssp);
        void setDonGia(int dg);

};

#endif // CNHANVIENSX_H

