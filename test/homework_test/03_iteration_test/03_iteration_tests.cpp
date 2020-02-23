#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dna.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test function get_gc_content")
{
	REQUIRE(get_gc_content("AGCTATAG") == .375);
	REQUIRE(get_gc_content("CGCTATAG") == .50);
}

TEST_CASE("Test function get_reverse_string")
{
	REQUIRE(get_reverse_string("AGCTATAG") == "GATATCGA");
	REQUIRE(get_reverse_string("CGCTATAG") == "GATATCGC");
}

TEST_CASE("Test function get_dna_compliment")
{
	REQUIRE(get_dna_compliment("AAAACCCGGT") == "ACCGGGTTTT");
	REQUIRE(get_dna_compliment("CCCGGAAAAT") == "ATTTTCCGGG");
}