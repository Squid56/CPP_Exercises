#include <gmock\gmock.h>
#include <gtest\gtest.h>
#include <iostream>

#define DELETE(ptr) {if (ptr) {delete ptr; ptr = 0;}}

class A{
public:
	~A(){
		std::cout << "A destructed" << std::endl;
	}

	virtual void foo()
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
		std::cout << "C destructed" << std::endl;
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

	void takeCval( C& tmp )
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

	// step 1 - We pass the object instance here - if we don't use the object instance ref,
	// the destructor gets called on the object when it leaves scope and the outside reference becomes invalid
	// causing an exception
	// The name variable of the class C object is printed
	b.takeCval(c);

	// step 2 - Here we pass the pointer to object c and the function in b uses pointer notation to call class C's print function
	b.takeCptr(&c);

	// step 3 - Here we pass c by reference, using the function argument to specify this
	// we can use standard dot notation to call C's method
	b.takeCref(c);

	std::cout << "Problem part B" << std::endl;
	A *a = new B();
	// step 4 - 
	// Since Class B inherits from A, the Class A version of the foo() function gets called since we declared 'a' as type A
	// even as we instantiate with Class B - this is very confusing behavior and should be avoided.  If the intent is to call
	// B's foo() function, the following would be the correct method - note we have to turn A into a polymorphic class to
	// achieve this (by adding the virtual keyword to foo())
	dynamic_cast<B*>(a)->foo(); // - ICK!
	delete a;



}