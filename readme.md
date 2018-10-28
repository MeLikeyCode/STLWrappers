STLWrappers.h
=============

STLWrappers.h is a *single* header-only file that defines some C++ STL wrapper functions that provide a *simpler* (less verbose, less generic, more for the common case) interface to the STL containers/algorithms.

STLWrappers.h does not have any dependencies. To use it, simply `#include` [this](STLWrappers/STLWrappers.h) file.

Note: Functions that take 'items' (notice the plural) can take either a container or an initializer list.

Currently, provides the following functions for all STL containers.
- find(inContainer, item) -> iterator to item if found, else end iterator
- contains(container, item) -> true if container contains item, else false
- containsAll(container,items) -> true if container contains all of the items
- containsAny(container,items) -> true if container contains any of the items
- add(inContainer, item) -> adds item to the container
- add(inMap, key, value) -> adds a key and value to a map
- addAll(inContainer,items) -> adds all items to the container
- remove(fromContainer, item) -> removes item from the container
- count(inContainer,item) -> number of times item is in the container

All functions use the most efficient search, add, and remove operations available for the container.