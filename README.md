# StrUtils ![Language](https://img.shields.io/badge/language-C++11-orange.svg) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](./LICENSE.md)
A small c++ library to perform operations on std::string

# Architecture
  - The "str-utils-lib" folder contains the sources of the library
  - The "str-utils-test" folder contains the unit tests of the library functions
  
# Supported operations
  - split : Retrieve every words in a std::string as separated items of a std::vector.
            The separator can be defined by the user.
  - isPalindrome : Checks if the std::string is a palindrome
  - beginsWith | endsWith
  - replaceFirst | replaceLast | replaceAll : Replace the occurence(s) of the given std::string
  - vector_join : returns the content of a std::vector as a string with user-defined separator
  - ltrim | rtrim | trim : trims the input std::string
  - toString : returns the input as a string (uses input type T::operator<<)
  - toUpper | toLower
  - repeat : returns a std::string built by repeating the input std::string
