cmake_minimum_required(VERSION 3.9)
project(ConnectN C)

set(CMAKE_C_STANDARD 11)

set(CURSES_USE_NCURSES TRUE)
find_package(Curses REQUIRED)

add_executable(ConnectN main.c Board.c Board.h CursortrackedWindow.c CursortrackedWindow.h GetMove.c GetMove.h InputWindow.c InputWindow.h win.c win.h OutputWindow.c OutputWindow.h)
target_link_libraries(ConnectN PRIVATE ${CURSES_LIBRARIES})
target_include_directories(ConnectN PRIVATE ${CURSES_INCLUDE_DIRS})




