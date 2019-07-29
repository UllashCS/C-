#include <iostream>
#include <thread>
#include <memory>
#include <mutex>

using namespace std;

class ThreadExample {
	public:
	void Start ();
	static void Thread1 ();
	static void Thread2 ();
	
	private:
	static mutex mu;
};
