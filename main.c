#include <stdio.h>
#include "chunk.h"
#include "debug.h"

int main(int argc, const char *argv[]) {
  printf("Written init");
  Chunk chunk;

  initChunk(&chunk);
  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 123);
  printf("Written first chunk");
  writeChunk(&chunk, constant, 123);
  writeChunk(&chunk, OP_RETURN, 123);

  disassembleChunk(&chunk, "test chunk");

  freeChunk(&chunk);
  return 0;
}
