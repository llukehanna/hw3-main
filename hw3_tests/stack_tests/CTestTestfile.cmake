# CMake generated Testfile for 
# Source directory: /home/codio/workspace/hw3/hw3_tests/stack_tests
# Build directory: /home/codio/workspace/hw3/hw3_tests/stack_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Stack.BasicString "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/stack_tests/stack_tests" "--gtest_filter=Stack.BasicString")
add_test(Stack.RandomInt "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/stack_tests/stack_tests" "--gtest_filter=Stack.RandomInt")
