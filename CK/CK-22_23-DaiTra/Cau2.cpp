#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base::Base()" << endl;
    }

    Base(int t)
    {
        cout << "Base::Base(int)" << endl;
    }

    Base(int t, int k)
    {
        cout << "Base::Base(int, int)" << endl;
    }

    Base(const Base& src)
    {
        cout << "Base::Base(const Base&)" << endl;
    }

    Base& operator=(const Base& src)
    {
        cout << "Base::operator=()" << endl;
        return *this;
    }

    virtual void doSth(int x)
    {
        cout << "Base::doSth(int)" << endl;
    }

    void doSthE(int x)
    {
        cout << "Base::doSthE(int)" << endl;
    }

    virtual ~Base()
    {
        cout << "Base::~Base()" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived::Derived()" << endl;
    }

    Derived(int t) : Base(t)
    {
        cout << "Derived::Derived(int)" << endl;
    }

    Derived(int t, int k)
    {
        cout << "Derived::Derived(int, int)" << endl;
    }

    Derived(const Derived& src) : Base(src)
    {
        cout << "Derived::Derived(const Derived&)" << endl;
    }

    Derived& operator=(const Derived& src)
    {
        cout << "Derived::operator=()" << endl;
        return *this;
    }

    void doSth(int x)
    {
        cout << "Derived::doSth(int)" << endl;
    }

    void doSthE(int x)
    {
        cout << "Derived::doSthE(int)" << endl;
    }

    ~Derived()
    {
        cout << "Derived::~Derived()" << endl;
    }
};

void testing(Base& first, Derived second)
{
    cout << "\nTesting 3: " << endl;
    Derived x;
    x = second;
    first.doSth(1);
    first.doSthE(2);

    cout << "\nTesting 4: " << endl;
    x.doSth(3);
    x.doSthE(4);
}

int main()
{
    cout << "Testing 1: " << endl; // không có gì hết 
    Derived x(5), y(3, 7);

    cout << "\nTesting 2: " << endl;
    testing(x, y);

    cout << "\nTesting 5: " << endl;

    // cout << "\nTesting 6:" << endl;

    // Base* z = new Derived();
    // // Base::Base()
    // // Base::~Base()
    // delete z;

    return 0;
}

// Đoạn mã nguồn trên sẽ in ra các thông tin như sau:
// Testing 1:
// Dòng Dirived sẽ in ra 2 thông tin , vì Derived có tham số đầu vào có kế thừa
// từ lớp Base (có tham số đầu vào)
// Base::Base(int)
// Derived::Derived(int)

// Dòng Derived y(3, 7) sẽ in 1 thông tin bên dưới
// Trước khi tạo lớp con thì lớp cha phải được tạo (dù hàm khởi tạo lớp con không để kế thừa)
// Base::Base(int, int) 
// Derived::Derived(int, int)

// Do tham số đầu vào của testing(x,y) có y là tham trị nên 1 phương thức khởi tạo sao chép sẽ được tạo ra cho biến y
// nên kết quả in là: 
// Testing 2: 
// Base::Base(const Base&)
// Derived::Derived(const Derived&)

// Testing 3:
// Derived::Derived() // phương thức khởi tạo mặc định được tạo ra
// Derived::operator=() // phương thức gán được in ra
// Derived::doSth(int) // Do lớp cha sử dụng từ khóa virtual nên phương thức
// doSth(int) của lớp cha không được in mà in ở lớp con (Derived)
// Base::doSthE(int) // Phương thức doSthE(int) của lớp cha sẽ được gọi

// Testing 4:
// Derived::doSth(int) // Phương thức doSth(int) của lớp con được gọi
// Derived::doSthE(int) // Phương thức doSthE(int) của lớp con được gọi
// Derived::~Derived() // Phương thức hủy của lớp con được gọi
// Base::~Base() // Phương thức hủy của lớp cha được gọi
// Derived::~Derived() // Phương thức hủy của lớp con được gọi
// Base::~Base() // Phương thức hủy của lớp cha được gọi

// Testing 5:
// Derived::~Derived() // Phương thức hủy của lớp con được gọi
// Base::~Base() // Phương thức hủy của lớp cha được gọi
// Derived::~Derived() // Phương thức hủy của lớp con được gọi
// Base::~Base() // Phương thức hủy của lớp cha được gọi
