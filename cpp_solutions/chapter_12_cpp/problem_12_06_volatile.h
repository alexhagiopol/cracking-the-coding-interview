/*
 * PROBLEM:
 * What is the significance of the keyword "volatile" in C?
 *
 * DISCUSSION:
 * The volatile keyword indicates to the compiler that a variable may be changed
 * outside the scope of the current block of code. This applies to situations in which
 * the variable may be changed by the hardware such as memory-mapped I/O. Syntactically the
 * volatile keyword is used in the same way as const.
 *
 * The keyword is necessary to prevent compiler optimizations that are done based on the
 * assumption that the variable does *not* change when it is *not* modified in the current
 * scope. If such compiler optimizations are done and the variable *is* modified e.g. by the
 * hardware outside the current scope, it would lead to undefined behavior. In the above case,
 * the compiler would re-use a stale variable value which would yield incorrect calculation
 * results.
 *
 * Note that in C++ 11, the volatile keyword is *not* intended for use in multithreaded scenarios,
 * and the std::atomic<T> template is intended to be used instead for inter-thread communication.
 * In C++ 11, the volatile keyword is only intended to handle hardware access scenarios.
 */