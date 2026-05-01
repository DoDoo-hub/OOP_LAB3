#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "cArray.h"
using namespace std;


cArray::cArray(): N(0){}

cArray::cArray(int n, vector<int> a): N(n), arr(a) {}

cArray::cArray(const cArray &a): N(a.N), arr(a.arr) {}

//vector<int> arr tự động giải phóng bộ nhớ khi đối tượng bị hủy
cArray::~cArray(){}

//tạo mảng ngẫu nhiên n số nguyên
//có giá trị các phần tử trong khoảng [min;max]
void cArray::TaoNgauNhien(int n){
    N=n;
    arr.clear();

    int min,max;
    cout<<"\nNhap khoang gia tri [min;max] cua cac phan tu:";
    cout<<"\nNhap min: ";
    cin>>min;
    do{
        cout<<"Nhap max(max>=min): ";
        cin>>max;
    }while(max<min);



    for(int i=0;i<N;i++){
        arr.push_back( min+ rand()%(max-min+1) );
    }
}

//Nhập thủ công n phần tử của mảng
void cArray::Nhap(int n){
    N=n;
    arr.resize(N);
    for(int i=0;i<N;i++){
        cout<<"Nhap a["<<i<<"]: ";
        cin>>arr[i];
    }
}

void cArray::Xuat(){
    for(int i=0;i<N;i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

int cArray::CountX(int x){// đếm số lần x xuất hiện
    int count=0;
    for(int i=0;i<N;i++)
        if(arr[i]==x)
            count++;
    return count;
}

//Kiểm tra mảng có tăng dần không, 1: tăng dần; 0: không tăng dần
bool cArray::TangDan(){
    for(int i=0;i<N-1;i++)
        if(arr[i+1] < arr[i])
            return 0;
    return 1;
}

//Nếu mảng ko có số lẻ thì trả về 0
//Ngược lại trả về số lẻ nhỏ nhất trong mảng
int cArray::PhanLeNhoNhat(){
    int minLe;
    bool timthayle=false; // mảng có tồn tại phần tử lẻ?

    for (int i=0;i<N;i++)
        if(arr[i]%2!=0) //Nếu là số lẻ
            if(!timthayle || arr[i]<minLe){ //nếu tìm thấy phần lẻ đầu tiên hoặc phần lẻ nhỏ hơn minLe
                minLe=arr[i];
                timthayle=true;
            }
    return (timthayle)?minLe:0;
}

bool isPrime(int num){ //Hàm kiểm tra số nguyên tố
    if(num<=1) return false;
    for (int i=2;i*i<=num;i++)
        if(num%i==0) return false;
    return true;
}
//Nếu mảng không có số nguyên tố thì trả về 0
//Ngược lại thì trả về số nguyên tố lớn nhất
int cArray::TimSoNguyenToLonNhat(){
    int maxSNT=0;

    for(int i=0;i<N;i++)
        if(isPrime(arr[i]) && arr[i]>maxSNT)
            maxSNT=arr[i];

    return maxSNT;
}


int cArray::Partition(int low, int high, bool tangDan){
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        //Dựa vào biến tangDan để xác định điều kiện để swap trong quicksort
        bool dieuKien= tangDan ? (arr[j]<=pivot) : (arr[j]>=pivot);
        if(dieuKien){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
//Sắp xếp mảng dùng QuickSort Lomuto
//Biến tangDan thể hiện lựa chọn sắp xếp (1:tăng dần / 0:giảm dần) mảng
void cArray::QuickSort(int low, int high, bool tangDan){
    if(low<high){
        int pi=Partition(low,high,tangDan);
        QuickSort(low,pi-1,tangDan);
        QuickSort(pi+1,high,tangDan);
    }
}


