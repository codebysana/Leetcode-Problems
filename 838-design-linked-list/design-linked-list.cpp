class MyLinkedList {
    struct Node{
        int val;
        Node* next;
        Node(int x) : val(x), next(NULL) {};
    };
    Node* head = NULL;
public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        Node* curr = head;
        while(curr && index > 0){
            index--;
            curr = curr->next;
        }
        return curr ? curr->val : -1;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        Node* curr = head;
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            return;
        } 
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        Node* curr = head;
        if(index == 0){
            addAtHead(val);
            return;
        }
        Node* newNode = new Node(val);
        while(curr){
            if(index == 1){
                newNode->next = curr->next;
                curr->next = newNode;
                return;
            }
            index--;
            curr = curr->next;
        }
    }
    
    void deleteAtIndex(int index) {
        if(!head){
            return;
        }
        if(index == 0){
            Node* node = head;
            head = head->next;
            delete node;
            return;
        }
        Node* curr = head;
        while(curr){
            if(index == 1 && curr && curr->next){
                Node* node = curr->next;
                curr->next = curr->next->next;
                delete node;
                return;
            }
            index--;
            curr = curr->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */