/**
 *  EPITECH PROJECT 2020
 *  CPP_RTYPE
 * File  description:
 *      Library permit to serialize an object to a binary stream or
 *      back up an object by deserialization.
*/

#ifndef     _SERIALIZER__HPP_
# define    _SERIALIZER__HPP_
# include   <string>
# include   <array>
# include   <sstream>
# include   <exception>

class SerializerException : public std::exception
{
private:
    const std::string   _what;

public:
    SerializerException(const std::string &what) throw(): _what(what) {}
    const char  *what() const throw() override {
        return this->_what.c_str();
    }
};

class Serializer
{
public:
    Serializer() {};
    virtual ~Serializer() {}

    /*!
     * The serialize function permit to serialize an type of object
     * @tparam T
     * @param object
     * @return an array of unsigned char corresponding to a binary array
     * of raw object data
     */
    template <typename T>
    static std::array<unsigned char, sizeof(T)>     serialize(const T& object)
    {
        std::array<unsigned char, sizeof(T)>    bytes;

        auto *begin = reinterpret_cast<const unsigned char *>(std::addressof(object));
        const unsigned char *end = begin + sizeof(T);
        std::copy(begin, end, std::begin(bytes));
        return (bytes);
    }

    /*!
     * The deserializer function permit to deserialize a trivial, copyable object
     * An exception is return is case of deserialize error
     * @tparam T
     * @param bytes
     * @param object
     * @return The unserialized object from the raw bytes give in param
     */
    template <typename T>
    static T       &deserialize(const std::array<unsigned char, sizeof(T)> &bytes,
                                T& object)
    {
        if (!std::is_trivially_copyable<T>::value)
            throw SerializerException("Cannot deserialize this type");
        auto begin_object = reinterpret_cast<unsigned char *>(std::addressof(object)) ;
        std::copy(std::begin(bytes), std::end(bytes), begin_object);
        return (object);
    }
};

#endif      /* !_SERIALIZER__HPP_! */