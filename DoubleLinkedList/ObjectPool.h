#pragma once
#include "List.h"

template<typename T>
class ObjectPool
{
public:
	ObjectPool();
	~ObjectPool();

	T Get();
	bool Release(T& item);
	void Clear();
private:
	List<T> m_InactiveList;
	List<T> m_ActiveList;
};

template<typename T>
inline ObjectPool<T>::ObjectPool()
{
}

template<typename T>
inline ObjectPool<T>::~ObjectPool()
{
}

template<typename T>
inline T ObjectPool<T>::Get()
{
	T item = m_InactiveList.popFront();
	m_ActiveList.pushBack(item);

	return item;
}

template<typename T>
inline bool ObjectPool<T>::Release(T& item)
{
	//find item in active list
	T value = m_ActiveList.popBack();
	//if found we need to remove from active list
	if (!value)
	{
		m_ActiveList.insert();
	}
	else
	{
		m_ActiveList.remove(value);
	}
	//add value to inactive list
	m_InactiveList.pushFront(value);
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
