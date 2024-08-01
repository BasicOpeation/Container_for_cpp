#pragma once
#ifndef TYPE_COMPARSION_H
#define TYPE_COMPARSION_H

template <typename T, typename U>
struct Type_Comparsion
{
	static constexpr bool same = false;
};

template <typename T>
struct Type_Comparsion<T, T>
{
	static constexpr bool same = true;
};


//这是模板变量哦，C++17引入的，高级吧，
//可以非常方便的调用模板元编程的匹配结果
template<typename T, typename U>
bool typesame = Type_Comparsion<T, U>::same;



//下面我们来做一些更高级的自动化判断
template <class T1, class T2>
bool typesamefun(T1 t1, T2 t2)
{
	return typesame<T1, T2>;
}

#endif