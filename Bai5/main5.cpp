#include <iostream>
#include <vector>
#include "cDaThuc.h"
using namespace std;

int main(){
    cDaThuc A,B;
    cout<<"Nhap da thuc A:\n";
    A.Nhap();

    cout<<"\nNhap da thuc B:\n";
    B.Nhap();

    cout<<"\nDa thuc A(x)= ";
    A.Xuat();
    cout<<"\nDa thuc B(x)= ";
    B.Xuat();

    cout<<"\n\nTinh gia tri da thuc A khi biet gia tri bien x";
    int x_a;
    cout<<"\nNhap x: "; cin>>x_a;
    cout<<"A("<<x_a<<")= "<<A.TinhGiaTri(x_a);

    cout<<"\n\nTinh gia tri da thuc B khi biet gia tri bien x";
    int x_b;
    cout<<"\nNhap x: "; cin>>x_b;
    cout<<"B("<<x_b<<")= "<<B.TinhGiaTri(x_b);


    // Tính toán
    cDaThuc tong = A.TinhTong(B);
    cDaThuc hieu = A.TinhHieu(B);

    cout << "\n\nTong A+B= ";
    tong.Xuat();
    cout << "\nHieu A-B= ";
    hieu.Xuat();

    return 0;
}
