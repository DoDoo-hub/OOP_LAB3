#include <iostream>
#include <cmath>
#include <vector>
#include "cDaGiac.h"
using namespace std;



cDaGiac::cDaGiac():N(0){}

cDaGiac::~cDaGiac(){}

void cDaGiac::Nhap(){
    do {
        cout <<"Nhap so dinh cua da giac (N > 2): ";
        cin>> N;
    } while(N<=2);

    dsDiem.resize(N);
    for(int i=0; i<N; i++) {
        cout <<"Nhap dinh " << i+1 << ":" << endl;
        dsDiem[i].Nhap();
    }
}

void cDaGiac::Xuat(){
    for(int i=0; i<N; i++) {
        cout <<"Dinh " << i+1 << ": ";
        dsDiem[i].Xuat();
        cout << (i == N-1 ? "" : ", ");
    }
}

double cDaGiac::TinhChuVi(){
    double chuVi=0;
    for(int i=0; i<N; i++) {
        //Tính khoảng cách từ đỉnh hiện tại đến đỉnh kế tiếp (đỉnh cuối nối về đỉnh đầu)
        chuVi += dsDiem[i].TinhKhoangCach(dsDiem[(i+1) % N]);
    }
    return chuVi;
}

double cDaGiac::TinhDienTich(){
    //Công thức Shoelace (diện tích đa giác bất kỳ)
    double dienTich = 0;
    for(int i=0; i<N; i++) {
        int next = (i + 1) % N;
        dienTich += (dsDiem[i].getX() * dsDiem[next].getY() - dsDiem[next].getX() * dsDiem[i].getY());
    }
    return fabs(dienTich) / 2.0;
}

void cDaGiac::TinhTien(double dx, double dy){//(dx,dy) là vector tịnh tiến
    for(int i=0; i<N; i++) {
        dsDiem[i].TinhTienDiem(dx,dy);
    }
}

void cDaGiac::Quay(double degree){ //Quay 1 góc alpha(đơn vị độ)
    for(int i=0; i<N; i++) {
        dsDiem[i].Quay(degree);
    }
}

void cDaGiac::PhongTo_ThuNho(double k){
    //1.Tìm trọng tâm G của đa giác
    double sumX=0, sumY=0;
    for (int i=0; i<N; i++) {
        sumX+= dsDiem[i].getX();
        sumY+= dsDiem[i].getY();
    }
    double xG =sumX / N;
    double yG =sumY / N;

    //2.Vị tự từng điểm theo hệ số k đối với trọng tâm
    for (int i=0; i<N; i++) {
        double newX =xG + (dsDiem[i].getX() - xG)*k;
        double newY =yG + (dsDiem[i].getY() - yG)*k;
        dsDiem[i].SetToaDo(newX, newY);
    }
}

