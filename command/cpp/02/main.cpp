#include <iostream>
#include <memory>

// Classe base para as operações (comandos)
class Command
{
public:
    virtual ~Command() {}
    virtual void Execute() = 0;
};

// Classe concreta para a operação "Cmd1"
class Cmd1Command : public Command
{
public:
    Cmd1Command (int x, int y, int z) : x_ (x), y_ (y), z_ (z) {}
    void Execute() override { std::cout << x_ + y_ + z_ << std::endl; }

private:
    int x_;
    int y_;
    int z_;
};

// Classe concreta para a operação "Cmd2"
class Cmd2Command : public Command
{
public:
    Cmd2Command (int x, int y) : x_ (x), y_ (y) {}
    void Execute() override { std::cout << x_ + y_ << std::endl; }

private:
    int x_;
    int y_;
};


// Classe que armazena e executa um comando
class Invoker
{
public:
    void SetCommand (std::unique_ptr<Command> command)
    {
        command_ = std::move (command);
    }
    void ExecuteCommand() { command_->Execute(); }

private:
    std::unique_ptr<Command> command_;
};

int main()
{
    Invoker invoker;
    invoker.SetCommand (std::make_unique<Cmd1Command> (10, 5, 8));
    invoker.ExecuteCommand();  // Imprime 23

    invoker.SetCommand (std::make_unique<Cmd2Command> (10, 5));
    invoker.ExecuteCommand();  // Imprime 15

    return 0;
}
