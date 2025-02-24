#pragma once
#include "List.h"

template<typename T>
class ObjectPool
{
public:
	ObjectPool(int defaultSize);
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
inline ObjectPool<T>::ObjectPool(int defaultSize)
{
}

template<typename T>
inline ObjectPool<T>::~ObjectPool()
{
}

template<typename T>
inline T& ObjectPool<T>::Get()
{
	T item = m_InactiveList.popFront();
	m_ActiveList.pushBack(item);

	return item;
}

template<typename T>
inline void ObjectPool<T>::Release(T& item)
{
	//find item in active list
	T item = m_ActiveList.find(item);
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
	m_InactiveList.pushFront(item);
	//return true or if item null return false
	if (value != null)
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
	T item = m_ActiveList || m_InactiveList;
	m_ActiveList.remove(item);
	m_InactiveList.remove(item);
}

template<typename T>
inline int ObjectPool<T>::GetInactiveCount()
{
	return m_InactiveList.getLength;
}

template<typename T>
inline int ObjectPool<T>::GetActiveCount()
{
	return m_ActiveList.getLength
}

template<typename T>
inline int ObjectPool<T>::GetTotalCount()
{
	return m_InactiveList.getLength + m_ActiveList.getLength;
}
