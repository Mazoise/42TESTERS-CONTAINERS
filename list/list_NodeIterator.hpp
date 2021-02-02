#ifndef LIST_NODEITERATOR_HPP
# define LIST_NODEITERATOR_HPP
# include "list_Node.hpp"
# include <iostream>

# ifdef DEBUG
#  define PRINT 1
# else
#  define PRINT 0
# endif

namespace ft
{
	template<class T>
		class list_Node;
	
	template<class T>
		class list_NodeIterator
		{
			public:
				typedef T					value_type;
				typedef	list_node<T>		node_type;
				typedef	node_type*			pointer;
				typedef value_type&			reference;
				typedef	::std::ptrdiff_t	difference_type;

				static const bool			input_iter;
				
				list_NodeIterator(): _ptr(NULL) {}
				list_NodeIterator(pointer ptr) : _ptr(ptr) {}
				list_NodeIterator(const list_NodeIterator& vec): _ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "NodeIter copy ctor\n";
				}
				~list_NodeIterator() {}

				list_NodeIterator& operator=(const list_NodeIterator& vec)
				{
					if (PRINT)
						std::cout << "NodeIter operator =\n";
					this->_ptr = vec.getPointer();
					return *this;
				}

				pointer			getPointer() const
				{
					if (PRINT)
						std::cout << "NodeIter getPointer()\n";
					return this->_ptr;
				}

				reference		operator*()
				{
					if (PRINT)
						std::cout << "NodeIter operator *\n";
					return this->_ptr->getMember();
				}

				value_type*		operator->()
				{
					if (PRINT)
						std::cout << "NodeIter operator ->\n";
					return (&this->_ptr->getMember());
				}

				list_NodeIterator	operator++()
				{
					this->_ptr = this->_ptr->next;
					return *this;
				}

				list_NodeIterator	operator++(int)
				{
					list_NodeIterator	tmp(*this);

					this->_ptr = this->_ptr->next;
					return tmp;
				}

				list_NodeIterator	operator--()
				{
					this->_ptr = this->_ptr->prev;
					return *this;
				}

				list_NodeIterator	operator--(int)
				{
					list_NodeIterator	tmp(*this);

					this->_ptr = this->_ptr->prev;
					return tmp;
				}

				bool 			operator==(const list_NodeIterator& right) const 
				{
					return (this->_ptr == right.getPointer());
				}

				bool 			operator!=(const list_NodeIterator& right) const 
				{
					bool ret = (*this == right);

					return (!ret);
				}

			private:
				pointer			_ptr;
		};

	template<class T>
		bool operator!=(const list_NodeIterator<T>& lhs, const list_NodeIterator<T>& rhs)
		{
			if (PRINT)
				std::cout << "Operator != (NodeIter, NodeIter)\n";
			return !(lhs == rhs);
		}
	

	template < class T>
		const bool list_NodeIterator<T>::input_iter = true;
}

#endif
