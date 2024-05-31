//#include<iostream>
//#include"IntegersTextProvider.h"
//
//int main() {
//
//	std::cout << "Working with integer arrays from text files\n\n" ;
//	IntegersTextProvider arr;
//	std::string filename = "input.txt";
//	std::vector<int>a = arr.read(filename);
//
//	std::cout << "Reading data from input.txt.\n";
//	std::cout << "Expected to find " << a.size() << " numbers.\n\n";
//	
//	
//	arr.Xuat(a);
//
//	std::cout << "Program is exiting. Press enter to quit...\n";
//
//	/*std::string x1 = "abcd";
//	std::string x2(x1.rbegin(), x1.rend());
//
//	std::cout << x2;*/
//
//	return 0;
//}


//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <cmath>
//#include<string>
//#include<iomanip>
//
//class Integer {
//private:
//    int _num;
//
//public:
//    void setNum(int val) { _num = val; }
//    int getNum() const { return _num; }
//
//    bool isOdd() const { return _num % 2 != 0; }
//    bool isPalindrome() const;
//    bool isPrime() const;
//    bool isSquare() const;
//    bool isPerfect() const;
//};
//
//bool Integer::isPalindrome() const {
//    std::string numStr = std::to_string(_num);
//    int i = 0, j = numStr.length() - 1;
//    while (i < j) {
//        if (numStr[i] != numStr[j])
//            return false;
//        ++i;
//        --j;
//    }
//    return true;
//}
//
//bool Integer::isPrime() const {
//    if (_num <= 1)
//        return false;
//    if (_num == 2)
//        return true;
//    if (_num % 2 == 0)
//        return false;
//    int sqrtNum = sqrt(_num);
//    for (int i = 3; i <= sqrtNum; i += 2) {
//        if (_num % i == 0)
//            return false;
//    }
//    return true;
//}
//
//bool Integer::isSquare() const {
//    int sqrtNum = sqrt(_num);
//    return sqrtNum * sqrtNum == _num;
//}
//
//bool Integer::isPerfect() const {
//    if (_num <= 1)
//        return false;
//    int sum = 1;
//    for (int i = 2; i * i <= _num; ++i) {
//        if (_num % i == 0) {
//            sum += i;
//            if (i != _num / i)
//                sum += _num / i;
//        }
//    }
//    return sum == _num;
//}
//
//class IntegersTextProvider {
//public:
//    static std::vector<int> read(const std::string& filename);
//    static void formatOutput(const std::vector<int>& numbers);
//};
//
//std::vector<int> IntegersTextProvider::read(const std::string& filename) {
//    std::ifstream input(filename);
//    if (!input.is_open()) {
//        std::cerr << "Failed to open file: " << filename << std::endl;
//        return {};
//    }
//
//    int num;
//    input >> num;
//    std::vector<int> numbers;
//    while (input >> num)
//        numbers.push_back(num);
//
//    return numbers;
//}
//
//void IntegersTextProvider::formatOutput(const std::vector<int>& numbers) {
//    std::vector<int> odd, even, palindromic, prime, square, perfect;
//
//    int min = numbers[0];
//    int max = numbers[0];
//    long long sum = 0;
//
//    for (int num : numbers) {
//        sum += num;
//        min = std::min(min, num);
//        max = std::max(max, num);
//
//        Integer integer;
//        integer.setNum(num);
//        if (integer.isOdd())
//            odd.push_back(num);
//        else
//            even.push_back(num);
//        if (integer.isPalindrome())
//            palindromic.push_back(num);
//        if (integer.isPrime())
//            prime.push_back(num);
//        if (integer.isSquare())
//            square.push_back(num);
//        if (integer.isPerfect())
//            perfect.push_back(num);
//    }
//
//    std::cout << "Found " << numbers.size() << " numbers: ";
//    for (size_t i = 0; i < numbers.size(); ++i) {
//        std::cout << numbers[i];
//        if (i != numbers.size() - 1)
//            std::cout << ", ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "Found " << odd.size() << " odd numbers: ";
//    for (size_t i = 0; i < odd.size(); ++i) {
//        std::cout << odd[i];
//        if (i != odd.size() - 1)
//            std::cout << ", ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "Found " << even.size() << " even numbers: ";
//    for (size_t i = 0; i < even.size(); ++i) {
//        std::cout << even[i];
//        if (i != even.size() - 1)
//            std::cout << ", ";
//    }std::cout << std::endl;
//
//    std::cout << "Found " << palindromic.size() << " palindromic numbers: ";
//    for (size_t i = 0; i < palindromic.size(); ++i) {
//        std::cout << palindromic[i];
//        if (i != palindromic.size() - 1)
//            std::cout << ", ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "Found " << prime.size() << " prime numbers: ";
//    for (size_t i = 0; i < prime.size(); ++i) {
//        std::cout << prime[i];
//        if (i != prime.size() - 1)
//            std::cout << ", ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "Found " << square.size() << " square numbers: ";
//    for (size_t i = 0; i < square.size(); ++i) {
//        std::cout << square[i];
//        if (i != square.size() - 1)
//            std::cout << ", ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "Found " << perfect.size() << " perfect numbers: ";
//    for (size_t i = 0; i < perfect.size(); ++i) {
//        std::cout << perfect[i];
//        if (i != perfect.size() - 1)
//            std::cout << ", ";
//    }
//    std::cout << std::endl;
//
//    // Similar formatting for palindromic, prime, square, perfect
//
//    std::cout << "Minimum value: " << min << std::endl;
//    std::cout << "Maximum value: " << max << std::endl;
//    std::cout << "Average value: " << std::fixed << std::setprecision(1) << (double)sum / numbers.size() << std::endl;
//    std::cout << "Sum of all numbers: " << sum << std::endl;
//}
//
//int main() {
//    std::cout << "Working with integer arrays from text files\n\n";
//    std::string filename = "input.txt";
//    std::vector<int> numbers = IntegersTextProvider::read(filename);
//    std::cout << "Reading data from " << filename << ".\n";
//    std::cout << "Expected to find " << numbers.size() << " numbers.\n\n";
//    IntegersTextProvider::formatOutput(numbers);
//    std::cout << "Program is exiting. Press enter to quit...\n";
//    return 0;
//} 


