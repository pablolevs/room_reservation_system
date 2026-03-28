#include <iostream>
#include "ReservationSystem.hpp"
#include "ReservationRequest.hpp"
using namespace std;

int main()
{
    // ===== Criação do Sistema =====
    int capacities[3] = {30, 50, 80};
    ReservationSystem system(3, capacities);

    // ===== Reserva de Salas =====
    // '1' representa sucesso e '0' representa falha
    cout << "===== Reserva de Salas =====" << endl;
    ReservationRequest req1("Calculo I", "segunda", 7, 9, 25);
    bool r1 = system.reserve(req1);
    cout << "Reserva 1: " << r1 << endl;

    ReservationRequest req2("Algebra Linear", "segunda", 8, 10, 20);
    bool r2 = system.reserve(req2);
    cout << "Reserva 2: " << r2 << endl;

    ReservationRequest req3("Fisica I", "segunda", 9, 11, 25);
    bool r3 = system.reserve(req3);
    cout << "Reserva 3: " << r3 << endl;

    ReservationRequest req4("Dados", "segunda", 7, 9, 45);
    bool r4 = system.reserve(req4);
    cout << "Reserva 4: " << r4 << endl;

    // ===== Reserva com capacidade indisponível =====
    ReservationRequest req5("Projeto", "terca", 10, 12, 100);
    bool r5 = system.reserve(req5);
    cout << "Reserva 5: " << r5 << endl;

    // ===== Reserva com horário conflitante =====
    ReservationRequest req6("Cálculo Vetorial", "segunda", 8, 10, 20);
    bool r6 = system.reserve(req6);
    cout << "Reserva 6: " << r6 << endl;

    cout << endl;

    // ===== Mostrar cronograma =====
    cout << "===== Cronograma =====" << endl;
    system.printSchedule();

    // ===== Cancelar uma reserva =====
    cout << "===== Cancelando uma reserva =====" << endl;
    system.cancel("Algebra Linear");
    cout << "Reserva para Algebra Linear cancelada" << endl;
    cout << endl;

    // ===== Cancelar uma reserva inexistente =====
    system.cancel("Inexistente");

    cout << "===== Cronograma final =====" << endl;
    system.printSchedule();

    return 0;
}
