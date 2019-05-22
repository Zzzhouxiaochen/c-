
//函数模板
template<typename T>
void Swap(T& left, T& right) {
	T temp = left;
	left = right;
	right = temp;
}

//模板实例化
//隐式实例化
//类型推演
template<class T> 
T Add(const T& left, const T& right) {
	return left + right;
}

int main() {
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add(a1, a2);
	Add(d1, d2);
	/*     注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅     Add(a1, d1);    */
	// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化    

	Add(a1, (int)d1);
	return 0;
}

//显式实例化：函数名之后加<类型>
template<class T> 
T Add(const T& left, const T& right) {
	return left + right;
}

int main() {
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add<int>(a1, d1); //显式实例化
	//如果类型不匹配，编译器会尝试进行隐式类型转换，如果无法转换成功编译器将会报错
	return 0;
}



//类模板
//C语言方式
typedef int DataType;
class  SeqList{
public:
	//我们之前的方式
	SeqList(size_t capacity = 10) {
		_array = new DataType[capacity];
		_capacity = capacity;
		_size = 0;
	}
	
	//初始化列表
	SeqList(size_t capacity = 10) 
		:_array(new DataType[capacity])
		, _capacity(capacity)
		,_size (0)
	{//赋初值
		_array = new DataType[capacity];
		_capacity = capacity;
		_size = 0;
	}

	~SeqList() {
		if (_array) {
			delete[] _array;
			_array= nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:    
	DataType* _array;    
	size_t _size;    
	size_t _capacity;
};


//类模板
template<class T>
class  SeqList{
public:
	//我们之前的方式
	SeqList(size_t capacity = 10) {
		_array = new DataType[capacity];
		_capacity = capacity;
		_size = 0;
	}

	//初始化列表
	SeqList(size_t capacity = 10)
		:_array(new DataType[capacity])
		, _capacity(capacity)
		, _size(0)
	{}

	~SeqList() {
		if (_array) {
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	void PushBack(const T& data） //加入的函数


private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

//注意：类模板中函数放在类外进行定义时，需要加模板参数列表 
//还有函数名字  SeqList<T>::PushBack   很关键
template<class T>
void SeqList<T>::PushBack(const T& data) {  //加入的函数
	_array[_size++] = data;
}

