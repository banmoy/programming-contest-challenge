* scanf字符类型不会忽略white-space,如果想忽略之前的\n，可以在输入之前gets()，具体参考[由scanf说起之1：scanf函数和回车、空格及其返回值](http://www.cnblogs.com/czl-sy/archive/2013/04/07/3006109.html)

* 实例化accumulate时，如果没有显式声明模板类型T，那么编译器会根据第三个参数init的输入类型推断，如果想用double实例化accumulate，并且初始值为1，那么参数init必须为1.0，否则会实例化为int类型

* WA可能是数据类型范围不够大，TLE可能是cin/cout费时太多，对于不同os，sizeof(long)不同:windows为4，linux为8，但long long都是64，因此如果要定义64位的整数，用long long一定不会出错
