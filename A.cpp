#include <iostream>
#include <math.h>
#include <deque>

void data_read();
void bus_analysis();
bool is_integer(float k);


int main() {
    bus_analysis();
    return 0;
}

void bus_analysis() {
    int n;
    int full_sum = 0;
    std::cin >> n;
    int tab[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> tab[i];
    }

    int subset = 1 << n;
    full_sum = 2 * n;
    std::deque<int> dq;

    for (int mask = 2; mask < subset; mask++) {
        dq.clear();
        if ((mask & mask - 1) == 0){
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                dq.push_back(tab[i]);
            }

        }
        
        for (auto& d : dq) {
            std::cout << d << " ";
        }
        std::cout << std::endl;
    }

}

bool is_integer(float k) {
    return std::floor(k)==k;
}