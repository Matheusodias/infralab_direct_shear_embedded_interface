src_dir := src
obj_dir := obj
build_dir := ./build
file := ../Interface/Interface.pro
executable := $(build_dir)/Interface
isRaspberrypi := 1
CC := gcc
flags := -W -Wshadow -Wall -pedantic
path_machine_control := /home/infralab/Teste_Embarcados/Teste_Completo
Compile := $(CC) $(flags)

ifeq ($(isRaspberrypi),1)
	qmake_command = qmake $(file)
	make_flag = -j4
        machine_flag = -pthread
else 
	qmake_command = /home/ivan/Qt/5.15.2/gcc_64/bin/qmake $(file)
	make_flag = -j8
endif


all:  compile_machine compile_interface           # added dependency (*before* any others)

run: run_machine run_interface

$(build_dir):                                     # rule which makes missing directories
	mkdir $@

run_machine:
	./execute_machine 

run_interface:
	$(executable)

compile_machine: $(path_machine_control)/machine_control.c  $(path_machine_control)/machine_functions.c     #./machine.c
	gcc -pthread $(path_machine_control)/machine_control.c $(path_machine_control)/machine_functions.c -o ./execute_machine -lm	
#$(Compile) $< $(machine_flag) -o ./execute_machine;

compile_interface : $(build_dir)
	cd $(build_dir);$(qmake_command); make $(make_flag); 

clean: 
	git checkout main
	rm -rf $(build_dir) ./interface ./machine ./execute_machine
