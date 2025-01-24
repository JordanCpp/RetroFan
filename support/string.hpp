/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef libcpp_string_hpp
#define libcpp_string_hpp

#include <LDL/Support.hpp>

#include <stddef.h>

namespace std
{
	template<class T>
	class base_string
	{
	public:
		~base_string()
		{
			if (_content != NULL)
			{
				delete[] _content;
			}
		}

		base_string() :
			_capacity(0),
			_position(0),
			_content(NULL)
		{
		}

		base_string(const base_string<T>& src) :
			_capacity(0),
			_position(0),
			_content(NULL)
		{
			append(src);
		}

		base_string(const T* value) :
			_capacity(0),
			_position(0),
			_content(NULL)
		{
			append(value);
		}

		void append(const T src)
		{
			push_back(src);
		}

		void append(const base_string<T>& src)
		{
			for (size_t i = 0; i < src.size(); i++)
			{
				push_back(src[i]);
			}
		}

		void append(base_string<T>& src)
		{
			for (size_t i = 0; i < src.size(); i++)
			{
				push_back(src[i]);
			}
		}

		void append(const T* src)
		{
			size_t i = 0;

			while (src[i] != '\0')
			{
				push_back(src[i]);
				i++;
			}
		}

		const T* c_str() const
		{
			return _content;
		}

		void reserve(size_t count)
		{
			size_t total = count + 1;

			if (total > _capacity)
			{
				T* p = new T[total];

				for (size_t i = 0; i < _position; i++)
				{
					p[i] = _content[i];
				}

				if (_content != NULL)
				{
					delete[] _content;
				}

				_content = p;
				_capacity = total;
			}
		}

		void resize(size_t count)
		{
			if (_capacity < count)
			{
				reserve(count);
			}

			_position = count;
			_content[_position] = '\0';
		}

		void push_back(const T& element)
		{
			if (_capacity == 0)
			{
				reserve(2);
			}
			else if (_position + 1 >= _capacity)
			{
				reserve(_capacity * 2);
			}

			_content[_position] = element;
			_position++;
			_content[_position] = '\0';
		}

		void clear()
		{
			_position = 0;
		}

		bool empty() const
		{
			return false;
		}

		size_t size() const
		{
			return _position;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		const T& operator[] (size_t index) const
		{
			return _content[index];
		}

		T& operator[] (size_t index)
		{
			return _content[index];
		}

		base_string<T>& operator+=(const T* src)
		{
			append(src);

			return *this;
		}

		base_string<T>& operator+=(const T src)
		{
			append(src);

			return *this;
		}

		base_string<T>& operator+=(const base_string<T>& src)
		{
			append(src);

			return *this;
		}

		base_string<T>& operator+(const T src)
		{
			append(src);

			return *this;
		}

		base_string<T>& operator=(const base_string<T>& other)
		{
			clear();
			append(other);

			return *this;
		}

		base_string<T>& operator=(const T* other)
		{
			clear();
			append(other);

			return *this;
		}

		base_string<T>& operator=(T other)
		{
			clear();
			append(other);

			return *this;
		}
	private:
		size_t _capacity;
		size_t _position;
		T* _content;
	};

	template<class T>
	base_string<T> operator+(const T* left, const base_string<T>& rigth)
	{
		base_string<T> result(left);

		result.append(rigth);

		return result;
	}

	template<class T>
	base_string<T> operator+(const base_string<T>& left, const T* rigth)
	{
		base_string<T> result(left);

		result.append(rigth);

		return result;
	}

	template<class T>
	inline base_string<T> operator+(const base_string<T>& left, const base_string<T>& rigth)
	{
		base_string<T> result(left);

		result.append(rigth);

		return result;
	}

	template<class T>
	base_string<T> operator+(const T& left, const base_string<T>& rigth)
	{
		base_string<T> result(left);

		result.append(rigth);

		return result;
	}

	template<class T>
	base_string<T> operator+(const base_string<T>& left, const T& rigth)
	{
		base_string<T> result(left);

		result.append(rigth);

		return result;
	}

	typedef base_string<char> string;
}

#endif