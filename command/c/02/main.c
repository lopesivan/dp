#include <stdio.h>
#include <stdlib.h>

// Estrutura base para as operações (comandos)
typedef struct Command_s
{
    void (*Execute) (struct Command_s *);
} Command;

// Estrutura concreta para a operação "Adicionar"
typedef struct Cmd1Command_s
{
    Command base;
    int x;
    int y;
    int z;
} Cmd1Command;

// Implementação da operação "Cmd1"
void Cmd1Command_Execute (Command *base)
{
    Cmd1Command *self = (Cmd1Command *)base;
    printf ("%d\n", self->x + self->y + self->z);
}

// Função que cria um objeto Cmd1Command
Cmd1Command *Cmd1Command_Create (int x, int y, int z)
{
    Cmd1Command *self = malloc (sizeof (Cmd1Command));
    self->base.Execute = Cmd1Command_Execute;
    self->x = x;
    self->y = y;
    self->z = z;
    return self;
}

// Estrutura que armazena e executa um comando
typedef struct Invoker_s
{
    Command *command;
} Invoker;

// Função que define o comando a ser executado
void Invoker_SetCommand (Invoker *self, Command *command)
{
    self->command = command;
}

// Função que executa o comando armazenado
void Invoker_ExecuteCommand (Invoker *self)
{
    self->command->Execute (self->command);
}

int main()
{
    Invoker invoker;

    // Define e executa o comando "Cmd1"
    Invoker_SetCommand (&invoker, (Command *)Cmd1Command_Create (10, 5, 6));
    Invoker_ExecuteCommand (&invoker); // Imprime 21

    return 0;
}
