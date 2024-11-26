#include <iostream>
#include <vector>
#include <algorithm> // For std::find

using namespace std;

void lru(const vector<int>& referenceString, int frameCount) {
    // Store the current pages in frames
    vector<int> frames(frameCount, -1);
    vector<int> recentlyUsed(frameCount, -1); // Keeps track of LRU index
    int pageHits = 0;
    int pageMisses = 0;

    cout << "Symbol\tFrames\n";

    for (size_t i = 0; i < referenceString.size(); i++) {
        int symbol = referenceString[i];
        auto it = find(frames.begin(), frames.end(), symbol);

        // If the symbol is already in the frames (Page Hit)
        if (it != frames.end()) {
            pageHits++;
            recentlyUsed[it - frames.begin()] = i; // Update the recent usage index
        } else {
            // Page Miss: Replace the least recently used frame
            pageMisses++;
            if (find(frames.begin(), frames.end(), -1) != frames.end()) {
                // If there are empty frames, find the first -1
                auto emptyFrame = find(frames.begin(), frames.end(), -1);
                *emptyFrame = symbol;
                recentlyUsed[emptyFrame - frames.begin()] = i;
            } else {
                // Replace the least recently used frame
                int lruIndex = distance(recentlyUsed.begin(), min_element(recentlyUsed.begin(), recentlyUsed.end()));
                frames[lruIndex] = symbol;
                recentlyUsed[lruIndex] = i;
            }
        }

        // Display the current frames state
        cout << symbol << "\t";
        for (int frame : frames) {
            if (frame == -1)
                cout << "- ";
            else
                cout << frame << " ";
        }
        cout << endl;
    }

    cout << "\nPage Hits: " << pageHits;
    cout << "\nPage Misses: " << pageMisses << endl;
}

int main() {
    vector<int> referenceString = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int frameCount = 4;

    lru(referenceString, frameCount);

    return 0;
}