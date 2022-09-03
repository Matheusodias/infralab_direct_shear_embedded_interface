src_dir := src
obj_dir := obj
build_dir := ./build
file := ../Interface/Interface.pro
executable:= ./Interface

  # new variable


all: $(build_dir)  compile_run            # added dependency (*before* any others)

$(build_dir):                                     # rule which makes missing directories
	mkdir $@

compile_run:
	cd $(build_dir);qmake $(file); make -j4; $(executable);

clean: 
	rm -rf $(build_dir)
