#include <iostream>
#include "cNhanVienSX.h"
#include <string>
using namespace std;


cNhanVienSX::cNhanVienSX(){
    ID= "";
    HoTen= "";
    NgaySinh= {0,0,0}; //Khởi tạo struct sDate
    SoSanPham= 0;
    DonGia= 0;
}

cNhanVienSX::~cNhanVienSX(){}

//Nhập thông tin 1 NV
void cNhanVienSX::Nhap(){
    cout<<"Nhap ID: "; cin>>ID;
    cin.ignore();

    cout<<"Nhap Ho Ten: "; getline(cin,HoTen);

    char slash; //Dùng để đọc ký tự '/' trong định dạng NgaySinh
    cout << "Nhap Ngay Sinh (dd/mm/yyyy): ";
    cin >>NgaySinh.ngay >>slash >>NgaySinh.thang >>slash >>NgaySinh.nam;

    cout << "Nhap So San Pham: ";
    cin >> SoSanPham;

    cout << "Nhap Don Gia: ";
    cin >> DonGia;
    cin.ignore();
}


//Hàm phụ để in ngày/tháng với 2 chữ số
void inHaiChuSo(int n){
    if(n<10) cout<< "0";
    cout<< n;
}
//In thông tin 1 NV
void cNhanVienSX::Xuat(){
    cout<<ID<<"\t|";
    cout<<HoTen<<"\t|";

    //In ngày sinh dạng dd/mm/yyyy
    //Dùng hàm phụ để in ngày/tháng
    inHaiChuSo(NgaySinh.ngay); cout<<"/";
    inHaiChuSo(NgaySinh.thang); cout<<"/";
    cout<<NgaySinh.nam<<"\t|";

    cout<<SoSanPham<<"\t|"<<DonGia<<" VND";
}

int cNhanVienSX::TinhLuong(){
    return SoSanPham * DonGia;
}


string cNhanVienSX::getID() {return ID;}
string cNhanVienSX::getHoten() {return HoTen;}
sDate cNhanVienSX::getNgaySinh() {return NgaySinh;}
int cNhanVienSX::getSoSanPham() {return SoSanPham;}
int cNhanVienSX::getDonGia() {return DonGia;}

void cNhanVienSX::setID(string id) {ID=id;}
void cNhanVienSX::setHoten(string ten) {HoTen=ten;}
void cNhanVienSX::setNgaySinh(sDate ns) {NgaySinh=ns;}
void cNhanVienSX::setSoSanPham(int ssp) {SoSanPham=ssp;}
void cNhanVienSX::setDonGia(int dg) {DonGia=dg;}


