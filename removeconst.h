#pragma once
#ifndef MREMOVE_CONST_H
#define MREMOVE_CONST_H

template <typename T,size_t size=0>
struct const_trait
{
	using type = T;
};

template <typename T>
struct const_trait<const T>
{
	using type = T;
};

template <typename T>
struct const_trait<const T*>
{
	using type = T*;
};

//下面的一个模板用来解决数组传给常量引用不退化的问题
template <typename T,size_t size>
struct const_trait< T[size]>
{
	using type = T*;
};
#endif // !MREMOVE_CONST_H
