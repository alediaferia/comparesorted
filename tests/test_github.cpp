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

/**
 * This test case is here to confirm
 * the example on the repository just works.
 */

int main(int argc, char* argv[]) {
    static const std::vector<int> old_array = { 1, 2, 3, 4, 5, 6, 7, 8, 12, 56 };
    static const std::vector<int> new_array = { 1, 3, 4, 5, 45, 56 };

    std::set<int> added;
    std::set<int> deleted;
    compare_sorted(old_array, new_array, std::less<int>(),
                   added, deleted);

    int expected_added[]   = { 45 };
    int expected_deleted[] = { 2, 6, 7, 8, 12 };
    int i = 0;

    if (added.size() != 1) {
        std::cerr << "Unexpected 'added' set size: " << added.size() << " != 1 (expected)" << std::endl;
        return 1;
    }
    if (deleted.size() != 5) {
        std::cerr << "Unexpected 'deleted' set size: " << deleted.size() << " != 5 (expected)" << std::endl;
        return 1;
    }

    for (int v : added) {
        if (v != expected_added[i]) {
            std::cerr << "Unexpected added element: " << expected_added[i] << "(expected) != " << v << std::endl;

            return 1;
        }
        ++i;
    }
    i = 0;
    for (int v : deleted) {
        if (v != expected_deleted[i]) {
            std::cerr << "Unexpected deleted element: " << expected_deleted[i] << "(expected) != " << v << std::endl;
            return 1;
        }
        ++i;
    }
    
    return 0;
}
