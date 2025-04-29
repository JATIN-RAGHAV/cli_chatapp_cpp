add_executable(frontend main.cpp)

configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/.env"
        "${CMAKE_CURRENT_BINARY_DIR}/.env"
        COPYONLY
)

target_link_libraries(frontend PRIVATE common)
