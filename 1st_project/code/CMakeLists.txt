cmake_minimum_required(VERSION 3.20)
project(AirportManagement_AED_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(AirportManagement_AED_Project src/main.cpp src/Plane.cpp include/Plane.h src/Service.cpp include/Service.h src/Flight.cpp include/Flight.h src/Passenger.cpp include/Passenger.h include/Date.h src/Ticket.cpp include/Ticket.h src/Company.cpp include/Company.h src/Date.cpp src/Airport.cpp include/Airport.h include/Transports.h src/Transports.cpp)
