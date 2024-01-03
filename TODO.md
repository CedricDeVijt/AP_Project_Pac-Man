- pointers to smart pointers
- cosnt, inline, constexpr, noexcept, override, final
- destructors
- const references

- Use namespaces to clearly divide modular sections of your code.
- Include exception handling to catch and deal with possible errors, such as the absence of
- required files.
- Proper use of the static, const and override keywords where they can be applied.
- Make sure to avoid memory leaks by explicitly creating virtual destructors where necessary.
- Always explicitly initialize primitive types. (Hint: check these last two with valgrind.)
- Avoid unnecessarily copying objects where they can be passed as a reference or pointer.
- Refrain from relying on dynamic casts! This usually means your design is lacking proper polymorphism.
- Avoid duplicate code, solve this by using better polymorphism or templates. Use clang-format with this configuration
  to format your code.
- Write proper code comments and API documentation.
- Use of smart pointers throughout the whole project is obligated. This is used to test your insight on where to use
  unique, shared or weak pointers, depending on the type of ownership. No raw pointers are allowed, except in certain
  design patterns where the use of smart pointers is prohibitive. But if you need them, please discuss this with us and
  provide your reasoning first. Passing objects by reference is also perfectly fine, this does not necessarily always
  need to happen through the use of pointers.