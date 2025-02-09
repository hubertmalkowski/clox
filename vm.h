#ifndef clox_vm_h
#define clox_vm_h

#include <stdarg.h>

#define STACK_MAX 256

#include "chunk.h"
#include "value.h"
#include <stdint.h>
typedef struct {
  Chunk *chunk;
  uint8_t *ip;
  Value stack[STACK_MAX];
  Value * stackTop;
  Obj* objects;
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
void push(Value value);
Value pop();
InterpretResult interpret(const char *source);

#endif // !clox_vm_h
