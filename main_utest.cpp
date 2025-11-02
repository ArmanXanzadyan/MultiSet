#include "headers/MultiSet.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <iterator>
/*
TEST(a, bc)
{
   
    /// Create input iterators from std::cin
    std::istream_iterator<int> start(std::cin);
    std::istream_iterator<int> end;

    /// Initialize set using input iterators
    /// Enter integers (non-integer to stop):
    MultiSet<int> s(start, end);
     
    std::stringstream ss;
    s.print(ss);
    EXPECT_EQ(ss.str(), "1 2 3 \n");
}
*/

TEST(a, b)
{
    MultiSet<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(9);
    
    std::stringstream ss;
    s.print(ss);
    EXPECT_EQ(ss.str(), "1 2 5 9 \n");
}
  
TEST(MultiSetint, insert)
{
    MultiSet<int> s;
    s.insert(100);
    s.insert(50);
    s.insert(150);
    s.insert(20);
    s.insert(70);
    s.insert(120);
    s.insert(170);
    s.insert(10);
    s.insert(30);
    s.insert(60);
    s.insert(80);
    s.insert(110);
    s.insert(130);
    s.insert(160);
    s.insert(180);
    
    std::stringstream ss;
    s.print(ss);
    EXPECT_EQ(ss.str(), "10 20 30 50 60 70 80 100 110 120 130 150 160 170 180 \n"); 
    
    //std::cout << s << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
     
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    std::cout << (s.empty() ? "empty" : "Not") << std::endl;
    s.print(); 
       
    const int size = 9;
    int arr[size] = {11, 22, 33, 44, 55, 66, 77, 88, 99}; 
    s.insert(arr, arr + size);
    std::cout << s << std::endl;
}

TEST(MultiSetInt, CopyConstructor)
{
    MultiSet<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    
    MultiSet<int> b = s;
    EXPECT_TRUE(b == s);
    
    MultiSet<int> c;
    c = b;
    EXPECT_TRUE(c == s);

    std::stringstream ss1;
    c.print(ss1);
    std::stringstream ss2;
    s.print(ss2);
    EXPECT_EQ(ss1.str(), ss2.str()); 
}
  
TEST(MultiSetInt, RangeConstructor)
{
    const int size = 10;
    int arr[size] = {4, 1, 4, 4, 4, 1, 1, 4, 5, 6};
    MultiSet<int> s(arr, arr + size);
    std::stringstream ss;
    s.print(ss);
    //EXPECT_EQ(ss.str(), "1 1 4 4 5 6 \n");
    std::cout << s << std::endl;
    std::cout << "kfjshgaljsdhgfljagjjahsdgfjlhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhjl";
}

TEST(MultiSetInt, EraseIterator1)
{
    MultiSet<int> s;
    s.insert(4);
    s.insert(1);
    s.insert(6);
    s.erase(s.begin());
    std::cout << s << std::endl;
    std::stringstream ss;
    s.print(ss);
    EXPECT_EQ(ss.str(), "4 6 \n");
}

TEST(MultiSetInt, EraseIterator2)
{
    MultiSet<int> s;
    s.insert(4);
    s.insert(1);
    s.insert(6);
    s.erase(++s.begin());
    std::cout << s << std::endl;
    std::stringstream ss;
    s.print(ss);
    EXPECT_EQ(ss.str(), "1 6 \n");
}

TEST(MultiSetInt, EraseIterator3)
{
    MultiSet<int> s;
    s.insert(4);
    std::cout << s << std::endl;
    s.insert(1);
    std::cout << s << std::endl;
    s.insert(3);
    std::cout << s << std::endl;
    s.erase(++(++s.begin()));
    std::cout << s << std::endl;
    s.erase(++s.begin());
    std::cout << s << std::endl;
    s.erase(s.begin());
    std::cout << s << std::endl;
    std::stringstream ss;
    s.print(ss);
    EXPECT_EQ(ss.str(), "\n");
}

