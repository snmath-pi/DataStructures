/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	string s, t;
 	cin >> s >> t;
 	// efficient way
 	function<bool(string, string)> is_rotation = [&](string s, string t) {
 		string new_s = s + s;
 		return (new_s.find(t) != string::npos);
 	};
 	// a decent way (uses memory)
 	function<bool(string, string)> is_rotation2 = [&](string s, string t) {
 		queue<char> q1, q2;
 		for(int i=0; i<(int) s.length(); i++) {
 			q1.push(s[i]);
 		}
 		for(int i=0; i<(int) t.length(); i++) {
 			q2.push(t[i]);
 		}
 		int k = (int) t.length();
 		while(k--) {
 			char c = q2.front();
 			q2.pop();
 			q2.push(c);
 			if(q1 == q2) return 1;
 		}
 		return 0;
 	};
 	cout << is_rotation(s, t) << "\n";
    cout << is_rotation2(s, t);
    return 0;
}
