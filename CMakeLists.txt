project(MapPointsExtractor)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(QOBJECT_SRCS MapPointsExtractor.h)

#qt4_wrap_ui(QT_UICES_HEADERS untitled.ui)
qt4_wrap_cpp(QT_MOCED_FILES ${QOBJECT_SRCS})

set(MapPointsExtractor_SRCS main.cpp MapPointsExtractor.cpp)

add_executable(MapPointsExtractor ${MapPointsExtractor_SRCS} ${QT_MOCED_FILES} ${QT_UICES_HEADERS})
target_link_libraries(MapPointsExtractor ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTWEBKIT_LIBRARY} ${QT_QTNETWORK_LIBRARY})
