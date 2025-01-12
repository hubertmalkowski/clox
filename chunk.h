#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,
  OP_RETURN,
} OpCode;

typedef struct {
  int line;
  int offset;
} LineEntry;

typedef struct {
  int count;
  int capacity;
  uint8_t *code;

  int line_capacity;
  int line_count;
  LineEntry* lines; 

  ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);
int getLine(Chunk* chunk, int offset);



#endif // !clox_chunk_h
