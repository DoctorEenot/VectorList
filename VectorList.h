#include <cstdlib>

#define DEFAULT_PLUS_SIZE 100

template <typename T>
class Cell {
	private:
		Cell<T>* next;
		Cell<T>* previous;
		T* data;
	public:
		Cell(unsigned long size);
		Cell(unsigned long size,
			Cell<T>* next,
			Cell<T>* previous);

		void set_next(Cell<T>* next);
		void set_previous(Cell<T>* previous);

		Cell<T>* get_next();
		Cell<T>* get_previous();

		void set(unsigned long index, T data) {
			this->data[index] = data;
		}

		T get(unsigned long index) {
			return this->data[index];
		}
};


template <typename T>
class VectorList {
	private:
		Cell<T>* head;
		Cell<T>* tail;
		unsigned long plus_size;
		unsigned long size;
		
		Cell<T>* get_cell(unsigned long index);
		
	public:
		VectorList();
		VectorList(unsigned long);
		unsigned long get_plus_size();
		unsigned long get_size();
		unsigned long amount_of_elements();

		void set(unsigned long index, T element);
		T get(unsigned long index);

		void enlarge();


};


template <typename T>
Cell<T>::Cell(unsigned long size) {
	this->next = nullptr;
	this->previous = nullptr;
	this->data = new T[size];
}

template <typename T>
Cell<T>::Cell(unsigned long size,
	Cell<T>* next,
	Cell<T>* previous) {

	this->next = next;
	this->previous = previous;
	this->data = new T[size];
}

template <typename T>
void Cell<T>::set_next(Cell<T>* next) {
	this->next = next;
}
template <typename T>
void Cell<T>::set_previous(Cell<T>* previous) {
	this->previous = previous;
}

template <typename T>
Cell<T>* Cell<T>::get_next() {
	return this->next;
}
template <typename T>
Cell<T>* Cell<T>::get_previous() {
	return this->previous;
}


template <typename T>
VectorList<T>::VectorList() {
	Cell<T>* new_cell = new Cell<T>(plus_size);

	this->head = new_cell;
	this->tail = new_cell;
	this->plus_size = DEFAULT_PLUS_SIZE;
	this->size = 1;
}

template <typename T>
VectorList<T>::VectorList(unsigned long plus_size) {
	Cell<T>* new_cell = new Cell<T>(plus_size);

	this->head = new_cell;
	this->tail = new_cell;
	this->plus_size = plus_size;
	this->size = 1;
}

template <typename T>
unsigned long VectorList<T>::get_plus_size() {
	return this->plus_size;
}

template <typename T>
unsigned long VectorList<T>::get_size() {
	return this->size;
}

template <typename T>
unsigned long VectorList<T>::amount_of_elements() {
	return this->get_plus_size() * this->get_size();
}

template <typename T>
Cell<T>* VectorList<T>::get_cell(unsigned long index) {
	Cell<T>* to_return;


	if (index <= (this->get_size() >> 1)) {
		to_return = this->head;
		for (unsigned long i = 0; i < index; i++) {
			to_return = to_return->get_next();
		}
	}
	else {
		to_return = this->tail;
		for (unsigned long i = this->get_size() - 1; i > index; i--) {
			to_return = to_return->get_previous();
		}
	}

	return to_return;
}

template <typename T>
void VectorList<T>::set(unsigned long index, T element) {
	std::lldiv_t div_result = std::lldiv(index, this->plus_size);

	Cell<T>* cell = this->get_cell(div_result.quot);

	cell->set(div_result.rem, element);

}

template <typename T>
T VectorList<T>::get(unsigned long index) {
	std::lldiv_t div_result = std::lldiv(index, this->plus_size);

	Cell<T>* cell = this->get_cell(div_result.quot);

	return cell->get(div_result.rem);
}

template <typename T>
void VectorList<T>::enlarge() {
	Cell<T>* new_cell = new Cell<T>(this->get_plus_size());

	new_cell->set_previous(this->tail);
	this->tail->set_next(new_cell);

	this->tail = new_cell;

	this->size += 1;
}
