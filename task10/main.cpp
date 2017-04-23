#define CATCH_CONFIG_RUNNER 
#include "catch.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"

TEST_CASE("Constant")
{
	Parser *p = new Parser("1");
	REQUIRE(p->calculate() == 1);

	Parser *p1 = new Parser("11");
	REQUIRE(p1->calculate() == 11);

	Parser *p2 = new Parser("(-11)");
	REQUIRE(p2->calculate() == -11);
}

TEST_CASE("Plus")
{
	Parser *p = new Parser("(1+1)");
	REQUIRE(p->calculate() == 2);

	Parser *p1 = new Parser("(11+1)");
	REQUIRE(p1->calculate() == 12);

	Parser *p2 = new Parser("(11+11)");
	REQUIRE(p2->calculate() == 22);

	Parser *p3 = new Parser("11+11");
	REQUIRE(p3->calculate() != 22);

	Parser *p4 = new Parser("((-11)+11)");
	REQUIRE(p4->calculate() == 0);

	Parser *p5 = new Parser("(-(11+11))");
	REQUIRE(p5->calculate() == -22);
}

TEST_CASE("Minus")
{
	Parser *p = new Parser("(1-1)");
	REQUIRE(p->calculate() == 0);

	Parser *p1 = new Parser("(11-1)");
	REQUIRE(p1->calculate() == 10);

	Parser *p2 = new Parser("(11-12)");
	REQUIRE(p2->calculate() == -1);
}

TEST_CASE("Product")
{
	Parser *p = new Parser("(1*1)");
	REQUIRE(p->calculate() == 1);

	Parser *p1 = new Parser("(11*1)");
	REQUIRE(p1->calculate() == 11);

	Parser *p2 = new Parser("(11*11)");
	REQUIRE(p2->calculate() == 121);
}

TEST_CASE("Division")
{
	Parser *p = new Parser("(1/1)");
	REQUIRE(p->calculate() == 1);

	Parser *p1 = new Parser("(11/1)");
	REQUIRE(p1->calculate() == 11);

	Parser *p2 = new Parser("(11/2)");
	REQUIRE(p2->calculate() == 5.5);
}

TEST_CASE("Expresions")
{
	Parser *p = new Parser("((2+4)*2)");
	REQUIRE(p->calculate() == 12);

	Parser *p1 = new Parser("((11*2)-3)");
	REQUIRE(p1->calculate() == 19);

	Parser *p2 = new Parser("((112-2)*(4/2))");
	REQUIRE(p2->calculate() == 220);

	Parser *p3 = new Parser("(10*(4/2))");
	REQUIRE(p3->calculate() == 20);

	Parser *p4 = new Parser("((-10)*(4/2))");
	REQUIRE(p4->calculate() == -20);

	Parser *p5 = new Parser("((10*(4/2))/(-2))");
	REQUIRE(p5->calculate() == -10);

	Parser *p6 = new Parser("(1+(4*(-1)))");
	REQUIRE(p6->calculate() == -3);
}

int main(int argc, char* argv[])
{
	int result = Catch::Session().run(argc, argv);
	getchar();
	return result;
}
