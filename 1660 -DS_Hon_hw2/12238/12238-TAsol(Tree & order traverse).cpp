#include <iostream>
using namespace std;

class ListNode {
public:
    int index;
    ListNode *prev;
    ListNode *next;

    ListNode(int index) {
        this->index = index;
        this->prev = this->next = NULL;
    }
};

class List {
public:
    ListNode *head;
    ListNode *tail;

    List() {
        this->head = this->tail = NULL;
    }

    ~List() {
        ListNode *temp, *cur = this->head;
        while(cur != NULL) {
            temp = cur;
            cur = cur->next;
            delete temp;
        }
        this->head = this->tail = NULL;
    }

    int back() {
        if(this->tail != NULL)
            return this->tail->index;
        return -1;
    }

    void push_back(int index) {
        if(this->head == NULL) {
            this->head = this->tail = new ListNode(index);
        } else {
            this->tail->next = new ListNode(index);
            this->tail->next->prev = this->tail;
            this->tail = this->tail->next;
        }
    }

    void pop(ListNode *node) {
        if(node != NULL && this->head != NULL) {
            if(node == this->head) {
                if(this->head == this->tail) {
                    this->head = this->tail = NULL;
                } else {
                    this->head = this->head->next;
                    this->head->prev = NULL;
                }
            } else if(node == this->tail) {
                this->tail = this->tail->prev;
                this->tail->next = NULL;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            delete node;
        }
    }
};

class TreeNode {
public:
    int index;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        this->index = 0;
        this->left = this->right = NULL;
    }

    TreeNode(int index) {
        this->index = index;
        this->left = this->right = NULL;
    }
};

class Tree {
public:
    TreeNode *root;
    List *preorder;
    List *inorder;
    List *postorder;
    List *stack;
    ListNode *next_in;

    Tree() {
        this->root = NULL;
        this->preorder = this->inorder = this->postorder = this->stack = NULL;
        this->next_in = NULL;
    }

    ~Tree() {
        destroy(this->root);
        this->root = NULL;
        this->preorder = this->inorder = this->postorder = this->stack = NULL;
        this->next_in = NULL;
    }

    void destroy(TreeNode *node) {
        if(node != NULL) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    void inputPreorder(int N) {
        this->preorder = new List();
        for(int i=0, input; i<N; ++i) {
            cin >> input;
            this->preorder->push_back(input);
        }
    }

    void inputInorder(int N) {
        this->inorder = new List();
        for(int i=0, input; i<N; ++i) {
            cin >> input;
            this->inorder->push_back(input);
        }
    }

    void inputPostorder(int N) {
        this->postorder = new List();
        for(int i=0, input; i<N; ++i) {
            cin >> input;
            this->postorder->push_back(input);
        }
    }

    void outputPostorder() {
        this->stack = new List();
        this->root = buildFromPreIn(this->preorder->head, this->inorder->head);
        post(this->root);
        cout << '\n';
    }

    TreeNode* buildFromPreIn(ListNode *cur_pre, ListNode *cur_in) {
        TreeNode *node = new TreeNode(cur_pre->index);

        if(cur_pre->index != cur_in->index && cur_pre->next != NULL) {
            this->stack->push_back(cur_pre->index);
            node->left = buildFromPreIn(cur_pre->next, cur_in);
            cur_in = this->next_in;
        } else {
            node->left = NULL;
        }

        if(cur_in->next != NULL) {
            if(cur_in->next->index != this->stack->back()) {
                node->right = buildFromPreIn(cur_pre->next, cur_in->next);
            } else {
                this->stack->pop(this->stack->tail);
                this->next_in = cur_in->next;
                node->right = NULL;
            }
        } else {
            this->stack->pop(this->stack->tail);
            node->right = NULL;
        }

        this->preorder->pop(cur_pre);
        this->inorder->pop(cur_in);

        return node;
    }

    void post(TreeNode *node) {
        if(node != NULL) {
            post(node->left);
            post(node->right);
            cout << node->index << ' ';
        }
    }

    void outputPreorder() {
        this->stack = new List();
        this->root = buildFromPostIn(this->postorder->tail, this->inorder->tail);
        pre(this->root);
        cout << '\n';
    }

    TreeNode* buildFromPostIn(ListNode *cur_post, ListNode *cur_in) {
        TreeNode *node = new TreeNode(cur_post->index);

        if(cur_post->index != cur_in->index && cur_post->prev != NULL) {
            this->stack->push_back(cur_post->index);
            node->right = buildFromPostIn(cur_post->prev, cur_in);
            cur_in = this->next_in;
        } else {
            node->right = NULL;
        }

        if(cur_in->prev != NULL) {
            if(cur_in->prev->index != this->stack->back()) {
                node->left = buildFromPostIn(cur_post->prev, cur_in->prev);
            } else {
                this->stack->pop(this->stack->tail);
                this->next_in = cur_in->prev;
                node->left = NULL;
            }
        } else {
            this->stack->pop(this->stack->tail);
            node->left = NULL;
        }

        this->postorder->pop(cur_post);
        this->inorder->pop(cur_in);

        return node;
    }

    void pre(TreeNode *node) {
        if(node != NULL) {
            cout << node->index << ' ';
            pre(node->left);
            pre(node->right);
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);

    int N;
    Tree *BT;

    cin >> N;
    BT = new Tree();
    BT->inputPreorder(N);
    BT->inputInorder(N);
    BT->outputPostorder();
    delete BT;

    cin >> N;
    BT = new Tree();
    BT->inputPostorder(N);
    BT->inputInorder(N);
    BT->outputPreorder();
    delete BT;

    return 0;
}
