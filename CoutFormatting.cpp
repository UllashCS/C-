#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        cout << showbase << nouppercase << hex << left << static_cast<unsigned long> (A) << endl;

        cout.fill('_');
        cout.width(15);
        cout.precision(2);
        cout << fixed << right << showpos << B << endl;

        cout.precision(9);
        cout << noshowpos;
        cout << uppercase << scientific << C << endl;
	}
	return 0;

}