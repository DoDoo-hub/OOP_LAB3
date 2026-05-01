#include <iostream>
#include <vector>
#include "cDaThuc.h"
using namespace std;


cDaThuc::cDaThuc():N(0){}

cDaThuc::cDaThuc(int bac):N(bac){}

//vector<cDonThuc> P tự động gọi hàm hủy của nó
//để giải phóng bộ nhớ cho các đơn thức
cDaThuc::~cDaThuc(){}

void cDaThuc::Nhap(){
    cout<<"Nhap bac cua da thuc: ";
    cin>>N;
    for (int i=N;i>-1;i--){ //thêm các đơn thức bậc N->0 vào P
        int a;
        cout<<"Nhap he so cua x^"<<i<<": ";
        cin>>a;
        P.push_back(cDonThuc(i,a));
    }
}

void cDaThuc::Xuat(){
    bool laDonThucDau=true;

    for(int i=0;i<=N;i++){
        int hs= P[i].getHeSo();
        if(hs==0) continue; //Bỏ qua nếu hệ số bằng 0

        if(laDonThucDau){
            if(hs<0) cout<< "-";
        }
        else{
            if(hs>0) cout<< " + ";
            else cout<< " - ";
        }

        P[i].Xuat();// In đơn thức(đã lấy trị tuyệt đối hệ số)

        laDonThucDau=false;
    }

    if(laDonThucDau) cout<< "0"; // Nếu đa thức = 0 -> In ra: 0
}

long long cDaThuc::TinhGiaTri(int x){
    long long kq=0;

    //cộng các giá trị(khi biết x) của từng đơn thức
    for (int i=0;i<=N;i++){
        kq+= P[i].TinhGiaTri(x);
    }
    return kq;
}

cDaThuc cDaThuc::TinhTong(const cDaThuc &B){ //Trả về đa thức C=A+B
    int Na=this->N;
    int Nb=B.N;
    cDaThuc C;//Đa thức chứa kết quả phép tổng
    int khoangcach=max(Na,Nb)-min(Na,Nb);//Tính chênh lệch bậc của A và B

    if(khoangcach>0){ //Trường hợp 2 đa thức có bậc khác nhau

        //Mục tiêu: Đưa các đơn thức bậc cao của đa thức lớn hơn vào trước,
        //sau đó mới cộng các đơn thức có cùng bậc với nhau.

        if(Na>Nb){
            for(int i=0;i<khoangcach;i++){
                cDonThuc c=this->P[i];
                C.P.push_back(c);
            }

            for(int i=0;i<=Nb;i++){
                cDonThuc c=this->P[i+khoangcach].TinhTong(B.P[i]);
                C.P.push_back(c);
            }
        }

        else{ //Nb>Na
            for(int i=0;i<khoangcach;i++){
                cDonThuc c=B.P[i];
                C.P.push_back(c);
            }

            for(int i=0;i<=Na;i++){
                cDonThuc c=B.P[i+khoangcach].TinhTong(this->P[i]);
                C.P.push_back(c);
            }
        }
    }


    else{ //Trường hợp 2 đa thức có cùng bậc
        bool check=0;// đã gặp đơn thức c đầu tiên !=0?
        for(int i=0;i<=Na;i++){
            cDonThuc c=this->P[i].TinhTong(B.P[i]);
            if(c.getHeSo()!=0){
                check=1;
                C.P.push_back(c);
            }
            else //c.getHeSo()==0
                if(check==1) C.P.push_back(c);
                // check=0 thì đến giờ các đơn thức đều=0, không cần thêm vào C
        }
    }

    C.N= C.P.size()-1;
    if(C.N==-1) C.P.push_back(cDonThuc(0,0)); // nếu A=B -> C=0
    return C;
}

cDaThuc cDaThuc::TinhHieu(const cDaThuc &B){ //Trả về đa thức C= A - B = A + -B
    //chuyển B thành -B (Đảo ngược dấu các đơn thức của B)
    cDaThuc B_copy=B;
    for(int i=0;i<=B_copy.N;i++){
        B_copy.P[i].setHeSo(-1 * B_copy.P[i].getHeSo());
    }

    return this->TinhTong(B_copy); //trả về phép hiệu: A - B = phép tổng: A + -B
}
