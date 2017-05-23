// g++ -g tests.cpp -o tests
// valgrind --leak-check=full -v ./tests

#include "Dicc.h"
#include <iostream>
#include <string>
#include <gtest/gtest.h>

using namespace aed2;

// template<typename T>
// string to_s(const T& m) {
//  	ostringstream os;
// 	os << m;
// 	return os.str();
//  }

struct DiccTest : public ::testing::Test {

};

/*
 * Test dicc
 */
TEST_F(ListaTest, test_dicc) {
	Dicc<std::string,int> d;
	ASSERT(!d.Definido("manzana"));
	ASSERT_EQ(d.CantClaves(),0)
	Dicc<std::string,int>::Iterador it = d.Definir("manzana", 3);
	ASSERT_EQ(d.CantClaves(),1)
	ASSERT(d.Definido("manzana"));
	ASSERT_EQ(d.Significado("manzana"), 3);
	d.Definir("pera", 10);
	ASSERT_EQ(d.CantClaves(),2)
	d.Definir("tomate", 20);
	ASSERT_EQ(d.CantClaves(),3)
	ASSERT(d.Definido("pera"));
	ASSERT_EQ(d.Significado("pera"), 10);
	ASSERT(d.Definido("tomate"));
	ASSERT_EQ(d.Significado("tomate"), 20);
	d.Borrar("pera");
	ASSERT_EQ(d.CantClaves(),2)
	ASSERT(d.Definido("manzana"));
	ASSERT(!d.Definido("pera"));
	ASSERT(d.Definido("tomate"));
	d.Borrar("manzana");
	ASSERT_EQ(d.CantClaves(),1)
	ASSERT(!d.Definido("manzana"));
	ASSERT(!d.Definido("pera"));
	ASSERT(d.Definido("tomate"));
	d.Borrar("tomate");
	ASSERT_EQ(d.CantClaves(),0)
	ASSERT(!d.Definido("manzana"));
	ASSERT(!d.Definido("pera"));
	ASSERT(!d.Definido("tomate"));
}

/*
 * Test iterador
 */
TEST_F(ListaTest, test_it) {
	Dicc<std::string,int> d;
	Dicc<std::string,int>::Iterador it = d.CrearIt();
	ASSERT(!it.HaySiguiente());
	it = d.Definir("manzana", 3);
	ASSERT(it.HaySiguiente());
	ASSERT_EQ(it.Siguiente().clave, "manzana");
	ASSERT_EQ(it.Siguiente().significado, 3);
	d.Definir("pera", 10);
	d.Definir("tomate", 20);
	it = d.CrearIt();
	it.Avanzar();
	ASSERT(it.HaySiguiente());
	ASSERT_EQ(it.Siguiente().clave, "pera");
	ASSERT_EQ(it.Siguiente().significado, 10);
	it.Avanzar();
	ASSERT(it.HaySiguiente());
	ASSERT_EQ(it.Siguiente().clave, "manzana");
	ASSERT_EQ(it.Siguiente().significado, 3);
	it.Avanzar();
	ASSERT(!it.HaySiguiente());
	it = d.CrearIt();
	ASSERT(it.HaySiguiente());
	ASSERT_EQ(it.Siguiente().clave, "tomate");
	ASSERT_EQ(it.Siguiente().significado, 20);
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
