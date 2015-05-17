/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 Alessandro Diaferia <alediaferia@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE. 
 *
 */

#include <comparesorted.h>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

int main(int argc, char *argv[])
{
    std::set<int> added;
    std::set<int> deleted;

    std::vector<int> s1 { 1,56,4,2,8,7,6,12,5 };  // 1, 2, 4, 5, 6, 7, 8, 12, 56
    std::vector<int> s2 { 4,5,3,45,56,2,1 };      // 1, 2, 3, 4, 5, 45, 56
 
    sort(s1.begin(), s1.end(), std::greater<int>());
    sort(s2.begin(), s2.end(), std::greater<int>());

    compare_sorted(s1, s2, std::greater<int>(), added, deleted);

    int expected_deleted[] = { 6, 7, 8, 12 };
    int expected_added[]   = { 3, 45 };

    std::set<int> ed(expected_deleted, expected_deleted + 4);
    std::set<int> ea(expected_added, expected_added + 2);

    if (ed.size() != deleted.size()) {
        std::cerr << "Unexpected set size for deleted elements:" << ed.size() << "(expected) !=" << deleted.size() << std::endl;
        return 1;
    }
    if (ea.size() != added.size()) {
        std::cerr << "Unexpected set size for added elements:" << ea.size() << "(expected) !=" << added.size() << std::endl;
        return 1;
    }

    std::set<int>::iterator it = deleted.begin();
    std::set<int>::iterator end = deleted.end();

    int i = 0;
    while (it != end) {
        if ((*it) != expected_deleted[i]) {
            std::cerr << "Unexpected deleted value:" << expected_deleted[i] << "(expected) !=" << *it << std::endl;
            return 1;
        }
        ++i;
        ++it;
    }

    i = 0;
    it = added.begin();
    end = added.end();

    while (it != end) {
        if ((*it) != expected_added[i]) {
            std::cerr << "Unexpected added value:" << expected_added[i] << "(expected) !=" << *it << std::endl;
            return 1;
        }
        ++i;
        ++it;
    }
    return 0;
}
