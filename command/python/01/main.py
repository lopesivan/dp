from abc import ABC, abstractmethod

# Classe base para as operações (comandos)


class Command(ABC):
    @abstractmethod
    def execute(self):
        pass

# Classe concreta para a operação "Adicionar"
class AddCommand(Command):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def execute(self):
        print(self.x + self.y)

# Classe concreta para a operação "Subtrair"


class SubtractCommand(Command):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def execute(self):
        print(self.x - self.y)

# Classe que armazena e executa um comando


class Calculator:
    def __init__(self):
        self.command = None

    def set_command(self, command):
        self.command = command

    def execute_command(self):
        self.command.execute()


def main():
    calculator = Calculator()

    # Define e executa o comando "Adicionar"
    calculator.set_command(AddCommand(10, 5))
    calculator.execute_command()  # Imprime 15

    # Define e executa o comando "Subtrair"
    calculator.set_command(SubtractCommand(10, 5))
    calculator.execute_command()  # Imprime 5


if __name__ == "__main__":
    main()
