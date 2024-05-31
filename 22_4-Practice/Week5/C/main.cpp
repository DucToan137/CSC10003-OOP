//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <cmath>
//#include<string>
//#include<iomanip>
//#include<functional>
//
////class IntegersTextProvider {
////public:
////    static std::vector<int> read(const std::string& filename) {
////        std::vector<int> integers;
////        std::ifstream file(filename);
////        if (file.is_open()) {
////            int num;
////            file >> num;
////            while (file >> num) {
////                integers.push_back(num);
////            }
////            file.close();
////        }
////        else {
////            std::cerr << "Unable to open file: " << filename << std::endl;
////        }
////        return integers;
////    }
////};
////
////class Integer {
////public:
////    static int parse(const std::string& info) {
////        return std::stoi(info);
////    }
////};
////
////bool isOdd(int num) {
////    return num % 2 != 0;
////}
////
////bool isEven(int num) {
////    return num % 2 == 0;
////}
////
////bool isPrime(int num) {
////    if (num <= 1) return false;
////    if (num == 2) return true;
////    if (num % 2 == 0) return false;
////    for (int i = 3; i <= sqrt(num); i += 2) {
////        if (num % i == 0) return false;
////    }
////    return true;
////}
////
////bool isPalindrome(int num) {
////    int reversed = 0;
////    int original = num;
////    while (num > 0) {
////        int digit = num % 10;
////        reversed = reversed * 10 + digit;
////        num /= 10;
////    }
////    return original == reversed;
////}
////
////bool isSquare(int num) {
////    int sqrtNum = sqrt(num);
////    return sqrtNum * sqrtNum == num;
////}
////
////bool isPerfect(int num) {
////    int sum = 1; // Start with 1 because every number is divisible by 1
////    for (int i = 2; i * i <= num; i++) {
////        if (num % i == 0) {
////            sum += i;
////            if (i != num / i) {
////                sum += num / i;
////            }
////        }
////    }
////    return sum == num;
////}
////
////int main() {
////    const std::string filename = "input.txt";
////    std::cout << "Working with integer arrays from text files\n\n";
////
////    std::cout << "Reading data from " << filename << ".\n";
////
////    std::vector<int> numbers = IntegersTextProvider::read(filename);
////    int count = numbers.size();
////    std::cout << "Expected to find " << count << " numbers.\n\n";
////
////    std::cout << "Found " << numbers.size() << " numbers: ";
////    for (size_t i = 0; i < numbers.size(); ++i) {
////        std::cout << numbers[i];
////        if (i != numbers.size() - 1)
////            std::cout << ", ";
////    }
////    std::cout << std::endl;
////
////    std::vector<int> oddNumbers, evenNumbers, primeNumbers, palindromicNumbers, squareNumbers, perfectNumbers;
////    int sum = 0;
////    double average = 0.0;
////    int min = numbers[0];
////    int max = numbers[0];
////
////    for (int num : numbers) {
////        if (num < min) min = num;
////        if (num > max) max = num;
////        sum += num;
////        if (isOdd(num)) oddNumbers.push_back(num);
////        if (isEven(num)) evenNumbers.push_back(num);
////        if (isPrime(num)) primeNumbers.push_back(num);
////        if (isPalindrome(num)) palindromicNumbers.push_back(num);
////        if (isSquare(num)) squareNumbers.push_back(num);
////        if (isPerfect(num)) perfectNumbers.push_back(num);
////    }
////
////    average = static_cast<double>(sum) / count;
////
////    std::cout << "Found " << oddNumbers.size() << " odd numbers: ";
////    for (size_t i = 0; i < oddNumbers.size(); ++i) {
////        std::cout << oddNumbers[i];
////        if (i != oddNumbers.size() - 1)
////            std::cout << ", ";
////    }
////    std::cout << std::endl;
////
////    std::cout << "Found " << evenNumbers.size() << " even numbers: ";
////    for (size_t i = 0; i < evenNumbers.size(); ++i) {
////        std::cout << evenNumbers[i];
////        if (i != evenNumbers.size() - 1)
////            std::cout << ", ";
////    }
////    std::cout << std::endl;
////
////    std::cout << "Found " << palindromicNumbers.size() << " palindromic numbers: ";
////    for (size_t i = 0; i < palindromicNumbers.size(); ++i) {
////        std::cout << palindromicNumbers[i];
////        if (i != palindromicNumbers.size() - 1)
////            std::cout << ", ";
////    }
////    std::cout << std::endl;
////
////    std::cout << "Found " << primeNumbers.size() << " prime numbers: ";
////    for (size_t i = 0; i < primeNumbers.size(); ++i) {
////        std::cout << primeNumbers[i];
////        if (i != primeNumbers.size() - 1)
////            std::cout << ", ";
////    }
////    std::cout << std::endl;
////
////    
////
////    std::cout << "Found " << squareNumbers.size() << " square numbers: ";
////    for (int num : squareNumbers) {
////        std::cout << " " << num;
////    }
////    std::cout << std::endl;
////
////    std::cout << "Found " << perfectNumbers.size() << " perfect numbers: ";
////    for (int num : perfectNumbers) {
////        std::cout << " " << num;
////    }
////    std::cout << std::endl;
////
////    std::cout << "Minimum value: " << min << std::endl;
////    std::cout << "Maximum value: " << max << std::endl;
////    std::cout << "Average value: " << std::fixed << std::setprecision(1) << average << std::endl;
////    std::cout << "Sum of all numbers: " << sum << std::endl;
////
////    std::cout << "\nProgram is exiting. Press enter to quit...";
////   // std::cin.ignore(); // Wait for user input before closing the console
////    return 0;
////}
////
//
////#include <bits/stdc++.h>
//
//class Integer {
//public:
//	static int parse(std::string info);
//	int assign(std::ifstream& input);
//};
//
//class IntegersTextProvider {
//public:
//	static std::vector<int> read(std::string filename);
//};
//
//class IntegerArray {
//private:
//	std::vector<int> _intArray;
//
//public:
//	IntegerArray();
//	IntegerArray(std::vector<int> intArray);
//	std::vector<int> getNumbers();
//	void setNumbers(std::vector<int> intArray);
//	bool isOdd(int number);
//	bool isEven(int number);
//	bool isPalindromic(int number);
//	bool isPrime(int number);
//	bool isSquare(int number);
//	bool isPerfect(int number);
//	std::vector<int> getCustomedNumbers(std::function<bool(int)> checkFunc);
//	int getMinimumValue();
//	int getMaximumValue();
//	double getAverageValue();
//	long long getSum();
//	void printArray(std::vector<int> arr);
//	void outputPreArray(std::string custom, std::vector<int> customArray);
//	void outputArray(std::string custom);
//	void outputValue(std::string custom);
//	void outputSum();
//};
//
//int Integer::parse(std::string info) {
//	int number = 0;
//	try {
//		number = stoi(info);
//	}
//	catch (std::exception ex) {
//		return -1;
//	}
//
//	return number;
//}
//
//int Integer::assign(std::ifstream& input) {
//	std::string stringBuffer;
//	input >> stringBuffer;
//	return this->parse(stringBuffer);
//}
//
//std::vector<int> IntegersTextProvider::read(std::string filename) {
//	std::ifstream input(filename);
//	if (input.fail()) {
//		return { };
//	}
//
//	Integer intBuffer;
//	int n = intBuffer.assign(input);
//	std::cout << "Reading data from " << filename << ".\n";
//	std::cout << "Expected to find " << n << " numbers.\n\n";
//
//	std::vector<int> intArr(n);
//	for (int i = 0; i < n; ++i) {
//		intArr[i] = intBuffer.assign(input);
//	}
//
//	return intArr;
//}
//
//IntegerArray::IntegerArray() {
//	this->_intArray = { };
//}
//
//IntegerArray::IntegerArray(std::vector<int> intArray) {
//	this->_intArray = intArray;
//}
//
//std::vector<int> IntegerArray::getNumbers() {
//	return this->_intArray;
//}
//
//void IntegerArray::setNumbers(std::vector<int> intArray) {
//	this->_intArray = intArray;
//}
//
//bool IntegerArray::isOdd(int number) {
//	return { number % 2 == 1 };
//}
//
//bool IntegerArray::isEven(int number) {
//	return { number % 2 == 0 };
//}
//
//bool IntegerArray::isPalindromic(int number) {
//	std::string stringNumber = std::to_string(number);
//	int stringSize = stringNumber.size();
//	for (int j = 0; j < stringSize; ++j) {
//		if (stringNumber[j] != stringNumber[stringSize - 1 - j]) {
//			return false;
//		}
//	}
//	return true;
//}
//
//bool IntegerArray::isPrime(int number) {
//	if (number < 2) {
//		return false;
//	}
//	else {
//		for (int j = 2; j <= sqrt(number); ++j) {
//			if (number % j == 0) {
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//bool IntegerArray::isSquare(int number) {
//	int squareRoot = sqrt(number);
//	return { squareRoot * squareRoot == number };
//}
//
//bool IntegerArray::isPerfect(int number) {
//	if (number <= 1) return false;
//
//	bool isSquare = this->isSquare(number);
//	long long sum = 1;
//	for (int j = 2; j <= sqrt(number); ++j) {
//		if (number % j == 0) {
//			sum += j + number / j;
//		}
//	}
//	if (isSquare) sum -= static_cast<long long>(sqrt(number));
//
//
//	if (static_cast<int>(sum) == number) {
//		return true;
//	}
//	return false;
//}
//
//std::vector<int> IntegerArray::getCustomedNumbers(std::function<bool(int)> checkFunc) {
//	std::vector<int> resultArray;
//
//	for (int i = 0; i < this->_intArray.size(); ++i) {
//		if (checkFunc(this->_intArray[i])) {
//			resultArray.push_back(this->_intArray[i]);
//		}
//	}
//
//	return resultArray;
//}
//
//void IntegerArray::printArray(std::vector<int> arr) {
//	int size = arr.size();
//	for (int i = 0; i < size; ++i) {
//		if (i != size - 1) {
//			std::cout << arr[i] << ", ";
//		}
//		else {
//			std::cout << arr[i] << "\n";
//		}
//	}
//}
//
//void IntegerArray::outputArray(std::string custom) {
//	std::vector<int> bufferArray;
//	if (custom == "") bufferArray = this->getNumbers();
//	if (custom == "odd") bufferArray = this->getCustomedNumbers(std::function<bool(int)>([this](int number) { return this->isOdd(number); }));
//	if (custom == "even") bufferArray = this->getCustomedNumbers(std::function<bool(int)>([this](int number) { return this->isEven(number); }));
//	if (custom == "palindromic") bufferArray = this->getCustomedNumbers(std::function<bool(int)>([this](int number) { return this->isPalindromic(number); }));
//	if (custom == "prime") bufferArray = this->getCustomedNumbers(std::function<bool(int)>([this](int number) { return this->isPrime(number); }));
//	if (custom == "square") bufferArray = this->getCustomedNumbers(std::function<bool(int)>([this](int number) { return this->isSquare(number); }));
//	if (custom == "perfect") bufferArray = this->getCustomedNumbers(std::function<bool(int)>([this](int number) { return this->isPerfect(number); }));
//	this->outputPreArray(custom, bufferArray);
//	bufferArray.erase(bufferArray.begin(), bufferArray.end());
//}
//
//int IntegerArray::getMinimumValue() {
//	if (this->_intArray.size() == 0) {
//		return -1;
//	}
//	int result = this->_intArray[0];
//	for (int i = 1; i < this->_intArray.size(); ++i) {
//		if (this->_intArray[i] < result) {
//			result = this->_intArray[i];
//		}
//	}
//	return result;
//}
//
//int IntegerArray::getMaximumValue() {
//	if (this->_intArray.size() == 0) {
//		return -1;
//	}
//	int result = this->_intArray[0];
//	for (int i = 1; i < this->_intArray.size(); ++i) {
//		if (this->_intArray[i] > result) {
//			result = this->_intArray[i];
//		}
//	}
//	return result;
//}
//
//double IntegerArray::getAverageValue() {
//	if (this->_intArray.size() == 0) {
//		return 0;
//	}
//	return static_cast<double>(this->getSum()) / this->_intArray.size();
//}
//
//void IntegerArray::outputValue(std::string custom) {
//	std::cout << custom << " value: ";
//	if (custom == "Minimum") std::cout << this->getMinimumValue();
//	if (custom == "Maximum") std::cout << this->getMaximumValue();
//	if (custom == "Average") std::cout << std::fixed << std::setprecision(1) << this->getAverageValue();
//	std::cout << "\n";
//}
//
//long long IntegerArray::getSum() {
//	int result = 0;
//	for (int i = 0; i < this->_intArray.size(); ++i) {
//		result += static_cast<long long>(this->_intArray[i]);
//	}
//	return result;
//}
//
//void IntegerArray::outputSum() {
//	std::cout << "Sum of all numbers: " << this->getSum() << "\n";
//}
//
//void IntegerArray::outputPreArray(std::string custom, std::vector<int> customArray) {
//	bool defaultArray = false;
//	int size = 0;
//	if (custom == "") {
//		customArray = _intArray;
//		defaultArray = true;
//	}
//	size = customArray.size();
//	int arrayStatus = size - 1;
//	if (arrayStatus > 1) arrayStatus = 1;
//
//	std::cout << "Found " << size;
//	if (custom != "") std::cout << " ";
//	std::cout << custom << " numbers: ";
//	this->printArray(customArray);
//	if (size == 0) std::cout << "\n";
//}
//
//int main() {
//	std::cout << "Working with integer arrays from text files\n\n";
//
//	std::string defaultReadFile = "input.txt";
//	IntegersTextProvider intText;
//	IntegerArray intArr(intText.read(defaultReadFile));
//	if (intArr.getNumbers().size() == 0) {
//		std::cout << "Khong the mo file de doc.";
//		return 1;
//	}
//
//	intArr.outputArray("");
//	intArr.outputArray("odd");
//	intArr.outputArray("even");
//	intArr.outputArray("palindromic");
//	intArr.outputArray("prime");
//	intArr.outputArray("square");
//	intArr.outputArray("perfect");
//
//	intArr.outputValue("Minimum");
//	intArr.outputValue("Maximum");
//	intArr.outputValue("Average");
//	intArr.outputSum();
//
//
//	std::cout << "\nProgram is exiting. Press enter to quit...";
//	//_getch();
//	return 0;
//}

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include<string>

