#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <fstream>
using namespace std;

// Node structure for the Huffman Tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Compare class for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // Min-Heap based on frequency
    }
};

// Function to build the Huffman Tree
Node* buildHuffmanTree(unordered_map<char, int>& frequencies) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a node for each character and push to priority queue
    for (auto& pair : frequencies) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build the tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node('\0', left->freq + right->freq); // Internal node
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    return pq.top(); // Root of the tree
}

// Function to generate Huffman Codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // Leaf node
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to encode the input text
string encodeText(const string& text, unordered_map<char, string>& huffmanCodes) {
    string encodedText = "";
    for (char ch : text) {
        encodedText += huffmanCodes[ch];
    }
    return encodedText;
}

// Function to decode the encoded text
string decodeText(const string& encodedText, Node* root) {
    string decodedText = "";
    Node* current = root;

    for (char bit : encodedText) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        // Leaf node
        if (!current->left && !current->right) {
            decodedText += current->ch;
            current = root; // Reset for the next character
        }
    }

    return decodedText;
}

// Utility function to delete the Huffman Tree
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Function to calculate the size of a string in bits
int calculateSizeInBits(const string& text) {
    return text.length() * 8; // Each character is 8 bits in size (ASCII)
}

// Function to calculate the size of the encoded text
int calculateCompressedSize(const string& encodedText) {
    return encodedText.length(); // Size in bits is simply the length of the encoded text (each bit is 1)
}

// Main Function
int main() {
    // Input text
    string text;
    cout << "Enter the text to compress: ";
    getline(cin, text);

    // Calculate frequency of each character
    unordered_map<char, int> frequencies;
    for (char ch : text) {
        frequencies[ch]++;
    }

    // Build Huffman Tree
    Node* root = buildHuffmanTree(frequencies);

    // Generate Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Display the codes
    cout << "\nHuffman Codes:\n";
    for (auto& pair : huffmanCodes) {
        cout << pair.first << " : " << pair.second << endl;
    }

    // Encode the text
    string encodedText = encodeText(text, huffmanCodes);
    cout << "\nEncoded Text: " << encodedText << endl;

    // Decode the text
    string decodedText = decodeText(encodedText, root);
    cout << "\nDecoded Text: " << decodedText << endl;

    // Calculate original size (in bits) and compressed size (in bits)
    int originalSize = calculateSizeInBits(text);
    int compressedSize = calculateCompressedSize(encodedText);

    // Display the sizes
    cout << "\nOriginal Size: " << originalSize << " bits" << endl;
    cout << "Compressed Size: " << compressedSize << " bits" << endl;
    cout << "Compression Ratio: " << (double)originalSize / compressedSize << endl;

    // Cleanup
    deleteTree(root);

    return 0;
}
