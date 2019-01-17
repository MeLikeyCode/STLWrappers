#pragma once

/// This file defines some STL wrapper functions that provide a simpler interface to the STL containers.
/// All functions use the most efficient search, add, and removal operations available for the container.
/// For a brief description of the functions provided see readme.md.
/// For more in depth description of what the functions do, look at the function's API documentation in this file.
/// @file
/// @author Abdullah Aghazadah

#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

/// This namespace contains some STL wrapper functions that provide a simpler interface to the STL.
/// Read the STLWrappers.h file level documentation and readme.md for more info.
namespace STLWrappers
{

	/// @name find(inContainer, item)
	/// Finds an item in a container.
	/// Returns an iterator to the item if found, otherwise returns the end iterator.
	/// If the container is a map (or unordered map) 'item' should be a key.
	/// In that case, if the key is found, you will get an iterator to the key-value pair, otherwise, you will get the end iterator.
	/// @note The most efficient search algorithm available for the container is used.
	///@{
	///
	/// Generic find() overload that works on any container. Complexity is linear.
	template<typename ContainerType, typename ItemType>
	auto find(const ContainerType& inContainer, const ItemType& item)
	{
		return std::find(std::begin(inContainer), std::end(inContainer), item);
	}
	///
	/// find() overload for set, uses binary search tree, thus complexity is logarithmic.
	template<typename ItemType>
	auto find(const std::set<ItemType>& inContainer, const ItemType& item)
	{
		return inContainer.find(item);
	}
	///
	/// find() overload for unordered set, uses hash table, thus complexity is constant.
	template<typename ItemType>
	auto find(const std::unordered_set<ItemType>& inContainer, const ItemType& item)
	{
		return inContainer.find(item);
	}
	///
	/// find() overload for map, uses binary search tree, thus complexity is logarithmic.
	template<typename KeyType, typename ValueType>
	auto find(const std::map<KeyType,ValueType>& inContainer, const KeyType& item)
	{
		return inContainer.find(item);
	}
	///
	/// find() overload for unordered map, uses hash table, thus complexity is constant.
	template<typename KeyType, typename ValueType>
	auto find(const std::unordered_map<KeyType, ValueType>& inContainer, const KeyType& item)
	{
		return inContainer.find(item);
	}
	///@}

	/// Returns true if the specified container contains the specified item.
	/// If the container is a map (or unordered map), 'item' should be a key.
	/// @note The most efficient search algorithm available for the container is used.
	template<typename ContainerType, typename ItemType>
	bool contains(const ContainerType& container, const ItemType& item)
	{
		return find(container, item) != std::end(container);
	}

	/// @name containsAll(container,items)
	/// Returns true if the specified container contains *all* the specified items.
	/// `items` can be another container or an initializer list.
	/// If the container is a map (or unordered map), the items should be keys.
	/// @note The most efficient search algorithm available for the container is used.
	///@{
	///
	///
	// internal (factors out common code between version taking a container and version taking an 
	// initializer list)
	template<typename ContainerToCheckType, typename ContainerOfItemsType>
	bool containsAll_(const ContainerToCheckType& container, const ContainerOfItemsType& items)
	{
		for (const auto& item : items)
			if (!contains(container, item))
				return false;
		return true;
	}

	///
	/// containsAll() overload for all types except initializer lists
	template<typename ContainerToCheckType, typename ContainerOfItemsType>
	bool containsAll(const ContainerToCheckType& container, const ContainerOfItemsType& items)
	{
		return containsAll_(container, items);
	}
	///
	/// containsAll() overload for initializer lists
	template<typename ContainerToCheckType, typename ItemType>
	bool containsAll(const ContainerToCheckType& container, const std::initializer_list<ItemType>& items)
	{
		return containsAll_(container, items);
	}
	///@}

	/// @name containsAny(container, items)
	/// Returns true if the specified container contains *any* of the specified items.
	/// `items` can be another container or an initializer list.
	/// @note The most efficient search algorithm available for the container is used.
	///@{
	///
	// internal
	template<typename ContainerToCheckType, typename ContainerOfItems>
	bool containsAny_(const ContainerToCheckType& container, const ContainerOfItems& items)
	{
		for (const auto& item : items) 
		{
			if (contains(container, item))
				return true;
		}

		return false;
	}
	///
	/// containsAny() overload for any types
	template<typename ContainerToCheckType, typename ContainerOfItems>
	bool containsAny(const ContainerToCheckType& container, const ContainerOfItems& items)
	{
		return containsAny_(container, items);
	}
	///
	template<typename ContainerToCheckType, typename ItemType>
	bool containsAny(const ContainerToCheckType& container, const std::initializer_list<ItemType>& items)
	{
		return containsAny_(container, items);
	}

	///@}