class Integer {
public:
    static int parse(std::string info);
    int assign(std::ifstream& input);
};

class IntegersTextProvider {
public:
    static std::vector<int> read(std::string filename);
};

class IntegerArray {
private:
    std::vector<int> _intArray;

public:
    IntegerArray();
    IntegerArray(std::vector<int> intArray);
    std::vector<int> getNumbers();
    void setNumbers(std::vector<int> intArray);
    static bool isOdd(int number);
    static bool isEven(int number);
    static bool isPalindromic(int number);
    static bool isPrime(int number);
    static bool isSquare(int number);
    static bool isPerfect(int number);
    std::vector<int> getCustomedNumbers(bool (*checkFunc)(int));
    int getMinimumValue();
    int getMaximumValue();
    double getAverageValue();
    long long getSum();
    void printArray(std::vector<int> arr);
    void outputPreArray(std::string custom, std::vector<int> customArray);
    void outputArray(std::string custom);
    void outputValue(std::string custom);
    void outputSum();
};

int Integer::parse(std::string info) {
    int number = 0;
    try {
        number = std::stoi(info);
    }
    catch (std::exception ex) {
        return -1;
    }

    return number;
}

int Integer::assign(std::ifstream& input) {
    std::string stringBuffer;
    input >> stringBuffer;
    return this->parse(stringBuffer);
}

