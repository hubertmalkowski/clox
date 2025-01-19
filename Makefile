build:
	zig cc main.c compiler.c scanner.c chunk.c value.c memory.c debug.c vm.c  && ./a.out
	
