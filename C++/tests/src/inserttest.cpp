#include "linkedlisttest.h"

using std::endl;
using std::cout;

TEST_F(LinkedListTest, InsertTest){
    EXPECT_EQ(l1.get_size(), 0);
    l1.insert(3,0);
    EXPECT_EQ(l1.get_size(), 1);
    l1.insert(2,0);
    EXPECT_EQ(l1.get_size(), 2);
    l1.push_front(1);
    EXPECT_EQ(l1.get_size(), 3);
    l1.insert(4,3);
    EXPECT_EQ(l1.get_size(), 4);
    l1.push_back(6);
    EXPECT_EQ(l1.get_size(), 5);
    l1.insert(5,4);
    EXPECT_EQ(l1.get_size(), 6);

    EXPECT_EQ(l1[0], 1);
    EXPECT_EQ(l1[1], 2);
    EXPECT_EQ(l1[2], 3);
    EXPECT_EQ(l1[3], 4);
    EXPECT_EQ(l1[4], 5);
    EXPECT_EQ(l1[5], 6);
}
