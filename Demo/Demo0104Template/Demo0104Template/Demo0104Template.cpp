#include <iostream>
#include <string>
#include <exception>
#include <format>

// .h / .cpp
// ==> 1. Riêng với template không tách .h và .ccp
// Vì ko được
// ==> 2. Về nhà tìm cách tách .h và .cpp => vẫn được
// ==> 3. ngẫm nghĩ và thấy mất đi ngữ nghĩa
// ==> 4. Nói lại với lứa sau / đàn em là tách ko được đâu

template <class T>
T tong(T a, T b) {
    return a + b;
}

double tong(double a, double b) {
    return a + b;
}

std::string tong(std::string a, std::string b) {
    return a + b;
}

//int tong(int a, int b) {
//    return a + b;
//}
//

//
//Fraction tong(Fraction a, Fraction b) {
//    return a + b;
//}
//
//float tong(float a, float b) {
//    return a + b;
//}

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
};

//template <typename T>
//class Result {
//public:
//    bool success;
//    T data;
//    int errorCode;
//    std::string message;
//};
//
//Result<Fraction> parse(std::string line);
//
//Result<Fraction> info = parse("5/7");
//if (info.success == true) {
//    info.data;
//}
//else {
//    std::cout << info.code << info.message;
//}


template <typename T>
class Result {
public:
    bool success;
    T data;
    int code;
    std::string message;
};

class AtmMachine;
class BankAccount;



class AtmMachine {
private:
    std::string _address;
    int _balance;
public:
    AtmMachine();
    AtmMachine(std::string address, int balance);
public:
    Result<int> canWithdraw(int amount);
    void withdraw(int amount);
};

void AtmMachine::withdraw(int amount) {
    _balance -= amount;
}

AtmMachine::AtmMachine() {
    _address = "";
    _balance = 0;
}

AtmMachine::AtmMachine(std::string address, int balance) {
    _address = address;
    // TODO: Xu li balance am
    _balance = balance;
}

Result<int> AtmMachine::canWithdraw(int amount) {
    Result<int> result;

    if (amount % 50000 != 0) {
        result.success = false;
        result.code = 1;
        result.message = "Tien rut phai la boi so cua 50.000";
        return result;
    }

    if (amount > this->_balance) {
        result.success = false;
        result.code = 2;
        result.message = "May khong con du tien";
        return result;
    }

    result.success = true;
    result.code = 0;
    result.data = amount;

    return result;
}

class BankAccount {
private:
    inline static const int MINIMUM_BALANCE = 50000;
    std::string _fullname;
    std::string _id;
    int _balance;
public:
    int balance();
public:
    BankAccount();
    BankAccount(std::string fullname, std::string id, int balance);
public:
    Result<int> withdrawAt(AtmMachine& atm, int amount);
};

Result<int> BankAccount::withdrawAt(AtmMachine& atm, int amount) {
    Result<int> result;
   
    // 1. Tien rut phai la boi so cua 50.000
    // 3. Atm con du tien
    Result<int> validator = atm.canWithdraw(amount);
    if (validator.success) {
         // 2. So du sau khi rut >= 50.000 - 310.000
        if (_balance - amount < 50000) {
            result.success = false;
            result.code = 50;
            result.message = std::format(
                "So du toi thieu phai la: {}", 
                MINIMUM_BALANCE);
                return result;
        }
    }
    else {
        result.success = false;
        result.data = 0;
        result.code = validator.code;
        result.message = validator.message;
        return result;
    }

    atm.withdraw(amount);
    _balance -= amount;

    result.success = true;
    result.data = amount;

    return result;
}

int BankAccount::balance() { return _balance; }
BankAccount::BankAccount() {
    _fullname = "";
    _id = "";
    _balance = 0;
}

BankAccount::BankAccount(std::string fullname, std::string id, int balance) {
    _fullname = fullname;
    _id = id;
    _balance = balance;
}



int main()
{
    // 1. Nếu có truy cập màn hình / bàn phím => sửa lỗi
    // 2. Throw cho caller xử lí
    // 3. Eat exception
    // 4. bỏ
    //Array<std::string> a;
    //a.push_back("He");
    //a.push_back("who");
    //a.push_back("laughes");
    //a.push_back("last");
    //a.push_back("laughes");
    //a.push_back("best");

    //for (int i = 0; i < a.size(); i++) {
    //    std::cout << a.getAt(i) << " ";
    //}
    //std::cout << "\n";

    //Array<double> b; // generics
    //b.push_back(1.1);
    //b.push_back(1.7);
    //b.push_back(2.9);
    //b.push_back(3.3);
    //b.push_back(12);
    //b.push_back(11.5);

    //for (int i = 0; i < b.size(); i++) {
    //    std::cout << b.getAt(i) << " ";
    //}
    // ==============================================================

    // Result(bool success, int data, int code, string message)
    AtmMachine atm("227 Nguyen Van Cu", 50000000);
    BankAccount account("Tran Van Long", "77126785", 470000);
    Result<int> result = account.withdrawAt(atm, 350000);
    if (result.success) { // 300.000
        std::cout << "Rut tien thanh cong cho so tien:" << result.data
            << ". So du con lai : " << account.balance();
    }   
    else {
        // 1. Tien rut phai la boi so cua 50.000 - 310.000
        // 2. So du sau khi rut >= 50.000 - 310.000
        // 3. May ATM khong the tra du tien - 200.000
        std::cout << "Khong the rut tien. Li do:"
            << result.message;
    }
}
