#include <iostream>
using namespace std;

class ListNode {
public:
    int key;
    ListNode *prev;
    ListNode *next;

    ListNode(int key) {
        this->key = key;
        prev = next = NULL;
    }
};

struct List {
public:
    ListNode *head;
    ListNode *tail;

    List() {
        head = tail = NULL;
    }

    ~List() {
        ListNode *temp;
        while(head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = NULL;
    }

    bool empty() {
        return head == NULL;
    }

    int front() {
        return (empty())? -1 : this->head->key;
    }

    int back() {
        return (empty())? -1 : this->tail->key;
    }

    void push_front(int key) {
        if(empty()) {
            head = tail = new ListNode(key);
        } else {
            head->prev = new ListNode(key);
            head->prev->next = head;
            head = head->prev;
        }
    }

    void push_back(int key) {
        if(empty()) {
            tail = head = new ListNode(key);
        } else {
            tail->next = new ListNode(key);
            tail->next->prev = tail;
            tail = tail->next;
        }
    }

    int pop_front() {
        ListNode *temp = head;
        int key = front();
        if(head == tail) {
            head = tail = NULL;
        } else {
            head->next->prev = NULL;
            head = head->next;
        }
        delete temp;
        return key;
    }

    int pop_back() {
        ListNode *temp = tail;
        int key = back();
        if(tail == head) {
            tail = head = NULL;
        } else {
            tail->prev->next = NULL;
            tail = tail->prev;
        }
        delete temp;
        return key;
    }

    void print() {
        for(ListNode *cur = head; cur != NULL; cur = cur->next)
            cout << cur->key << ' ';
        cout << '\n';
    }
};

class Order {
public:
    List *preorder;
    List *inorder;
    List *postorder;
    List *deque;
    ListNode *nextPre;
    ListNode *nextIn;
    ListNode *nextPost;

    Order() {
        preorder = new List();
        inorder = new List();
        postorder = new List();
        deque = new List();
        nextPre = nextIn = nextPost = NULL;
    }

    ~Order() {
        delete preorder;
        delete inorder;
        delete postorder;
        delete deque;
        nextPre = nextIn = nextPost = NULL;
    }

    void prein2post(ListNode *curPre, ListNode *curIn) {
        if(curPre->key != curIn->key && curPre->next != NULL) {
            deque->push_back(curPre->key);
            prein2post(curPre->next, curIn);
            curIn = nextIn;
        }

        if(curIn->next != NULL) {
            if(!deque->empty() && curIn->next->key == deque->back()) {
                deque->pop_back();
                nextPre = (nextPre == NULL)? curPre->next : nextPre;
                nextIn = curIn->next;
            } else {
                ListNode *next = (nextPre == NULL)? curPre->next : nextPre;
                nextPre = NULL;
                prein2post(next, curIn->next);
            }
        }

        postorder->push_back(curPre->key);
    }

    void postin2pre(ListNode *curPost, ListNode *curIn) {
        if(curPost->key != curIn->key && curPost->next != NULL) {
            deque->push_back(curPost->key);
            postin2pre(curPost->next, curIn);
            curIn = nextIn;
        }

        if(curIn->next != NULL) {
            if(!deque->empty() && curIn->next->key == deque->back()) {
                deque->pop_back();
                nextPost = (nextPost == NULL)? curPost->next : nextPost;
                nextIn = curIn->next;
            } else {
                ListNode *next = (nextPost == NULL)? curPost->next : nextPost;
                nextPost = NULL;
                postin2pre(next, curIn->next);
            }
        }
        preorder->push_front(curPost->key);
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    int N;

    cin >> N;
    Order *O = new Order();
    for(int i=0, key; i<N; ++i) {
        cin >> key;
        O->preorder->push_back(key);
    }
    for(int i=0, key; i<N; ++i) {
        cin >> key;
        O->inorder->push_back(key);
    }
    O->prein2post(O->preorder->head, O->inorder->head);
    O->postorder->print();
    delete O;

    cin >> N;
    O = new Order();
    for(int i=0, key; i<N; ++i) {
        cin >> key;
        O->postorder->push_front(key);
    }
    for(int i=0, key; i<N; ++i) {
        cin >> key;
        O->inorder->push_front(key);
    }

    O->postin2pre(O->postorder->head, O->inorder->head);
    O->preorder->print();
    delete O;

    return 0;
}
