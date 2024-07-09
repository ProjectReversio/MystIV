project(aresdx_app_rd)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} SHARED "")
target_compile_definitions(${PROJECT_NAME} PRIVATE ARESDX_APP_RD_LIBRARY)
target_sources(${PROJECT_NAME}
    PRIVATE
        aresdx_app_rd.cpp
    PUBLIC
        aresdx_app_rd.hpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
