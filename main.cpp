#include <iostream>
#include "ReservationSystem.hpp"
#include "ReservationRequest.hpp"
using namespace std;

int main() {
    int capacities[3] = {30, 50, 80};
    ReservationSystem system(3, capacities);
}