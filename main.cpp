#include <iostream>
#include "CircularSequentialQueue.h"

using namespace std;
int main() {
    CircularSequentialQueue<int> queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    queue.dequeue();
    queue.enqueue(5);
    return 0;
}