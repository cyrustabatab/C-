#include <queue>
#include <stack>
#include <iostream>

int main() {
    
    std::queue<int> q;

    q.push(1);
    q.push(2);

    std::cout << "front = " << q.front() << " and back = " << q.back() << std::endl;


    q.pop();
    std::cout << "front = " << q.front() << " and back = " << q.back() << std::endl;
    

    std::stack<int> s;

    s.push(1);
    s.push(2);

    std::cout << "top = " << s.top() << std::endl;

    s.pop();

    std::cout << "top = " << s.top() << std::endl;


}

