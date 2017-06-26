//Ali Bayati


#ifndef MAIN_SAVITCH_BAG1_H
#define MAIN_SAVITCH_BAG1_H
#include <cstdlib>  // Provides size_t
#include <iostream>
#include <cassert>

using namespace std;

namespace main_savitch_3
{
	class bag
	{
	public:
		// TYPEDEFS and MEMBER CONSTANTS
		typedef int value_type;
		typedef std::size_t size_type;
		static const size_type CAPACITY = 30;

		// CONSTRUCTOR
		bag() { used = 0; }

		// MODIFICATION MEMBER FUNCTIONS
		size_type erase(const value_type& target);
		bool erase_one(const value_type& target);
		void insert(const value_type& entry);
		void operator +=(const bag& addend);

		// CONSTANT MEMBER FUNCTIONS
		size_type size() const { return used; }
		size_type count(const value_type& target) const;

		// my added function for testing
		void test() const;
	private:
		value_type data[CAPACITY];  // The array to store items
		size_type used;             // How much of array is used


	};

	//   size_type count(const value_type& target) const
	//     Postcondition: The return value is number of times target is in the bag.
	//
	bag::size_type bag::count(const value_type& target) const
	{
		size_type counter = 0;

		for (size_type i = 0; i < used; i++)
			if (data[i] == target)
				counter++;

		return counter;
	}
	// NONMEMBER FUNCTIONS for the bag class:
	//   bag operator +(const bag& b1, const bag& b2)
	//     Precondition:  b1.size( ) + b2.size( ) <= bag::CAPACITY.
	//     Postcondition: The bag returned is the union of b1 and b2.
	//

	bag operator +(const bag& b1, const bag& b2)
	{
		// newBag = b1 + b2;
		assert(b1.size() + b2.size() <= bag::CAPACITY);

		bag newBag;

		newBag += b1;
		newBag += b2;

		return newBag;
	}

	//   void operator +=(const bag& addend)
	//     Precondition:  size( ) + addend.size( ) <= CAPACITY.
	//     Postcondition: Each item in addend has been added to this bag.
	//
	void bag::operator +=(const bag& addend)
	{
		// a += addend
		assert(this->size() + addend.size() <= CAPACITY);

		// loop and copy from addend to 'this' bag
		for (size_type i = 0; i < addend.size(); i++)
		{
			data[used] = addend.data[i];
			used++;
		}

	}

	//   size_type erase(const value_type& target);
	//     Postcondition: All copies of target have been removed from the bag.
	//     The return value is the number of copies removed (which could be zero).
	//
	bag::size_type bag::erase(const value_type& target)
	{
		size_type counter = 0;

		/*while (this->erase_one(target))
			counter++;*/
		for (size_type i = 0; i < used; i++)
		{
			if (data[i] == target)
			{
				//move last entry to this location
				data[i] = data[used - 1];
				used--;
				i--;
				counter++;
			}
		}

		return counter;
	}

	//   bool erase_one(const value_type& target)
	//     Postcondition: If target was in the bag, then one copy has been removed;
	//     otherwise the bag is unchanged. A true return value indicates that one
	//     copy was removed; false indicates that nothing was removed.
	//
	bool bag::erase_one(const value_type& target)
	{
		// find "first" target
		bool found = false;

		for (size_type i = 0; i < used && !found; i++)
		{
			if (data[i] == target)
			{
				data[i] = data[used-1];
				used--;
				found = true;
			}
		}
		return found;
	}

	//   void insert(const value_type& entry)
	//     Precondition:  size( ) < CAPACITY.
	//     Postcondition: A new copy of entry has been added to the bag.
	//
	void bag::insert(const value_type& entry)
	{
		assert(this->size() < CAPACITY);

		// insert 'entry' in next open spot
		data[used] = entry;
		used++;
	}


	// my test function
	void bag::test() const
	{
		// loop through and print array (for testing only)
		cout << "{ ";

		for (size_type i = 0; i < used; i++)
			cout << data[i] << ", ";

		cout << "} size = " << used << endl;
	}



} // end of namespace

#endif