	/// @name remove(fromContainer, item)
	/// Removes the specified item from the container (if it exists).
	/// @note The most efficient removal algorithm available for the container is used.
	///@{
	///
	/// remove() Overload that works for any container that the "erase and remove" idiom works for.
	/// Complexity is linear.
	template<typename ContainerType, typename ItemType>
	void remove(ContainerType& fromContainer, const ItemType& item)
	{
		auto new_end_itr = std::remove(std::begin(fromContainer), std::end(fromContainer), item);
		fromContainer.erase(new_end_itr,std::end(fromContainer));
	}
	///
	/// remove() overload for set, complexity is logarithmic.
	template<typename ItemType>
	void remove(std::set<ItemType>& fromContainer, const ItemType& item)
	{
		fromContainer.erase(item);
	}
	///
	/// remove() overload for unordred set, complexity is constant.
	template<typename ItemType>
	void remove(std::unordered_set<ItemType>& fromContainer, const ItemType& item)
	{
		fromContainer.erase(item);
	}
	/// remove() overload for map, complexity is logarithmic.
	template<typename KeyType, typename ValueType>
	void remove(std::map<KeyType,ValueType>& fromContainer, const KeyType& item)
	{
		fromContainer.erase(item);
	}
	///
	/// remove() overload for unordered map, complexity is constant.
	template<typename KeyType, typename ValueType>
	void remove(std::unordered_map<KeyType, ValueType>& fromContainer, const KeyType& item)
	{
		fromContainer.erase(item);
	}
	///@}

	/// Adds an item to the end of a container.
	/// @note Uses the most efficient insertion operation available for the container.
	template<typename ContainerType, typename ItemType>
	void add(ContainerType& inContainer, const ItemType& item)
	{
		inContainer.insert(std::end(inContainer), item);
	}

	/// Adds a key and value to a map (or unordered map).
	template<typename  MapType, typename KeyType, typename ValueType>
	void add(MapType& inMap, const KeyType& key, const ValueType& value)
	{
		inMap[key] = value;
	}

	/// @name add(inContainer, items)
	/// Adds all the items of one container (or an initializer list) to another container.
	/// Convenience function; simply calls add() repeatedly (once for each item to be added).
	/// Complexity of this function depends on the complexity of adding a single element to the container.
	/// More formally, complexity is O(n*c) where n is the number of items in `items` and c is the complexity 
	/// of adding to `inContainer`.
	///@{
	///
	/// overload for everything except an initializer list
	template<typename ToContainerType, typename FromContainerType>
	void addAll(ToContainerType& inContainer, const FromContainerType& items)
	{
		for (const auto& item : items)
			add(inContainer, item);
	}
	///
	/// overload for adding from an initializer list
	template<typename ToContainerType, typename ItemType>
	void addAll(ToContainerType& inContainer, const std::initializer_list<ItemType>& items)
	{
		for (const auto& item : items)
			add(inContainer, item);
	}
	///@}

	/// @name count(inContianer, item)
	/// Returns the number of copies of an item that are in a container.
	/// @note Uses the most efficient search operation available for the container.
	///@{
	///
	/// Generic count() overload that works for any container.
	template<typename ContainerType, typename ItemType>
	size_t count(const ContainerType& inContainer, const ItemType& item)
	{
		return std::count(std::begin(inContainer), std::end(inContainer), item);
	}
	///
	/// count() overload for set, complexity is logarithmic.
	template<typename ItemType>
	size_t count(const std::set<ItemType>& inContainer, const ItemType& item)
	{
		return inContainer.count(item);
	}
	///
	/// count() overload for unordered set, complexity is constant.
	template<typename ItemType>
	size_t count(const std::unordered_set<ItemType>& inContainer, const ItemType& item)
	{
		return inContainer.count(item);
	}
	///
	/// count() overload for map, complexity is logarithmic.
	template<typename KeyType, typename ValueType>
	size_t count(const std::map<KeyType,ValueType>& inContainer, const KeyType& item)
	{
		return inContainer.count(item);
	}
	///
	/// count() overload for unordered map, complexity is constant.
	template<typename KeyType, typename ValueType>
	size_t count(const std::unordered_map<KeyType, ValueType>& inContainer, const KeyType& item)
	{
		return inContainer.count(item);
	}
	///@}

	/// @name inFirstButNotSecond(firstContainer,secondContainer)
	/// Returns the set of items in the 'firstContainer' but not in the 'secondContainer'.
	///@{
	///
	// overload for when both arguments are containers
	template<typename FirstContainerType, typename SecondContainerType>
	auto inFirstButNotInSecond(const FirstContainerType& firstContainer, const SecondContainerType& secondContainer) {
		return inFirstButNotInSecond_(firstContainer, secondContainer);
	}

	// overload for when the first argument is an initializer list
	template<typename ItemType, typename SecondContainerType>
	auto inFirstButNotSecond(const std::initializer_list<ItemType>& firstContainer, const SecondContainerType& secondContainer) {
		return inFirstButNotInSecond_(firstContainer, secondContainer);
	}

	// overload for when the second argument is an initializer list
	template<typename ItemType, typename FirstContainerType>
	auto inFirstButNotSecond(const FirstContainerType& firstContainer, const std::initializer_list<ItemType>& secondContainer) {
		return inFirstButNotInSecond_(firstContainer, secondContainer);
	}

	// overload for when both arguments are initializer lists
	template<typename ItemType>
	auto inFirstButNotSecond(const std::initializer_list<ItemType>& firstContainer, const std::initializer_list<ItemType>& secondContainer) {
		return inFirstButNotInSecond_(firstContainer, secondContainer);
	}

	// internal function with core logic, used to reduce duplicate code
	template<typename FirstContainerType, typename SecondContainerType>
	auto inFirstButNotInSecond_(const FirstContainerType& firstContainer, const SecondContainerType& secondContainer) {
		std::unordered_set<FirstContainerType::value_type> results{};
		for (const auto& item : firstContainer) {
			if (!contains(secondContainer, item))
				results.insert(item);
		}
		return results;
	}
	///@}
}