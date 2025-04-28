file(GLOB UTILS_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

add_library(common STATIC ${UTILS_FILES})

target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(libpqxx REQUIRED)

target_link_libraries(common PRIVATE libpqxx::pqxx)
