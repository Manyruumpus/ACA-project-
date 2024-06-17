//question 4
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
	int n;int k;
	cin >> n >> k;
	// making a vector of pair of pair that is with 3 part 
	// first will store the indices 
	// second the cost and third the number of oreo
	vector <pair<int , pair<int,int>>> rate(n);
	// taking the input all the three entry 
		for( int i=0;i<n;i++){
			cin >> rate[i].second.first >> rate[i].second.second;
		}
        for( int i=0;i<n;i++){
            rate[i].first=i;
        }
		// arranging on the basis of the rate per oreo
		// sort is the part of stl under algorithm library time complexity O(nlog(n))
	sort(rate.begin(), rate.end(), [](pair<int, pair<int,int>> a, pair<int, pair<int,int>> b) 
    { return (double)a.second.second / a.second.first > (double)b.second.second / b.second.first; });
    
	int oreo_count=0;
	int spent=0;
	int i=0;
        int ans=0;
    vector <int> order;//vector to store the order 
	while( i<n && spent<=k){
	 ans=oreo_count;
		if(spent+rate[i].first<k){
			oreo_count = oreo_count + rate[i].second.second;
			spent = spent + rate[i].second.first;
			// inserting the index of packect using 
            order.push_back(rate[i].first);
            i++; 
		}
		else{
			i++;
		}
	}
//	// ans = maximum oreo can buy
//	cout << ans <<endl;
	// printing the indices
        for( int i=0;i<order.size();i++){
        	
            cout << order[i] +1<< " ";
}
	}
    
}
// total time complexity O(nlog(n)) by the sort function only and rest work on O(n);
