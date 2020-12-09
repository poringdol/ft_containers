#pragma once

#include <iterator>
#include <bits/cpp_type_traits.h>
#include <limits>

#if __cplusplus <= 199711L
	#define NOEXCEPT throw()
#else
	#define NOEXCEPT noexcept
#endif


namespace ft {
/********************************** List container ***************************************/
	template<typename T, typename Alloc = std::allocator<T> >
	class list {

	private:
	struct list_node;

// Supporting structure list_node ---------------------------------------------

		struct list_node {
			T data;
			list_node *prev;
			list_node *next;

			list_node (const T& new_data = T(),
					  list_node *new_prev = NULL,
					  list_node *new_next = NULL) NOEXCEPT
					: data(new_data), prev(new_prev), next(new_next) {}
		};
// ============================================================================
	
	public:

	struct iterator;
	struct const_iterator;
	struct reverse_iterator;
	struct const_reverse_iterator;
	
// Iterator class -------------------------------------------------------------

		struct iterator : std::bidirectional_iterator_tag {
			list_node* ptr;

			iterator() NOEXCEPT : ptr(NULL) {}
			iterator(list_node* new_ptr) NOEXCEPT : ptr(new_ptr) {}
			iterator(const iterator& new_it) NOEXCEPT : ptr(new_it.ptr) {}
			iterator(const const_iterator& new_it) NOEXCEPT : ptr(new_it.ptr) {}
			iterator(const reverse_iterator& new_it) NOEXCEPT : ptr(new_it.ptr) {}
			iterator(const const_reverse_iterator& new_it) NOEXCEPT : ptr(new_it.ptr) {} 

			template<typename Iterator>
			iterator
			operator= (const Iterator& x) { return iterator(x.ptr); }

			T&
			operator*() const NOEXCEPT {
				return this->ptr->data;
			}
			
			T*
			operator->() const NOEXCEPT {
				return &this->ptr->data;
			}

			iterator
			operator++ () NOEXCEPT {
				this->ptr = this->ptr->next;
				return *this;
			}

			iterator
			operator++ (int) NOEXCEPT {
				iterator tmp = *this;
				this->ptr = this->ptr->next;
				return tmp;
			}
			
			iterator
			operator-- () NOEXCEPT {
				this->ptr = this->ptr->prev;
				return *this;
			}

			iterator
			operator-- (int) NOEXCEPT {
				iterator tmp = *this;
				this->ptr = this->ptr->prev;
				return tmp;
			}

			bool
			operator== (const iterator& x) NOEXCEPT {
				return this->ptr == x.ptr;
			}

			bool
			operator!= (const iterator& x) NOEXCEPT {
				return this->ptr != x.ptr;
			}
		};
// ============================================================================

// Const iterator class -------------------------------------------------------

	public:
		struct const_iterator : std::bidirectional_iterator_tag {
			// typedef const_iterator iterator;

			const list_node* ptr;

			const_iterator() NOEXCEPT : ptr(NULL) {}
			const_iterator(const list_node* new_ptr) NOEXCEPT : ptr(new_ptr) {}
			const_iterator(const iterator& new_it) NOEXCEPT : ptr(new_it.ptr) {}
			const_iterator(const const_iterator& new_it) NOEXCEPT : ptr(new_it.ptr) {}
			const_iterator(const reverse_iterator& new_it) NOEXCEPT : ptr(new_it.ptr) {}
			const_iterator(const const_reverse_iterator& new_it) NOEXCEPT : ptr(new_it.ptr) {} 

			template<typename Iterator>
			const_iterator
			operator= (Iterator& x) { return const_iterator(x.ptr); }

			const T
			operator*() const NOEXCEPT { return this->ptr->data; }
			
			const T*
			operator->() const NOEXCEPT { return &this->ptr->data; }

			const_iterator
			operator++ () NOEXCEPT {
				this->ptr = this->ptr->next;
				return *this;
			}

			const_iterator
			operator++ (int) NOEXCEPT {
				const_iterator tmp = *this;
				this->ptr = this->ptr->next;
				return tmp;
			}
			
			const_iterator
			operator-- () NOEXCEPT {
				this->ptr = this->ptr->prev;
				return *this;
			}

