#include <iostream>
#include <cmath>
#include "cDiem.h"
using namespace std;
const double PI = 3.14159265358979323846;


cDiem::cDiem():x(0), y(0){}

cDiem::~cDiem(){}

void cDiem::Nhap(){
    cout<< "Nhap toa do x: ";
    cin>>x;
    cout<< "Nhap toa do y: ";
    cin>>y;
}

void cDiem::Xuat(){
    cout<< "(" << x << ";" << y << ")";  // Xuất tọa dộ dạng (x,y)
}

double cDiem::getX(){return x;}
double cDiem::getY(){return y;}

void cDiem::SetToaDo(double nX, double nY){
    x= nX;
    y= nY;
}

double cDiem::TinhKhoangCach(cDiem B){  // Tính khoảng cách giữa 2 điểm
    double AB= (x-B.x)*(x-B.x) + (y-B.y)*(y-B.y);
    AB= sqrt(AB);
    return AB;
}

void cDiem::TinhTienDiem(double dx, double dy){ //Tịnh tiến điểm (x,y) với vector tịnh tiến (dx,dy)
    x+=dx;
    y+=dy;
}

void cDiem::Quay(double degree){
    double rad = degree * PI / 180.0; // chuyển đơn vị góc từ độ sang radian
    double x_temp=x;
    double y_temp=y;

    x= x_temp * cos(rad) - y_temp * sin(rad);
    y= x_temp * sin(rad) + y_temp * cos(rad);
}



