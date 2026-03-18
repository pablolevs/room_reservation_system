#ifndef RESERVATIONREQUEST_HPP
#define RESERVATIONREQUEST_HPP

#include <iostream>
#include <string>

class ReservationRequest {

private:
    std::string course_name;
    std::string weekday;
    int start_hour;
    int end_hour;
    int student_count;

public:
    ReservationRequest() {}
    ReservationRequest(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count);

    int getStartHour();
    int getEndHour();
    std::string getCourseName();
    std::string getWeekday();
    int getStudentCount();
};

#endif