project(CrashRpt)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} SHARED "")
target_compile_definitions(${PROJECT_NAME} PRIVATE CRASHRPT_LIBRARY)
target_sources(${PROJECT_NAME}
    PRIVATE
        CrashRpt.cpp
    PUBLIC
        CrashRpt.hpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
