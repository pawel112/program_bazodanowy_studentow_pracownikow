cmake_minimum_required (VERSION 2.6)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lista.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
SET (name program_bazodanowy)
SET (sources glowny.cpp zapis_odczyt.cpp obiekty.cpp menu.cpp)
SET (headers zapis_odczyt.h menu.h obiekty.h)
project (${name})
add_executable (${name} ${sources} ${headers})