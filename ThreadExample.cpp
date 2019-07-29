#include "ThreadExample.hpp"

using namespace std;

mutex ThreadExample::mu;

void ThreadExample::Thread1 () {
	int x;
	while (true) {
		mu.lock ();
		cout << "Thread 1" <<endl;
		cin >> x;
		cout << "Thread 1 -> " << x <<endl;
		mu.unlock ();
		}
}

void ThreadExample::Thread2 () {
	int x;
	while (true) {
		mu.lock ();
		cout << "Thread 2" <<endl;
		cin >> x;
		cout << "Thread 2 -> " << x <<endl;
		mu.unlock ();
		}
}
void ThreadExample::Start () {
	unique_ptr<thread> t1;
	unique_ptr<thread> t2;
	t1.reset (new thread(Thread1));
	t2.reset (new thread(Thread2));
	t1->join();
	t2->join();
}

int main()
{
	ThreadExample Object;
	
	Object.Start ();
	return 0;
}
