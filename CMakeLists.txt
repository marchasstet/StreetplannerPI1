cmake_minimum_required(VERSION 3.5)

project(StreetplannerWorking VERSION 0.1 LANGUAGES CXX)
set(CMAKE_OSX_SYSROOT /Library/Developer/CommandLineTools/SDKs/MacOSX14.5.sdk)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(StreetplannerWorking
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        city.h city.cpp
        map.h map.cpp
        abstractmap.cpp
        abstractmap.h
        streets.h streets.cpp
        street.h street.cpp
        neue_stadt_hinzufuegen.h neue_stadt_hinzufuegen.cpp neue_stadt_hinzufuegen.ui
        mapio.cpp
        mapio.h
        mapionrw.cpp
        mapionrw.h
        dijkstra.cpp
        dijkstra.h
        pathdialog.h pathdialog.cpp pathdialog.ui
        makestreet.h makestreet.cpp makestreet.ui
        bigtown.h bigtown.cpp
        smallcity.h smallcity.cpp
        mapiofileinput.h
        mapiofileinput.cpp
        smalltown.h smalltown.cpp
        txtFiles/city_file_small.txt
        txtFiles/city_file_zusatz.txt
        txtFiles/city_file.txt
        txtFiles/street_file_small.txt
        txtFiles/street_file_zusatz.txt
        txtFiles/street_file.txt




    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET StreetplannerWorking APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(StreetplannerWorking SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(StreetplannerWorking
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(StreetplannerWorking PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.StreetplannerWorking)
endif()
set_target_properties(StreetplannerWorking PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS StreetplannerWorking
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(StreetplannerWorking)
endif()
