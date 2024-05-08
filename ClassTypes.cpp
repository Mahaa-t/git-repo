// Concrete class
class A {
public:
	A() {}
};

// Abstract class
class A {
protected :
	A() {}
};

// Abstract class
// Combination of both implemented and non implemented methods
class A {
public:
	void test() {}
	virtual void task() = 0;
};

// Interface
class A {
public:
	virtual void test() = 0;
	virtual void task() = 0;
};

// Concrete
class A {
public:
	virtual void test() {}
};