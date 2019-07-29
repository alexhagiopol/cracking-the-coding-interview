/*
 * QUESTION:
 * What is the difference between deep copy and shallow copy? Explain how you would use each.
 *
 * DISCUSSION:
 * A shallow copy of an object copies all of its member variables. This sounds simple, but it hides one big
 * piece of complexity: if among the object's
 * member variables there exist pointers to allocated memory, only the pointers themselves are copied
 * while the allocated memory remains the same. Thus if two such shallow copied objects exist, they will
 * contain different pointers to the same block of allocated memory. Unless this behavior is intended (it usually
 * isn't), it could cause program logic errors as well as memory access violation errors because.
 *
 * Shallow copies are useful when we need const pointers or const references to a large block of memory that
 * does not change and has the proper const keywords to prevent change. An example of this would be passing copies of
 * pointers to a large image do different image processing functions that each needs to read the raw image, do computation,
 * and return a result.
 *
 * Deep copies are what the name implies: the copy operation travels recursively to all pointed-to allocated
 * memory, allocates new memory, copies the data over, and then returns a new pointer to the newly allocated block.
 * Deep copies are useful when different segments of the same program must alter a set of data in different ways
 * and the further operate on the results of the changes.
 *
 */
