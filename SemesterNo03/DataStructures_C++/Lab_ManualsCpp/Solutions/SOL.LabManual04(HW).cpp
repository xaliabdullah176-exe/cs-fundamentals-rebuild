
#include <iostream>
#include <string>

using namespace std;

// Node of the singly linked list representing one visited page.

// so BrowserHistory can link/unlink nodes directly, the same way

class Node {
public:
    string url;
    Node* next;

    Node(const string &u) : url(u), next(nullptr) {}
};

// isFull() doesn't make sense for a linked-list-backed stack because the
// nodes are allocated one at a time from the heap as pages are visited,
// instead of living inside a fixed-size array reserved up front - so
// there is no pre-set capacity to ever reach (the only limit is the
// machine running out of memory, which is not a "full lane" condition
// the class itself can meaningfully detect or report).
class BrowserHistory {
private:
    Node* top;      // pointer to the node for the current page
    int count;       // number of pages currently in the history

public:
    BrowserHistory() {
        top = nullptr;
        count = 0;
    }

    // visit(url) - create a new node for url and push it on top
    void visit(const string &url) {
        Node* newNode = new Node(url);
        newNode->next = top;
        top = newNode;
        count++;
        cout << " Navigated to \"" << url << "\"." << endl;
    }

    // goBack() - pop the current page off the history and delete its node;
    // the page now on top becomes the current page
    void goBack() {
        if (isEmpty()) {
            cout << " !! Stack Underflow !! No previous page to go back to." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
        count--;

        if (isEmpty())
            cout << " Went back. No pages left in history." << endl;
        else
            cout << " Went back. You landed on \"" << top->url << "\"." << endl;
    }

    // currentPage() - peek at the page on top without changing anything
    string currentPage() {
        if (isEmpty()) {
            cout << " No pages visited yet." << endl;
            return "";
        }
        return top->url;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    // historyCount() - how many pages are currently in the back-history
    int historyCount() {
        return count;
    }

    // showHistory() - print all visited pages from most recent to oldest,
    // without modifying the list
    void showHistory() {
        if (isEmpty()) {
            cout << " History is empty." << endl;
            return;
        }
        cout << " History (most recent -> oldest): ";
        Node* curr = top;
        while (curr != nullptr) {
            cout << curr->url << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Destructor - free every remaining node so no memory is leaked
    ~BrowserHistory() {
        while (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

void runBrowserHistory() {
    BrowserHistory history;
    int choice;

    do {
        cout << "\n------ Browser History (Linked List Stack) ------" << endl;
        cout << "1. Visit a new page" << endl;
        cout << "2. Go Back" << endl;
        cout << "3. Show Current Page" << endl;
        cout << "4. Show Full History" << endl;
        cout << "5. Show History Count" << endl;
        cout << "-1. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string url;
                cout << "Enter URL to visit: ";
                cin >> url;
                history.visit(url);
                break;
            }
            case 2:
                history.goBack();
                break;
            case 3: {
                string page = history.currentPage();
                if (!page.empty())
                    cout << " Current page: " << page << endl;
                break;
            }
            case 4:
                history.showHistory();
                break;
            case 5:
                cout << " Pages in history: " << history.historyCount() << endl;
                break;
            case -1:
                cout << "Exiting Program..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != -1);
}

int main() {
    runBrowserHistory();
    return 0;
}
