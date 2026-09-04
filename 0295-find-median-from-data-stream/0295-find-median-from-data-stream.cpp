class MedianFinder {
public:
    // Smaller half
    priority_queue<int> left;

    // Larger half
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {
    }

    void addNum(int num) {
        // Put num into left first
        left.push(num);

        // Largest element of left goes to right
        right.push(left.top());
        left.pop();

        // Keep left size >= right size
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }

        return (left.top() + right.top()) / 2.0;
    }
};