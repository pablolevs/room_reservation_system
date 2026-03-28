# Room Reservation System

## Descrição

Este é um sistema de reservas de salas para matérias a serem lecionadas em uma universidade.
Para cada nova reserva, procura a priemeira sala disponível que não esteja ocupada no horário pedido e que tenha
a capacidade necessária. Cada reserva contém o nome da matéria, o tamanho da turma, o dia da semana (é considerado 
apenas dias de segunda a sexta) e o horário de início e o horário de término da aula.

**Funcionalidades:**
- reserve (Faz uma reserva para uma aula)
- cancel (Cancela uma reserva feita)
- printSchedule (Exibe o cronograma das aulas, dividido por salas, dias da semana e horários)
- getDayNumber (Função auxiliar que converte os dias da semana em números inteiros, ajuda na inserção correta)

## Estrutura dos arquivos
- main.cpp (Programa principal com casos testes)
- ReservationSystem.hpp (Declaração da classe ReservationSystem e seus métodos)
- ReservationSystem.cpp (Implementação da classe ReservationSystem)
- ReservationRequest.hpp (Declaração da classe ReservationRequest e seus getters)
- ReservationRequest.cpp (Implementação da classe ReservationRequest)

## Compilação

Para compilar o projeto, utilize este comando no terminal:

```bash
g++ main.cpp ReservationSystem.cpp ReservationRequest.cpp -o reservation_system
```

## Execução

Após a compilação, execute o programa com:

```bash
./reservation_system
```

O programa exibirá os resultados dos testes implementados no main.cpp, entre eles, reservas bem sucedidas, reservas mal sucedidas negadas
por conflito de horários e por falta de capacidade. Exibe o cronograma após as reservas, cancela uma reserva, e exibe o cronograma após o
cancelamento.

## Organização dos Dados

- Salas: Um array armazena a capacidade de cada sala.
- Reservas: Cada sala contém uma lista encadeada (`ReservationNode`) contendo cada recerva feita.
- Ordenação: As reservas são adicionadas de forma já ordenada por dia da semana (segunda a sexta) e por horário (7h as 21h).
- Verificação: Ao fazer um requerimento de reserva, o sistema analisa a capacidade de cada sala e a sobreposição dos horários
e reserva a primeria disponível.
- Cancelamento: Percorre cada reserva buscando pelo nome da matéria a ser cancelada, ao achar, apaga a reserva e libera a memória.

## Complexidade

- Adicionar uma nova reserva tem custo O(n) onde **n** é o número de reservas na sala (pois percorre cada reserva para ver em qual posição se deve adicionar)
- Cancelar uma reserva tem custo O(m) onde **m** é o número total de reservas (pois percorre todas as reservas em busca daquela a ser cancelada)
- Verificação tem custo O(k) por sala, onde **k** é o número de reservas naquela sala (pois percorre cada reserva verificando os horários)

## Autores

- Raul Medici Martinelli
- Pablo Levy Fernandes Alcântara



