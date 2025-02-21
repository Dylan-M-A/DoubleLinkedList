# Double Linked List
# Table of Contents
- [Node](#Node)
- [Iterator](#Iterator)
- [List](#List)
- [Object Pool](#Object-Pool)

# Functions

## Class: Node 
|Name | Description |
|:-|:-|
|Node| A node is the connection point in a computer network.|
|Node(T value)| 
|~Node| This function is used as a destructor, which deletes the fuction automatically if it goes out of scope or is explicitly deleted.|

## Class: Iterator
### Private Constructor: m_current

|Name |Description|
|:-|:-|
|Iterator|Allows traversal through arrays, vectors,and lists.|
|Iterator(Node* node)|Uses nodes in order to connect to another part of code.|
|T operator*() const|It returns m_current as value.|
|Iterator operator++()|If m_current is the value then it becomes the next value and returns a nullptr.|
|Iterator operator++(int)|If m_current is the value then it becomes the next value and returns a nullptr. Same as Iterator operator++() but uses integers.|
|Iterator operator--()|If m_current is the value then it becomes the previous value and returns a nullptr.|
|Iterator operator--(int)|If m_current is the value then it becomes the previous value and returns a nullptr. Same as Iterator operator--() but uses integers.|
|const bool operator==(const Iterator& other) const|It returns the value of m_current as equal to other.m_current.|
|const bool operator!=(const Iterator& other) const|It returns the value of m_current as not equal to other.m_current.|

## Class: List
### Private Constructor: m_heads
### Private Constructor: m_tails
### Private Constructor: m_length

|Name | Description|
|:-|:-|
|List|This allows you to create a list of items.|
|List(std::initializer_list list)|Uses an initializer to make a list.|
|~List|Is a deconstructor of the list function and will destroy the list. The m_head will delete and turn into a nullptr. The m_tail will delete and then turn into nullptr.|
|void pushFront(const T& value)|It will take a new number and push it in front of the first number. Example: (1), (2,1), (3,2,1)|
|void pushBack(const T& value)|It takes a new number and pushes it behind the first number. Example: (1), (1,2), (1,2,3)|
|T popFront|It takes the first number and takes it out of a list of numbers until all numbers are gone. Example: (1,2,3,4,5), (2,3,4,5), (3,4,5), ect.|
|T popBack|It take the last number of any list of numbers and gets rid of it until all numbers are gone. Example: (1,2,3,4,5), (1,2,3,4), (1,2,3), ect.|
|bool insert(const T& value, int index)|It will take a number and insert it into a set of coordinates in the code. Does not have to be in order. Example: (2,4,6,8) -> (1,2,4,6,8), ect.|
|int remove(const T& value)|It will take a number from a existing list and remove it from the list. Does not have to be in order. Example: (1,2,3,4,5) -> (1,3,4,5), ect.|
|T first const|Gives you the first number in a list. Example: (1,2,3,4,5) first = 1.|
|T last const|Gives you the last number in a list. Example: (1,2,3,4,5) last = 5.|
|Iterator begin|This will give you the beginning number of a list. Another way to do first. Example: (1,2,3,4,5) begin = 1.|
|Iterator end|This wil give you the ending number of a list. Another way to do last. Example: (1,2,3,4,5) end = 5.|
|void destroy|This will delete the list to the fullest extent to where the program does not remember it at all.|
|int getLength const|It will give you the length of any list big or small.|

## Class: Object Pool
### Private Constructor: m_ActiveList
### Private Constructor: m_InactiveList

|Name|Description|
|:-|:-|
|Object Pool|Contains all objects in a pool like container and will release them when needed.|
|~Object Pool|Is a deconstructor of object pool and can delete the object pool with everything in it.|
|Get| Takes an item from the object pool and puts it into the active list.
|Release| Takes the item that was put into the active list and puts it into the inactive list.
|Clear| Deletes items in both active and inactive lists.