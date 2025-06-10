#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
      char data;
      TrieNode* children[26];
      bool isTerminal;

      // Constructor
      TrieNode(char ch) {
            this->data = ch;
            for (int i = 0; i < 26; i++) {
                  children[i] = NULL;
            }
            this->isTerminal = false;
      }
      };

class Trie {
public:
      TrieNode* root;

      Trie() {
            root = new TrieNode('\0');
      }

      void insertUtil(TrieNode* root, string word) {
            // Base case
            if (word.length() == 0) {
                  root->isTerminal = true;
                  return;
            }

            // Current character
            char ch = word[0];
            int index = ch - 'a'; // Assumes input is lowercase

            // Check if the character is already present
            TrieNode* child;
            if (root->children[index] != NULL) {
                  child = root->children[index];
            } else {
                  // Create a new node
                  child = new TrieNode(ch);
                  root->children[index] = child;
            }

            // Recursive call for the remaining string
            insertUtil(child, word.substr(1));
      }

      void insertWord(string word) {
            insertUtil(root, word);
      }

      bool sUtil(TrieNode* root, string word){

            //base case
            if(word.length()==0){
                  return root->isTerminal;
            }

            int index = word[0]-'a';
            TrieNode* child;

            if(root->children[index] != NULL){
                  child = root->children[index];
            }else{
                  return false;
            }

            return sUtil(child,word.substr(1)); 
      }

      bool searchWord(string word){
            return sUtil(root,word);
      }

      bool remUtil(TrieNode* root, string word){

            //base case
            if(word.length()==0){
                  root->isTerminal = false;
            }

            int index = word[0]-'a';
            TrieNode* child;

            if(root->children[index] != NULL){
                  child = root->children[index];
            }else{
                  return false;
            }

            return remUtil(child,word.substr(1)); 
      }

      bool removeWord(string word){
            return remUtil(root,word);
      }
};

int main() {
      Trie* t = new Trie();
      t->insertWord("abcde");
      t->insertWord("zoo");
      t->insertWord("for");
      t->insertWord("temp");

      cout << "Word inserted successfully!" << endl;
      cout << "Present or Not " << t->searchWord("abcde") << endl;
      cout << "Present or Not " << t->searchWord("tem") << endl;
      cout << "Present or Not " << t->searchWord("temp") << endl;
      t->removeWord("temp");
      cout << "removed "<<endl;
        cout << "Present or Not " << t->searchWord("temp") << endl;
      return 0;
}
