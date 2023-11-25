interface AbstractProductA {
  void functionA();
}

interface AbstractProductB {
  void functionB();
}

class ProductA1 implements AbstractProductA {
  public void functionA() {
    System.out.println("ProductA1 functionA");
  }
}

class ProductA2 implements AbstractProductA {
  public void functionA() {
    System.out.println("ProductA2 functionA");
  }
}

class ProductB1 implements AbstractProductB {
  public void functionB() {
    System.out.println("ProductB1 functionB");
  }
}

class ProductB2 implements AbstractProductB {
  public void functionB() {
    System.out.println("ProductB2 functionB");
  }
}

interface AbstractFactory {
  AbstractProductA createProductA();

  AbstractProductB createProductB();
}

class Factory1 implements AbstractFactory {
  public AbstractProductA createProductA() {
    return new ProductA1();
  }

  public AbstractProductB createProductB() {
    return new ProductB1();
  }
}

class Factory2 implements AbstractFactory {
  public AbstractProductA createProductA() {
    return new ProductA2();
  }

  public AbstractProductB createProductB() {
    return new ProductB2();
  }
}

public class Main {
  public static void main(String[] args) {
    AbstractFactory factory1 = new Factory1();
    AbstractProductA productA1 = factory1.createProductA();
    AbstractProductB productB1 = factory1.createProductB();
    productA1.functionA();
    productB1.functionB();

    AbstractFactory factory2 = new Factory2();
    AbstractProductA productA2 = factory2.createProductA();
    AbstractProductB productB2 = factory2.createProductB();
    productA2.functionA();
    productB2.functionB();
  }
}
