#include<iostream>
#include<vector>
#include"IShape.h"
#include"Rectangle.h"
#include"Circle.h"
#include"IntegerGenerator.h"
#include"IRandomGenerate.h"

using namespace std;

struct {
	int n;
	vector<IShape*> shapes;
} state;


int main() {

	const int min = 6;
	const int max = 12;

	// Config
	vector<IShape*> prototypes = {
		new Rectangle(),
		new Circle()
	};

	state.n = IntegerGenerator::instance()->next(min, max);

	vector<IShape*> a;

	for (int i = 0; i < state.n; i++)
	{
		int index = IntegerGenerator::instance()->next(prototypes.size());

		auto rng = dynamic_cast<IRandomGenerator*>(prototypes[index]);
		IShape* shape = (IShape*)rng->IRandomGenerate();

		a.push_back(shape);
	}

	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i]->toString() << "\n"
			<< "	perimeter: " << a[i]->perimeter() 
			<< ",area: " << a[i]->area() << "\n";
	}

	return 0;
}