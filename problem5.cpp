// question 5 
// the code is pretty much self explanatory
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int sum = 0;
        int k = 0;
        for (char c : s) {
            sum += c - '0';
            k++;
        }
        v[i] = {sum, k};
    }
// stroing the sum of string and there lenght manually and then sortig them in the basis of sum 
    sort(v.begin(), v.end());

    int counter = 0;
    int left = 0, right = n - 1;
    // now using sliding window approach to solve this 
    while (left < right) {
        int curr_sum = v[left].first + v[right].first;
        int curr_length = v[left].second + v[right].second;
        if (curr_sum == 50 && curr_length == 12) {
            counter++;
            left++;
            right--;
        } else if (curr_sum < 50) {
            left++;
        } else {
            right--;
        }
    }

    cout << counter << endl;

    return 0;
}

//complexity = O(nlog(n)) of sort function and rest on O(n)
