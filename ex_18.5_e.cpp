#include <iostream>
#include <vector>

template <typename T>
class Array {
private:
    std::vector<T> data;

public:
    Array(const std::vector<T>& vec) : data(vec) {}

    void insertionSort() {
        for (size_t i = 1; i < data.size(); ++i) {
            T key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                --j;
            }
            data[j + 1] = key;
        }
    }

    void print() const {
        for (const T& elem : data) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> vec = {8, 3, 7, 1, 4, 2, 5};
    Array<int> array(vec);

    std::cout << "Before sorting: ";
    array.print();

    array.insertionSort();

    std::cout << "After sorting: ";
    array.print();

    return 0;
}
