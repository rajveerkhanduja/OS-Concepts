#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void mfuPageReplacement(const vector<int>& pages, int noFrames) {
    vector<int> frames(noFrames, -1);       // Frame slots initialized to -1
    vector<int> frameFrequency(noFrames, 0); // Tracks frequency of each frame
    int hit = 0, miss = 0;

    cout << "Page\tFrames\t\tStatus\n";

    for (size_t pageIndex = 0; pageIndex < pages.size(); pageIndex++) {
        int page = pages[pageIndex];
        bool pageHit = false;

        // Check if the page is already in one of the frames (Page Hit)
        for (int i = 0; i < noFrames; i++) {
            if (frames[i] == page) {
                hit++;
                frameFrequency[i]++;
                pageHit = true;
                break;
            }
        }

        if (!pageHit) { // Page Miss
            miss++;
            bool emptyFrameAvailable = false;

            // Place the page in an empty frame, if available
            for (int i = 0; i < noFrames; i++) {
                if (frames[i] == -1) {
                    frames[i] = page;
                    frameFrequency[i] = 1; // Initialize frequency for the new page
                    emptyFrameAvailable = true;
                    break;
                }
            }

            // Replace the most frequently used page if no empty frame is available
            if (!emptyFrameAvailable) {
                int mfuIndex = 0; // Index of the Most Frequently Used page
                for (int i = 1; i < noFrames; i++) {
                    if (frameFrequency[i] > frameFrequency[mfuIndex]) {
                        mfuIndex = i;
                    }
                }

                frames[mfuIndex] = page;
                frameFrequency[mfuIndex] = 1; // Reset frequency for the new page
            }
        }

        // Display the current status of the frames
        cout << page << "\t";
        for (int frame : frames) {
            if (frame == -1)
                cout << "- ";
            else
                cout << frame << " ";
        }
        cout << (pageHit ? "\tHit" : "\tMiss") << endl;
    }

    // Output the number of hits and misses
    cout << "\nTotal Page Hits: " << hit;
    cout << "\nTotal Page Misses: " << miss << endl;
}

int main() {
    int noFrames, noPages;

    cout << "Enter the number of frames: ";
    cin >> noFrames;

    cout << "Enter the number of pages: ";
    cin >> noPages;

    vector<int> pages(noPages);
    cout << "Enter the page string: ";
    for (int i = 0; i < noPages; i++) {
        cin >> pages[i];
    }

    mfuPageReplacement(pages, noFrames);

    return 0;
}