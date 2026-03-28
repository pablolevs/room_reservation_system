#include "ReservationSystem.hpp"
using namespace std;

ReservationSystem::ReservationSystem(int room_count, int *room_capacities)
{
    this->room_count = room_count;
    this->room_capacities = new int[room_count];
    for (int i = 0; i < room_count; i++)
    {
        this->room_capacities[i] = room_capacities[i];
    }

    this->room_schedules = new ReservationNode *[room_count];
    for (int i = 0; i < room_count; i++)
    {
        this->room_schedules[i] = nullptr;
    }
}

ReservationSystem::~ReservationSystem()
{
    delete[] room_capacities;

    for (int i = 0; i < room_count; i++)
    {
        ReservationNode *atual = room_schedules[i];
        while (atual != nullptr)
        {
            ReservationNode *proximo = atual->next;
            delete atual;
            atual = proximo;
        }
    }
    delete[] room_schedules;
}

int ReservationSystem::getDayNumber(string weekday)
{
    if (weekday == "segunda")
        return 1;
    if (weekday == "terca")
        return 2;
    if (weekday == "quarta")
        return 3;
    if (weekday == "quinta")
        return 4;
    if (weekday == "sexta")
        return 5;
    return 0;
}

bool ReservationSystem::reserve(ReservationRequest request)
{
    for (int i = 0; i < room_count; i++)
    {
        if (this->room_capacities[i] >= request.getStudentCount())
        {
            bool conflito = false;
            ReservationNode *temp = this->room_schedules[i];

            while (temp != nullptr)
            {
                if (temp->request.getWeekday() == request.getWeekday())
                {
                    if (request.getStartHour() < temp->request.getEndHour() &&
                        temp->request.getStartHour() < request.getEndHour())
                    {
                        conflito = true;
                        break;
                    }
                }
                temp = temp->next;
            }

            if (conflito == false)
            {
                ReservationNode *novoNo = new ReservationNode(request);
                ReservationNode *atual = room_schedules[i];
                ReservationNode *anterior = nullptr;

                while (atual != nullptr)
                {
                    int diaAtual = getDayNumber(atual->request.getWeekday());
                    int diaNovo = getDayNumber(request.getWeekday());

                    if (diaNovo < diaAtual)
                    {
                        break;
                    }
                    else if (diaNovo == diaAtual)
                    {
                        if (request.getStartHour() < atual->request.getStartHour())
                        {
                            break;
                        }
                        else
                        {
                            anterior = atual;
                            atual = atual->next;
                        }
                    }
                    else
                    {
                        anterior = atual;
                        atual = atual->next;
                    }
                }

                if (anterior == nullptr)
                {
                    novoNo->next = room_schedules[i];
                    room_schedules[i] = novoNo;
                }
                else
                {
                    novoNo->next = atual;
                    anterior->next = novoNo;
                }

                return true;
            }
        }
    }
    return false;
}

bool ReservationSystem::cancel(string course_name)
{
    for (int i = 0; i < room_count; i++)
    {
        ReservationNode *atual = room_schedules[i];
        ReservationNode *anterior = nullptr;
        while (atual != nullptr)
        {
            if (atual->request.getCourseName() == course_name)
            {
                if (anterior == nullptr)
                {
                    room_schedules[i] = atual->next;
                }
                else
                {
                    anterior->next = atual->next;
                }
                delete atual;
                return true;
            }
            anterior = atual;
            atual = atual->next;
        }
    }
    return false;
}

void ReservationSystem::printSchedule()
{
    for (int i = 0; i < room_count; i++)
    {
        cout << "Room " << i << endl;

        ReservationNode *atual = room_schedules[i];

        while (atual != nullptr)
        {
            string diaAtual = atual->request.getWeekday();

            cout << diaAtual << ":" << endl;
            while (atual != nullptr && atual->request.getWeekday() == diaAtual)
            {
                cout << atual->request.getStartHour()
                     << "h~" << atual->request.getEndHour()
                     << "h: " << atual->request.getCourseName() << endl;

                atual = atual->next;
            }
        }
        cout << endl;
    }
}