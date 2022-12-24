#include <iostream>
#include <memory>

// Classe base para as operações (comandos)
class Command
{
public:
    virtual ~Command() {}
    virtual void Execute() = 0;
};

// Classe concreta para a operação "Adicionar"
class AddCommand : public Command
{
public:
    AddCommand (int x, int y) : x_ (x), y_ (y) {}
    void Execute() override { std::cout << x_ + y_ << std::endl; }

private:
    int x_;
    int y_;
};

// Classe concreta para a operação "Subtrair"
class SubtractCommand : public Command
{
public:
    SubtractCommand (int x, int y) : x_ (x), y_ (y) {}
    void Execute() override { std::cout << x_ - y_ << std::endl; }

private:
    int x_;
    int y_;
};

// Classe que armazena e executa um comando
class Calculator
{
public:
    void SetCommand (std::unique_ptr<Command> command) {
            command_ = std::move (command);
        }
    void ExecuteCommand() { command_->Execute(); }

private:
    std::unique_ptr<Command> command_;
};

int main()
{
    Calculator calculator;
    calculator.SetCommand (std::make_unique<AddCommand> (10, 5));
    calculator.ExecuteCommand();  // Imprime 15

    calculator.SetCommand (std::make_unique<SubtractCommand> (10, 5));
    calculator.ExecuteCommand();  // Imprime 5

    return 0;
}
