build:
	zig cc main.c scanner.c chunk.c value.c memory.c debug.c vm.c  && ./a.out
	
