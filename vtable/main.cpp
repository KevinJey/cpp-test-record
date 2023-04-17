#include <iostream>

using namespace std;
namespace cord1{
	class A{
		public:
			int a;
			virtual void foo(){ cout << 1 << endl;}	
	};	
	void test(){
		A *a_instance = new A();
		cout << &a_instance << endl; // 	0x7fffd4b006b0
		cout << &a_instance->a << endl; //  0x7fffcc6a4eb8
	}
};
namespace cord2{
	class A{
		public:
			int a;
			// virtual void foo(){ cout << 1 << endl;}	
	};
	class B{
	public:
		int a;
		static int c;
		static int d;
		static int e;
	};
	// static won't be calced into sizeof(class)
	void test(){
		// 4 4
		cout << sizeof(A) << endl;
		cout << sizeof(B) << endl;
	}
};
namespace cord3{
	class A{
		public:
			// int a;
			virtual void foo(){ cout << 1 << endl;}	
	};
	class B:public A{
			virtual void foo() override{ cout << 1 << endl;}	
			virtual void Bb(){ ;}
	};
	class C:public B {
			virtual void foo() final{ cout << 1 << endl;}	

	};
	// static won't be calced into sizeof(class)
	void test(){
		// 8 8 8
		// only one vtable
		cout << sizeof(A) << endl;
		cout << sizeof(B) << endl;
		cout << sizeof(C) << endl;
	}
};

int main(){
	using namespace cord3;
	test();
	return 0;
}