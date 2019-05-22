
//����ģ��
template<typename T>
void Swap(T& left, T& right) {
	T temp = left;
	left = right;
	right = temp;
}

//ģ��ʵ����
//��ʽʵ����
//��������
template<class T> 
T Add(const T& left, const T& right) {
	return left + right;
}

int main() {
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add(a1, a2);
	Add(d1, d2);
	/*     ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�     Add(a1, d1);    */
	// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����    

	Add(a1, (int)d1);
	return 0;
}

//��ʽʵ������������֮���<����>
template<class T> 
T Add(const T& left, const T& right) {
	return left + right;
}

int main() {
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add<int>(a1, d1); //��ʽʵ����
	//������Ͳ�ƥ�䣬�������᳢�Խ�����ʽ����ת��������޷�ת���ɹ����������ᱨ��
	return 0;
}



//��ģ��
//C���Է�ʽ
typedef int DataType;
class  SeqList{
public:
	//����֮ǰ�ķ�ʽ
	SeqList(size_t capacity = 10) {
		_array = new DataType[capacity];
		_capacity = capacity;
		_size = 0;
	}
	
	//��ʼ���б�
	SeqList(size_t capacity = 10) 
		:_array(new DataType[capacity])
		, _capacity(capacity)
		,_size (0)
	{//����ֵ
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


//��ģ��
template<class T>
class  SeqList{
public:
	//����֮ǰ�ķ�ʽ
	SeqList(size_t capacity = 10) {
		_array = new DataType[capacity];
		_capacity = capacity;
		_size = 0;
	}

	//��ʼ���б�
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

	void PushBack(const T& data�� //����ĺ���


private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

//ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б� 
//���к�������  SeqList<T>::PushBack   �ܹؼ�
template<class T>
void SeqList<T>::PushBack(const T& data) {  //����ĺ���
	_array[_size++] = data;
}

