#include <iostream>
#include <memory>
#include <format>

#pragma warning (disable : 6386 )

class Random {
public:
    typedef std::shared_ptr<Random> Ptr;
public:
    inline static Ptr _instance = nullptr;
private:
    Random() {
        srand(time(NULL));
    }
public:
    ~Random() {
        std::cout << "Destructor\n";
    }
public:
    static Ptr instance() { // getInstance
        if (_instance == nullptr) {
            Random* temp = new Random();
            _instance = Ptr(temp);
        }
        return _instance;
    }
public:
    int next() { return rand(); }
    int next(int ceiling) { return rand() % ceiling; }
};

typedef std::shared_ptr<int> intPtr;



template <typename T>
class SmartPointer {
private:
    T* _p;
    int _count;
public:
    SmartPointer() { _p = nullptr; _count = 0; }
    SmartPointer(T* p) { _p = p; _count = 1; }
    SmartPointer(const SmartPointer& other) { // copy constructor
        this->_p = other._p;
        this->_count = other._count + 1;
    }
    ~SmartPointer() {
        _count--;
        if ((_count == 0) && (_p != nullptr)) {
            std::cout << "time to go!\n";
            delete _p;
        }
    }
public:
    int count() { return _count; }
};

void update1(SmartPointer<int> p1);
void update2(SmartPointer<int> p2);

void update1(SmartPointer<int> p1) {
    std::cout << "Start update 1:" << p1.count() << "\n";
    update2(p1);
    std::cout << "End update 1:" << p1.count() << "\n";
}

void update2(SmartPointer<int> p2) {
    std::cout << "Start update 2:" << p2.count() << "\n";
}

template <typename T>
class Array {
private:
    T* _items;
    int _maxSize;
    int _length;
public:
    int size() { return _length; }
    void push_back(T item) {
        if (_length == _maxSize) {
            // Step 1: tăng size
            const int STEP = 10;
            _maxSize = _maxSize + STEP;

            // Step 2: Cấp phát bộ nhớ
            T* temp = new T[_maxSize];

            // Step 3: di chuyển dữ liệu
            // Bulk transfer - memset
            for (int i = 0; i < _length; i++) {
                temp[i] = _items[i];
            }
            delete[] _items;
            _items = temp;
        }
        _items[_length] = item;
        _length++;
    }
    T& getAt(int index) {
        if ((index < 0) || (index >= _length)) {
            throw std::exception("Index of bound exception");
        }
        return _items[index];
    }
public:
    Array() {
        const int INITIAL_SIZE = 10;
        _maxSize = INITIAL_SIZE;
        _items = new T[_maxSize];
        _length = 0;
    }

    ~Array() {
        delete[] _items;
    }

    Array(const Array& other) { // copy constructor
        std::cout << "Copy \n";
        _maxSize = other._maxSize;
        _length = other._length;
        _items = new T[_maxSize];

        // Copy dữ liệu
        for (int i = 0; i < _length; i++) {
            _items[i] = other._items[i];
        }
    }

    // Copy assignment operator
    // a = b = c = d = e;
    const Array& operator=(const Array& other) {
        std::cout << "Operator =\n";
        if (this == &other) { return *this; }
        if (_items != nullptr) { delete[] _items;  }

        _maxSize = other._maxSize;
        _length = other._length;
        _items = new T[_maxSize];

        for (int i = 0; i < _length; i++) {
            _items[i] = other._items[i];
        }

        return *this; 
    }
};

//Fibonacci.h

class Fibonacci {
private:
    int _size;
    int* _elements;
public:
    Fibonacci();
    ~Fibonacci();
    Fibonacci(const Fibonacci& other);
    const Fibonacci& operator=(const Fibonacci& other);
public:
    void generate(int n);
    friend std::ostream& operator<<(std::ostream& out, const Fibonacci& f);
private:
    void _clone(const Fibonacci& other);
};

std::ostream& Fibonacci::operator<<(std::ostream& out) {
    for (int i = 0; i < _size; i++) {
        out << std::format("F[{}] = {}\n", i, _elements[i]);
    }

    return out;
}

Fibonacci::~Fibonacci() {
    if (_elements != nullptr) {
        delete[] _elements;
    }
}

Fibonacci::Fibonacci(const Fibonacci& other) {
    _clone(other);
}

void Fibonacci::_clone(const Fibonacci& other)
{
    _size = other._size;
    if (_size > 0) {
        _elements = new int[_size];
        for (int i = 0; i < _size; i++) {
            _elements[i] = other._elements[i];
        }
    }
}

const Fibonacci& Fibonacci::operator=(const Fibonacci& other) {
    if (this == &other) { return *this; }
    if (_elements != nullptr) { delete[] _elements; }

    _clone(other);
    return *this;
}

Fibonacci::Fibonacci() {
    _size = 0;
    _elements = nullptr; // NULL
}

// Gia dinh ham chi duoc goi 1 lan
void Fibonacci::generate(int n) {
    _size = n;
    _elements = new int[n];

    _elements[0] = 0;
    _elements[1] = 1;

    for (int i = 2; i < n; i++) {
        _elements[i] = _elements[i - 1] + _elements[i - 2];
    }
}

std::ostream& operator<<(std::ostream& out, const Fibonacci& f) {
    for (int i = 0; i < f._size; i++) {
        out << std::format("F[{}] = {}\n", i, f._elements[i]);
    }

    return out;
}

// std::cout << f; cout<< f << g << h << i << j;
// => operator<<(cout, f);

//#define square(x) x*x;

int main()
{
    Fibonacci f;
    f.generate(10);

    //f.xuat(); f.output();

    //std::cout << f;
    //std::cout << f.toString(); // converter
    

    //int x = 5;
    //std::cout << 5 + 1 * 5 + 1; // square(x + 1);

   /* std::cout << Random::instance()->next(10) << "\n";
    std::cout << Random::instance()->next(30) << "\n";
    std::cout << Random::instance()->next(46) << "\n";
    std::cout << Random::instance()->next(30) << "\n";*/

    /*SmartPointer<int> x = SmartPointer(new int(99));
    std::cout << "Start of main: " << x.count() << "\n";
    update1(x);
    std::cout << "End of main: " << x.count() << "\n";*/

    /*Array<int> a;
    a.push_back(11);
    a.push_back(12);
    a.push_back(13);
    a.push_back(14);
    a.push_back(15);

    for (int i = 0; i < a.size(); i++) {
        std::cout << a.getAt(i) << " ";
    }
    std::cout << "\n";

    Array<int> d = a;*/

    /*
    Array<int> b(a);
    b.push_back(99);
    b.push_back(100);
    for (int i = 0; i < b.size(); i++) {
        std::cout << b.getAt(i) << " ";
    }
    std::cout << "\n";

    Array<int> c(a);
    c = b;
    for (int i = 0; i < c.size(); i++) {
        std::cout << c.getAt(i) << " ";
    }*/

    

    
}