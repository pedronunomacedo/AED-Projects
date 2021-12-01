cmake_minimum_required(VERSION 3.20)
project(AirportManagement_AED_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(AirportManagement_AED_Project main.cpp Tests/Plane.cpp Tests/Plane.h Tests/tests.cpp Tests/Service.cpp Tests/Service.h Tests/Flight.cpp Tests/Flight.h Tests/Passenger.cpp Tests/Passenger.h Tests/Date.h Tests/Ticket.cpp Tests/Ticket.h Tests/Company.cpp Tests/Company.h)
