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

#ifndef SORTANDCOMPARE_H
#define SORTANDCOMPARE_H

#include <set>

template< class Iterable, class Compare >
void compare_sorted(Iterable &i1, // out of date list
                      Iterable &i2, // up-to-date list
                      Compare comp,
                      std::set<typename Iterable::value_type> &added,
                      std::set<typename Iterable::value_type> &deleted) {

    // now the dance begins
    auto it1 = std::begin(i1);
    auto end1 = std::end(i1);

    auto it2 = std::begin(i2);
    auto end2 = std::end(i2);

    int counter1, counter2 = 0;
    while (it1 != end1) {
        bool found = false;
        while (it2 != end2) {
            if (*it2 == *it1) {
                found = true;
                counter2++;
                ++it2;
                break;
            } else if (comp(*it1, *it2)) {
                // *it1 is less than *it2
                // so this means we are already
                // over the pivot item
                // so we should break this loop
                break;
            } else {
                // *it1 is greater than *it2
                // so we are pointing to a new
                // element in the up-to-date list
                added.insert(*it2);
            }
            counter2++;
            ++it2;
        }
        if (!found) {
            deleted.insert(*it1);
        }
        counter1++;
        ++it1;
        if (counter1 == i1.size() && it2 != end2) {
            // all remaining elements of i2 should be
            // registered as new elements
            while (it2 != end2) {
                added.insert(*it2);
                ++it2;
            }
        } else if (it2 == end2 && it1 != end1) {
            while (it1 != end1) {
                deleted.insert(*it1);
                ++it1;
            }
        }
    }
}

#endif // SORTANDCOMPARE_H
