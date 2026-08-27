#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Split a string on whitespace (spaces, tabs, newlines)
vector<string> split_by_whitespace(const string &s) {
	stringstream ss(s);
	string word;
	vector<string> words;
	while (ss >> word) {
		words.push_back(word);
	}
	return words;
}

// Split a string using a custom delimiter character
vector<string> split_by_delim(const string &s, char delim) {
	stringstream ss(s);
	string token;
	vector<string> tokens;
	while (getline(ss, token, delim)) {
		tokens.push_back(token);
	}
	return tokens;
}

int main() {
	string s1 = "hello world how are you";
	auto words = split_by_whitespace(s1);
	cout << "Split by whitespace:\n";
	for (const auto &w : words) cout << w << '\n';

	string s2 = "apple,banana,cherry";
	auto toks = split_by_delim(s2, ',');
	cout << "\nSplit by ',' delimiter:\n";
	for (const auto &t : toks) cout << t << '\n';

	return 0;
}

