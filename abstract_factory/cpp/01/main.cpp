#include <iostream>
#include <memory>

// Interface de Produto Abstrato A
class AbstractProductA
{
  public:
    virtual void functionA() const = 0;
    virtual ~AbstractProductA()
    {
    }
};

// Interface de Produto Abstrato B
class AbstractProductB
{
  public:
    virtual void functionB() const = 0;
    virtual ~AbstractProductB()
    {
    }
};

// Produto Concreto A1
class ProductA1 : public AbstractProductA
{
  public:
    void functionA() const override
    {
        std::cout << "ProductA1 functionA\n";
    }
};

// Produto Concreto A2
class ProductA2 : public AbstractProductA
{
  public:
    void functionA() const override
    {
        std::cout << "ProductA2 functionA\n";
    }
};

// Produto Concreto B1
class ProductB1 : public AbstractProductB
{
  public:
    void functionB() const override
    {
        std::cout << "ProductB1 functionB\n";
    }
};

// Produto Concreto B2
class ProductB2 : public AbstractProductB
{
  public:
    void functionB() const override
    {
        std::cout << "ProductB2 functionB\n";
    }
};

// Interface de Fábrica Abstrata
class AbstractFactory
{
  public:
    virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
    virtual ~AbstractFactory()
    {
    }
};

// Fábrica Concreta 1
class Factory1 : public AbstractFactory
{
  public:
    std::unique_ptr<AbstractProductA> createProductA() const override
    {
        return std::make_unique<ProductA1>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override
    {
        return std::make_unique<ProductB1>();
    }
};

// Fábrica Concreta 2
class Factory2 : public AbstractFactory
{
  public:
    std::unique_ptr<AbstractProductA> createProductA() const override
    {
        return std::make_unique<ProductA2>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override
    {
        return std::make_unique<ProductB2>();
    }
};

// Função main que atua como o cliente
int main()
{
    // Fábrica 1
    std::unique_ptr<AbstractFactory> factory1 = std::make_unique<Factory1>();
    auto productA1 = factory1->createProductA();
    auto productB1 = factory1->createProductB();
    productA1->functionA();
    productB1->functionB();

    // Fábrica 2
    std::unique_ptr<AbstractFactory> factory2 = std::make_unique<Factory2>();
    auto productA2 = factory2->createProductA();
    auto productB2 = factory2->createProductB();
    productA2->functionA();
    productB2->functionB();

    return 0;
}
