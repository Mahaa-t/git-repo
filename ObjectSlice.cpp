// Every view should be a base class
// Interface should be named with starting letter "I"

class IEmployee {

public:
	virtual void professional() = 0; // Views / Interface should not have implemenation and hence assigned to 0.
	// Pure virtual method is called as interface in C++. Only pure virtual method can be assigned with 0. And it
	// should not have body written.
	// C++ do not have an interface directly. It is synthesized by using pure virtual methods.
};
class IFamilyMember {
public:
	virtual void casual() = 0;
	virtual void cranky() = 0;
};
// Person fulfills (implements) IEmployee contract and IFamilyMember contract
// This is not mutiple inheritance but implementing multiple interfaces
class Person:public IEmployee, public IFamilyMember {
public:
	void casual() {}
	void professional() {}
	void cranky() {}
};

class OfficeContext {
public:
	void Enter(IEmployee* obj) {// The pointer to the base class can be used to access only the member of the base class
		obj->professional();
	}
};

class FamilyContext {
public:
	void Enter(IFamilyMember* obj) {
		obj->cranky();
		obj->casual();
	}
};

int main_sl() {
	FamilyContext fContext;
	OfficeContext oContext;

	Person tom;
	fContext.Enter(&tom);
	oContext.Enter(&tom);

	Person harry;
	fContext.Enter(&harry);
	oContext.Enter(&harry);
	return 0;
}