TEST(MultiSetInt, RangeErase)
{
    MultiSet<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(1);
    
    std::cout << s << std::endl;
    
    s.erase(++(s.begin()));
    std::cout << s << "\n\n" << std::endl;
    
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    EXPECT_TRUE(s.empty());
    s.clear(); 

    MultiSet<int>::iterator it = s.begin();
    MultiSet<int>::iterator jt = s.end();
    s.erase(it, jt);
    s.print();
}

TEST(MultiSetInt, Big_RangeErase)
{
    MultiSet<int> s;
    s.insert(4);
    s.insert(1);
    s.insert(6);
    s.insert(32);
    s.insert(13);
    s.insert(10);
    s.insert(11);
    s.insert(30);
    std::cout << s << std::endl;
    MultiSet<int>::iterator it = s.begin();
    MultiSet<int>::iterator jt = s.end();
    s.erase(it, jt);
    s.print();
    EXPECT_TRUE(s.empty());
}

TEST(MultiSetInt, RangeErase1)
{
    int arr[] = {4, 1, 9, 2, 7, 6};
    MultiSet<int> s(arr, arr + 6);
    MultiSet<int>::iterator it = s.begin();
    MultiSet<int>::iterator jt = s.end();
    EXPECT_EQ(*it, 1);
    std::cout << s << std::endl;
    s.erase(it, jt);
    EXPECT_TRUE(s.empty());
}

TEST(MultiSetInt, eraseKey)
{
    int arr[] = {4, 1, 9, 2, 7, 6};
    MultiSet<int> s(arr, arr + 6);
    std::cout << s << std::endl;
    
    s.erase(1);
    std::cout << s << std::endl;
    s.erase(4);
    std::cout << s << std::endl;
    s.erase(9);
    std::cout << s << std::endl;
    s.erase(2);
    std::cout << s << std::endl;
    s.erase(7);
    std::cout << s << std::endl;
    s.erase(6);
    EXPECT_TRUE(s.empty());
}

TEST(MultiSetInt, erase42)
{
    MultiSet<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(15);
    s.insert(12);
    s.insert(18);
    s.insert(0);
    s.insert(11);
    s.insert(13);
    s.insert(16);
    s.insert(19);
    std::cout << s << "\n\n" << std::endl;
    
}

TEST(MultiSetInt, decrement)
{
    MultiSet<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(15);
    s.insert(12);
    s.insert(18);
    s.insert(0);
    s.insert(11);
    s.insert(13);
    s.insert(16);
    s.insert(19);
    std::cout << s << "\n\n" << std::endl;
    MultiSet<int>::const_iterator first = s.begin();
    while (first != s.end()) {
        std::cout << *(first) << ' ';
        ++first;
    }    
    std::cout << std::endl;
    MultiSet<int>::const_iterator last = s.find(19); 
    while (last != s.end()) {
        std::cout << *last-- << ' ';
    }    
    std::cout << std::endl;
    MultiSet<int>::reverse_iterator b = s.rbegin();
    while (b != s.rend()) { std::cout << *b << ' '; ++b; }
    b = s.rbegin();
    std::cout << *(b.operator->()) << std::endl;    
}

TEST(MultiSetInt, bounds)
{
    MultiSet<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(15);
    s.insert(12);
    s.insert(18);
    s.insert(0);
    s.insert(11);
    s.insert(13);
    s.insert(16);
    s.insert(19);
    std::cout << s << "\n\n" << std::endl;
    int key1 = 4;
    std::cout << *s.lower_bound(key1) << std::endl;
    std::cout << *s.upper_bound(key1) << std::endl;
    EXPECT_TRUE(*s.lower_bound(key1) == 11);
    EXPECT_TRUE(*s.upper_bound(key1) == 11);
    int key2 = 16;
    EXPECT_TRUE(*s.lower_bound(key2) == 16);
    EXPECT_TRUE(*s.upper_bound(key2) == 18);
}