			const_iterator
			operator-- (int) NOEXCEPT {
				const_iterator tmp = *this;
				this->ptr = this->ptr->prev;
				return tmp;
			}

			bool
			operator== (const const_iterator& x) NOEXCEPT { return this->ptr == x.ptr; }

			bool
			operator!= (const const_iterator& x) NOEXCEPT { return this->ptr != x.ptr; }
		};
// ============================================================================

// Reverse iterator class -----------------------------------------------------

	public:
		struct reverse_iterator : public ft::list<T, Alloc>::iterator {
			
			typedef ft::list<T, Alloc>::iterator	base_iterator;

			reverse_iterator() NOEXCEPT : base_iterator() {}
			reverse_iterator(list_node* new_ptr) NOEXCEPT : base_iterator(new_ptr) {}
			reverse_iterator(const iterator& new_it) NOEXCEPT : base_iterator(new_it.ptr) {}
			reverse_iterator(const const_iterator& new_it) NOEXCEPT : base_iterator(new_it.ptr) {}
			reverse_iterator(const reverse_iterator& new_it) NOEXCEPT : base_iterator(new_it.ptr) {}
			reverse_iterator(const const_reverse_iterator& new_it) NOEXCEPT : base_iterator(new_it.ptr) {}  

			template<typename Iterator>
			reverse_iterator
			operator= (Iterator& x) { return reverse_iterator(x.ptr); }

			reverse_iterator
			operator++ () NOEXCEPT {
				this->ptr = this->ptr->prev;
				return *this;
			}

			reverse_iterator
			operator++ (int) NOEXCEPT {
				reverse_iterator tmp = *this;
				this->ptr = this->ptr->prev;
				return tmp;
			}
			
			reverse_iterator
			operator-- () NOEXCEPT {
				this->ptr = this->ptr->next;
				return *this;
			}

			reverse_iterator
			operator-- (int) NOEXCEPT {
				reverse_iterator tmp = *this;
				this->ptr = this->ptr->next;
				return tmp;
			}
		};
// ============================================================================

// Const reverse iterator class -----------------------------------------------

	public:

		struct const_reverse_iterator : public ft::list<T, Alloc>::const_iterator {
			
			typedef ft::list<T, Alloc>::const_iterator	base_iterator;
			// typedef const_reverse_iterator		iterator;

			const_reverse_iterator() NOEXCEPT : base_iterator() {}
			const_reverse_iterator(list_node* new_ptr) NOEXCEPT : base_iterator(new_ptr) {}
			const_reverse_iterator(const iterator& new_it) NOEXCEPT : base_iterator(new_it.ptr) {}
			const_reverse_iterator(const const_iterator& new_it) NOEXCEPT : base_iterator(new_it.ptr) {}
			const_reverse_iterator(const reverse_iterator& new_it) NOEXCEPT : base_iterator(new_it.ptr) {}
			const_reverse_iterator(const const_reverse_iterator& new_it) NOEXCEPT : base_iterator(new_it.ptr) {} 

			template<typename Iterator>
			const_reverse_iterator
			operator= (Iterator& x) { return iterator(x.ptr); }

			const_reverse_iterator
			operator++ () NOEXCEPT {
				this->ptr = this->ptr->prev;
				return *this;
			}

			const_reverse_iterator
			operator++ (int) NOEXCEPT {
				iterator tmp = *this;
				this->ptr = this->ptr->prev;
				return tmp;
			}
			
			const_reverse_iterator
			operator-- () NOEXCEPT {
				this->ptr = this->ptr->next;
				return *this;
			}

			const_reverse_iterator
			operator-- (int) NOEXCEPT {
				iterator tmp = *this;
				this->ptr = this->ptr->next;
				return tmp;
			}
		};
// ============================================================================

	private:
		size_t list_size;
		list_node *head;
		Alloc alloc;


// Supporting functions -------------------------------------------------------

		void
		_list_init () NOEXCEPT {
			this->head = new list_node;
			this->head->prev = this->head->next = this->head;
		}

