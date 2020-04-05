#include "List.h"

// when list is at capacity, it overwrites the oldest data

List::List(int capacity) {
    _capacity = capacity;
    size = 0;

    _data = new unsigned int[_capacity](); // initializes to 0
    _currentIdx = 0;
}

void List::push(unsigned int value) {
    // pops value if list too big
    _data[_currentIdx] = value;
    _currentIdx++;
    _currentIdx = _currentIdx % _capacity;
    Serial.println(_currentIdx);
    
    size++;
    size = min(size, _capacity);
}

float List::getMean() {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        total += (float) _data[i];
    }
    float mean = total / size;
    return mean;
}