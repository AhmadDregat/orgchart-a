/**
 * OrgChart file for the exercise on iterators
 */
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace ariel
{
    class Node
    {
    public:
        string data;
        vector<Node> subs;
    };
    class OrgChart
    {

    private:
        Node root;
        Node End;
        std::vector<std::string> levelOrder;
        std::vector<std::string> RLevelOrder;
        std::vector<std::string> preOrder;

    public:
        OrgChart &add_root(const string name)
        {
            return *this;
        }
        OrgChart &add_sub(const string parent, const string son) { return *this; }
        string *begin_level_order() { return &levelOrder[0]; }
        string *end_level_order() { return &levelOrder[0]; }
        string *reverse_order() { return &RLevelOrder[0]; }
        string *begin_reverse_order() { return &RLevelOrder[0]; }
        string *begin() { return begin_level_order(); }
        string *end() { return end_level_order(); }
        string *begin_preorder() { return &preOrder[0]; }
        string *end_preorder() { return &preOrder[0]; }

        friend ostream &operator<<(ostream &out, const OrgChart &root) { return out; }
    };
}