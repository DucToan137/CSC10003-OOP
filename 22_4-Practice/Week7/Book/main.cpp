#include<iostream>
#include"Book.h"

int main() {
	Book a("The Catcher in the Rye", "J.D. Salinger", "978-3-16-148413-1");
	a.borrowBook();

	a.displayBook();
}