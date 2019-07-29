/*
 * QUESTION:
 * How do virtual functions work in C++?
 *
 * DISCUSSION (researched from C++ Primer Plus and Jumping into C++):
 *
 * In C++, the virtual function concept enables polymorphism. A function is declared virtual
 * in a base class if it may be reimplemented by the derived class. This allows constructs such
 * as declaring an array of base class pointers (all the same size and type) to point to a multitude
 * of different derived class objects and enable a multitude of different implementations for common functions to be invoked.
 *
 * For example, assume Student and Teacher classes are derived from the Person class. Assume
 * also that we create an std::vector<Person*> array to represent the people in a school course.
 * The Person class declares and implements a function getID() which prints "I am a Person." However in the
 * Student and Teacher classes, getID() prints "I am a Student" and "I am a Teacher" respectively. The problem
 * is that these different implementations of getID() would not be accessible from the Person* pointers stored
 * in the std::vector<Person*> unless getID() were declared virtual in the Person class definition.
 *
 * To implement this behavior, object instances carry an extra hidden member that is a pointer to block of data
 * called a vtable or "virtual table". There is one vptr ("virtual table pointer") per object for each interface the
 * object inherits. There is one vtable per interface. I.e. there would be one vtable for Person, one for Student,
 * and one for Teacher. Each object would contain a pointer to the class vtable of its type.
 * A vtable contains memory addresses of the possible functions that may be used by an object. Each entry in the
 * table corresponds to a different possible function, and the address in each entry is the address of the
 * version of that function (base class version or derived class version) that is appropriate to use. So if a
 * derived class reimplements a virtual function in the base class, the vtable will point to the derived class
 * reimplementation. If the derived class does not reimplement a virtual function in the base class, the vtable
 * entry will point to the base class version of that function.
 *
 * vtables enable dynamic binding as opposed to static binding. Static binding happens at compile time in cases when the
 * executable function code that must be bound to a function name call is unambiguous. This happens - among other cases - for
 * non-virtual member functions of classes. However, there are cases where the executable function code that must be
 * bound to a function call is not known at compile time and is only found out at runtime. An example of this is if
 * the choice of Student or Teacher derived classes depends on user input. The vtable object thus enables this dynamic
 * binding of executable function code along with the polymorphism concept.
 *
 * In C++, static binding is the default instead of dynamic binding for performance reasons: there is a compute cost
 * associated with vtable storage and operation. At each function call, there is an extra lookup operation that must
 * be made before the function call itself is executed. Furthermore, each object must carry a vtable pointer for each inherited
 * interface which costs a couple of bytes. In practice these are very small costs but they are non-zero. The storage
 * cost would become significant if there are many many objects with few member variables and thus the vtable memory
 * consumption may become significant.
 */
