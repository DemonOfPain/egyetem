#ifndef INDEXGEN_HPP
#define INDEXGEN_HPP

#include "gtest_lite.h"
#include <iostream>
#include "indexgen.h"
#include <sstream>
#include <vector>


class IndexgenTest {
public:
	static void runTest() {
		TEST(IndexgenTest, Kiiras) {
			EXPECT_NO_THROW(std::vector<int> x = indexgen(0, 4));

			std::vector<int> t = indexgen(0, 4);
			std::cout << "elvart: 0,1,2,3" << std::endl;
			std::cout << "kapott: ";
			for (int k : t)
				std::cout << k << ','; // 0,1,2,3
			for (size_t i = 0; i < t.size(); i++)
				EXPECT_EQ(t[i], i);
		} END
	}
};

#endif 