#include <iostream>
#ifndef RESERVATIONREQUEST_HPP
#define RESERVATIONREQUEST_HPP

class ReservationRequest {

private:
    std::string course_name;
    std::string weekday;
    int start_hour;
    int end_hour;
    int student_count;

public:

    ReservationRequest(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count);

    int getStartHour();
    int getEndHour();
    std::string getCourseName();
    std::string getWeekday();
    int getStudentCount();
};

#endif