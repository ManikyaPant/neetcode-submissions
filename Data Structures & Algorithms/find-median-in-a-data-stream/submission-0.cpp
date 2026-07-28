class MedianFinder {
public:
    multiset<int> st1, st2;

    MedianFinder() {
    }

    void addNum(int num) {
        if (st1.empty() || num <= *st1.rbegin()) {
            st1.insert(num);
        } else {
            st2.insert(num);
        }

       
        if (st1.size() > st2.size() + 1) {
            auto it = prev(st1.end());
            st2.insert(*it);
            st1.erase(it);
        }

        // st2 should never have more elements than st1
        if (st2.size() > st1.size()) {
            auto it = st2.begin();
            st1.insert(*it);
            st2.erase(it);
        }
    }

    double findMedian() {
        int totalSize = st1.size() + st2.size();

        if (totalSize % 2 == 1) {
            return static_cast<double>(*st1.rbegin());
        }

        long long left = *st1.rbegin();
        long long right = *st2.begin();

        return (left + right) / 2.0;
    }
};