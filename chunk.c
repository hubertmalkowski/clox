#include "chunk.h"
#include "memory.h"
#include "value.h"
#include <stdio.h>
#include <stdlib.h>

void initChunk(Chunk *chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;

  chunk->line_count = 0;
  chunk->line_capacity = 0;
  chunk->lines = NULL;
  initValueArray(&chunk->constants);
}

void freeChunk(Chunk *chunk) {
  FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
  FREE_ARRAY(int, chunk->lines, chunk->capacity);
  freeValueArray(&chunk->constants);
  initChunk(chunk);
}

void writeChunk(Chunk *chunk, uint8_t byte, int line) {
  if (chunk->count + 1 > chunk->capacity) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code =
        GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
  }

  chunk->code[chunk->count] = byte;
  chunk->count++;

  // 1. Check if we are still on the same line
  // 2. If yes, we return, if no we gro array with the new line and set offset
  // to count - 1

  if (chunk->line_count > 0 && chunk->lines[chunk->line_count - 1].line == line)
    return;

  if (chunk->line_count + 1 > chunk->line_capacity) {
    int oldCapacity = chunk->line_capacity;
    chunk->line_capacity = GROW_CAPACITY(chunk->line_capacity);
    chunk->lines =
        GROW_ARRAY(LineEntry, chunk->lines, oldCapacity, chunk->line_capacity);
  }

  LineEntry entry;
  entry.line = line;
  entry.offset = chunk->count - 1;

  chunk->lines[chunk->line_count] = entry;
  chunk->line_count++;
}

int addConstant(Chunk *chunk, Value value) {
  writeValueArray(&chunk->constants, value);
  return chunk->constants.count - 1;
}

int getLine(Chunk* chunk, int offset) {
    int beg = 0;
    int end = chunk->line_count - 1;

    while (beg <= end) {
        int mid = (beg + end) / 2;
        LineEntry* line = &chunk->lines[mid];

        if (offset < line->offset) {
            end = mid - 1;
        } else if (mid == chunk->line_count- 1 || offset < chunk->lines[mid + 1].offset) {
            return line->line;
        } else {
            beg = mid + 1;
        }
    }

    // -1 if not found
    return -1;
}

