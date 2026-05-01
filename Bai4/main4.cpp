#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "cArray.h"
using namespace std;

int main(){
    srand(time(0));

    cArray A;
    int n;
    do{   //Nhập vào độ dài mảng lớn hơn 0
        cout<<"Nhap do dai mang (>0): ";
        cin>>n;
    }while(n<=0);

    //Tạo mảng bằng cách nhập thủ công hoặc chương trình sinh số ngẫu nhiên
    char option;
    cout<<"\nTao mang so nguyen:";
    cout<<"\nHay nhap vao:";
    cout<<"\n1: Tao mang ngau nhien";
    cout<<"\nCac ki tu khac: Nhap thu cong mang\n";
    cin>>option;
    if(option=='1') A.TaoNgauNhien(n);
    else A.Nhap(n);

    cout<<"\nMang: ";
    A.Xuat();

    //Đếm số lần xuất hiện giá trị x
    int x;
    cout<<"\nNhap gia tri x: ";
    cin>>x;
    cout<<"So lan xuat hien gia tri "<<x<<" trong mang: "<<A.CountX(x);

    //Kiểm tra mảng có tăng dần không
    bool check=A.TangDan();
    if(check)
        cout<<"\n\nMang tang dan";
    else cout<<"\n\nMang khong tang dan";

    //Tìm phần lẻ nhỏ nhất
    int minLe=A.PhanLeNhoNhat();
    if(minLe==0) cout<<"\n\nMang khong co phan le";
    else cout<<"\n\nPhan le nho nhat trong mang: "<<minLe;

    //Tìm số nguyên tố lớn nhất
    int maxSNT=A.TimSoNguyenToLonNhat();
    if(maxSNT==0) cout<<"\n\nMang khong co so nguyen to";
    else cout<<"\n\nSo nguyen to lon nhat trong mang: "<<maxSNT;


    //Sắp xếp mảng (dùng QuickSort)
    char luaChon;
    cout<<"\n\nNhap lua chon sap xep mang:";
    cout<<"\n0: Sap xep giam dan";
    cout<<"\nCac ki tu khac: Sap xep tang dan\n";
    cin>>luaChon;

    bool tangDan= (luaChon!='0');
    A.QuickSort(0,n-1,tangDan);
    cout<<"\nMang sau khi sap xep: ";
    A.Xuat();

    return 0;
}

