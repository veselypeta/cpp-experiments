enable_testing()

add_executable(experiment_tests
        AutoTypeDecl.cpp
        thread-lambda.cpp
        )
target_link_libraries(experiment_tests gtest_main)
target_compile_options(experiment_tests PUBLIC -Wall -Werror -Wextra)
include(GoogleTest)
gtest_discover_tests(experiment_tests)