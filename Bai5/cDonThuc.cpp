#include <iostream>
#include "cDonThuc.h"
using namespace std;

cDonThuc::cDonThuc():bac(0),heso(0){}

cDonThuc::cDonThuc(int n, int a):bac(n),heso(a){}

cDonThuc::~cDonThuc(){}

void cDonThuc::Xuat(){
    //chỉ in trị tuyệt đối của hệ số, còn dấu(+/-) thì do DaThuc xử lý
    int absHeso=abs(heso);

    //Nếu hệ số=0 thì không cần in đơn thức đó
    if(absHeso==0) return;

    // 1. Xử lý phần hệ số
    if (absHeso != 1 || bac == 0) {
        cout << absHeso;
    }

    // 2. Xử lý phần x và bậc
    if (bac>0) {
        cout << "x";
        if (bac > 1)
            cout << "^" << bac;
    }

}

//Tính giá trị đơn thức khi biết x
long long cDonThuc::TinhGiaTri(int x){
    long long luyThua=1;
    for(int i=0;i<bac;i++)
        luyThua*=x;
    return (long long)heso * luyThua;//trả về giá trị đơn thức
}

cDonThuc cDonThuc::TinhTong(const cDonThuc &B) const {
    cDonThuc c;
    c.bac=B.bac; //bacC=bacB=bacA
    c.heso=this->heso+B.heso;
    return c;
}

int cDonThuc::getBac(){return bac;}

int cDonThuc::getHeSo(){return heso;}

void cDonThuc::setHeSo(int hs_moi){heso=hs_moi;}
