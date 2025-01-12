#ifndef clox_value_h
#define clox_value_h

typedef double Value;

typedef struct {
  int capacity; // Ile rzeczy możemy wrzucić do naszego "arraya"
  int count; // Ile aktualnie rzeczy mamy w naszym "arrayu"
  Value *values; // To jest nasz "array"
} ValueArray ;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif // !clox_value_h