		/* 'insert' node placed to current position, 'current' moved to next position */
		void
		_node_insert (list_node* current, list_node* insert) {
			insert->next = current;
			insert->prev = current->prev;
			current->prev = current->prev->next = insert;
		}

		template<typename InputIterator>
		void
		_insert (iterator position, InputIterator first, InputIterator last, std::__false_type) {
			for (; first != last; ++first) {
				this->insert(position, *first);
			}
		}

		template<typename T1>
		void
		_insert (iterator position, size_t n, T1 val, std::__true_type) {
			while (n--) {
				iterator temp = position;
				this->insert(temp, val);
			}
		}

		template<typename InputIterator>
		void
		_assign (InputIterator first, InputIterator last, std::__false_type) {
			this->clear();
			while (first != last) {
				this->push_back(*first);
				++first;
			}
		}

		template<typename T1>
		void
		_assign (size_t n, T1 val, std::__true_type) {
			this->clear();
			while (n--) {
				this->push_back(val);
			}
		}

		static bool
		_compare (T val1, T val2) { return val1 > val2; }

		static bool
		_compare_sort (T val1, T val2) { return val1 < val2; }

		void
		_cut (iterator it) {
			it.ptr->prev->next = it.ptr->next;
			it.ptr->next->prev = it.ptr->prev;
		}
// ============================================================================

	public:
// List constructors

		explicit
		list (const Alloc& x = Alloc())
					: list_size(0), alloc(x) { _list_init(); }

		explicit
		list (size_t n, const T& val = T(), const Alloc& x = Alloc()): list_size(0), alloc(x) {
			_list_init();
			iterator temp = head;
			while (n--) {
				this->push_back(val);
			}
		}
		

		template<typename InputIterator>
		list (InputIterator first, InputIterator last, const Alloc& x = Alloc()): list_size(0), alloc(x) {
			_list_init();
			this->assign(first, last);
		}

		list (const list& x): list_size(0) { 
			this->_list_init();
			*this = x;
		}

		list&
		operator= (const list& x) {
			this->clear();

			const_iterator temp = x.begin();
			while (temp != x.end()) {
				this->push_back(temp.ptr->data);
				temp++;
			}
			return *this;
		}

// List destructor

		~list() {
			clear();
			delete this->head;
		}
	
// List methods ---------------------------------------------------------------------

		size_t
		size () const NOEXCEPT		{ return list_size; }

		bool
		empty () const NOEXCEPT		{ return list_size == 0; }

		size_t
		max_size () const NOEXCEPT	{ return std::numeric_limits<size_t>::max() / sizeof(list_node); }

		iterator
		begin () NOEXCEPT			{ return iterator(this->head->next); }

		const_iterator
		begin () const NOEXCEPT		{ return const_iterator(this->head->next); }

		iterator
		end () NOEXCEPT				{ return iterator(this->head); }

		const_iterator
		end () const NOEXCEPT		{ return const_iterator(this->head); }

		reverse_iterator
		rbegin () NOEXCEPT			{ return reverse_iterator(this->head->prev); }

		const_reverse_iterator
		rbegin () const NOEXCEPT 	{ return const_reverse_iterator(this->head->prev); }

		reverse_iterator
		rend () NOEXCEPT				{ return reverse_iterator(this->head); }

		const_reverse_iterator
		rend () const NOEXCEPT		{ return const_reverse_iterator(this->head); }

		T&
		front () NOEXCEPT			{ return *(begin()); }

		const T&
		front () const NOEXCEPT		{ return *(this->begin()); }

		T&
		back () NOEXCEPT				{ return *(-- (this->end())); }

		const T&
		back () const NOEXCEPT		{ return *(-- (this->end())); }

		template<typename InputIterator>
		void
		assign (InputIterator first, InputIterator last) {
			typedef typename std::__is_integer<InputIterator>::__type _Integral;
			_assign(first, last, _Integral());
		}

		void
		assign (size_t n, const T& val) {
			_assign(n, val, std::__true_type());
		}

		void
		merge (list& x) { this->merge(x, _compare); }

