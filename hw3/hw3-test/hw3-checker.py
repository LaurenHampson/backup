import cs_grading as cs
import os

text_editor = 'subl'
compile_flags = '-g -Wall -std=c++11'

run_stack_test = 1
stack_source_file = "stack_gtest.cpp ../lliststr.cpp ../stackstr.cpp"
stack_use_valgrind = 1
stack_output = 'stack_results.txt'
stack_valgrind = 'stack_valgrind.txt'




def run_stack():
	cs.compile_student_code(0, 
							source_files=stack_source_file, 
							flags=compile_flags, 
							use_gtest=1, 
							target='stack')
	cs.run_gtest_with_filter(executable_path='./',
							executable_name='stack',
							test_suite_name='StackStrTest',
							test_prefix='Test',
							test_number_min = 1,
							test_number_max = 14,
							test_delimiter='',
							redirect_output=stack_output,
							use_valgrind=stack_use_valgrind,
							valgrind_log_filename=stack_valgrind)

if run_stack_test:
	cs.run_test(problem_name="stack", problem_grading=run_stack, open_results=1, remove_files=1)

