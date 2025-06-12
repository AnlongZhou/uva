#include <iostream>
#include <stack>
using namespace std;

stack<char> st;
string target, source;

void dfs(int i, int j, string res) {
  if (j == target.size()) {
    cout << res << "\n";
  }

  if(i < source.size()) {
    st.push(source[i]);
    dfs(i + 1, j, res + (res.empty()? "i" : " i"));
    st.pop();
  }

  if(!st.empty() && st.top() == target[j]) {
    char c = st.top();
    st.pop();
    dfs(i, j + 1, res + " o");
    st.push(c);
  }
}

int main() {
  while (cin >> source >> target) {
    st = stack<char>();
    cout << "[\n";
    if(source.size() == target.size()) {
      dfs(0, 0, "");
    }
    cout << "]\n";
  }
}
