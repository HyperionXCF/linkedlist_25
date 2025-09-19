#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            next = nullptr;
        }
};

class List{
    private:
        int length;
        Node* head;
        Node* tail;
    
    public:
        List(int data){
            Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        // get length of the list 
        void getLength(){
            cout << length << endl;
        }

        // get data at head
        void gethead(){
            cout << head->data << endl;
        }

        // get data at tail  
        void gettail(){
            cout << tail->data << endl;
        }

        // insert at head
        void insert_at_head(int data){
            Node* newNode = new Node(data);
            if(head == NULL){
                head = tail = newNode;
            }else{
                newNode->next = head;
                head = newNode;
            }
            length++;
            return;
        }

        // insert at tail
        void insert_at_tail(int data){
            Node* newNode = new Node(data);
            if(head == NULL){
                head = tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
            length++;
            return;
        }

        
        // delete from head
        void delete_from_front(){
            if(head == NULL){
                cout << "empty list" << endl;
                return;
            }
            
            if(head->next == NULL){
                delete head;
                head = tail = nullptr;
            }else{
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            length--;
            return;
        }
        
        // delete from tail
        void delete_from_end(){
            if(head == NULL){
                cout << "list is empty" << endl;
                return;
            }
            
            if(head->next == NULL){
                delete head;
                head = tail = nullptr;
            }else{
                Node* temp = head;
                while(temp->next->next != NULL){
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = nullptr;
                tail = temp;
            }
            length--;
            return;
        }
        
        // get function
        Node* get_node(int index){
            if(index < 0 || index >=length){
                cout << "invalid index" << endl;
                return nullptr;
            }
            Node* temp = head;
            for(int i=0;i<index;i++){
                temp = temp->next;
            }
            return temp;
            // make sure to check if the returned node is nullptr before using it
        }

        // set function
        bool set_node(int index, int newValue){
            Node* temp = get_node(index);

            if(temp!= nullptr){
                temp->data = newValue;
                return true;
            }

            return false;
        }


        // insert at position
        bool insert_at_position(int index, int value){
            if(index < 0 || index >length){
                return false;
            }

            if(index == 0){
                insert_at_head(value);
                return true;
            }

            if(index == length -1){
                insert_at_tail(value);
                return true;
            }

            Node* newNode = new Node(value);
            Node* temp = get_node(index-1);

            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }

        // delete from position
        void delete_from_position(int index){
            if(index < 0  || index >= length){
                cout << "index out of bound" << endl;
                return;
            }

            if(index == 0){
                return delete_from_front();
            }

            if(index == length-1){
                return delete_from_end();
            }

            Node* prev = get_node(index -1);
            Node* temp = prev->next;

            prev->next = temp->next;
            delete temp;
            length--;
            return;
        }
        
        // convert linkedlist to array
        vector<int> convert_ll_to_array(){
            vector<int> v;
            if(head == NULL){
                return {};
            }
            
            Node* temp = head;
            while(temp != NULL){
                v.push_back(temp->data);
                temp = temp->next;
            }
            return v;
        }
        
        // search in linkedlist
        bool search_element_in_linkedlist(int data){
            Node* temp = head;
            while (temp != NULL && temp->data != data){
                temp = temp->next;
            }
            if(temp){
                if(temp->data == data){
                    return true;
                }
                return false;
            }
            return false;
        }
        
        // create a linkedlist from a list of data
        Node* create_ll_from_array(vector<int>v){
            int size = v.size();
            Node* head_of_list = nullptr;
            Node* tail_of_list = nullptr;
            
            for(int i=0;i<size;i++){
                Node* newNode = new Node(v[i]);
                if(head_of_list == NULL){
                    head_of_list = tail_of_list = newNode;
                }else{
                    tail_of_list->next = newNode;
                    tail_of_list = newNode;
                }
            }
            
            return head_of_list;
        }
        
        // find middle element
        // get middle node of the list;
        Node* get_middle_node(){
            Node* slow = head;
            Node* fast = head;

            while(fast && fast->next){
                fast = fast->next->next;
                slow = slow->next;
            }

            return slow;
        }

        // get node at some index
        Node* get_node_at_index(int index){
            if(index < 0 || index >= length){
                return nullptr;
            }

            if(index == 0){
                return head;
            }

            if(index == length -1){
                return tail;
            }

            Node* temp = head;
            for(int i=0;i<index;i++){
                temp = temp->next;
            }
            return temp;
        }

        // binary search on linedlist 
        Node* binary_search_on_ll(int target){
            if(head == NULL){
                cout << "empty list" << endl;
                return nullptr;
            }

            vector<int> v = convert_ll_to_array();
            int lower_bound = 0;
            int upper_bound = v.size() -1;
            while(lower_bound <= upper_bound){
                int mid = lower_bound + (upper_bound - lower_bound)/2;
                if(v[mid] == target){
                    return get_node_at_index(mid);
                }else if(v[mid] < target){
                    lower_bound = mid+1;
                }else{
                    upper_bound = mid-1;
                }
            }
            return nullptr;
        }

        // get nth node from end 
        Node* nth_node_from_end(int n){
            if(head == NULL || n <=0 || n>length){
                return nullptr;
            }

            Node* fast = head;
            Node* slow = head;

            // move fast n steps ahead;
            for(int i=0;i<n;i++){
                fast = fast->next;
            }

            while(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }

            return slow;
        }

        // reverse linkedlist 
        void reverse_linkedlist(){
            Node* prev = nullptr;
            Node* curr = head;
            Node* next;

            tail = head;

            while(curr != nullptr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            head = prev;
        }

        // detect cycle floyd's algorithm on linkedlist
        bool detect_cycle(){
            Node* slow = head; // slow moves 1 step 
            Node* fast = head; // fast moves 2 steps
            // if theres a cycle eventually fast and slow will become equal 
            // if fast reaches nullptr then no cycle
            while(fast !=nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast){
                    return true;
                    // cycle detected
                }
            }

            return false;
        }

        // display linkedlist 
        void display_linkedlist(){
            if(head == nullptr){
                cout << "empty list" << endl;
                return;
            }
            
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
        
        // delete / clear the list
        ~List(){
            Node* temp = head;
            while(head != NULL){
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
            head = tail = nullptr;
        }

        // sum of the list elements
        int sum_of_all_elements_in_list(){
            int sum = 0;
            Node* temp = head;
            while(temp != nullptr){
                sum += temp->data;
                temp = temp->next;
            }
            cout << "sum of all elements : " << sum << endl;
            return sum;
        }

        // min of list elements 
        int min_element_in_ll(){
            int min = head->data;
            Node* temp = head;
            while(temp != nullptr){
                if(temp->data < min){
                    min = temp->data;
                }
                temp = temp->next;
            }
            cout << "minimum element : " << min << endl;
            return min;
        }

        // max of the list elements
        int max_element_in_ll(){
            int max = head->data;
            Node* temp = head;
            while(temp != NULL){
                if(temp->data > max){
                    max = temp->data;
                }
                temp = temp->next;
            }
            cout << "max element : " << max << endl;
            return max;
        }

        // harder functions to implement 
        // remove duplicates 
        // merge 2 linkedlists 
        // check if the list is a palindrome
        // copy a linked list
        // sort linked list
        // merge sort, quick sort, bubble sort on linkedlist
};

int main()
{
    cout << "=== Linked List Testing ===\n";

    List ll(10); // initial node
    cout << "After initializing with 10:\n";
    ll.display_linkedlist();
    ll.getLength();
    ll.gethead();
    ll.gettail();

    // insertions
    ll.insert_at_head(5);
    ll.insert_at_tail(20);
    ll.insert_at_tail(15);
    ll.insert_at_head(3);
    cout << "\nAfter insertions:\n";
    ll.display_linkedlist();
    ll.getLength();

    // get, set, insert at position
    Node *n = ll.get_node_at_index(2);
    if (n)
        cout << "Node at index 2: " << n->data << endl;

    ll.set_node(2, 25);
    cout << "After setting index 2 to 25:\n";
    ll.display_linkedlist();

    ll.insert_at_position(3, 30);
    cout << "After inserting 30 at index 3:\n";
    ll.display_linkedlist();

    // deletions
    ll.delete_from_front();
    cout << "After deleting from front:\n";
    ll.display_linkedlist();

    ll.delete_from_end();
    cout << "After deleting from end:\n";
    ll.display_linkedlist();

    ll.delete_from_position(2);
    cout << "After deleting from position 2:\n";
    ll.display_linkedlist();

    // sum, min, max
    ll.sum_of_all_elements_in_list();
    ll.min_element_in_ll();
    ll.max_element_in_ll();

    // reverse
    ll.reverse_linkedlist();
    cout << "After reversing:\n";
    ll.display_linkedlist();

    // nth node from end
    Node *nth = ll.nth_node_from_end(2);
    if (nth)
        cout << "2nd node from end: " << nth->data << endl;

    // middle node
    Node *mid = ll.get_middle_node();
    if (mid)
        cout << "Middle node: " << mid->data << endl;

    // search
    cout << "Searching for 25: " << (ll.search_element_in_linkedlist(25) ? "Found" : "Not found") << endl;
    cout << "Searching for 100: " << (ll.search_element_in_linkedlist(100) ? "Found" : "Not found") << endl;

    // convert to array and binary search
    vector<int> arr = ll.convert_ll_to_array();
    cout << "Linked list as array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    Node *found = ll.binary_search_on_ll(25);
    if (found)
        cout << "Binary search found 25 at node: " << found->data << endl;
    else
        cout << "Binary search did not find 25" << endl;

    // detect cycle
    cout << "Cycle detected? " << (ll.detect_cycle() ? "Yes" : "No") << endl;

    // create linkedlist from an vector and display it 
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    Node* newHead = ll.create_ll_from_array(v);
    Node* temp = newHead;
    while(temp!=nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    
    return 0;
}
