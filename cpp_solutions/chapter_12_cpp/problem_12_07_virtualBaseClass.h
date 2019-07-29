/*
 * QUESTION:
 * Why does a destructor in a base class need to be declared virtual?
 *
 * DISCUSSION (researched from C++ Primer Plus and Jumping into C++):
 * This issue arises when we use a base class pointer to point to an object of a derived class
 * e.g. assume the Student class is derived from the Parent class:
 *
 * Person * p = new Student();
 *
 * If Person's destructor were not virtual, the Student object would be destructed with
 * the destructor in Parent because the pointer to p is a Parent pointer. This could
 * lead to situations in which Student-specific memory allocations are not cleaned up which lead
 * to memory corruption.
 *
 */