		template <class Compare>
		void
		merge (list& x, Compare comp) {
			if (&x == this)
				return;
			iterator first1 = this->begin(), first2 = x.begin(),
					  last1 = this->end(),	  last2 = x.end();
			while (first1 != last1 && first2 != last2) {
				if (comp(*first1, *first2 )) {
					iterator temp = first2;
					temp++;
					_node_insert(first1.ptr, first2.ptr);
					first2 = temp;
					this->list_size++;
				}
				else
					++first1;
			}
			while (first2 != last2) {
				iterator temp = first2;
				temp++;
				_node_insert(first1.ptr, first2.ptr);
				first2 = temp;
				this->list_size++;;
			}
			x.head->next = x.head->prev = x.head;
			x.list_size = 0;
		}

		void
		splice (iterator position, list& x) {
			while (x.list_size--) {
				iterator first = x.begin();
				iterator temp = ++ (x.begin());
				_cut(first);
				_node_insert(position.ptr, first.ptr);
				first = temp;
				list_size++;
			}
			x.head->next = x.head->prev = x.head;
			x.list_size = 0;
		}

		void
		splice (iterator position, list& x, iterator i) {
			_cut(i);
			list_size++;
			x.list_size--;
			_node_insert(position.ptr, i.ptr);
		}

		void
		splice (iterator position, list& x, iterator first, iterator last) {
			while (first != last) {
				iterator temp = first;
				++temp;
				_cut(first);
				_node_insert(position.ptr, first.ptr);
				first = temp;
				list_size++;
				x.list_size--;
			}
		}

		iterator
		insert (iterator position, const T& data) {
			if (position == this->begin()) {
				push_front(data);
				return this->begin();
			}

			list_node *temp = new list_node(data);
			_node_insert(position.ptr, temp);
			list_size++;
			return iterator(temp);
		}

		void
		insert (iterator position, size_t n, const T& val) {
			_insert(position, n, val, std::__true_type());
		}
		
		template<class InputIterator>
		void
		insert (iterator position, InputIterator first, InputIterator last) {
			typedef typename std::__is_integer<InputIterator>::__type _Integral;
			_insert(position, first, last, _Integral());
		}

		void
		push_back (const T& data) {
			if (!list_size) {
				list_node *temp = new list_node(data);
				this->head->prev = this->head->next = temp;
				temp->prev = temp->next = this->head;
			} else {
				list_node *temp = new list_node(data, this->head->prev, this->head);
				this->head->prev->next = temp;
				this->head->prev = temp;
			}
			list_size++;
		}

		void
		push_front (const T& data) {
			list_node *temp = new list_node(data, this->head, this->head->next);
			this->head->next = this->head->next->prev = temp;
			list_size++;
		}

		void
		pop_front () NOEXCEPT { this->erase(this->begin()); }

		void
		pop_back () NOEXCEPT { this->erase(iterator(this->head->prev)); }

		void
		resize (size_t new_size, T val = T()) {
			if (new_size < this->list_size) {
				iterator it = this->begin();
				while (new_size--)
					++it;
				erase(it, this->end());
			} else {
				insert(this->end(), new_size - this->list_size, val);
			}
		}

		void
		reverse () {
			iterator first = this->head;
			size_t size = this->list_size;
			while (size--) {
				iterator last = -- (this->end());
				_cut(last);
				
				first.ptr->next->prev = last.ptr;
				last.ptr->next = first.ptr->next;
				first.ptr->next = last.ptr;
				last.ptr->prev = first.ptr;
				++first;
			}
		}

		void
		clear () NOEXCEPT {
			list_node *temp;
			while (this->list_size) {
				temp = this->head->next;
				delete this->head;
				this->head = temp;
				this->list_size--;
			}
			this->head->prev = this->head->next = this->head;
		}

		iterator
		erase (iterator position) {
			if (position != this->end()) {
				_cut(position);
				iterator temp = position++;
				if (temp == this->begin())
					this->head->next = temp.ptr;
				delete temp.ptr;
				list_size -= list_size ? 1 : 0;
			}
			return position;
		}

		iterator
		erase (iterator first, iterator last) {
			while (first != last) {
				first = erase(first);
			}
			return last;
		}

		void
		remove (const T& val) {
			iterator it = this->begin();
			while (it != this->end()) {
				iterator temp = it;
				++it;
				if (*temp == val) {
					this->erase(temp);
				}
			}
		}

