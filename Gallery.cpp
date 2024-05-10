// Gallery contains media items - images and videos. 
// Every media item is identified by date created and size. 
// Every video has different type - mp4, avi
// Every image has different type - jpeg, png, gif. 
// Media items can be shared thro' different applications. 
// Applications allowed are bluetooth, whatsapp and mailbox. 
// Sharing is possible only thro' one application.

// Step - 1: Identify the objects and assign responsibilities


#include <string>
using namespace std;

class MediaItems {
	string date;
	int size;
};

class Images : public MediaItems {
	enum imageType;
};

class Videos : public MediaItems {
	enum videoType;
};


class Applications {
public:
	void shareViaBluetooth() {

	}
	void shareViaWhatsapp() {

	}
	void shareViaMailbox() {

	}
};

class Gallery {

};

