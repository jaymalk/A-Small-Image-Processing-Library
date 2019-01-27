make:
	@./run.sh core
	@./run.sh mkl
	@./run.sh oblas

core:
	@./run.sh core

mkl:
	@./run.sh mkl

oblas:
	@./run.sh oblas

old:
	@echo "Compiling non-threaded..."
	@g++ interpreter.cpp -o ipl
	@echo "Complete."

#Clear all files matching [ipl*]
clear:
	rm -f ipl*
