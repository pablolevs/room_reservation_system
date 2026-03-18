#include "ReservationSystem.hpp"

ReservationSystem::ReservationSystem(int room_count, int* room_capacities) {
    this->room_count = room_count;
    this->room_capacities = new int[room_count];
    for (int i = 0; i < room_count; i++) {
        this->room_capacities[i] = room_capacities[i];
    }

    this->room_schedules = new ReservationNode*[room_count];
    for (int i = 0; i < room_count; i++) {
        this->room_schedules[i] = nullptr;
    }
}

ReservationSystem::~ReservationSystem() {
    delete []room_capacities;

    for (int i = 0; i < room_count; i++) {
        ReservationNode* atual = room_schedules[i];
        while (atual != nullptr) {
            ReservationNode* proximo = atual->next;
            delete atual;
            atual = proximo;
        }
    }
    delete[] room_schedules;
}

bool ReservationSystem::reserve(ReservationRequest request){
    for (int i = 0; i < room_count; i++) {
        if (this->room_capacities[i] >= request.getStudentCount()) {
            bool conflito = false;
            ReservationNode* temp = this->room_schedules[i];

            while (temp != nullptr) {
                if (temp->request.getWeekday() == request.getWeekday()) {
                    if(request.getStartHour() < temp->request.getEndHour() &&
                    temp->request.getStartHour() < request.getEndHour()) {
                        conflito = true;
                        break;
                    }
                }
                temp = temp->next;
            }

            if (conflito == false) {
                ReservationNode* novoNo = new ReservationNode(request);

                novoNo->next = this->room_schedules[i];
                this->room_schedules[i] = novoNo;

                return true;
            }
        }
    }
    return false;
}