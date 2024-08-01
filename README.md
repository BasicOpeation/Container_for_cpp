# README

## 文件说明

本项目一共包含3个文件

- `comper.h` 提供类型对比的模板
- `removeconst.h`使用trait技术，将类型的const修饰符去掉
- `Container.h` 项目主体，`Container`类定义所在地，项目的主要功能区

## 使用说明

### 环境

下载文件之后将其添加进入你的项目，大致如下

```CMD
│  comper.h
│  Container.h
│  removeconst.h
│  TEST2.cpp
│  TEST2.vcxproj
│  TEST2.vcxproj.filters
│  TEST2.vcxproj.user
│
└─x64
    └─Debug
```



### 使用

```CPP
#include <iostream>
#include <string>


//使用的时候，只用包含Container.h文件即可，剩下的文件会自动包含
#include "Container.h"

using namespace std;


int main()
{
    //你可以将自己喜欢的对象放入container,确保它有一个可靠的拷贝构造函数
	Container contint = 16;
	Container confloat = 3.14f;
	Container constring = string("hello template");
	Container concstring = "hello c string template";
	//存的时候很方便，但是取用的时候就比较麻烦了，要传一个引用进去

	//一共提供了两个函数get 和getname
	int getint;
	contint.get(getint);

	cout << getint << endl;

	//要看看里面存的类型？
	cout << concstring.getname().name() << endl;
	//其余同理
	return 0;
}
```

