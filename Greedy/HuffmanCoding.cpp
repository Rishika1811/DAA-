#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int frequency;
    unsigned char character;
    Tree *left = nullptr;
    Tree *right = nullptr;
    Tree(char ch, int f){
        character=ch;
        frequency=f;
        left=right=NULL;
    }
};

struct cmp{
    bool operator()(Tree *a, Tree *b){
        return a->frequency > b->frequency;
    }
};
void generateCode(Tree *root, string code,unordered_map<char,string>&huffCode) {
    if(!root) return;
    if (!root->right && !root->left) {
        huffCode[root->character] = code; 
    }
    generateCode(root->left, code + "0", huffCode);
    generateCode(root->right, code + "1", huffCode);
}

void buildHuffmanTree(unordered_map<char, int> freqMap) {
    priority_queue<Tree *, vector<Tree *>, cmp> minHeap;
    for (auto pair: freqMap){
        minHeap.push(new Tree(pair.first,pair.second));
    }
    while (minHeap.size() > 1) {
        Tree* a = minHeap.top();
        minHeap.pop();
        Tree* b = minHeap.top();
        minHeap.pop();
        Tree *c = new Tree('$',a->frequency + b->frequency);
        c->left = a;
        c->right = b;
        minHeap.push(c);
    }
    Tree* root= minHeap.top();
    unordered_map<char,string>huffCode;
    generateCode(root,"",huffCode);
    for(auto pair: huffCode)
        cout<<pair.first<<':'<<pair.second<<endl;
}

int main()
{
    unordered_map<char, int> freqMap={
        {'a',4},{'b',10},{'c',5},{'d',8}
    };
    buildHuffmanTree(freqMap);
}
