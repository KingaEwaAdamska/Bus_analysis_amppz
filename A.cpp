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

    struct station {
        int time;
        short cost = 0;
    };

    int n;
    int full_sum = 0;
    std::cin >> n;
    int tab[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> tab[i];
    }

    int subset = 1 << n;
    full_sum = 2 * n;
    std::deque<station> dq;

    for (int mask = 2; mask < subset; mask++) {
        dq.clear();
        if ((mask & mask - 1) == 0){
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                dq.push_back({tab[i]});
            }
        }
        int ticket_end = 0;
        int full_ride_cost = 0;
        int tmp_cost = 0;
        for (auto it = dq.begin(); it != dq.end(); ++it) {
            if (ticket_end < (*it).time) {
                (*it).cost = 2;
                ticket_end = (*it).cost + 20;
                tmp_cost += (*it).cost;
            }
        }
        
        for (auto it = dq.begin(); it != dq.end(); ++it) {
            std::cout << (*it).time << " ";
        }
        std::cout << std::endl;
        full_sum += tmp_cost;
    }
    std::cout << std::endl << full_sum << std::endl;
}

bool is_integer(float k) {
    return std::floor(k)==k;
}