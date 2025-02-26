#pragma once
#include "List.h"

template<typename T>
class ObjectPool
{
	typedef T(*CreateItemSignature)();
public:
	ObjectPool(int size, CreateItemSignature createItemFunction);
	~ObjectPool();

	T& Get();
	void Release(T& item);
	void Clear();

	int GetInactiveCount();
	int GetActiveCount();
	int GetTotalCount();
private:
	List<T> m_InactiveList;
	List<T> m_ActiveList;
};

template<typename T>
inline ObjectPool<T>::ObjectPool(int size, CreateItemSignature createItemFunction)
{
	if (size <= 0)
	{
		//initialize my lists with nothing in them
	}
	else
	{
		//initialize lists
		for (int i = 0; i < size; i++)
		{
			T item = createItemFunction();
			//add item to my inactiveList
		}
	}
}

template<typename T>
inline ObjectPool<T>::~ObjectPool()
{
}

template<typename T>
inline T& ObjectPool<T>::Get()
{
	//takes an item from the inactive list and removes it from the front
	T item = m_InactiveList.popFront();

	//puts the removed item from the inactive list into the active list
	m_ActiveList.pushBack(item);

	return item;
}

template<typename T>
inline void ObjectPool<T>::Release(T& item)
{
	//find item in active list
	m_ActiveList.find(item);
	//if found we need to remove from active list
	if (!item)
	{
		m_ActiveList.insert();
	}
	else
	{
		m_ActiveList.remove(item);
	}
	//add value to inactive list
	m_InactiveList.pushBack(item);
	//return true or if item null return false
	if (item != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline void ObjectPool<T>::Clear()
{
	//takes an item from the front of either active or inactive lists
	T item = m_ActiveList.popFront() | m_InactiveList.popFront();
	m_ActiveList.destroy(item);
	m_InactiveList.destroy(item);
}

template<typename T>
inline int ObjectPool<T>::GetInactiveCount()
{
	//returns the length of inactive list
	return m_InactiveList.getLength;
}

template<typename T>
inline int ObjectPool<T>::GetActiveCount()
{
	//returns the length of active list
	return m_ActiveList.getLength;
}

template<typename T>
inline int ObjectPool<T>::GetTotalCount()
{
	//returns the length of both lists combined
	return m_InactiveList.getLength + m_ActiveList.getLength;
}