#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include<string>

using namespace std;

class IntegersTextProvider {
public:
    static vector<int> read(string filename) {
        vector<int> integers;
        ifstream file(filename);
        int num;
        while (file >> num) {
            integers.push_back(num);
        }
        return integers;
    }
};

class Integer {
public:
    static int parse(string info) {
        return stoi(info);
    }
};

bool isOdd(int num) {
    return num % 2 != 0;
}

bool isEven(int num) {
    return num % 2 == 0;
}

bool isPalindrome(int num) {
    string numStr = to_string(num);
    int len = numStr.length();
    for (int i = 0; i < len / 2; ++i) {
        if (numStr[i] != numStr[len - 1 - i])
            return false;
    }
    return true;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

bool isSquare(int num) {
    int root = sqrt(num);
    return root * root == num;
}

bool isPerfect(int num) {
    int sum = 1;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num)
                sum += num / i;
        }
    }
    return sum == num && num != 1;
}

int main() {
    string filename = "input.txt";
    vector<int> numbers = IntegersTextProvider::read(filename);

    cout << "Found " << numbers.size() << " numbers:";
    for (int num : numbers) {
        cout << " " << num;
    }
    cout << endl;

    int oddCount = 0, evenCount = 0, primeCount = 0;
    int minVal = numbers[0], maxVal = numbers[0], sum = 0;
    for (int num : numbers) {
        if (isOdd(num)) oddCount++;
        if (isEven(num)) evenCount++;
        if (isPrime(num)) primeCount++;

        minVal = min(minVal, num);
        maxVal = max(maxVal, num);
        sum += num;
    }

    cout << "Found " << oddCount << " odd numbers:";
    for (int num : numbers) {
        if (isOdd(num))
            cout << " " << num;
    }
    cout << endl;

    cout << "Found " << evenCount << " even numbers:";
    for (int num : numbers) {
        if (isEven(num))
            cout << " " << num;
    }
    cout << endl;

    cout << "Found " << primeCount << " prime numbers:";
    for (int num : numbers) {
        if (isPrime(num))
            cout << " " << num;
    }
    cout << endl;

    int squareCount = 0, palindromeCount = 0, perfectCount = 0;
    for (int num : numbers) {
        if (isPalindrome(num)) palindromeCount++;
        if (isSquare(num)) squareCount++;
        if (isPerfect(num)) perfectCount++;
    }

    cout << "Found " << palindromeCount << " palindromic numbers." << endl;
    cout << "Found " << squareCount << " square numbers." << endl;
    cout << "Found " << perfectCount << " perfect numbers." << endl;

    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;
    cout << "Average value: " << fixed << setprecision(1) << static_cast<double>(sum) / numbers.size() << endl;
    cout << "Sum of all numbers: " << sum << endl;

    cout << "\nProgram is exiting. Press enter to quit...";
    cin.ignore();
    return 0;
}