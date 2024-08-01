#pragma once


#ifndef Container_basicoperation_h
#define Container_basicoperation_h

#include "comper.h"
#include "removeconst.h"
#include <typeinfo>
using namespace std;

struct Wrapper_base
{
	virtual ~Wrapper_base() {}
	const std::type_info& itemname;
	Wrapper_base(const std::type_info& typeInfo) : itemname(typeInfo) {}
};

template <typename T>
struct Wrapper :Wrapper_base
{
private:
	T data;
public:
	Wrapper(const T& val) :data(val), Wrapper_base(typeid(val)) {}
	bool get(T& ref) {
		if (typesamefun(data, ref))
		{
			ref = data;
			return true;
		}
		return false;
	}
};


struct Container
{
private:
	Wrapper_base* wrapperbaseptr;
public:
	Container() :wrapperbaseptr(nullptr) {}
	template <typename T>
	Container(const T& val) {
		using tagtype = typename const_trait<T>::type;
		tagtype removed_val = (tagtype)(val);
		wrapperbaseptr = new Wrapper<tagtype>(removed_val);
	}
	~Container() { delete wrapperbaseptr; }
	template <typename T>
	bool get(T& val)
	{
		Wrapper<T>* wbp = (Wrapper<T>*)(wrapperbaseptr);
		if (wbp != nullptr) { if (wbp->get(val)) { return true; }return false; }
		return false;
	}
	//重载get
	const std::type_info& getname() { return wrapperbaseptr->itemname; }
};

#endif // !Container_basicoperation_h
