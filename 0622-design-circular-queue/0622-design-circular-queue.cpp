class MyCircularQueue {
    int *q, front, rear, size, cap;

public:
    MyCircularQueue(int k) {
        q = new int[k];
        front = 0;
        rear = -1;
        size = 0;
        cap = k;
    }

    bool enQueue(int value) {
        if (size == cap)
            return false;
        rear = (rear + 1) % cap;
        q[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (size == 0)
            return false;
        front = (front + 1) % cap;
        size--;
        return true;
    }

    int Front() { return size == 0 ? -1 : q[front]; }

    int Rear() { return size == 0 ? -1 : q[rear]; }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == cap; }

    ~MyCircularQueue() { delete[] q; }
};