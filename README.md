Double Linked List

This is a library designed to give the use of three main classes. The classes in question are node, iterator, and list. They all are very flexible and can be used in various scenerios. 

- Node: Is a fundamental building block of linked lists. Its most common use as a data or pointer is dependent on what the user needs done. If you need to store a value, then use a data (or more accurately, use the m_current as used in code). If you want to move to the next node, then use the pointer (also know as m_next), or you can even go to the previous node (using m_previous).
- Iterator: Is used as a travel agent in the code. If the user puts objects inside of a container (like an object pool), then iterators will allow for movement inside the container and go through it.
- List: This is used for many things. Such use cases include inserting and removing, placing items at the first and last spots of a area, along with an iterator version called beginning and end. It also includes a pushFront, pushBack, popFront, and popBack along with a destroy. PushFront adds elements or integers to the front of a line of elements and pushBack is vis versa, pushFront example: 30, 20, 10. PopFront is used to remove the first element or integer of a line of elements and popBack is vis versa, popFront example: (30,20,10)->(20,10).