std::vector<int> IntegersTextProvider::read(std::string filename) {
    std::ifstream input(filename);
    if (input.fail()) {
        return {};
    }

    Integer intBuffer;
    int n = intBuffer.assign(input);
    std::cout << "Reading data from " << filename << ".\n";
    std::cout << "Expected to find " << n << " numbers.\n\n";

    std::vector<int> intArr(n);
    for (int i = 0; i < n; ++i) {
        intArr[i] = intBuffer.assign(input);
    }

    return intArr;
}

IntegerArray::IntegerArray() {
    this->_intArray = {};
}

IntegerArray::IntegerArray(std::vector<int> intArray) {
    this->_intArray = intArray;
}

std::vector<int> IntegerArray::getNumbers() {
    return this->_intArray;
}

void IntegerArray::setNumbers(std::vector<int> intArray) {
    this->_intArray = intArray;
}

bool IntegerArray::isOdd(int number) {
    return { number % 2 == 1 };
}

bool IntegerArray::isEven(int number) {
    return { number % 2 == 0 };
}

bool IntegerArray::isPalindromic(int number) {
    std::string stringNumber = std::to_string(number);
    int stringSize = stringNumber.size();
    for (int j = 0; j < stringSize; ++j) {
        if (stringNumber[j] != stringNumber[stringSize - 1 - j]) {
            return false;
        }
    }
    return true;
}

