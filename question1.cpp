// question 1
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        // making a max heap to access the max only
        priority_queue<int> book;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            book.push(x);
        }
        
        int cost = 0;
        int ans;
        // check for the max first element of heap so that it if it satisfy the
//		condition remove that and add it again after subracting one in it then 
//		repeating the same task till stopping condition is achived 
        while(cost <= k) {
            ans = book.top();
            cost += ans;
            book.pop();
            book.push(ans - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
//// time complexity of the code due to priorirty queue is log n 
//and by the for loop it O(n)
//hence the final time complexity of the code is O(nlog(n))
