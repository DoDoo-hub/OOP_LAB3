#ifndef CDONTHUC_H
#define CDONTHUC_H


class cDonThuc
{
    private:
        int bac;
        int heso;
    public:
        cDonThuc();
        cDonThuc(int n, int a);
        ~cDonThuc();
        void Xuat();
        long long TinhGiaTri(int x);
        cDonThuc TinhTong(const cDonThuc &B)const;
        int getBac();
        int getHeSo();
        void setHeSo(int hs_moi);
};

#endif // CDONTHUC_H
