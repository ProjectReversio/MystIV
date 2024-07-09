project(Myst4)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} WIN32 "")
target_link_libraries(${PROJECT_NAME} PRIVATE CrashRpt base_rd aresdx_app_rd m4_thor_rd)

target_sources(${PROJECT_NAME}
    PRIVATE
        resource.h
        resource.rc
        main.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)