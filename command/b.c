#include <stdio.h>
#include <stdlib.h>

// Estrutura base para as operações (comandos)
typedef struct Command_s {
  void (*Execute)(struct Command_s*);
} Command;

// Estrutura concreta para a operação "Adicionar"
typedef struct AddCommand_s {
  Command base;
  int x;
  int y;
} AddCommand;

// Implementação da operação "Adicionar"
void AddCommand_Execute(Command* base) {
  AddCommand* self = (AddCommand*)base;
  printf("%d\n", self->x + self->y);
}

// Estrutura concreta para a operação "Subtrair"
typedef struct SubtractCommand_s {
  Command base;
  int x;
  int y;
} SubtractCommand;

// Implementação da operação "Subtrair"
void SubtractCommand_Execute(Command* base) {
  SubtractCommand* self = (SubtractCommand*)base;
  printf("%d\n", self->x - self->y);
}

// Função que cria um objeto AddCommand
AddCommand* AddCommand_Create(int x, int y) {
  AddCommand* self = malloc(sizeof(AddCommand));
  self->base.Execute = AddCommand_Execute;
  self->x = x;
  self->y = y;
  return self;
}

// Função que cria um objeto SubtractCommand
SubtractCommand* SubtractCommand_Create(int x, int y) {
  SubtractCommand* self = malloc(sizeof(SubtractCommand));
  self->base.Execute = SubtractCommand_Execute;
  self->x = x;
  self->y = y;
  return self;
}

// Estrutura que armazena e executa um comando
typedef struct Calculator_s {
  Command* command;
} Calculator;

// Função que define o comando a ser executado
void Calculator_SetCommand(Calculator* self, Command* command) {
  self->command = command;
}

// Função que executa o comando armazenado
void Calculator_ExecuteCommand(Calculator* self) {
  self->command->Execute(self->command);
}

int main() {
  Calculator calculator;

  // Define e executa o comando "Adicionar"
  Calculator_SetCommand(&calculator, (Command*)AddCommand_Create(10, 5));
  Calculator_ExecuteCommand(&calculator);  // Imprime 15

  // Define e executa o comando "Subtrair"
  Calculator_SetCommand(&calculator, (Command*)SubtractCommand_Create(10, 5));
  Calculator_ExecuteCommand(&calculator);  // Imprime 5

  return 0;
}
