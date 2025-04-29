file(GLOB COMMON_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/*/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp"
)


add_library(common STATIC ${COMMON_FILES})

target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/database")

find_package(libpqxx REQUIRED)
find_package(libenvpp REQUIRED)

target_link_libraries(common PRIVATE libpqxx::pqxx)
target_link_libraries(common PRIVATE libenvpp::libenvpp)
