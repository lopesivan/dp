# Classe base para as operações (comandos)
class Command
  def execute
    raise NotImplementedError
  end
end

# Classe concreta para a operação "Adicionar"
class AddCommand < Command
  def initialize(x, y)
    @x = x
    @y = y
  end

  def execute
    puts @x + @y
  end
end

# Classe concreta para a operação "Subtrair"
class SubtractCommand < Command
  def initialize(x, y)
    @x = x
    @y = y
  end

  def execute
    puts @x - @y
  end
end

# Classe que armazena e executa um comando
class Calculator
  def initialize
    @command = nil
  end

  def set_command(command)
    @command = command
  end

  def execute_command
    @command.execute
  end
end

def main
  calculator = Calculator.new

  # Define e executa o comando "Adicionar"
  calculator.set_command(AddCommand.new(10, 5))
  calculator.execute_command  # Imprime 15

  # Define e executa o comando "Subtrair"
  calculator.set_command(SubtractCommand.new(10, 5))
  calculator.execute_command  # Imprime 5
end

main
