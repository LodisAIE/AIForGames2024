#pragma once

template <typename T>
class DynamicArray
{
public:
	/// <summary>
	/// Adds a new value to the end of the array
	/// </summary>
	/// <param name="value">The new value to add to the array</param>
	void add(T value);

	/// <summary>
	/// Removes the value from the array
	/// </summary>
	/// <param name="value">The value to remove</param>
	/// <returns>False if the array does not contain an item that matches the value</returns>
	bool remove(T value);

	/// <summary>
	/// Removes a value from the array
	/// </summary>
	/// <param name="index">The index of the value to remove from the array</param>
	/// <returns>False if the index is out of bounds</returns>
	bool remove(int index);

	/// <summary>
	/// Gets the value at the specific index from the array
	/// </summary>
	/// <param name="index">The index of the desired value</param>
	/// <param name="value">A reference to store the value found in the array</param>
	/// <returns>Returns false if the index is invalid</returns>
	bool getItem(int index, T& value);

	/// <summary>
	/// Gets the length of the array
	/// </summary>
	int getLength() { return m_itemCount; }

	/// <summary>
	/// Checks if the value is in the array
	/// </summary>
	/// <param name="value">The value that will be used for comparisons</param>
	/// <returns>False if a matching value is not in the array</returns>
	bool contains(T value);

	/// <summary>
	/// Removes all items from the array.
	/// </summary>
	void clear();

	T operator [](int index)
	{
		return m_items[index];
	}

private:
	T* m_items;
	int m_itemCount;
};

template<typename T>
inline void DynamicArray<T>::add(T value)
{
	//Create a new array with a size one greater than our old array
	T* appendedArray = new T[m_itemCount + 1];
	//Copy the values from the old array to the new array
	for (int i = 0; i < m_itemCount; i++)
	{
		appendedArray[i] = m_items[i];
	}

	//Set the last value in the new array to be the value we want to add
	appendedArray[m_itemCount] = value;

	delete m_items;

	//Set old array to hold the values of the new array
	m_items = appendedArray;
	m_itemCount++;
}

template<typename T>
inline bool DynamicArray<T>::remove(T value)
{
	bool itemRemoved = false;
	//Create a new array with a size one less than our old array
	T* newArray = new T[m_itemCount - 1];

	//Create variable to access tempArray index
	int j = 0;
	//Copy values from the old array to the new array
	for (int i = 0; i < m_itemCount; i++)
	{
		if (value != m_items[i])
		{
			newArray[j] = m_items[i];
			j++;
		}
		else
		{
			itemRemoved = true;
		}
	}
	//Set the old array to the new array
	if (itemRemoved)
	{
		delete m_items;
		m_items = newArray;
		m_itemCount--;
	}
	//Return whether or not the removal was successful
	return itemRemoved;
}

template<typename T>
inline bool DynamicArray<T>::remove(int index)
{
	//Check to see if the index is outside the bounds of our array
	if (index < 0 || index >= m_itemCount)
	{
		return false;
	}

	bool itemRemoved = false;

	//Create a new array with a size one less than our old array 
	T* newArray = new T[m_itemCount - 1];
	//Create variable to access tempArray index
	int j = 0;
	//Copy values from the old array to the new array
	for (int i = 0; i < m_itemCount; i++)
	{
		//If the current index is not the index that needs to be removed,
		//add the value into the old array and increment j
		if (i != index)
		{
			newArray[j] = m_items[i];
			j++;
		}
		else
		{
			itemRemoved = true;
		}
	}

	//Set the old array to be the tempArray
	delete m_items;
	m_items = newArray;
	m_itemCount--;
	return itemRemoved;
}

template<typename T>
inline bool DynamicArray<T>::getItem(int index, T& value)
{
	//Return false if the index is out of bounds
	if (index < 0 || index >= m_itemCount)
		return false;

	value = m_items[index];

	return true;
}

template<typename T>
inline bool DynamicArray<T>::contains(T value)
{
	//Iterate through actor array
	for (int i = 0; i < m_itemCount; i++)
	{
		//return true if the current actor if it matches the argument
		if (m_items[i] == value)
			return true;
	}

	return false;
}

template<typename T>
inline void DynamicArray<T>::clear()
{
	delete m_items;
	m_items = nullptr;
	m_itemCount = 0;
}


