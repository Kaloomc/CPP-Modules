/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 23:39:43 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/19 14:15:25 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : elements(NULL) , _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	elements = new T[n]();
}

template <typename T>
Array<T>::~Array() {
    delete[] this->elements;
}


template <typename T>
Array<T>::Array(const Array& cpy) : elements(NULL), _size(cpy._size)
{
    if (cpy.elements == NULL)
        return;
    
    elements = new T[_size]();
    for (unsigned int i = 0; i < _size; i++)
    {
        elements[i] = cpy.elements[i];
    }
}
template <typename T>
Array<T>& Array<T>::operator=(Array<T> const & rhs)
{
	if(this != &rhs)
	{
		delete[] this->elements;
		this->_size = rhs._size;
		if (rhs.elements == NULL)
		{
			this->elements = NULL;
        	return *this;
		}
		this->elements = new T[_size]();
		for (unsigned int i = 0; i < _size; i++)
		{
			this->elements[i] = rhs.elements[i];
		}
	}
	return *this;
}

template <typename T>
T & Array<T>::operator[](unsigned int index)
{
	if(index >= this->_size)
		throw Array<T>::OutOfBounds();
	return this->elements[index];
}

template <typename T>
T const & Array<T>::operator[](unsigned int index) const
{
	if(index >= this->_size)
		throw Array<T>::OutOfBounds();
	return this->elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}