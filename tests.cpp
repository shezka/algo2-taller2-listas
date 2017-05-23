#include <iostream>
#include <gtest/gtest.h>
#include "lista.h"

using namespace std;

struct ListaTest : public ::testing::Test {

};

TEST_F(ListaTest, Crear) {
    Lista<int> l;
    Lista<int>::Iterador i2 = l.AgregarAdelante(2);
    Lista<int>::Iterador i4 = i2.Insertar(4);
    i4.Insertar(6);
    i4.Remover();
    std::cout << std::endl;
}

TEST_F(ListaTest, it_de_lista_vacia) {
    Lista<int> l;
    Lista<int>::Iterador it = l.CrearIt();
    ASSERT_EQ(it.HaySiguiente(), false);
    std::cout << std::endl;
}

TEST_F(ListaTest, it_de_lista_unitaria) {
    Lista<int> l;
    l.AgregarAdelante(4);
    Lista<int>::Iterador it = l.CrearIt();
    ASSERT_EQ(it.HaySiguiente(), true);
    ASSERT_EQ(it.Siguiente(), 4);
    it.Avanzar();
    ASSERT_EQ(it.HaySiguiente(), false);
    std::cout << std::endl;
}

TEST_F(ListaTest, test_ej2) {
    Lista<int> l;
    Lista<int>::Iterador i2 = l.AgregarAdelante(2);
    Lista<int>::Iterador i4 = i2.Insertar(4);
    i4.Insertar(6);

    ASSERT_EQ(l.cant(), 3);
    ASSERT_EQ(l.to_s(), "[2, 4, 6]");

    Lista<int> l2;
    ASSERT_EQ(l2.cant(), 0);
    ASSERT_EQ(l2.to_s(), "[]");
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
