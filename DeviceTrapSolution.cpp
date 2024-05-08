#include <iostream>
#include <string>
using namespace std;

// Interface only for contract
class IPrint {
public:
	virtual void print(string content) = 0;
};

class IScan {
public:
	virtual void scan(string content) = 0;
};

// Reused abstract class and cannot be instantiated
class Device {
private:
	string name;
	string model;
	string version;
protected:
	Device(string nameArg, string modelArg, string versionArg) :name{ nameArg }, model{ modelArg }, version{ versionArg } {
		cout << "Device created" << endl;
	}
	~Device() {
		cout << "Device deleted" << endl;
	}
};

class Printer :public Device, public IPrint {
public:
	Printer() : Device{ "","","" } {
		cout << "Printer created" << endl;
	}
	~Printer() {
		cout << "Printer deleted" << endl;
	}
	void print(string content) {
		cout << "Print " << content << endl;
	}
};

class Scanner : public Device, public IScan {
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

class PrintScanner: public Device, public IPrint, public IScan {
	Printer printerObj;
	Scanner scannerObj;
public:
	void print(string content) {
		this->printerObj.print(content);
	}
	void scan(string content) {
		this->scannerObj.scan(content);
	}
	PrintScanner(string n, string m, string v) : Device{ n, m, v } {
		cout << "PrintScanner created" << endl;
	}
	~PrintScanner() {
		cout << "PrintScanner deleted" << endl;
	}
};

class TaskManager {
public:
	void invokePrintTask(IPrint* printerPtr, string content) {
		printerPtr->print(content);
	}
	void invokeScanTask(IScan* scannerPtr, string content) {
		scannerPtr->scan(content);
	}
};

int main() {
	Printer hpPrinter;
	Scanner hpScanner;
	PrintScanner hpPrintScanner("", "", "");
	TaskManager taskMgr;

	taskMgr.invokePrintTask(&hpPrinter, "doc.pdf");
	taskMgr.invokeScanTask(&hpScanner, "doc.pdf");

	taskMgr.invokePrintTask(&hpPrintScanner, "doc.pdf");
	taskMgr.invokeScanTask(&hpPrintScanner, "doc.pdf");
}