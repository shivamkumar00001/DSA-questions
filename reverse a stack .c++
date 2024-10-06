#include <stack>
#include <iostream>

void insertAtBottom(std::stack<int>& St, int element) {
    if (St.empty()) {
        St.push(element);
        return;
    }

    int top = St.top();
    St.pop();
    
    insertAtBottom(St, element); 
    
    St.push(top); 
}

void rev(std::stack<int>& St) {
    if (St.empty()) {
        return; 
    }

    int top = St.top();
    St.pop();
    
    rev(St); 
    
    insertAtBottom(St, top); 
}

void Reverse(std::stack<int>& St) {
    rev(St);
}

// Example usage
int main() {
    std::stack<int> St;
    St.push(1);
    St.push(2);
    St.push(3);
    St.push(4);

    Reverse(St);

    while (!St.empty()) {
        std::cout << St.top() << " ";
        St.pop();
    }

    return 0;
}
