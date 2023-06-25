#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string input;
	cin >> input;
	int freq[26] = {0};
	for(int i=0; i<input.length(); i++) {
	    freq[input[i]-'a']++;
	}
	for(int i=0; i<26; i++) {
	    if(freq[i]) {
	        cout << (char) (i + 97) << ':' << freq[i] << ' ';
	    }
	}
	return 0;
}
