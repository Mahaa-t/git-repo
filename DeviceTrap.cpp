#include <iostream>
#include <string>
using namespace std;

class Device {
private:
	string name;
	string model;
	string version;
public:
	Device(string nameArg, string modelArg, string versionArg) :name{ nameArg }, model{ modelArg }, version{ versionArg } {
		cout << "Device created" << endl;
	}
	~Device() {
		cout << "Device deleted" << endl;
	}
};

class Printer:virtual public Device {
public:
	Printer() : Device{"","",""} {
		cout << "Printer created" << endl;
	}
	~Printer() {
		cout << "Printer deleted" << endl;
	}
	void print(string content) {
		cout << "Print " << content << endl;
	}
};

class Scanner:virtual public Device {
public:
	Scanner() : Device{ "","","" } {
		cout << "Scanner created" << endl;
	}
	~Scanner() {
		cout << "Scanner deleted" << endl;
	}
	void scan(string content) {
		cout << "Scan " << content << endl;
	}
};

// C++ allows derived class to call the ancestor and not the immediate base class (parent)
// Diamond problem caused by multiple inheritance 
class PrintScanner : public Printer, public Scanner {
public:
	PrintScanner(string n, string m, string v) : Device{ n, m, v }{
		cout << "PrintScanner created" << endl;
	}
	~PrintScanner() {
		cout << "PrintScanner deleted" << endl;
	}
};

class TaskManager {
public:
	void invokePrintTask(Printer* printerPtr, string content) {
		printerPtr->print(content);
	}
	void invokeScanTask(Scanner* scannerPtr, string content) {
		scannerPtr->scan(content);
	}
};

int main() {
	//Printer hpPrinter;
	//Scanner hpScanner;
	PrintScanner hpPrintScanner("","","");
	TaskManager taskMgr;
	//taskMgr.invokePrintTask(&hpPrinter, "doc.pdf");
	//taskMgr.invokeScanTask(&hpScanner, "doc.pdf");
	// Base class pointer can store the address of derived class object
	taskMgr.invokePrintTask(&hpPrintScanner, "doc.pdf");
	taskMgr.invokeScanTask(&hpPrintScanner, "doc.pdf");
}