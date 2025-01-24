#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <bitset>

using namespace std;

// Node structure for the Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    
    Node(char character, int frequency, Node* leftNode = nullptr, Node* rightNode = nullptr)
        : ch(character), freq(frequency), left(leftNode), right(rightNode) {}
};

// Custom comparator for the priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Function to encode characters
void encode(Node* root, const string& str, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Function to decode a Huffman-encoded string
string decode(Node* root, const string& encodedStr) {
    string decodedStr;
    Node* current = root;
    for (char bit : encodedStr) {
        if (bit == '0') current = current->left;
        else current = current->right;

        if (!current->left && !current->right) {
            decodedStr += current->ch;
            current = root;
        }
    }
    return decodedStr;
}

// Build Huffman Tree
Node* buildHuffmanTree(const string& text) {
    unordered_map<char, int> freqMap;
    for (char ch : text) freqMap[ch]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        pq.push(new Node('\0', left->freq + right->freq, left, right));
    }

    return pq.top();
}

// Save encoded data and tree to file
void saveToFile(const string& filename, const string& encodedData, const unordered_map<char, string>& huffmanCode) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    outFile << huffmanCode.size() << "\n";
    for (auto& pair : huffmanCode) {
        outFile << pair.first << " " << pair.second << "\n";
    }

    outFile << encodedData;
    outFile.close();
}

// Load encoded data and tree from file
pair<string, unordered_map<string, char>> loadFromFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return {};
    }

    unordered_map<string, char> reverseHuffmanCode;
    int mapSize;
    inFile >> mapSize;

    for (int i = 0; i < mapSize; i++) {
        char ch;
        string code;
        inFile >> ch >> code;
        reverseHuffmanCode[code] = ch;
    }

    string encodedData;
    inFile >> encodedData;

    inFile.close();
    return {encodedData, reverseHuffmanCode};
}

int main() {
    string text;
    cout << "Enter text to compress: ";
    getline(cin, text);

    Node* root = buildHuffmanTree(text);

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    string encodedData;
    for (char ch : text) {
        encodedData += huffmanCode[ch];
    }

    cout << "Huffman Encoded Data: " << encodedData << endl;

    string filename = "compressed.huffman";
    saveToFile(filename, encodedData, huffmanCode);

    auto [loadedData, reverseHuffmanCode] = loadFromFile(filename);

    // Decoding the data
    Node* currentNode = root;
    string decodedData = decode(currentNode, encodedData);
    cout << "Decoded Data: " << decodedData << endl;

    return 0;
}
