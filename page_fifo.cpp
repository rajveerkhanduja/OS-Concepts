#include <iostream>
#include <vector>
#include <iomanip> // For formatting output

using namespace std;

void printFrames(const vector<int>& frames) {
    for (int frame : frames) {
        if (frame != -1)
            cout << setw(8) << frame;
        else
            cout << setw(8) << "-";
    }
}

int main() {
    vector<int> incomingStream = {4, 1, 2, 4, 5};
    int pageFaults = 0;
    int frameCount = 3;

    cout << "Incoming Stream\t Frame 1\t Frame 2\t Frame 3\n";

    vector<int> frames(frameCount, -1); // Initialize frames with -1

    for (size_t i = 0; i < incomingStream.size(); i++) {
        int currentPage = incomingStream[i];
        bool isPageInFrame = false;

        // Check if the current page is already in the frame
        for (int frame : frames) {
            if (frame == currentPage) {
                isPageInFrame = true;
                break;
            }
        }

        if (!isPageInFrame) {
            pageFaults++;
            // Replace the page in a circular manner
            frames[(pageFaults - 1) % frameCount] = currentPage;
        }

        // Print the current page and the state of the frames
        cout << setw(15) << currentPage;
        printFrames(frames);
        cout << "\n";
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;

    return 0;
}