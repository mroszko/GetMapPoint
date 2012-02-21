project(MapPointsExtractor)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(MapPointsExtractor_SRCS MapPointsExtractor.cpp main.cpp)
qt4_automoc(${MapPointsExtractor_SRCS})
add_executable(MapPointsExtractor ${MapPointsExtractor_SRCS})
target_link_libraries(MapPointsExtractor ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
