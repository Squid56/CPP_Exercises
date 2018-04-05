#include <gmock\gmock.h>
#include <gtest\gtest.h>
#include <iostream>

#define DELETE(ptr) {if (ptr) {delete ptr; ptr = 0;}}

class A{
public:
	~A(){
		std::cout << "A destructed" << std::endl;
	}

	void foo()
	{
		std::cout << "foo. A" << std::endl;
	}
};


class C {
public:
	C() {
		name = new std::string("Geremy");
	}

	virtual ~C(){
		DELETE(name);
	}

	void print(){
		std::cout << "name is: " << *name << std::endl;
	}
private:
	std::string* name;
};


class B : public A{
public:
	B():A(){
		name = "Geremy";
	}

	void takeCref( C &tmpC )
	{
		tmpC.print();
	}

	void takeCptr( C *tmpC )
	{
		tmpC->print();
	}

	void takeCval( C tmp )
	{
		tmp.print();
	}

	void foo()
	{
		std::cout << "foo. B" << std::endl;
	}

	~B(){
		std::cout << "B destructed" << std::endl;
	}
private:
	std::string name;
};

/*
Question: 1
Explain what happens in steps 1, 2 and 3. What will be the expected output for these steps?
Do you see any problems with the code? Fix the program if there are any problems.

Question: 2
Explain what should happen in step 4. Fix the program if there are any problems.
*/



int main(int argc, char* argv[])
{
	std::cout << std::endl << std::endl << "Problem part A" << std::endl;
	C c;
	B b;
	// step 1
	b.takeCval(c);

	// step 2
	b.takeCptr(&c);

	// step 3
	b.takeCref(c);

	std::cout << "Problem part B" << std::endl;
	A *a = new B();
	// step 4
	a->foo();
	delete a;


}