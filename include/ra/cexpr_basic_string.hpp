#include <cstdlib>
#include <stdexcept>

namespace ra::cexpr {

    // A basic string class template for use in constexpr contexts.
    template <class T, std::size_t M>
    class cexpr_basic_string {
        public:
            // An unsigned integral type used to represent sizes.
            using size_type = std::size_t;

            // The type of each character in the string (i.e., an alias for
            // the template parameter T).
            using value_type = T;

            // The type of a mutating pointer to each character in the string.
            using pointer = T*;

            // The type of a non-mutating pointer to each character in the
            // string.
            using const_pointer = const T*;

            // The type of a mutating reference to a character in the string.
            using reference = T&;

            // The type of a non-mutating reference to a character in the
            // string.
            using const_reference = const T&;

            // A mutating iterator type for the elements in the string.
            using iterator = pointer;

            // A non-mutating iterator type for the elements in the string.
            using const_iterator = const_pointer;

            // Creates an empty string (i.e., a string containing no
            // characters).
            constexpr cexpr_basic_string() : m_size_(0), m_data_{value_type(0)} {}

            // Explicitly default some special members.
            constexpr cexpr_basic_string(const cexpr_basic_string&) = default;
            constexpr cexpr_basic_string& operator=(const cexpr_basic_string&) = default;
            ~cexpr_basic_string() = default;

            // Creates a string with the contents given by the
            // null-terminated character array pointed to by s.
            // If the string does not have sufficient capacity to hold
            // the character data provided, an exception of type
            // std::runtime_error is thrown.
            constexpr cexpr_basic_string(const value_type* s) : m_size_(0), m_data_{value_type(0)} {
                while (*s++) {
                    ++m_size_;
                }

                if (m_size_ > M) {
                    throw std::runtime_error("cexpr_basic_string: insufficient capacity");
                }

                s = s - m_size_ - 1;
                for (size_type i = 0; i < m_size_; ++i) {
                    m_data_[i] = *s++;
                }
                m_data_[m_size_] = value_type(0);
            }

            // Creates a string with the contents specified by the characters
            // in the iterator range [first, last).
            // If the string does not have sufficient capacity to hold
            // the character data provided, an exception of type
            // std::runtime_error is thrown.
            constexpr cexpr_basic_string(const_iterator first, const_iterator last) : m_size_(0), m_data_{value_type(0)} {
                while (first++ != last) {
                    ++m_size_;
                    //++first;
                }

                if (m_size_ > M) {
                    throw std::runtime_error("cexpr_basic_string: insufficient capacity");
                }

                first = first - m_size_ - 1;
                for (size_type i = 0; i < m_size_; ++i) {
                    m_data_[i] = *first++;
                }
                m_data_[m_size_] = value_type(0);
            }

            // Returns the maximum number of characters that can be held by a
            // string of this type.
            // The value returned is the template parameter M.
            static constexpr size_type max_size() {
                return M;
            }

            // Returns the maximum number of characters that the string can
            // hold. The value returned is always the template parameter M.
            constexpr size_type capacity() const {
                return M;
            }

            // Returns the number of characters in the string (excluding the
            // dummy null character).
            constexpr size_type size() const {
                return m_size_;
            }

            // Returns a pointer to the first character in the string.
            // The pointer that is returned is guaranteed to point to a
            // null-terminated character array.
            // The user of this class shall not alter the dummy null
            // character stored at data() + size().
            value_type* data() {
                return m_data_;
            }
            const value_type* data() const {
                return m_data_;
            }

            // Returns an iterator referring to the first character in the
            // string.
            constexpr iterator begin() {
                return &m_data_[0];
            }
            constexpr const_iterator begin() const {
                return &m_data_[0];
            }

            // Returns an iterator referring to the fictitious
            // one-past-the-end character in the string.
            constexpr iterator end() {
                return &m_data_[m_size_];
            }
            constexpr const_iterator end() const {
                return &m_data_[m_size_];
            }

            // Returns a reference to the i-th character in the string if i
            // is less than the string size; and returns a reference to the
            // dummy null character if i equals the string size.
            // Precondition: The index i is such that i >= 0 and i <= size().
            constexpr reference operator[](size_type i) {
                return m_data_[i];
            }
            constexpr const_reference operator[](size_type i) const {
                return m_data_[i];
            }

            // Appends (i.e., adds to the end) a single character to the
            // string. If the size of the string is equal to the capacity,
            // the string is not modified and an exception of type
            // std::runtime_error is thrown.
            constexpr void push_back(const T& x) {
                if (m_size_ == M) {
                    throw std::runtime_error("push_back: string if full");
                }

                m_data_[m_size_++] = x;
                m_data_[m_size_] = value_type(0);
            }

            // Erases the last character in the string.
            // If the string is empty, an exception of type std::runtime_error
            // is thrown.
            constexpr void pop_back() {
                if (m_size_ == 0) {
                    throw std::runtime_error("pop_back: string is empty");
                }

                m_data_[--m_size_] = value_type(0);
            }

            // Appends (i.e., adds to the end) to the string the
            // null-terminated string pointed to by s.
            // Precondition: The pointer s must be non-null.
            // If the string has insufficient capacity to hold the new value
            // resulting from the append operation, the string is not modified
            // and an exception of type std::runtime_error is thrown.
            constexpr cexpr_basic_string& append(const value_type* s) {
                while (*s) {
                    push_back(*s++);
                }
                return *this;
            }

            // Appends (i.e., adds to the end) to the string another
            // cexpr_basic_string with the same character type (but
            // possibly a different maximum size).
            // If the string has insufficient capacity to hold the new value
            // resulting from the append operation, the string is not modified
            // and an exception of type std::runtime_error is thrown.
            template <size_type OtherM>
            constexpr cexpr_basic_string& append(const cexpr_basic_string<value_type, OtherM>& other) {
                if (other.size() > M - m_size_) {
                    throw std::runtime_error("append: insufficient capacity");
                }

                for (size_type i = 0; i < other.size(); ++i) {
                    push_back(other[i]);
                }
                return *this;
            }

            // Erases all of the characters in the string, yielding an empty
            // string.
            constexpr void clear() {
                m_size_ = 0;
                m_data_[0] = value_type(0);
            }

        private:
            // The number of characters in the string (excluding the dummy
            // null character).
            size_type m_size_;

            // The characters in the string.
            value_type m_data_[M + 1];
    };

    template <std::size_t M>
    using cexpr_string = cexpr_basic_string<char, M>;

    // The to_string function converts the integer n to its equivalent (decimal)
    // null-terminated string representation. The buffer to be used to store the
    // result starts at the location pointed to by buffer and has a size of size
    // characters. The resulting string produced by the function is null-terminated.
    // The number of characters written to the buffer, excluding the null character,
    // is returned. If end is non-null, *end is set to point to the null character
    // at the end of the converted string. If the buffer provided does not have
    // sufficient capacity to hold the string resulting from the conversion process,
    // an exception of type std::runtime_error is thrown.
    constexpr std::size_t to_string(std::size_t n, char* buffer, std::size_t size, char** end) {
        std::size_t i = 0;
        std::size_t num = n;
        while (num > 0) {
            ++i;
            num /= 10;
        }

        if (i > size) {
            throw std::runtime_error("to_string: insufficient buffer size");
        }

        char* p = buffer + i;
        *p = '\0';

        if (*end) {
            *end = p;
        }

        while (n > 0) {
            *--p = '0' + (n % 10);
            n /= 10;
        }

        return i;
    }

}  // namespace ra::cexpr