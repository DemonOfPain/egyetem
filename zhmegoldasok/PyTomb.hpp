#ifndef PYTOMB_HPP
#define PYTOMB_HPP

#include "gtest_lite.h"
#include <iostream>
#include <vector>
#include "PyTomb.h"
#include <sstream>


class PyTombTest {
public:
	static void runTest() {
		TEST(PyTomb, Ketparameteres) {
			PyTomb<int> vi(3);
			
			EXPECT_NO_THROW(vi[0] = 1; vi[1] = 2; vi[2] = 3;);
			
			std::cout << "elvart: 321" << std::endl;
			std::cout << "kapott: " << vi[-1] << vi[-2] << vi[-3] << std::endl;
			
			EXPECT_EQ(vi[-1], 3);
			EXPECT_EQ(vi[-2], 2);
			EXPECT_EQ(vi[-3], 1);
		} END

		TEST(PyTomb, IteratorokkalMegadottKonstruktor) {
			int t[] = { 1, 2, 3, 4, 5 };
			PyTomb<int> vt(t, t + 5);
			
			std::cout << "elvart: 12345" << std::endl;
			std::cout << "kapott: " << vt[0] <<vt[1] << vt[2] << vt[3] << vt[4] << std::endl;
			
			EXPECT_EQ(vt[0], 1);
			EXPECT_EQ(vt[1], 2);
			EXPECT_EQ(vt[2], 3);
			EXPECT_EQ(vt[3], 4);
			EXPECT_EQ(vt[4], 5);
		} END

		TEST(PyTomb, Konverzio) {
			PyTomb<int> vi(3);
			std::vector<int> v = vi;
			EXPECT_NO_THROW();
		} END

		TEST(PyTomb, Inzerter) {
			PyTomb<double> dd;

			EXPECT_NO_THROW(dd.insert(dd.begin(), 3.14));

			std::cout << "elvart: 3.14 3.14" << std::endl;
			std::cout << "kapott: " << dd[0] << ' ' << dd[-1] << std::endl;

			try {
				dd[-2];
			}
			catch (...) {
				std::cout << "out_of_range error" << std::endl;
			}
			std::cout << "ha nem jelent meg feljebb egy error, akkor baj van" << std::endl;
		} END
	}
};

#endif 