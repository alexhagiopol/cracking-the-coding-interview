/*
 * QUESTION:
 * Compare and contrast hash table and STL map.
 *
 * a. How is a hash table implemented?
 * b. If the number of inputs is small, which data structure options can be used instead of a
 * hash table?
 *
 *
 * DISCUSSION PART (a):
 *
 * A hash table is a key-value pair data structure that allows O(1) time lookup of a value given its key.
 *
 * First a hash table relies on a hashing function that converts a key into an index used to look up
 * that key's associated value. The hashing function is important to implement well because the set
 * of total possible keys could be very vast while the set of total possible indices could be very small.
 * Thus, index collison is a problem for hash table implementation. For example, if the hashing function
 * is not ideal, multiple keys could map to the same value index. For small datasets, a trivial hashing function
 * may be the key itself. Creating a hashing function usually requires good knowledge of the data type
 * of the key: different hashing functions may be more appropriate for different key data types. The C++ 11
 * standard provides a hash<key> template that unordered associate containers such as unordered_map use by default.
 * Specializations of this template define hashing functions for the different primitive types in C++. Programmers
 * would have to define their own hashing functions for custom types.
 *
 * The second component of the hash table is the data structure itself which typically is an array of linked
 * lists. The index computed by the hash function is used to look up array elements; in the case of an
 * index collision, multiple values associated with that index are pushed to the back of the linked list
 * at that index. Below is an example of hash table operation:
 *
 * Keys:    Values:
 * A        78
 * B        12
 * C        90
 *
 * Assume that the hashing function has a collision for keys A and B.
 * Thus the array of linked lists looks like this:
 *
 * Array Index:         0,                  1
 * Linked List Content: [A, 78], [B, 12]    [C, 90]
 *
 * When the key "B" is looked up, its index collides with the index for "A". Thus, to retrieve the
 * value for "B" the linked list at array index 0 must be traversed one element at a time in order to find
 * "B"'s value. This means that hash tables have amortized O(1) lookup time. In the absolute worst case
 * - e.g. a very bad hashing function that assigns all N keys to the same array index - the lookup time is O(N).
 *
 * One final issue in hash table implementation is expanding the hash table size when the memory allocated for
 * it has been depleted. This expansion operation would require copying all contents of the hash table, and so
 * must not be done too often.
 *
 * DISCUSSION PART (b):
 *
 * If the keys support >, <, = relationships, a map could be implemented as a binary search tree or a derivative
 * of a binary search tree. In this case, the lookup time is O(long(N)), but if N is small this time could be negligible.
 * The std::map structure is implemented using a red-black tree, which is a binary search tree with one extra bit per node:
 * a color red or black. According to CLRS: "by constraining the node colors on any simple path from root to leaf,
 * red-black trees ensure that no such path is more than twice as long as any other so that the tree is approximately balanced."
 */
