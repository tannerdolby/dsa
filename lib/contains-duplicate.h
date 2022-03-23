// O(n) time and O(n) space where n = length of the input sequence
template <typename T>
bool containsDuplicate(std::vector<T> &sequence) {
    std::unordered_set<T> uset;
    for (auto val : sequence) {
        if (uset.count(val) > 0) {
            return true;
        }
        uset.insert(val);
    }
    return false;
}