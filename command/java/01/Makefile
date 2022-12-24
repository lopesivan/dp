SOURCE = Main.java

CLASS = AddCommand.class Calculator.class Command.class Main.class SubtractCommand.class

ALL: Main.class

Main.class:
	javac $(SOURCE)

run: $(CLASS)
	java Main

clean:
	rm $(CLASS)
