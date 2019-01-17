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

	SECTION("search (find, contains, contains all, and count) works") {
		SECTION("on vectors")
		{
			REQUIRE(STLWrappers::find(v, 3) != std::end(v));
			REQUIRE(STLWrappers::find(v, 0) == std::end(v));
			REQUIRE(STLWrappers::contains(v, 1) == true);
			REQUIRE(STLWrappers::contains(v, 0) == false);
			REQUIRE(STLWrappers::count(v, 3) == 2);
			REQUIRE(STLWrappers::count(v, 1) == 1);
			REQUIRE(STLWrappers::count(v, 0) == 0);
			REQUIRE(STLWrappers::containsAll(v, {1,3,3}));
			REQUIRE(STLWrappers::containsAll(v, { 1,2,3 }) == false);
		}

		SECTION("on sets")
		{
			REQUIRE(STLWrappers::find(s, 3) != std::end(s));
			REQUIRE(STLWrappers::find(s, 0) == std::end(s));
			REQUIRE(STLWrappers::contains(s, 1) == true);
			REQUIRE(STLWrappers::contains(s, 0) == false);
			REQUIRE(STLWrappers::count(s, 3) == 1);
			REQUIRE(STLWrappers::count(s, 0) == 0);
			REQUIRE(STLWrappers::containsAll(s, { 1,2,3 }));
			REQUIRE(STLWrappers::containsAll(s, { 1,7,3 }) == false);
		}

		SECTION("on unordered sets")
		{
			REQUIRE(STLWrappers::find(us, 3) != std::end(us));
			REQUIRE(STLWrappers::find(us, 0) == std::end(us));
			REQUIRE(STLWrappers::contains(us, 1) == true);
			REQUIRE(STLWrappers::contains(us, 0) == false);
			REQUIRE(STLWrappers::count(us, 3) == 1);
			REQUIRE(STLWrappers::count(us, 0) == 0);
			REQUIRE(STLWrappers::containsAll(us, { 1,2,3 }));
			REQUIRE(STLWrappers::containsAll(us, { 1,7,3 }) == false);
		}

		SECTION("on maps")
		{
			REQUIRE(STLWrappers::find(m, 3) != std::end(m));
			REQUIRE(STLWrappers::find(m, 0) == std::end(m));
			REQUIRE(STLWrappers::contains(m, 1) == true);
			REQUIRE(STLWrappers::contains(m, 0) == false);
			REQUIRE(STLWrappers::count(m, 3) == 1);
			REQUIRE(STLWrappers::count(m, 0) == 0);
			REQUIRE(STLWrappers::containsAll(m, { 1,2,3 }));
			REQUIRE(STLWrappers::containsAll(m, { 1,7,3 }) == false);
		}

		SECTION("on unordered maps")
		{
			REQUIRE(STLWrappers::find(um, 3) != std::end(um));
			REQUIRE(STLWrappers::find(um, 0) == std::end(um));
			REQUIRE(STLWrappers::contains(um, 1) == true);
			REQUIRE(STLWrappers::contains(um, 0) == false);
			REQUIRE(STLWrappers::count(um, 3) == 1);
			REQUIRE(STLWrappers::count(um, 0) == 0);
			REQUIRE(STLWrappers::containsAll(um, { 1,2,3 }));
			REQUIRE(STLWrappers::containsAll(um, { 1,7,3 }) == false);
		}

	}

	SECTION("add works")
	{
		SECTION("on vectors")
		{
			STLWrappers::add(v, 5);
			REQUIRE(std::size(v) == 4);
			REQUIRE(STLWrappers::contains(v, 5) == true);
		}

		SECTION("on sets")
		{
			STLWrappers::add(s, 4);
			REQUIRE(std::size(s) == 4);
			REQUIRE(STLWrappers::contains(s, 4) == true);
		}

		SECTION("on unordered sets")
		{
			STLWrappers::add(us, 4);
			REQUIRE(std::size(us) == 4);
			REQUIRE(STLWrappers::contains(us, 4) == true);
		}

		SECTION("on maps")
		{
			STLWrappers::add(m, std::make_pair(4,5));
			REQUIRE(std::size(m) == 4);
			REQUIRE(STLWrappers::contains(m, 4) == true);
			
			STLWrappers::add(m, 5, 6);
			REQUIRE(std::size(m) == 5);
			REQUIRE(STLWrappers::contains(m, 5));
		}

		SECTION("on unordered maps")
		{
			STLWrappers::add(um, std::make_pair(4, 5));
			REQUIRE(std::size(um) == 4);
			REQUIRE(STLWrappers::contains(um, 4) == true);

			STLWrappers::add(um, 5, 6);
			REQUIRE(std::size(um) == 5);
			REQUIRE(STLWrappers::contains(um, 5));
		}
	}

	SECTION("remove works")
	{
		SECTION("on vectors")
		{
			STLWrappers::remove(v, 1);
			REQUIRE(STLWrappers::contains(v, 1) == false);
			REQUIRE(std::size(v) == 2);
			REQUIRE(STLWrappers::contains(v, 3) == true); 
			REQUIRE(STLWrappers::count(v, 3) == 2);
		}

		SECTION("on sets")
		{
			STLWrappers::remove(s, 2);
			REQUIRE(STLWrappers::contains(s, 2) == false);
			REQUIRE(std::size(s) == 2);
			REQUIRE(STLWrappers::contains(s, 3) == true);
		}

		SECTION("on unordered sets")
		{
			STLWrappers::remove(us, 2);
			REQUIRE(STLWrappers::contains(us, 2) == false);
			REQUIRE(std::size(us) == 2);
			REQUIRE(STLWrappers::contains(us, 3) == true);
		}

		SECTION("on maps")
		{
			STLWrappers::remove(m, 2);
			REQUIRE(STLWrappers::contains(m, 2) == false);
			REQUIRE(std::size(m) == 2);
			REQUIRE(STLWrappers::contains(m, 3) == true);
		}

		SECTION("on unordered maps")
		{
			STLWrappers::remove(um, 2);
			REQUIRE(STLWrappers::contains(um, 2) == false);
			REQUIRE(std::size(um) == 2);
			REQUIRE(STLWrappers::contains(um, 3) == true);
		}

	}

	SECTION("addAll works")
	{

		SECTION("on vectors")
		{
			std::vector<int> v1{ 1,2,3 };
			std::vector<int> v2{ 4,5,6 };
			size_t v1OldSize = std::size(v1);
			
			STLWrappers::addAll(v1, v2);
			REQUIRE(std::size(v1) == v1OldSize + std::size(v2));
			REQUIRE(STLWrappers::containsAll(v1, v2));
		}

		SECTION("on sets")
		{
			std::set<int> c1{ 1,2,3 };
			std::set<int> c2{ 4,5,6 };
			size_t v1OldSize = std::size(c1);

			STLWrappers::addAll(c1, c2);
			REQUIRE(std::size(c1) == v1OldSize + std::size(c2));
			REQUIRE(STLWrappers::containsAll(c1, c2));
		}

		SECTION("on unordered sets")
		{
			std::unordered_set<int> c1{ 1,2,3 };
			std::unordered_set<int> c2{ 4,5,6 };
			size_t v1OldSize = std::size(c1);

			STLWrappers::addAll(c1, c2);
			REQUIRE(std::size(c1) == v1OldSize + std::size(c2));
			REQUIRE(STLWrappers::containsAll(c1, c2));
		}

		SECTION("on maps")
		{
			std::map<int, int> c1{ {1,1},{2,2},{3,3} };
			std::map<int, int> c2{ {4,4},{5,5},{6,6} };
			size_t v1OldSize = std::size(c1);

			STLWrappers::addAll(c1, c2);
			REQUIRE(std::size(c1) == v1OldSize + std::size(c2));
			REQUIRE(STLWrappers::containsAll(c1, c2));
		}

		SECTION("on unordered maps")
		{
			std::unordered_map<int, int> c1{ { 1,1 },{ 2,2 },{ 3,3 } };
			std::unordered_map<int, int> c2{ { 4,4 },{ 5,5 },{ 6,6 } };
			size_t v1OldSize = std::size(c1);

			STLWrappers::addAll(c1, c2);
			REQUIRE(std::size(c1) == v1OldSize + std::size(c2));
			REQUIRE(STLWrappers::containsAll(c1, c2));
		}

		SECTION("on initializer list")
		{
			std::vector<int> c1{ 1,2,3 };
			size_t v1OldSize = std::size(c1);

			STLWrappers::addAll(c1, {4,5,6});
			REQUIRE(std::size(c1) == 6);
			REQUIRE(STLWrappers::containsAll(c1, {4,5,6}));
		}

	}

}

TEST_CASE("containsAny()")
{
	SECTION("vector")
	{
		std::vector<int> v{1, 2, 3};
		SECTION("on vector")
		{
			std::vector<int> v2{ 0,1,2 };
			REQUIRE(STLWrappers::containsAny(v, v2));

			std::vector<int> v3{ 0,0,0 };
			REQUIRE(!STLWrappers::containsAny(v, v3));
		}
	}

	SECTION("map")
	{
		std::map<int, int> m{ {1,1} };

		SECTION("on vector")
		{
			std::vector<int> v{ 1 };
			REQUIRE(STLWrappers::containsAny(m, v));
		}
	}
}

TEST_CASE("inFirstButNotSecond()") {
	SECTION("vector on vector") {
		std::vector<int> v1{ 1,2,3 };
		std::vector<int> v2{ 1,4,5 };
		auto results = STLWrappers::inFirstButNotInSecond(v1, v2);
		std::vector<int> compare{ 2,3 };
		REQUIRE(std::equal(std::begin(results), std::end(results), std::begin(compare),std::end(compare)));

		STLWrappers::inFirstButNotInSecond(std::vector<int>{1, 2, 3}, std::vector<int>{3});
	}
}