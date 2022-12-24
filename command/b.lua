-- Classe base para as operações (comandos)
local Command = {}
Command.__index = Command

function Command:new()
  local self = setmetatable({}, Command)
  self.execute = function()
    error("Método 'execute' não implementado")
  end
  return self
end

-- Classe concreta para a operação "Adicionar"
local AddCommand = Command:new()

function AddCommand:new(x, y)
  local self = setmetatable(Command:new(), AddCommand)
  self.x = x
  self.y = y
  self.execute = function(self)
    print(self.x + self.y)
  end
  return self
end

-- Classe concreta para a operação "Subtrair"
local SubtractCommand = Command:new()

function SubtractCommand:new(x, y)
  local self = setmetatable(Command:new(), SubtractCommand)
  self.x = x
  self.y = y
  self.execute = function(self)
    print(self.x - self.y)
  end
  return self
end

-- Classe que armazena e executa um comando
local Calculator = {}
Calculator.__index = Calculator

function Calculator:new()
  local self = setmetatable({}, Calculator)
  self.command = nil
  return self
end

function Calculator:set_command(command)
  self.command = command
end

function Calculator:execute_command()
  self.command:execute()
end

function main()
  local calculator = Calculator:new()

  -- Define e executa o comando "Adicionar"
  calculator:set_command(AddCommand:new(10, 5))
  calculator:execute_command()  -- Imprime 15

  -- Define e executa o comando "Subtrair"
  calculator:set_command(Sub

