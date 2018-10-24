#pragma once

/// This file defines some STL wrapper functions that provide a simpler interface to the STL containers.
/// All functions use the most efficient search, add, and removal operations available for the container.
/// For a brief description of the functions provided see readme.md.
/// For more in depth description of what the functions do, look at the function documentation in this file.
/// @file

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
	/// If the container is a map (or unordered map), the items should be keys.
	///@{
	///
	/// containsAll() overload for all types except initializer lists
	template<typename ContainerToCheckType, typename ContainerOfItemsType>
	bool containsAll(const ContainerToCheckType& container, const ContainerOfItemsType& items)
	{
		// approach:
		// - for each item in items
		//		- if its not contained in container, return false
		// - at the end (return true)

		for (const auto& item : items)
			if (!contains(container, item))
				return false;
		return true;
	}
	///
	/// containsAll() overload for initializer lists
	template<typename ContainerToCheckType, typename ItemType>
	bool containsAll(const ContainerToCheckType& container, const std::initializer_list<ItemType>& items)
	{
		// approach:
		// - for each item in items
		//		- if its not contained in container, return false
		// - at the end (return true)

		for (const auto& item : items)
			if (!contains(container, item))
				return false;
		return true;
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

}