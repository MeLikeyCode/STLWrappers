#include <vector>
#include "catch.hpp"

#include "STLWrappers.h"

TEST_CASE("operations work on containers")
{
	// set up containers
	std::vector<int> v = { 1,3,3 };
	std::set<int> s = { 1,2,3 };
	std::unordered_set<int> us = { 1,2,3 };
	std::map<int, int> m = { {1,2}, {2,3}, {3,4} };
	std::unordered_map<int, int> um = { {1,2}, {2,3}, {3,4} };

	SECTION("search works") {
		SECTION("on vectors")
		{
			REQUIRE(STLWrappers::find(v, 3) != std::end(v));
			REQUIRE(STLWrappers::find(v, 0) == std::end(v));
			REQUIRE(STLWrappers::contains(v, 1) == true);
			REQUIRE(STLWrappers::contains(v, 0) == false);
			REQUIRE(STLWrappers::count(v, 3) == 2);
			REQUIRE(STLWrappers::count(v, 1) == 1);
			REQUIRE(STLWrappers::count(v, 0) == 0);
		}

		SECTION("on sets")
		{
			REQUIRE(STLWrappers::find(s, 3) != std::end(s));
			REQUIRE(STLWrappers::find(s, 0) == std::end(s));
			REQUIRE(STLWrappers::contains(s, 1) == true);
			REQUIRE(STLWrappers::contains(s, 0) == false);
			REQUIRE(STLWrappers::count(s, 3) == 1);
			REQUIRE(STLWrappers::count(s, 0) == 0);
		}

		SECTION("on unordered sets")
		{
			REQUIRE(STLWrappers::find(us, 3) != std::end(us));
			REQUIRE(STLWrappers::find(us, 0) == std::end(us));
			REQUIRE(STLWrappers::contains(us, 1) == true);
			REQUIRE(STLWrappers::contains(us, 0) == false);
			REQUIRE(STLWrappers::count(us, 3) == 1);
			REQUIRE(STLWrappers::count(us, 0) == 0);
		}

		SECTION("on maps")
		{
			REQUIRE(STLWrappers::find(m, 3) != std::end(m));
			REQUIRE(STLWrappers::find(m, 0) == std::end(m));
			REQUIRE(STLWrappers::contains(m, 1) == true);
			REQUIRE(STLWrappers::contains(m, 0) == false);
			REQUIRE(STLWrappers::count(m, 3) == 1);
			REQUIRE(STLWrappers::count(m, 0) == 0);
		}

		SECTION("on unordered maps")
		{
			REQUIRE(STLWrappers::find(um, 3) != std::end(um));
			REQUIRE(STLWrappers::find(um, 0) == std::end(um));
			REQUIRE(STLWrappers::contains(um, 1) == true);
			REQUIRE(STLWrappers::contains(um, 0) == false);
			REQUIRE(STLWrappers::count(um, 3) == 1);
			REQUIRE(STLWrappers::count(um, 0) == 0);
		}

	}

//	SECTION("add works on vectors")
//	{
//		STLWrappers::add(v, 4);
//		REQUIRE(STLWrappers::contains(v, 4) == true);
//	}
//
//	SECTION("remove works on vectors")
//	{
//		STLWrappers::remove(v, 3);
//		REQUIRE(STLWrappers::contains(v, 3) == false);
//	}


}