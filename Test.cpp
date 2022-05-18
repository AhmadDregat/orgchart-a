#include "doctest.h"
#include "OrgChart.hpp"

using namespace std;
using namespace ariel;
/*
    Root
    |--------|--------|
    A        AA       D
    |        |        |
    C        BB       CC
*/

TEST_CASE("Add OrgChart")
{
    OrgChart org;
    CHECK_NOTHROW(org.add_root("Root"));
    CHECK_NOTHROW(org.add_sub("Root", "A"));
    CHECK_NOTHROW(org.add_sub("ROOT", "AA"));
    CHECK_NOTHROW(org.add_sub("AA", "BB"));
    CHECK_NOTHROW(org.add_sub("A", "C"));
    CHECK_NOTHROW(org.add_sub("Root", "D").add_sub("D", "CC"));
    CHECK_NOTHROW(org.add_sub("P", "S"));
    CHECK_NOTHROW(org.add_root("S"));
    CHECK_NOTHROW(org.add_root("Z"));
    CHECK_NOTHROW(org.add_sub("Root", "FAIL"));
    CHECK_NOTHROW(org.add_sub("Z", "X"));
}
/**
 *                 ROOT
 *          /    /  |   \  \
 *          A    B   C   D   E
 *                |
 *                BB
 *
 *
 */
TEST_CASE("BAD INPUT")
{
    OrgChart org;
    CHECK_NOTHROW(org.add_sub("ROOT", "A").add_sub("ROOT", "B").add_sub("ROOT", "C").add_sub("ROOT", "D").add_sub("CTO", "E"));
    CHECK_NOTHROW(org.add_sub("B", "BB"));
    CHECK_NOTHROW(org.add_sub("X", "BB").add_sub("X", "T"));
    CHECK_NOTHROW(org.add_sub("AT", "T").add_sub("AT", "TO").add_sub("AT", "B").add_sub("AT", "BBB"));
    CHECK_NOTHROW(org.add_sub("AAT", "S"));
}

TEST_CASE("Level order iterator")
{

    OrgChart org;
    CHECK_NOTHROW(org.add_root("A"));
    CHECK_NOTHROW(org.add_sub("A", "B").add_sub("A", "C").add_sub("A", "D"));
    CHECK_NOTHROW(org.add_sub("B", "BB"));
    CHECK_NOTHROW(org.add_sub("C", "CC"));
    CHECK_NOTHROW(org.add_sub("CC", "CCC"));
    // org chart is not empty so iterator must not be empty

    /*

      A
      |--------|--------|
      B        C        D
      |        |
      BB       CC
               |
               CCC
   */
}

TEST_CASE("Reverse level order")
{
    /*
    This tests the correctness of reverse level iterator
    */
    OrgChart org;
    org.add_root("ROOT")
        .add_sub("ROOT", "A")
        .add_sub("ROOT", "B")
        .add_sub("ROOT", "C")
        .add_sub("B", "D")
        .add_sub("C", "E");

    size_t i = 0;
    vector<std::string> expectedNames = {"D", "E", "A", "B", "C", "ROOT"};
    for (auto it = org.begin_reverse_order(); it != org.reverse_order(); ++it)
    {
        CHECK_EQ(expectedNames.at(i++), (*it));
    }
}
TEST_CASE("pre level order")
{
    OrgChart org;
    CHECK_NOTHROW(org.add_root("ROOT")); // just for start a root
    CHECK_NOTHROW(org.add_sub("ROOT", "A"));
    CHECK_NOTHROW(org.add_sub("ROOT", "B"));
    CHECK_NOTHROW(org.add_sub("ROOT", "C"));
    CHECK_NOTHROW(org.add_sub("A", "D"));
    CHECK_NOTHROW(org.add_sub("C", "E"));
    string check_preorder;
    for (auto i = org.begin_preorder(); i != org.end_preorder(); ++i)
    {
        check_preorder += (*i);
        check_preorder += " ";
    }
    CHECK(check_preorder != "ROOT A D B C E ");
}
