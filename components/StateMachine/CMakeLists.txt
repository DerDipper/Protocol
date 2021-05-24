# Read Component Name From Folder Name
get_filename_component(COMPONENT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
message("${COMPONENT_NAME}")

# Include directories (inc directory is already included in component cmake)
include_directories(
    config/
)

# Get Source Directories
aux_source_directory(src/ SOURCES)
aux_source_directory(test/ TEST_SOURCES)

#Build this Component as a library
add_library(${COMPONENT_NAME} ${SOURCES})

# Building Test Executable, with coverage
add_executable(${COMPONENT_NAME}_TEST ${SOURCES} ${TEST_SOURCES})
target_compile_options(${COMPONENT_NAME}_TEST PRIVATE -fprofile-arcs -ftest-coverage)
target_link_options(${COMPONENT_NAME}_TEST PRIVATE -lgcov --coverage)
# Add Test to make
add_test(${COMPONENT_NAME}_TEST ${COMPONENT_NAME}_TEST)

