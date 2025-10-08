#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void print_LIS(vector<int> &alt, vector<int> &length, vector<int> &previous,
               int index) {
    if (previous[index] < index) {
        print_LIS(alt, length, previous, previous[index]);
    }
    cout << alt[index] << "\n";
}

int main() {
    int T;
    while (cin >> T) {
        cin.ignore();
        cin.ignore();
        while (T--) {
            vector<int> alt;

            string input;
            while (getline(cin, input) && input != "") {
                stringstream ss(input);
                int num;
                ss >> num;
                alt.push_back(num);
            }

            vector<int> length(alt.size()), previous(alt.size());
            length[0] = 1;

            for (int i = 1; i < alt.size(); i++) {
                length[i] = 1;
                previous[i] = i;
                for (int j = 0; j < i; j++) {
                    if (alt[j] < alt[i]) {
                        if (length[i] < length[j] + 1) {
                            length[i] = length[j] + 1;
                            previous[i] = j;
                        }
                    }
                }
            }

            int max_index = 0;
            for (int i = 1; i < length.size(); i++) {
                if (length[max_index] < length[i]) {
                    max_index = i;
                }
            }

            cout << "Max hits: " << length[max_index] << "\n";
            print_LIS(alt, length, previous, max_index);
            if (T)
                cout << "\n";
        }
    }
}