bool IntegerArray::isPrime(int number) {
    if (number < 2) {
        return false;
    }
    else {
        for (int j = 2; j <= sqrt(number); ++j) {
            if (number % j == 0) {
                return false;
            }
        }
    }
    return true;
}

bool IntegerArray::isSquare(int number) {
    int squareRoot = sqrt(number);
    return { squareRoot * squareRoot == number };
}

bool IntegerArray::isPerfect(int number) {
    if (number <= 1) return false;

    bool isSquare = IntegerArray::isSquare(number);
    long long sum = 1;
    for (int j = 2; j <= sqrt(number); ++j) {
        if (number % j == 0) {
            sum += j + number / j;
        }
    }
    if (isSquare) sum -= static_cast<long long>(sqrt(number));


    if (static_cast<int>(sum) == number) {
        return true;
    }
    return false;
}

std::vector<int> IntegerArray::getCustomedNumbers(bool (*checkFunc)(int)) {
    std::vector<int> resultArray;

    for (int i = 0; i < this->_intArray.size(); ++i) {
        if (checkFunc(this->_intArray[i])) {
            resultArray.push_back(this->_intArray[i]);
        }
    }

    return resultArray;
}

void IntegerArray::printArray(std::vector<int> arr) {
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        if (i != size - 1) {
            std::cout << arr[i] << ", ";
        }
        else {
            std::cout << arr[i] << "\n";
        }
    }
}

