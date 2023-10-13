# CMake generated Testfile for 
# Source directory: C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4
# Build directory: C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test-queue "test-queue")
set_tests_properties(test-queue PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;36;add_test;C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;0;")
add_test(test00 "pathfinder" "C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/tests/maze00.png" "output00.png")
set_tests_properties(test00 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;37;add_test;C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;0;")
add_test(test00-compare "compare" "C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/tests/output00.png" "output00.png")
set_tests_properties(test00-compare PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;38;add_test;C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;0;")
add_test(test01 "pathfinder" "C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/tests/maze01.png" "output01.png")
set_tests_properties(test01 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;39;add_test;C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;0;")
add_test(test01-compare "compare" "C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/tests/output01.png" "output01.png")
set_tests_properties(test01-compare PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;40;add_test;C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;0;")
add_test(test02 "pathfinder" "C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/tests/maze02.png" "output02.png")
set_tests_properties(test02 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;41;add_test;C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;0;")
add_test(test02-compare "compare" "C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/tests/output02.png" "output02.png")
set_tests_properties(test02-compare PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;42;add_test;C:/Users/zdavi/OneDrive/Documents/ECE302C++/starter-code-ece0302/projects/project4/CMakeLists.txt;0;")
subdirs("lib")
