#include <iostream>
using namespace std;

class Bike
{
private:
    char *brand; // hiệu xe
public:
    // Có khả năng sử dụng
    virtual void move(int t1)
    {
        brand = new char[30];
        cout << brand << ":" << t1 * 12 << " ";
    }
    // Khai báo thêm phương thức phá hủy để xóa vùng nhớ con trỏ sau khi sử dụng
    // Dùng thêm từ khóa new để cấp phát vùng nhớ, nếu không có new sẽ báo lỗi
    ~Bike()
    {
        delete brand;
    }
};


class EBike : public Bike
{
public:
    void move(int t2)
    {
        Bike::move(t2 * 2);
    }
};

void display(Bike &a, EBike &b)
{
    a.move(2);
    b.move(2);
}

int main()
{
    EBike b1, b2;
    display(b1, b2);
    return 0;
}

// b. Kết quả hiển thị màn hình là nội dung của branch và số 48 (hiển thị 2 lần giống nhau)
// Hiển thị nội dung brand:48
// và nội dung brand:48
// Giải thích: hàm display sẽ truyền vào b1, b2, sau đó a.move(2) sẽ gọi lên phương thức: void move(int t2)
//{
//  Bike::move(t2 * 2);
//} giá trị của move lúc này là 2*2 = 4. Sau đó được gọi lên lớp cha virtual void move(int t1) hiển thị nội dung brand, 4*12 = 48
// Tương tự b.move(2) cũng giống vậy.

// c. Nêu sự khác biệt giữa class và object, instance
// Lớp là 1 thực thể tổng quan, còn đối tượng thì cụ thể hơn. Trong ví dụ trên lớp là Bike, EBike, còn đối tượng là b1, b2

