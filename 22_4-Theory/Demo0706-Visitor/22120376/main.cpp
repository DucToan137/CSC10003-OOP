#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Circuit {
public:
	virtual double r() = 0;
};

// mạch tuần tự
class SimpleCircuit : public Circuit {
private:
	double _r;
public:
	double r() {
		return _r;
	}

	SimpleCircuit(double r) {
		_r = r;
	}

};

// mạch phức
class ComplexCircuit : public Circuit {
protected:
	vector<Circuit*> _subSircuit;
public:
	void add(Circuit *c) {
		_subSircuit.push_back(c);
	}

	double r() {
		return 0;
	}
};


// mạch song song
class ParallelCircuit : public ComplexCircuit {
public:
	double r() {
		double result = 0;

		for (int i = 0; i < _subSircuit.size(); i++) {
			result += 1 / _subSircuit[i]->r();
		}

		result = 1 / result;

		return result;
	}
};

// mạch nối tiếp
class SequentialCircuit : public ComplexCircuit {
public:
	double r() {
		double result = 0;

		for (int i = 0; i < _subSircuit.size(); i++) {
			result += _subSircuit[i]->r();
		}

		

		return result;
	}
};

int main() {

	//////////////CAU 1////////////////

	/*ComplexCircuit * final = new SequentialCircuit();
	final->add(new SimpleCircuit(4));

	ComplexCircuit* temp = new ParallelCircuit();

	ComplexCircuit* r23 = new SequentialCircuit();
	r23->add(new SimpleCircuit(4));
	r23->add(new SimpleCircuit(6));

	temp->add(r23);
	temp->add(new SimpleCircuit(10));

	final->add(temp);

	final->add(new SimpleCircuit(3));

	cout << final->r() << endl;*/

	//////////////CAU 2////////////////

	ComplexCircuit * final = new SequentialCircuit();
	final->add(new SimpleCircuit(2.4));

	

	ComplexCircuit * r24 = new ParallelCircuit();
	r24->add(new SimpleCircuit(14));
	r24->add(new SimpleCircuit(6));

	ComplexCircuit* r35 = new ParallelCircuit();
	r35->add(new SimpleCircuit(4));
	r35->add(new SimpleCircuit(6));

	final->add(r24);
	final->add(r35);

	cout << final->r() << "\n";

	return 0;
}