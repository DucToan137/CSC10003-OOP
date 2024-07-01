#include<iostream>
#include<string>
#include<vector>

using namespace std;


//-----------------Lớp Project----------------
class Project{
protected:
    string _name;
public:
    Project(); 
public:
    virtual long grantMoney() = 0;
    virtual void print() = 0;
};

Project::Project(){
    _name = "";
}

//-------------Lớp Idea----------------
class Idea : public Project{
private:
    int _growth;
public:
    Idea(string name, int growth);
public:
    long grantMoney();
    void print();
};

Idea::Idea(string name, int growth){
    _name = name;
    _growth = growth;
}

long Idea::grantMoney(){
    return 20000000 * _growth;
}

void Idea::print(){
    cout << "Y tuong: " << _name << "." 
        << "Phat trien: " << _growth << " thang." 
        << "Kinh phi: " << grantMoney();
}

//-------------Lớp Mvp----------------
class Mvp : public Project{
private:
     int _operation;
     int _marketing;
public:
    Mvp(string name, int operation, int marketing);
public:
    long grantMoney();
    void print();
};

Mvp::Mvp(string name, int operation, int marketing){
    _name = name;
    _operation = operation;
    _marketing = marketing;
}

long Mvp::grantMoney(){
    return (_operation + _marketing) * 15000000;
}

void Mvp::print(){
    cout << "San pham: " << _name << ". Van hanh: " << _operation <<" thang."
        << "Marketing: " << _marketing << " thang."
        << "Kinh phi: " << grantMoney();
}


int main()
{
    vector<Project*> projects = {
        new Idea("SuperTech", 6),
        new Mvp("FutureCar", 6, 3),
        new Idea("VirtualHouse", 7),
        new Idea("NightVision", 4),
        new Mvp("Smartkey", 4, 5)
    };

    cout << "So du an: " << projects.size() << endl;
    int sum = 0;
    for (int i = 0; i < projects.size(); i++) {
        sum += projects[i]->grantMoney();
        cout << i + 1 << ". ";
        projects[i]->print();
        cout << endl;
    }
    /*cout << "Tong tien tai tro: " << MoneyFormatter::format(sum) << endl;

    Table t({"Loai du an", "Ten du an", "Thong tin", "Kinh phi"});
    for (int i = 0; i < projects.size(); i++) {
        t.addRow(projects[i]);
    }
    t.print();

    for (int i = 0; i < projects.size(); i++) {
        delete projects[i];
    }*/

    return 0;
}


// Ý tưởng câu 3.2a
// Bước 1: chuyển kiểu dữ liệu số tiền từ long -> string. Tên chuỗi s
// Bước 2: Dùng vòng lặp để chạy từ dưới lên của chuỗi s
//  Nếu biến đếm count = 3 chèn thêm 1 dấu .
//      Xét thêm nếu count = 3, nhưng biến chạy = 0, lúc này đã về đầu chuỗi
//      thì chúng ta cũng dừng vòng lặp
// Bước 3: Kết thúc vòng dừng chương trình, in ra số tiền cần chuẩn hóa


// Ý tưởng câu 3.2b
// Giả sử ban đầu số tiền đang hiển thị là: 120.000.000 thì cách để chuyển sang VND như sau
// Bước 1: chèn kí tự tại s[size] = " " (dấu khoảng cách)
// Bước 2: Sau đó chèn kí tự tại s[size+1] = "đ" (dấu VND)
// Bước 3: Dừng chương trình hiển thị lại số tiền

// Nếu chuyển sang đô la mĩ thì làm như sau:
// Bước 1: Dùng vòng lặp chạy từ đầu đến cuối chuỗi
// Thay các dấu "." thành dấu ","
// Bước 2: Dùng vòng lặp chạy tự cuối chuỗi dời các kí tự về 2 ô
// vẽ hình
// Bước 3: Chèn s[0] = "$" (dấu đô la), s[1] = " " (dấu khoảng trắng) 


// Ý tưởng câu 3.2c
// Bước 1: Hiển thị các tiêu đề của bảng bằng cách dùng hàm cout.
// Loại dự án   | Tên dự án     | Thông tin     | Kinh phí
// ---------------------------------------------------------
// Bước 2: Tiếp tục in thông tin của Project là Idea
// "Y tuong: " (dấu tab) << "|" << name << "." << "Phat trien: " << growth << " thang." << "Kinh phi: " << gọi hàm grantMoney();
// Bước 3: In thông tin của Project là Mvp
// "San pham: " (dấu tab) << "|" << name << ". Van hanh: " << operation << " thang." << "Marketing: " << marketing << " thang." << "Kinh phi: " << gọi hàm grantMoney();


// Ý tưởng câu 3.2d
// Bước 1: Thêm 1 thuộc tính _office (kiểu chuỗi) và crypto (kiểu số thực) vào lớp Project
// Bước 2: 
//      Idea: Khi dự án chạy quá 6 tháng thì công thức tính tiền tài trợ sẽ thay đổi như sau
//      Tiền tài trợ mới = Tiền tài trợ cũ + ((_growth - 6) * (20%*tiền tài trợ cũ))
//      Mvp: Tiền tài trợ mới = Tiền tài trợ cũ + ((_operation-6)+(marketing-6))*(20%*Tiền tài trợ cũ)
// Bước 3: Chạy lại số liệu để cập nhật thông tin mới ở trên
