// Проект Task 
// SparseArr.h 
#ifndef SPARSE_ARR_H 
#define SPARSE_ARR_H 
#include <list>  // ==========!!!!!===

template <class DataT> class SA_item {
	public:
		SA_item() : index(-1), info(DataT()) {}
		SA_item(long i, DataT d) : index(i), info(d) {}
		long index;
		DataT info;
};

template <class T> class SparseArr {
	public:
		SparseArr(long len) : length(len) {}
		T& operator [ ](long ind);
		void Show(const char*);
	private:
		std::list<SA_item<T> > arr;
		long length;
};

template <class T>
	void SparseArr<T>::Show(const char* title) {
		cout << "===== " << title << " =====\n";
		list<SA_item<T> >::iterator i = arr.begin();
		list<SA_item<T> >::iterator n = arr.end();
		for (i; i != n; ++i)
			cout << i->index << "\t" << i->info << endl;
	}

template <class T>
T& SparseArr<T>::operator[ ](long ind) {
		if ((ind < 0) && (ind > length - 1)) {
			cout << "Error of index: " << ind << endl;
			SA_item<T> temp;
			return temp.info;
		}
		list<SA_item<T> >::iterator i = arr.begin();
		list<SA_item<T> >::iterator n = arr.end();
		for (i; i != n; ++i) if (ind == i->index)
			return i->info; // элемент найден 
		// Элемент не найден, создаем новый элемент 
		arr.push_back(SA_item<T>(ind, T()));
		//arr.push_back(SA_item<T>(ind Т));
		i = arr.end();
		return (--i)->info;
}
#endif /* SPARSE_ARR_H */
