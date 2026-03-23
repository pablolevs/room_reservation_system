#ifndef RESERVATIONSYSTEM_HPP
#define RESERVATIONSYSTEM_HPP

#include <iostream>
#include "ReservationRequest.hpp"
using namespace std;

struct ReservationNode
{
    ReservationRequest request;
    ReservationNode *next;

    ReservationNode(ReservationRequest req)
    {
        this->request = req;
        this->next = nullptr;
    }
};

class ReservationSystem
{

private:
    int room_count;
    int *room_capacities;
    // Estruturas internas escolhidas pelos alunos
    // para armazenar e gerenciar as reservas, os horários, ...
    ReservationNode **room_schedules;

public:
    ReservationSystem(int room_count, int *room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);
    void printSchedule();
    int getDayNumber(string weekday);

    // Outros métodos utilitários necessários
    // para auxiliar nas funções requisitadas
};

#endif