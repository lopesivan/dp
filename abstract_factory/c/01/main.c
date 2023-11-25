#include <stdio.h>
#include <stdlib.h>

// Forward declarations
typedef struct AbstractProductA AbstractProductA;
typedef struct AbstractProductB AbstractProductB;
typedef struct AbstractFactory AbstractFactory;

// ProductA interface
struct AbstractProductA
{
    void (*functionA)(AbstractProductA*);
};

void ProductA1_functionA(AbstractProductA* self)
{
    printf("ProductA1 functionA\n");
}

void ProductA2_functionA(AbstractProductA* self)
{
    printf("ProductA2 functionA\n");
}

// ProductB interface
struct AbstractProductB
{
    void (*functionB)(AbstractProductB*);
};

void ProductB1_functionB(AbstractProductB* self)
{
    printf("ProductB1 functionB\n");
}

void ProductB2_functionB(AbstractProductB* self)
{
    printf("ProductB2 functionB\n");
}

// AbstractFactory interface
struct AbstractFactory
{
    AbstractProductA* (*createProductA)(AbstractFactory*);
    AbstractProductB* (*createProductB)(AbstractFactory*);
};

// Concrete Factories
AbstractProductA* Factory1_createProductA(AbstractFactory* self)
{
    AbstractProductA* product = (AbstractProductA*)malloc(sizeof(AbstractProductA));
    product->functionA = ProductA1_functionA;
    return product;
}

AbstractProductB* Factory1_createProductB(AbstractFactory* self)
{
    AbstractProductB* product = (AbstractProductB*)malloc(sizeof(AbstractProductB));
    product->functionB = ProductB1_functionB;
    return product;
}

AbstractProductA* Factory2_createProductA(AbstractFactory* self)
{
    AbstractProductA* product = (AbstractProductA*)malloc(sizeof(AbstractProductA));
    product->functionA = ProductA2_functionA;
    return product;
}

AbstractProductB* Factory2_createProductB(AbstractFactory* self)
{
    AbstractProductB* product = (AbstractProductB*)malloc(sizeof(AbstractProductB));
    product->functionB = ProductB2_functionB;
    return product;
}

AbstractFactory* create_factory1()
{
    AbstractFactory* factory = (AbstractFactory*)malloc(sizeof(AbstractFactory));
    factory->createProductA = Factory1_createProductA;
    factory->createProductB = Factory1_createProductB;
    return factory;
}

AbstractFactory* create_factory2()
{
    AbstractFactory* factory = (AbstractFactory*)malloc(sizeof(AbstractFactory));
    factory->createProductA = Factory2_createProductA;
    factory->createProductB = Factory2_createProductB;
    return factory;
}

// Client code
int main()
{
    AbstractFactory* factory1 = create_factory1();
    AbstractProductA* productA1 = factory1->createProductA(factory1);
    AbstractProductB* productB1 = factory1->createProductB(factory1);
    productA1->functionA(productA1);
    productB1->functionB(productB1);

    AbstractFactory* factory2 = create_factory2();
    AbstractProductA* productA2 = factory2->createProductA(factory2);
    AbstractProductB* productB2 = factory2->createProductB(factory2);
    productA2->functionA(productA2);
    productB2->functionB(productB2);

    // Cleanup
    free(productA1);
    free(productB1);
    free(factory1);
    free(productA2);
    free(productB2);
    free(factory2);

    return 0;
}
