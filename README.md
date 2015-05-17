# compare_sorted
This tiny C++11 template library was born out of the need of comparing sorted lists for another project.

Given 2 sorted lists, the only method in this library, `compare_sorted`, will fill 2 [std::set](http://en.cppreference.com/w/cpp/container/set)'s with, respectively, **new elements** found and **deleted elements** detected.

## The function

```c++
template< class Iterable, class Compare >
void compare_sorted(Iterable &i1, // out of date iterable
    Iterable &i2, // up-to-date iterable
    Compare comp,  
    std::set<typename Iterable::value_type> &added, 
    std::set<typename Iterable::value_type> &deleted);
```

The template function expects 2 sorted forward iterable instances. The first one will be considered as the old one. The second one is used as the up-to-date one. A compare `comp` function is required to perform the elements comparison. It must meet the requirements of [Compare](http://en.cppreference.com/w/cpp/concept/Compare).

## A usage example
This project is currently just a header, `comparesorted.h`, which you can freely include in your own project in order to take advantage of it.

The simplest usage case involves 2 sorted arrays. The second array represent a new state for the old one and you are interested in detecting which elements have been deleted and which elements have been added in  the meantime.
```c++
    #include <comparesorted.h>
    #include <vector>
    
    int main(int argc, char* argv[]) {
        static const std::vector<int> old_array = { 1, 2, 3, 4, 5, 6, 7, 8, 12, 56 };
        static const std::vector<int> new_array = { 1, 3, 4, 5, 45, 56 };
        
        std::set<int> added;
        std::set<int> deleted;
        compare_sorted(old_array, new_array, std::greater<int>(),
                       added, deleted);
                       
        std::cout << "Added elements are as follows:" << std::endl;
        for (int v : added)  {
            std::cout << v << std::endl;
        }
        std::cout << std::endl;
        
        std::cout << "Deleted elements are as follows:" << std::endl;
        for (int v : deleted)  {
            std::cout << v << std::endl;
        }
        std::cout << std::endl;
        
        return 0;
    }
```

Output for this code will be as follows:
```
Added elements are as follows:
45

Deleted elements are as follows:
2
6
7
8
12
```

## Testing
This project comes with test cases. In order to run them you can go with the following steps:

```bash
cd comparesorted/build
cmake ..
make
make test
```

The test files are unexpectedly under `tests/` :)

## Contribute, please
This is just a trivial project I started for learning purposes. I'm rather used to C++03 but I'm rather new to C++11 so, please, help me address any issue in taking advantage of it.
That being said, I really appreciate any form of contribution that could help this project become helpful for more people other than me. 

## License
This code is released under the MIT License. You can find a copy of the license in this repository.
