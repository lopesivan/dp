SOURCE = Main.java

CLASS = \
AbstractFactory.class  \
AbstractProductA.class \
AbstractProductB.class \
Factory1.class         \
Factory2.class         \
ProductA1.class        \
ProductA2.class        \
ProductB1.class        \
ProductB2.class        \
Main.class

ALL: Main.class

Main.class:
	javac $(SOURCE)

run: $(CLASS)
	java Main

clean:
	rm $(CLASS)