		template <class Compare>
		void
		remove_if (Compare comp) {
			iterator it = this->begin();
			while (it != this->end()) {
				iterator temp = it;
				++it;
				if (comp(*temp)) {
					this->erase(temp);
				}
			}
		}

		void
		sort() {
			this->sort(_compare_sort);
		}

		template <class Compare>
		void
		sort (Compare comp) {
			for (iterator it = begin(); it != end(); ) {
				iterator it_min = it;
				for (iterator itt = it; itt != end(); ++itt) {
					if (comp(itt.ptr->data, it_min.ptr->data)) {
						it_min = itt;
					}
				}
				if (it_min != it) {
					_cut(it_min);
					_node_insert(it.ptr, it_min.ptr);
				} else {
					++it;
				}
			}
		}

		void
		swap (list& x) {
			list_node* temp = this->head;
			this->head = x.head;
			x.head = temp;

			size_t size = this->list_size;
			list_size = x.list_size;
			x.list_size = size;
		}

		void
		unique() {
			iterator first = this->begin();
			++first;
			while (first != this->end()) {
				if (first.ptr->data == first.ptr->prev->data) {
					iterator temp = first;
					++temp;
					_cut(first);
					delete first.ptr;
					list_size--;
					first = temp;
				} else {
					++first;
				}
			}
		}

		template <class BinaryPredicate>
		void
		unique (BinaryPredicate binary_pred) {
						iterator first = this->begin();
			++first;
			while (first != this->end()) {
				if (binary_pred(first.ptr->data, first.ptr->prev->data)) {
					iterator temp = first;
					++temp;
					_cut(first);
					delete first.ptr;
					list_size--;
					first = temp;
				} else {
					++first;
				}
			}
		}

// ============================================================================

// Friend functions -----------------------------------------------------------
	template<typename _T, typename _Alloc>
	friend bool
	operator== (const list<_T,_Alloc>& lhs, const list<_T,_Alloc>& rhs);

	template<typename _T, typename _Alloc>
	friend bool
	operator!= (const list<_T,_Alloc>& lhs, const list<_T,_Alloc>& rhs);

	template<typename _T, typename _Alloc>
	friend  bool
	operator<  (const list<_T,_Alloc>& lhs, const list<_T,_Alloc>& rhs);

	template<typename _T, typename _Alloc>
	friend bool
	operator<= (const list<_T,_Alloc>& lhs, const list<_T,_Alloc>& rhs);

	template<typename _T, typename _Alloc>
	friend bool
	operator>  (const list<_T,_Alloc>& lhs, const list<_T,_Alloc>& rhs);

	template<typename _T, typename _Alloc>
	friend bool
	operator>= (const list<_T,_Alloc>& lhs, const list<_T,_Alloc>& rhs);

	template<typename _T, typename _Alloc>
	friend void
	swap (list<_T,_Alloc>& x, list<_T,_Alloc>& y);
// ============================================================================
	};
/**************************************************************************************/

// Friend functions realization -----------------------------------------------

	template <class T, class Alloc>
	bool
	operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		if (lhs.list_size != rhs.list_size)
			return false;
		typename ft::list<T>::iterator first1 = lhs.begin();
		typename ft::list<T>::iterator first2 = rhs.begin();
		while (first1 != lhs.end()) {
			if (lhs.head->data != rhs.head->data)
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class T, class Alloc>
	bool
	operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool
	operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {

		typename ft::list<T>::iterator first1 = lhs.begin();
		typename ft::list<T>::iterator first2 = rhs.begin();
		while (first1 != lhs.end() && first2 != rhs.end()) {
			if (lhs.head->data >= rhs.head->data)
				return false;
			++first1;
			++first2;
		}
		if (lhs.list_size > rhs.list_size)
			return false;
		return true;
	}

	template <class T, class Alloc>
	bool
	operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool
	operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return rhs < lhs;
	}

	template <class T, class Alloc>
	bool
	operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void
	swap (list<T,Alloc>& x, list<T,Alloc>& y) {
		x.swap(y);
	}
}
