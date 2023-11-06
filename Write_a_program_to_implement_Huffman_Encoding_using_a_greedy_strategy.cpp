#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Creating Huffman tree node
class Node {
public:
    int freq;       // frequency of symbol
    char symbol;    // symbol name (character)
    Node* left;     // node left of current node
    Node* right;    // node right of current node
    string huff;    // tree direction (0/1)

    Node(int _freq, char _symbol, Node* _left = nullptr, Node* _right = nullptr)
        : freq(_freq), symbol(_symbol), left(_left), right(_right), huff("") {}

    bool operator<(const Node& other) const {
        return freq > other.freq;
    }
};

void printNodes(Node* node, string val = "") {
    string newVal = val + node->huff;

    if (node->left) {
        printNodes(node->left, newVal);
    }
    if (node->right) {
        printNodes(node->right, newVal);
    }

    if (!node->left && !node->right) {
        cout << node->symbol << " -> " << newVal << endl;
    }
}

int main() {
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    priority_queue<Node> nodes;

    for (int i = 0; i < chars.size(); i++) {
        nodes.push(Node(freq[i], chars[i]));
    }

    while (nodes.size() > 1) {
        Node* left = new Node(nodes.top());
        nodes.pop();
        Node* right = new Node(nodes.top());
        nodes.pop();

        left->huff = "0";
        right->huff = "1";

        Node* newNode = new Node(left->freq + right->freq, left->symbol + right->symbol, left, right);
        nodes.push(*newNode);
    }

    Node* root = new Node(nodes.top());
    printNodes(root);

    return 0;
}