//: C05: Handle.h
// Handle classes
#ifdef HANDLE_H
#define HANDLE_H

class Handle {
	struct Cheshire; // Class declaration only
	Cheshire* smile;
	public:
	void initialize();
	void cleanup();
	int read();
	void change(int);
};
#endif // HANDLE_H ///:~
