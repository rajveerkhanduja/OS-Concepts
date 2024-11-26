#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class ProducerConsumer {
private:
    int bufferSize;  // Size of the buffer
    int full;        // Number of full slots
    int empty;       // Number of empty slots
    int item;        // Current item in the buffer

    mutex mtx;                  // Mutex for critical section
    condition_variable cv;      // Condition variable for synchronization

public:
    // Constructor to initialize buffer size
    ProducerConsumer(int size) : bufferSize(size), full(0), empty(size), item(0) {}

    // Producer function
    void producer() {
        unique_lock<mutex> lock(mtx);  // Lock the mutex

        // Wait if the buffer is full
        cv.wait(lock, [this]() { return empty > 0; });

        // Produce an item
        ++full;
        --empty;
        ++item;
        cout << "Producer produces item " << item << endl;

        // Notify the consumer
        cv.notify_all();
    }

    // Consumer function
    void consumer() {
        unique_lock<mutex> lock(mtx);  // Lock the mutex

        // Wait if the buffer is empty
        cv.wait(lock, [this]() { return full > 0; });

        // Consume an item
        --full;
        ++empty;
        cout << "Consumer consumes item " << item << endl;
        --item;

        // Notify the producer
        cv.notify_all();
    }
};

int main() {
    int bufferSize = 10;  // Size of the buffer
    ProducerConsumer pc(bufferSize);

    int choice;

    cout << "1. Press 1 for Producer" << endl;
    cout << "2. Press 2 for Consumer" << endl;
    cout << "3. Press 3 for Exit" << endl;

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            thread producerThread(&ProducerConsumer::producer, &pc);
            producerThread.join();
            break;
        }
        case 2: {
            thread consumerThread(&ProducerConsumer::consumer, &pc);
            consumerThread.join();
            break;
        }
        case 3:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}