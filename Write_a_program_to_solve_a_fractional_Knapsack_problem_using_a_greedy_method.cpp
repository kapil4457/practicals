#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
public:
    int weight;
    int value;

    
    Item() {
        weight = 0;
        value = 0;
    }

    
    Item(int w, int v) {
        weight = w;
        value = v;
    }
};

bool compareItems(const Item& item1, const Item& item2) {
    double ratio1 = static_cast<double>(item1.value) / item1.weight;
    double ratio2 = static_cast<double>(item2.value) / item2.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < items.size(); i++) {
        const Item& item = items[i];
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += (static_cast<double>(remainingCapacity) / item.weight) * item.value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the weight and value of item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    double maxValue = fractionalKnapsack(items, capacity);

    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}