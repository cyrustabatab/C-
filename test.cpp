#include <iostream>
#include <string>
#include <exception>



class EmptyListException: public std::runtime_error {
    public: 
        EmptyListException(std::string message="Empty List"): std::runtime_error{message} {};
        const char* what() const noexcept {return message.c_str();};

           
    private:
        std::string message;


};




template <typename T>
struct Node {
    
    Node(T value) {
        this->value = value; 
        next = nullptr;


    }
    

    T getValue() {
        return value;

    }

    T setNext(Node* node) {

        this->next = node;
        

    }



    T value;
    Node<T>* next;



};

template <typename T>
struct LL {
    
    LL() {
        size =0;
        head = nullptr;
        tail = nullptr;

    }
    

    bool empty() {
        return size == 0;

    }


    unsigned int getSize() {
       return size; 

    }
    void addFront(T value) {
      Node<T>* new_node = new Node<T>{value};

      if(head == nullptr) {
        head = new_node;
        tail = new_node;
      } else {
          new_node->setNext(head);
          head = new_node;
         
      }

      ++size;
    




    }
    

    void insert(int index,T value) {
        
        if(index ==0)
            addFront(value);
        else if(index == size)
            addBack(value);
        else {

            int i = 0;
            Node<T>* current = head;

            while(current != nullptr && i + 1 != index) {
                current = current->next;
                i++;


            }

            if(current == nullptr) {
                std::cout << "Index Out of Bounds" << std::endl; 
                return;
            }

            Node<T>* new_node = new Node<T>{value};
            new_node->next = current->next;
            current->next = new_node;
            size++;

        }



    }


    void remove(int index) {
        if(index == 0)
            removeFront();
        else if(index == size - 1)
            removeEnd();
        else
            int i{0};
            while(current != nullptr && i + 1 != index) {
                current = current->next;
                ++i;
            }

            if(current == nullptr) {
                std::cout << "Index Out of Bounds" << std::endl;
                return;
            }

            Node<T>*temp = current->next->next;
            delete current->next;
            current->next = temp;
            --size;





    }
    void addBack(T value) {
        Node<T>* new_node = new Node<T>{value};

        if(tail == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->setNext(new_node);
            tail = new_node;
            
        }

        ++size;


    }

    T removeFront()  {
        if(!empty()) {
            T value = head->value;
            Node<T>* new_head = head->next;
            delete head;
            head = new_head;
            if(head == nullptr) {
                tail = nullptr;

            }
            --size;
            return value;

        } else  {
            throw EmptyListException();
        }
            



    }

    T removeEnd() {
        if(!empty()) {
            T value = tail->value;

            if(size == 1) {
                head = tail = nullptr;
            } else {

                Node<T>* current = head;
                
                while(current->next != tail) {
                   current = current->next;

                }

                current->next = nullptr;

            }
            --size;
                
            return value;
        } else {
            std::cout << "Empty list" << std::endl;

        }


    }

    void display() {
        Node<T>* current = head;

        while(current != nullptr) {
            std::cout << current->value << ((current->next != nullptr)? "->": "\n");
            current = current->next;

        }

    }

    private:
        Node<T>* head;
        Node<T>* tail;
        unsigned int size; 






};


template <typename T>
void display(Node<T> node) {
    
    Node<T>* current = &node;

    while(current != nullptr) {
        std::cout << current->value << ' ';
        current = current->next;

    }




}


template <typename T>
T add(T x,T y) {
    return x +y;

}




int main() {

    LL<int> ll{};
    
    ll.addFront(2); 
    ll.addFront(4);
    ll.insert(1,5);
    ll.display();





}
