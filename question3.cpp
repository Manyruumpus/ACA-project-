// question 3

#include <bits/stdc++.h>

using namespace std;

int grand_sum(vector<int> &arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    return sum;
}

int opr(vector<int> &arr, int q) {
	// as doing the given opr for the one element will be removing it 
	//from arr and then adding that number minus that number which equals to zero and then sum will be equal to zero 
	if(arr.size()==1) return 0;
	// if q=0 then we dont need th change the arr and directly print the sum of the arr
	// grand sum is function to find the sum of all element of the arr
	else if (q == 0) return grand_sum(arr);
	// now for other 
	// find the max and min element of the array using max_element function of algorithm library with complexity O(n)
	// then remove them using erase of stl and adding the diff of them and reduce q by ine and then again calling the 
	// function for a=modified arr and q
    else {
        int max_val = *max_element(arr.begin(), arr.end());
        int min_val = *min_element(arr.begin(), arr.end());
        int diff = max_val - min_val;
        arr.erase(remove(arr.begin(), arr.end(), max_val), arr.end());
        arr.erase(remove(arr.begin(), arr.end(), min_val), arr.end());
        arr.push_back(diff);
        q--;
        return opr(arr, q);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    // 2 vector to store the data 
    vector<int> arr(N);
    vector<int> que(Q);
    // taking input 
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < Q; i++) {	 
        cin >> que[i];
    }
    // applying the opr for each member of que
    for (int i = 0; i < Q; i++) {
    	//call for opr function
        cout << opr(arr, que[i]) << " ";
    }
    return 0;
    
    // overall complexity in O(n^2) , this is the best I can get 
    // this is a optional question apart from 4 which u asked to submit which are with required complexity 
}
