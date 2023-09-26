# Build main.c on PROJECT_NAME, I could call it wahtever I wanted
add_executable(
    main 
    Main.cpp 
    Knight.cpp 
    State.cpp 
    IdleState.cpp 
    WalkState.cpp 
    ImageLoader.cpp
    AttackState.cpp
    Sprite.cpp
    constrains/SimpleConstrain.cpp
)

target_link_libraries(main raylib)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(main "-framework IOKit")
    target_link_libraries(main "-framework Cocoa")
    target_link_libraries(main "-framework OpenGL")
endif()

# Our Project
set(resources_dir)
# Any any resources
file(GLOB resources_list ${PROJECT_SOURCE_DIR}/resources/*)
list(APPEND resources_dir ${resources_list})

include(CMakePrintHelpers)
cmake_print_variables(resources_dir)
# Copy all of the resource files to the destination
file(COPY ${resources_dir} DESTINATION "resources/")