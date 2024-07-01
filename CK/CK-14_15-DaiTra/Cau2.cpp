#include <iostream>
using namespace std;

// Đại diện cho interface. Là một lớp giao diện trong đó không có thuộc tính,
// mà chỉ có các phương thức ảo và thuần ảo
// Hay dùng cho đa kế thức 
class IFace
{
public:
    virtual void show() = 0;
    virtual IFace *clone() = 0;
    virtual ~IFace()
    {
    }
};

class Face : public IFace
{
protected:
    string shape;

protected:
    string getShape();

public:
    Face(string sh) : shape(sh)
    {
    }
    
    virtual void show()
    {
        cout << "Shape : " << shape << endl;
    }

    Face *clone()
    {
        return new Face(*this);
    }

    Face(){

    }
};

class EyedFace : public Face{
private:
    int eyes;
    inline static int count = 0;
public:
    // xuất ra màn hình giá trị của 2 thuộc tính 
    void show(){
        Face::show();
        cout << "Eyes : " << eyes << endl;
    }
    
    // clone() trả về 1 đối tượng EyedFace mới là 1 bản sao của đối tượng này
    EyedFace *clone(){
        return new EyedFace(*this);
    }

    EyedFace(string sh, int e) : Face(sh), eyes(e){
        count++;
    }

    ~EyedFace(){
        count--;
    }

    static int getCount(){
        return count;
    }
};

void testFace(IFace *fc)
{
    IFace *a[3] = {fc, fc->clone(), fc->clone()};
    for (int i = 0; i < 3; i++)
    {
        a[i]->show();
    }
    // Dùng vòng lặp để chạy qua các đối tượng con trỏ được tạo ở trên sau đó xóa từng đối tượng và gán về NULL
    // a[0] không cấp phát động nên k cần xóa
    for (int i = 1; i < 3; i++)
    {
        delete a[i];
        a[i] = nullptr;
    }

    cout << "The same 3 lines ?";
}

int main()
{
    Face *fc; // Lớp Face 1 đối tượng được tạo ra phải là 1 con trỏ hoặc phải có 1 hàm khởi tạo mặc định
    Face fc1("Rectangle");
    testFace(&fc1);
    // Thêm 1 đối tượng EyedFace fc2 để gọi các constructor tạo ra đối tượng mới.
    EyedFace fc2("Circle", 2);
    cout << "\nSo luong doi tuong EyeFace trong bo nho: " << EyedFace::getCount() << endl;
    return 0;
}

// b. 
// Hàm testFace hiển thị ra 3 chữ giống nhau là Rectangle. Do có 3 đối tượng được tạo ra là a[0], a[1], a[2] thuộc về lớp Face

// c.
