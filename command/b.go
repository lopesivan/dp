package main

import "fmt"

// Classe base para as operações (comandos)
type Command interface {
	Execute()
}

// Classe concreta para a operação "Adicionar"
type AddCommand struct {
	x int
	y int
}

func (c *AddCommand) Execute() {
	fmt.Println(c.x + c.y)
}

// Classe concreta para a operação "Subtrair"
type SubtractCommand struct {
	x int
	y int
}

func (c *SubtractCommand) Execute() {
	fmt.Println(c.x - c.y)
}

// Classe que armazena e executa um comando
type Calculator struct {
	command Command
}

func (c *Calculator) SetCommand(command Command) {
	c.command = command
}

func (c *Calculator) ExecuteCommand() {
	c.command.Execute()
}

func main() {
	calculator := &Calculator{}

	// Define e executa o comando "Adicionar"
	calculator.SetCommand(&AddCommand{10, 5})
	calculator.ExecuteCommand()  // Imprime 15

	// Define e executa o comando "Subtrair"
	calculator.SetCommand(&SubtractCommand{10, 5})
	calculator.ExecuteCommand()  // Imprime 5
}

