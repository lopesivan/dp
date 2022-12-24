import java.util.function.Consumer;

// Classe base para as operações (comandos)
interface Command extends Consumer<Void> {
}

// Classe concreta para a operação "Adicionar"
class AddCommand implements Command {
	private int x;
	private int y;

	public AddCommand(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public void accept(Void v) {
		System.out.println(x + y);
	}
}

// Classe concreta para a operação "Subtrair"
class SubtractCommand implements Command {
	private int x;
	private int y;

	public SubtractCommand(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public void accept(Void v) {
		System.out.println(x - y);
	}
}

// Classe que armazena e executa um comando
class Calculator {
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
		Calculator calculator = new Calculator();

		// Define e executa o comando "Adicionar"
		calculator.setCommand(new AddCommand(10, 5));
		calculator.executeCommand(); // Imprime 15

		// Define e executa o comando "Subtrair"
		calculator.setCommand(new SubtractCommand(10, 5));
		calculator.executeCommand(); // Imprime 5
	}
}
