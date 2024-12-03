#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Auto {
    std::string brand;
    std::string model;
    std::string number;
    std::string owner;
    double repairCost;

    Auto(std::string b, std::string m, std::string n, std::string o, double cost)
        : brand(b), model(m), number(n), owner(o), repairCost(cost) {}
};

struct CompareRepairCost {
    bool operator()(const Auto& a, const Auto& b) {
        return a.repairCost > b.repairCost;
    }
};

int main() {
    std::priority_queue<Auto, std::vector<Auto>, CompareRepairCost> repairQueue;

    repairQueue.emplace("Toyota", "Corolla", "AB1234CD", "John Doe", 500.0);
    repairQueue.emplace("Honda", "Civic", "BC5678EF", "Jane Smith", 300.0);
    repairQueue.emplace("Ford", "Focus", "CD9012GH", "Mike Brown", 700.0);

    std::cout << "Repair queue processing:\n";
    while (!repairQueue.empty()) {
        Auto car = repairQueue.top();
        repairQueue.pop();
        std::cout << "Brand: " << car.brand
                  << ", Model: " << car.model
                  << ", Number: " << car.number
                  << ", Owner: " << car.owner
                  << ", Repair Cost: $" << car.repairCost << std::endl;
    }

    return 0;
}