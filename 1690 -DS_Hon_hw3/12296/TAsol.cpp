#include <iostream>
#include <string>
#define LEN     10000
#define SIGMA   27
using namespace std;

class Node {
public:
    char ch;
    int times;
    Node *left;
    Node *right;

    Node() {
        ch = '\0';
        times = 0;
        left = right = NULL;
    }

    Node(char ch) {
        this->ch = ch;
        times = 0;
        left = right = NULL;
    }
};

class Heap {
public:
    int size;
    Node *nodes[SIGMA];

    Heap() {
        size = 0;
    }

    void push(Node *node) {
        int i = size++, p;
        int i_t = node->times, p_t;
        int i_ch = node->ch, p_ch;

        while(i > 0) {
            p = (i-1) >> 1;
            p_t = nodes[p]->times; p_ch = nodes[p]->ch;
            if(i_t < p_t || (i_t == p_t && i_ch < p_ch)) {
                nodes[i] = nodes[p];
                i = p;
            } else break;
        }

        nodes[i] = node;
    }

    Node* pop() {
        Node *top = nodes[0];
        Node *node = nodes[--size];
        int i_t = node->times, i = 0, L, R, L_t, R_t;
        char i_ch = node->ch, L_ch, R_ch;

        while(1) {
            L = (i<<1)+1;
            R = (i<<1)+2;

            if(L < size && R < size) {
                L_t = nodes[L]->times; L_ch = nodes[L]->ch;
                R_t = nodes[R]->times; R_ch = nodes[R]->ch;

                if(i_t == L_t && i_t == R_t) {
                    if(L_ch < R_ch && L_ch < i_ch) {
                        nodes[i] = nodes[L];
                        i = L;
                    } else if(R_ch < L_ch && R_ch < i_ch) {
                        nodes[i] = nodes[R];
                        i = R;
                    }
                } else if(i_t == L_t) {
                    if(i_t < R_t) {
                        if(i_ch > L_ch) {
                            nodes[i] = nodes[L];
                            i = L;
                        } else break;
                    } else {
                        nodes[i] = nodes[R];
                        i = R;
                    }
                } else if(i_t == R_t) {
                    if(i_t < L_t) {
                        if(i_ch > R_ch) {
                            nodes[i] = nodes[R];
                            i = R;
                        } else break;
                    } else {
                        nodes[i] = nodes[L];
                        i = L;
                    }
                } else if(L_t == R_t && i_t > L_t) {
                    if(L_ch < R_ch) {
                        nodes[i] = nodes[L];
                        i = L;
                    } else {
                        nodes[i] = nodes[R];
                        i = R;
                    }
                } else if(L_t < R_t && L_t < i_t) {
                    nodes[i] = nodes[L];
                    i = L;
                } else if(R_t < L_t && R_t < i_t) {
                    nodes[i] = nodes[R];
                    i = R;
                } else break;
            } else if(L < size) {
                L_t = nodes[L]->times; L_ch = nodes[L]->ch;
                if(i_t > L_t || (i_t == L_t && i_ch > L_ch)) {
                    nodes[i] = nodes[L];
                    i = L;
                } break;
            } else break;
        }

        nodes[i] = node;
        return top;
    }
};

class Huffman {
public:
    char S[LEN+1];
    Node *root;
    Node *nodes[SIGMA];
    char codes[SIGMA][SIGMA];

    Huffman() {
        root = NULL;
        for(int i=0; i<SIGMA; ++i)
            nodes[i] = NULL;
    }

    ~Huffman() {
        destroy(root);
    }

    void destroy(Node *node) {
        if(node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    int tag(char ch) {
        return (ch == '-')? (SIGMA-1) : (ch-'a');
    }

    void getDistribution() {
        char ch;
        int i = 0, j;

        while((ch = cin.get()) != '\n') {
            j = tag(ch);
            if(nodes[j] == NULL)
                nodes[j] = new Node(ch);
            ++nodes[j]->times;
            S[i++] = ch;
        }

        S[i] = '\0';
    }

    Node* combineNode(Node *node_0, Node *node_1) {
        Node *node = new Node();
        int t_0 = node_0->times, t_1 = node_1->times;
        char ch_0 = node_0->ch, ch_1 = node_1->ch;
        int flag = (t_0 < t_1 || (t_0 == t_1 && ch_0 < ch_1));

        node->times = t_0 + t_1;
        node->ch = (ch_0 < ch_1)? ch_0 : ch_1;
        node->left = (flag)? node_0 : node_1;
        node->right = (flag)? node_1 : node_0;

        return node;
    }

    void buildTree() {
        Heap *H = new Heap();

        for(int i=0; i<SIGMA; ++i)
            if(nodes[i])
                H->push(nodes[i]);

        while(H->size > 1)
            H->push(combineNode(H->pop(), H->pop()));

        root = H->pop();

        delete H;
    }

    void getCodes() {
        if(root->left || root->right) { /* >= 2 kinds of characters in S */
            char code[SIGMA];
            getCode(root, code, 0);
        }
    }

    void getCode(Node *node, char *code, int i) {
        if(node->left || node->right) {
            code[i] = '0';
            getCode(node->left, code, i+1);

            code[i] = '1';
            getCode(node->right, code, i+1);
        } else { /* leaf */
            int j = tag(node->ch), k;
            for(k=0; k<i; ++k)
                codes[j][k] = code[k];
            codes[j][k] = '\0';
        }
    }

    void encodeS() {
        if(root->left || root->right) {
            for(int i=0; S[i]; ++i)
                cout << codes[tag(S[i])];
        } else { /* only one kind of characters in S */
            for(int i=0; S[i]; ++i)
                cout << '0';
        }
        cout << '\n';
    }

    void decodeT() {
        char ch;
        if(root->left || root->right) {
            while((ch = cin.get()) != '\n')
                decode(root, ch);
        } else { /* only one kind of characters in S */
            while((ch = cin.get()) != '\n')
                cout << S[0];
        }
        cout << '\n';
    }

    void decode(Node *node, char ch) {
        if(ch == '0') {
            if(node->left->left || node->left->right) {
                decode(node->left, cin.get());
            } else { /* leaf */
                cout << node->left->ch;
            }
        } else {
            if(node->right->left || node->right->right) {
                decode(node->right, cin.get());
            } else { /* leaf */
                cout << node->right->ch;
            }
        }
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    Huffman *huffman;

    cin >> C;
    cin.get();

    while(C--) {
        huffman = new Huffman();

        huffman->getDistribution();
        huffman->buildTree();
        huffman->getCodes();
        huffman->encodeS();
        huffman->decodeT();

        delete huffman;
    }

    return 0;
}