TEST(MultiSetInt, eraseKey4)
{
    MultiSet<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(2);
    s.insert(8);
    s.insert(12);
    s.insert(18);
    s.insert(0);
    s.insert(3);
    s.insert(6);
    s.insert(9);
    s.insert(11);
    s.insert(13);
    s.insert(16);
    s.insert(19);
    std::cout << s << "\n\n" << std::endl;
    
    s.erase(5);
    std::cout << s << "\n\n" << std::endl;
    
    s.erase(10);
    std::cout << s << "\n\n" << std::endl;
    s.erase(9);
    std::cout << s << "\n\n" << std::endl;
    s.erase(8);
    std::cout << s << "\n\n" << std::endl;
    s.erase(6);
    std::cout << s << "\n\n" << std::endl;
    s.erase(3);
    std::cout << s << "\n\n" << std::endl;
    s.erase(0);
    std::cout << s << "\n\n" << std::endl;
    s.erase(2);
    std::cout << s << "\n\n" << std::endl;
    
    std::stringstream ss1, ss2;
    s.preOrderIter(ss1);
    s.preOrderRec(ss2);
    EXPECT_TRUE(ss1.str() == ss2.str()); 
    
    ss1.str("");
    ss2.str("");
    s.inOrderIter(ss1);
    s.inOrderRec(ss2);
    EXPECT_TRUE(ss1.str() == ss2.str()); 
    
    ss1.str("");
    ss2.str("");
    s.postOrderRec(ss2);
    EXPECT_EQ(ss2.str(), "11 13 12 16 19 18 15 ");
    s.postOrderIter(ss1);
    EXPECT_EQ(ss1.str(), "11 13 12 16 19 18 15 ");
}

TEST(MultiSetInt, bound)
{
    MultiSet<double> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(2);
    s.insert(8);
    s.insert(12);
    s.insert(18);
    s.insert(0);
    s.insert(3);
    s.insert(6);
    s.insert(9);
    s.insert(11);
    s.insert(13);
    s.insert(16);
    s.insert(19);
    std::cout << s << "\n\n" << std::endl;
    EXPECT_TRUE(s.lower_bound(15) == s.find(15));
    EXPECT_TRUE(s.upper_bound(15) == s.find(16));
    EXPECT_TRUE(s.lower_bound(17) == s.find(18));
    EXPECT_TRUE(s.upper_bound(17) == s.find(18));
    EXPECT_TRUE(s.lower_bound(4.5) == s.find(5));
    EXPECT_TRUE(s.upper_bound(4.5) == s.find(5));
    EXPECT_TRUE(s.lower_bound(99) == s.end());
    EXPECT_TRUE(s.lower_bound(99) == s.end());
    EXPECT_TRUE(s.upper_bound(99) == s.end());
    EXPECT_TRUE(s.lower_bound(-1) == s.begin());
    EXPECT_TRUE(s.upper_bound(-1) == s.begin());
    EXPECT_TRUE(s.equal_range(9).first == s.lower_bound(9));
    EXPECT_TRUE(s.equal_range(9).second == s.upper_bound(9));
    EXPECT_TRUE(++s.equal_range(9).first == s.equal_range(9).second);
}

TEST(MultiSetInt, multi)
{
    MultiSet<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(0);
    s.insert(5);
    s.insert(15);
    s.insert(2);
    s.insert(8);
    s.insert(12);
    s.insert(18);
    s.insert(0);
    s.insert(3);
    s.insert(6);
    s.insert(9);
    s.insert(11);
    s.insert(13);
    s.insert(16);
    s.insert(19);
    std::cout << s << "\n\n" << std::endl;
    typedef MultiSet<int>::iterator It;
    It first = s.lower_bound(5);
    It last = s.upper_bound(5);
    std::cout << *first << std::endl;
    std::cout << *last << std::endl;
    for (It it = first; it != last; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    It it1 = s.lower_bound(5);//find(5);
    std::cout << *(--it1)++ << std::endl;
    std::cout << *(++it1) << std::endl;
    std::cout << "count(5): " << s.count(5) << std::endl;
    std::cout << "count(6): " << s.count(6) << std::endl;
    std::cout << s << "\n\n" << std::endl;
    std::cout << "total number of 5: " << s.erase(5) << std::endl;
    std::cout << s << "\n\n" << std::endl;
    std::cout << "total number of 6: " << s.erase(6) << std::endl;
    std::cout << s << "\n\n" << std::endl;
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

