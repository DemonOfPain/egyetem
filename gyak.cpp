template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node *next;
        Node(const T &value) : data(value), next(nullptr) {}
    };
    Node *head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
    void append(const T &value);
};

template <typename T>
void LinkedList<T>::append(const T &value) {
    Node *uj = new Node(value);

    if (head == nullptr) {
        head = uj;
        return;
    }

    Node *kov;
    for (kov = head; kov->next != nullptr; kov = kov->next) {
    }
    kov->next = uj;
    return;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    if (head == nullptr) {
        return;
    }

    Node *ez = head;
    Node *kov;
    while (ez != nullptr) {
        kov = ez->next;
        delete ez;
        ez = kov;
    }
}