project(m4_thor_rd)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} SHARED "")
target_compile_definitions(${PROJECT_NAME} PRIVATE M4_THOR_RD_LIBRARY)
target_link_libraries(${PROJECT_NAME} PRIVATE base_rd aresdx_app_rd)
target_sources(${PROJECT_NAME}
    PRIVATE
        m4_thor_rd.cpp
    PUBLIC
        m4_thor_rd.hpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
