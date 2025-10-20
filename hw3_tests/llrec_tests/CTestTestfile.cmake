# CMake generated Testfile for 
# Source directory: /home/codio/workspace/hw3/hw3_tests/llrec_tests
# Build directory: /home/codio/workspace/hw3/hw3_tests/llrec_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Pivot.Empty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Pivot.Empty")
add_test(Pivot.Size1SmallEmpty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Pivot.Size1SmallEmpty")
add_test(Pivot.Size1LargeEmpty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Pivot.Size1LargeEmpty")
add_test(Pivot.Size2SmallLarge "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Pivot.Size2SmallLarge")
add_test(Pivot.Size2LargeSmall "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Pivot.Size2LargeSmall")
add_test(Pivot.Size3LargeSmallLarge "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Pivot.Size3LargeSmallLarge")
add_test(Pivot.Size3SmallLargeSmall "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Pivot.Size3SmallLargeSmall")
add_test(Pivot.Size3LargeLargeSmall "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Pivot.Size3LargeLargeSmall")
add_test(Pivot.Size6SmallThenLarge "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Pivot.Size6SmallThenLarge")
add_test(Pivot.Size6LargeThenSmall "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Pivot.Size6LargeThenSmall")
add_test(Pivot.Nominal "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Pivot.Nominal")
add_test(Pivot.SameValues "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Pivot.SameValues")
add_test(Pivot.NoCopySameNodeCheck "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Pivot.NoCopySameNodeCheck")
add_test(Filter.EmptyList "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Filter.EmptyList")
add_test(Filter.Size1_F "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Filter.Size1_F")
add_test(Filter.Size1_nF "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Filter.Size1_nF")
add_test(Filter.Size2_F_nF "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Filter.Size2_F_nF")
add_test(Filter.Size2_nF_F "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Filter.Size2_nF_F")
add_test(Filter.Size3_nF_F_nF "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Filter.Size3_nF_F_nF")
add_test(Filter.Size3_F_nF_F "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Filter.Size3_F_nF_F")
add_test(Filter.SameNodeCheck "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Filter.SameNodeCheck")
add_test(Filter.MultipleCalls "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Filter.MultipleCalls")
add_test(Filter.CompareWithLlrec "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw3/hw3_tests/llrec_tests/llrec_tests" "--gtest_filter=Filter.CompareWithLlrec")
