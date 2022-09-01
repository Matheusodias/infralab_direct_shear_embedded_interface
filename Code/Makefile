src_dir := src
obj_dir := obj
build_dir := ../../build
file := ../../Interface/Interface.pro
executable:= ./Interface

  # new variable


all: $(build_dir)  compile            # added dependency (*before* any others)

$(build_dir):                                     # rule which makes missing directories
	mkdir $@

compile:
	cd $(build_dir);qmake $(file); $(executable);


