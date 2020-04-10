#include <algorithm>
#include <iostream>
#include <deque> 
#include <iterator>
using namespace std;

void printKMax(int arr[], int n, int k){
    //Write your code here.
    deque<unsigned int> dq;
    deque<unsigned int>::const_reverse_iterator itr;
    deque<unsigned int>::const_iterator itmax;
    int maxVal = 0, removedVal = 0;

    for (unsigned int i = 0; i < k  ; i++) {
        dq.push_back(arr[i]);
    }

    itmax = max_element (dq.begin(), dq.end());
    maxVal = *itmax; 
    cout << maxVal << " ";

    for (unsigned int i = k ; i < n; i++) {
        removedVal = dq.front();
        dq.pop_front();
        dq.push_back(arr[i]);
        
        if (arr[i] > maxVal){
            maxVal = arr[i];
        }
        else if ((removedVal == maxVal) && (arr[i] != maxVal)) {
            itmax = max_element (dq.begin(), dq.end());
            maxVal = *itmax; 
        }

        cout << maxVal << " ";
    }
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
