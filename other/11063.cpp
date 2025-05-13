#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int n, count = 0, caseNum = 1; vector<int> arr;
    unordered_set<int> st;


    while(cin >> n) {
        arr.clear();
        st.clear();
        bool b2 = true;
        for(int i = 0 ; i < n ; i++) {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        for(int i = 0 ; i < arr.size() ; i++) {
            for(int j = i ; j < arr.size() ; j++) {
                if(st.count(arr[i] + arr[j])) {
                    b2 = false;
                }
                st.insert(arr[i] + arr[j]);
            }
        }

        cout << "Case #" << caseNum++ << ":";

        if(b2) cout << " It is a B2-Sequence.\n\n";
        else cout << " It is not a B2-Sequence.\n\n";

        string temp;
        cin >> temp;
    }
}
