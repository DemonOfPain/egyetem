#ifndef SCOMPLEX_HPP
#define SCOMPLEX_HPP

#include "gtest_lite.h"
#include <iostream>
#include "SComplex.h"
#include <sstream>


class SComplexTest {
public:
	static void runTest() {
		TEST(SComplexTest, Konstruktor) {
			SComplex s1(2, 5);
			EXPECT_EQ(s1.getR(), 2);
			EXPECT_EQ(s1.getI(), 5);
		} END

		TEST(SComplexTest, Kiiras) {
			SComplex s2(2, 5);

			s2.write(std::cout);
			std::cout << "elvart: SComplex 2+5" << std::endl;
			std::cout << "kapott: "; s2.write(std::cout); std::cout << std::endl;

		} END

		TEST(SComplexTest, Olvasas) {
			SComplex s3;

			std::istringstream fakeIn("SComplex 6+7");
			auto* oldBuf = std::cin.rdbuf();
			std::cin.rdbuf(fakeIn.rdbuf());
			EXPECT_NO_THROW(s3.read(std::cin));
			std::cin.rdbuf(oldBuf);

			std::cout << "elvart: SComplex 6+7" << std::endl;
			std::cout << "kapott: "; s3.write(std::cout); std::cout << std::endl;
		} END

		TEST(PyTomb, Error) {
			SComplex s4;

			try {
				std::istringstream fakeIn("XXXX");
				auto* oldBuf = std::cin.rdbuf();
				std::cin.rdbuf(fakeIn.rdbuf());
				s4.read(std::cin);
				std::cin.rdbuf(oldBuf);
			}
			catch (...) {
				std::cout << "wrong" << std::endl;
			}
			std::cout << "ha nem jelent meg feljebb egy error, akkor baj van" << std::endl;
		} END
	}
};

#endif 