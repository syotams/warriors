set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

# Build main.c on PROJECT_NAME, I could call it wahtever I wanted
add_executable(
    warriors 
    main.cpp 
    textures_container.cpp
    helpers/ImageLoader.cpp
    helpers/Log.cpp
    models/Game.cpp
    models/Sprite.cpp
    models/Knight.cpp 
    models/Enemy.cpp 
    models/Level.cpp
    views/State.cpp 
    views/IdleState.cpp 
    views/WalkState.cpp 
    views/AttackState.cpp
    constrains/GridChaseConstrain.cpp
    constrains/DogChaseConstrain.cpp
    constrains/SimpleConstrain.cpp
    constrains/ScreenConstrain.cpp
)

target_link_libraries(warriors raylib)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(warriors "-framework IOKit")
    target_link_libraries(warriors "-framework Cocoa")
    target_link_libraries(warriors "-framework OpenGL")
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