void IntegerArray::outputArray(std::string custom) {
    std::vector<int> bufferArray;
    if (custom == "") bufferArray = this->getNumbers();
    else if (custom == "odd") bufferArray = this->getCustomedNumbers(&IntegerArray::isOdd);
    else if (custom == "even") bufferArray = this->getCustomedNumbers(&IntegerArray::isEven);
    else if (custom == "palindromic") bufferArray = this->getCustomedNumbers(&IntegerArray::isPalindromic);
    else if (custom == "prime") bufferArray = this->getCustomedNumbers(&IntegerArray::isPrime);
    else if (custom == "square") bufferArray = this->getCustomedNumbers(&IntegerArray::isSquare);
    else if (custom == "perfect") bufferArray = this->getCustomedNumbers(&IntegerArray::isPerfect);
    outputPreArray(custom, bufferArray);
}

int IntegerArray::getMinimumValue() {
    if (this->_intArray.size() == 0) {
        return -1;
    }
    int result = this->_intArray[0];
    for (int i = 1; i < this->_intArray.size(); ++i) {
        if (this->_intArray[i] < result) {
            result = this->_intArray[i];
        }
    }
    return result;
}

int IntegerArray::getMaximumValue() {
    if (this->_intArray.size() == 0) {
        return -1;
    }
    int result = this->_intArray[0];
    for (int i = 1; i < this->_intArray.size(); ++i) {
        if (this->_intArray[i] > result) {
            result = this->_intArray[i];
        }
    }
    return result;
}

double IntegerArray::getAverageValue() {
    if (this->_intArray.size() == 0) {
        return 0;
    }
    return static_cast<double>(this->getSum()) / this->_intArray.size();
}

void IntegerArray::outputValue(std::string custom) {
    std::cout << custom << " value: ";
    if (custom == "Minimum") std::cout << this->getMinimumValue();
    if (custom == "Maximum") std::cout << this->getMaximumValue();
    if (custom == "Average") std::cout << std::fixed << std::setprecision(1) << this->getAverageValue();
    std::cout << "\n";
}

long long IntegerArray::getSum() {
    int result = 0;
    for (int i = 0; i < this->_intArray.size(); ++i) {
        result += static_cast<long long>(this->_intArray[i]);
    }
    return result;
}

void IntegerArray::outputSum() {
    std::cout << "Sum of all numbers: " << this->getSum() << "\n";
}

void IntegerArray::outputPreArray(std::string custom, std::vector<int> customArray) {
    bool defaultArray = false;
    int size = 0;
    if (custom == "") {
        customArray = _intArray;
        defaultArray = true;
    }
    size = customArray.size();
    int arrayStatus = size - 1;
    if (arrayStatus > 1) arrayStatus = 1;

    std::cout << "Found " << size;
    if (custom != "") std::cout << " ";
    std::cout << custom << " numbers: ";
    this->printArray(customArray);
    if (size == 0) std::cout << "\n";
}

int main() {
    std::cout << "Working with integer arrays from text files\n\n";

    std::string defaultReadFile = "input.txt";
    IntegersTextProvider intText;
    IntegerArray intArr(intText.read(defaultReadFile));
    if (intArr.getNumbers().size() == 0) {
        std::cout << "Khong the mo file de doc.";
        return 1;
    }

    intArr.outputArray("");
    intArr.outputArray("odd");
    intArr.outputArray("even");
    intArr.outputArray("palindromic");
    intArr.outputArray("prime");
    intArr.outputArray("square");
    intArr.outputArray("perfect");

    intArr.outputValue("Minimum");
    intArr.outputValue("Maximum");
    intArr.outputValue("Average");
    intArr.outputSum();


    std::cout << "\nProgram is exiting. Press enter to quit...";
    return 0;
}