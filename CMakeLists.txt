cmake_minimum_required(VERSION 3.28)
project(MuzTorgZ)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(Windows Models Database Tools Database Dialogs)

find_package(OpenSSL REQUIRED)
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        REQUIRED)

add_executable(MuzTorgZ main.cpp
        Windows/authorizationwin.cpp
        Windows/authorizationwin.h
        Windows/authorizationwin.ui
        Models/CurrentUser.h
        Models/Roles.h
        Database/dbmanager.cpp
        Database/dbmanager.h
        Models/CurrentUser.cpp
        Tools/Hashing.cpp
        Tools/Hashing.h
        Tools/MuzMsgBox.h
        Windows/dbwindow.cpp
        Windows/dbwindow.h
        Windows/dbwindow.ui
        Dialogs/regdialog.cpp
        Dialogs/regdialog.h
        Dialogs/regdialog.ui
)


target_link_libraries(MuzTorgZ
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        OpenSSL::SSL
        OpenSSL::Crypto
)





