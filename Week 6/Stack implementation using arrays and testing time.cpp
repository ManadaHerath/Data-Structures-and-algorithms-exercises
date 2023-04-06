class Node { //using linkedlist doing the same tasks to implement and get time in main
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Stack {
private:
    int SIZE;
    int count;
    Node* top;

public:
    Stack(int size) {
        SIZE = size;
        count = 0;
        top = nullptr;
    }

    void push(int x) {
        if (count < SIZE) {
            Node* newNode = new Node(x);
            newNode->next = top;
            top = newNode;
            count++;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            int x = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            count--;
            return x;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool isFull() {
        return count == SIZE;
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;
        } else {
            return top->data;
        }
    }

    void Display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};


int main() {
    cout << "Enter the size of the stack: ";
    int length;
    cin >> length;
    vector<double> time;
    double sum=0;
    for (int i = 0;i<5;i++){
        auto start = high_resolution_clock::now();
        Stack stack(length);
        for (int i = 0; i < length/2; i++)
            stack.push(rand() % length);

        for (int i = 0; i < 5; i++)
            stack.pop();
        stack.Display();
        for (int i = 0; i < length/2; i++)
            stack.push(rand() % length);
        stack.Display();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        time.push_back(duration.count());
    }
    for (double i : time){
        sum+=i;

    }
    cout<<sum/time.size()<<"microseconds";


    return 0;
}