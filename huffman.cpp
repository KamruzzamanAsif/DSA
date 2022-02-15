#include <bits/stdc++.h>
using namespace std;

#define MAX_TREE_HT 100
string encodestr, decodestr;
// to store the frequency of character of the input data
map<char, int> freq;
// to map each character its huffman value
map<char, string> codes;

// huffman tree node
struct MinHeapNode{
    char data; // for storing character
    unsigned freq;  // frequency of the character
    struct MinHeapNode *left, *right; // for storing left and right child address of this node
};

// min-heap node
struct MinHeap {
	unsigned size; // current size of mean-heap
	unsigned capacity; // capacity of min heap
	struct MinHeapNode** array; // Array of min-heap node pointers
};

// function to allocate a new min-heap node with char and it's frequency
struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

// function to create a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity)
{
    struct MinHeap* minHeap= (struct MinHeap*)malloc(sizeof(struct MinHeap));

    minHeap->size = 0; // current size is 0

    minHeap->capacity = capacity;

    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// function to swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a,struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// The standard minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size
        && minHeap->array[left]->freq
               < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size
        && minHeap->array[right]->freq
               < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest],
                        &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// function to check if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap)
{

    return (minHeap->size == 1);
}

// function to extract minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

// A utility function to insert a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap,struct MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq){
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// function to build min heap
void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// function to print an array of size n
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);

    printf("\n");
}

// function to check if this node is leaf
int isLeaf(struct MinHeapNode* root)
{
    return !(root->left) && !(root->right);
}

// Creates a min heap of capacity
// equal to size and inserts all character of
// data[] in min heap. Initially size of
// min heap is equal to capacity
struct MinHeap* createAndBuildMinHeap(char data[],int freq[], int size)
{
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}


// The main function that builds Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[],int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;

    // Step 1: Create a min heap of capacity
    // equal to size.  Initially, there are
    // modes equal to size.
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    // Iterate while size of heap doesn't become 1
    while (!isSizeOne(minHeap)) {

        // Step 2: Extract the two minimum
        // freq items from min heap
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        // Step 3:  Create a new internal
        // node with frequency equal to the
        // sum of the two nodes frequencies.
        // Make the two extracted node as
        // left and right children of this new node.
        // Add this node to the min heap
        // '$' is a special value for internal nodes, not
        // used
        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    // Step 4: The remaining node is the
    // root node and the tree is complete.
    return extractMin(minHeap);
}

// storing codes of each char
void storeCodes(struct MinHeapNode* root, string str)
{
	if (root==NULL)
		return;
	if (root->data != '$')
		codes[root->data]=str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}

void printCodes(struct MinHeapNode* root, string str)
{
	if (!root)
		return;
	if (root->data != '$')
		cout << root->data << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

string decode_data(struct MinHeapNode* root, string s)
{
	string ans = "";
	struct MinHeapNode* curr = root;
	for (int i=0;i<s.size();i++)
	{
		if (s[i] == '0')
		curr = curr->left;
		else
		curr = curr->right;

		// reached leaf node
		if (curr->left==NULL and curr->right==NULL)
		{
			ans += curr->data;
			curr = root;
		}
	}
	// cout<<ans<<endl;
	return ans+'\0';
}

// The main function that builds a Huffman Tree and store and encode and decode codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size, string str)
{
    // Construct Huffman Tree
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

    // Print Huffman codes using
    // the Huffman tree built above
    string s;
    storeCodes(root,s);
    printCodes(root,s);
    for (int i=0;i<str.size();i++) // generating encoded format of given text
    {
        char c = str[i];
        encodestr+=codes[c];
    }
    decodestr = decode_data(root, encodestr); // decoding through decode_data function
}

int main()
{
    int len=0, f[100];
    char arr[100];
    //string str="abra-ka-dabra";
    //char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    //int freq[] = { 5, 9, 12, 13, 16, 45 };
    //int size = sizeof(arr) / sizeof(arr[0]);

    fstream inText( "huffman_text.txt", ios::in ); // fstream calss's object
    string line, str;
    while( getline( inText, line ) )
    {
       str += line + " ";
    }
    inText.close();

    for (int i=0; i<str.size(); i++)  // calculating the frequency of each char
		freq[str[i]]++;
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
    {
        arr[len] = v->first;  // assigning char and their frequencies into array
        f[len] = v->second;
        len++;
    }

    HuffmanCodes(arr, f, len, str);


	cout << "\nEncoded Huffman data:\n" << encodestr << endl;


	cout << "\nDecoded Huffman Data:\n" << decodestr << endl;

    return 0;
}








