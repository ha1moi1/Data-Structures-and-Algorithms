#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(7);
    q.push(5);
    cout << q.front() << " " << q.back() << endl;
    q.pop();

    cout << "Front element after pop: " << q.front() << endl;
}