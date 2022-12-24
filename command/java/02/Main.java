import java.util.function.Consumer;

// Classe base para as operações (comandos)
interface Command extends Consumer<Void> {
}

// Classe concreta para a operação "Adicionar"
class Cmd1Command implements Command {
	private int x;
	private int y;

	public Cmd1Command(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public void accept(Void v) {
		System.out.println(x + y);
	}
}

// Classe que armazena e executa um comando
class Invoke {
	private Command command;

	public void setCommand(Command command) {
		this.command = command;
	}

	public void executeCommand() {
		command.accept(null);
	}
}

public class Main {
	public static void main(String[] args) {
    Invoke invoke = new Invoke();

    // Define e executa o comando "Adicionar"
    invoke.setCommand(new Cmd1Command(10, 5));
    invoke.executeCommand(); // Imprime 15
  }


