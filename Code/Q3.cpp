#include <iostream>
#include <string>
#include <map>

using namespace std;

struct TrieNode {
    map<char, TrieNode*> children;
};

int main() {
    string s;
    cin>>s;
    int count=1;
    TrieNode* root=new TrieNode();
    for (int i=0;i<s.length();i++) {
        TrieNode* current = root;
        for (int j=i;j<s.length();j++) {
            char ch = s[j];
            if (current->children.find(ch)==current->children.end()) {
                current->children[ch]=new TrieNode();
                count++;
            }
            current = current->children[ch];
        }
    }
    cout<<"The number of distinct substrings of "<< s << " is: " << count << endl;
    return 0;
}