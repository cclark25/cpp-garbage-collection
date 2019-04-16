#ifndef _Condom__h
#define _Condom__h
#include <iostream>
#include <set>
#include <utility>
#include <type_traits>
using namespace std;

namespace Condoms {
	
//	struct _memNode {
//		const void *ptr;
//		unsigned int count;
//	
//		friend bool operator< (const _memNode &lhs, const _memNode &rhs){
//			return lhs.ptr < rhs.ptr;
//		}
//		friend bool operator> (const _memNode &lhs, const _memNode &rhs){
//			return lhs.ptr > rhs.ptr;
//		}
//		friend bool operator== (const _memNode &lhs, const _memNode &rhs){
//			return lhs.ptr == rhs.ptr;
//		}
//	
//	};
	static unsigned long int usedMemory = 0;
	
	template<class T>
	class Condom {
		static_assert(!(is_pointer<T>::value), "A Condom cannot be a reference to a pointer.");
		static_assert(!(is_array<T>::value), "A Condom cannot be a reference to an array.");
	private:
		
		//static set<_memNode> manager;
		pair<unsigned int, T>* nodePTR;
		T* ptr;
	
		void RemoveReference() {
			nodePTR->first--;
			if(nodePTR->first <= 0){
				delete nodePTR;
			}

			//_memNode dummy;
			//dummy.ptr = ptr;
			//auto target = nodePTR->first; //manager.find(dummy);
			//const _memNode &reff = *target;
			//const_cast<_memNode&>(reff).count--;
	
			//if(reff.count == 0){
			//	manager.erase(target);
			//	delete ptr;
			//}
		}
	
	protected:
		T& Data() const{
			return *ptr;
		}
		
	public:
	
		Condom(){
			//ptr = new T();
			//_memNode newNode;
			//newNode.ptr = ptr;
			//newNode.count = 1;
			//manager.insert(newNode);
			nodePTR = new pair<unsigned int, T>();
			nodePTR->first = 1;
			ptr = &(nodePTR->second);
		}
	
		Condom(T init){
			//ptr = new T(init);
			//_memNode newNode;
			//newNode.ptr = ptr;
			//newNode.count = 1;
			//manager.insert(newNode);
			nodePTR = new pair<unsigned int, T>(1, init);
			ptr = &(nodePTR->second);
		}
	
		Condom(const Condom &obj){
			//this->ptr = obj.ptr;
			//_memNode dummy;
			//dummy.ptr = ptr;
			//const_cast<_memNode&>(*manager.find(dummy)).count++;
			this->ptr = obj.ptr;
			this->nodePTR = obj.nodePTR;
			this->nodePTR->first++;
		}
	
		~Condom(){
			RemoveReference();
		}
	
		T& operator *(){
			return *ptr;
		}
	
	
		T* operator ->() const {
			return ptr;
		}
	
		auto& operator [](unsigned int index){
			return ptr->operator[](index);
		}
	
		Condom<T> operator + (const Condom<T> &obj) const {
			Condom<T> newObj;
			*(newObj.ptr) = *ptr + *(obj.ptr);
			return newObj;
		}
	
		Condom<T> operator + (const T value) const {
			Condom<T> newObj;
			*(newObj.ptr) = *ptr + value;
			return newObj;
		}
	
		Condom<T>& operator + () const {
			return *this;
		}
	
		Condom<T> operator - (const Condom<T> &obj) const {
			Condom<T> newObj;
			*(newObj.ptr) = *ptr - *(obj.ptr);
			return newObj;
		}
	
		Condom<T> operator - (const T value) const {
			Condom<T> newObj;
			*(newObj.ptr) = *ptr - value;
			return newObj;
		}
	
		Condom<T> operator - () const {
			Condom<T> newObj;
			*(newObj.ptr) = -(*ptr);
			return newObj;
		}
	
		Condom<T> operator * (const Condom<T> &obj) const {
			Condom<T> newObj;
			*(newObj.ptr) = *ptr * *(obj.ptr);
			return newObj;
		}
	
		Condom<T> operator * (const T value) const {
			Condom<T> newObj;
			*(newObj.ptr) = *ptr * value;
			return newObj;
		}
	
		Condom<T> operator / (const Condom<T> &obj) const {
			Condom<T> newObj;
			*(newObj.ptr) = *ptr / *(obj.ptr);
			return newObj;
		}
	
		Condom<T> operator / (const T value) const {
			Condom<T> newObj;
			*(newObj.ptr) = *ptr / value;
			return newObj;
		}
	
		Condom<T> operator % (const Condom<T> &obj) const {
			Condom<T> newObj;
			*(newObj.ptr) = *ptr % *(obj.ptr);
			return newObj;
		}
		Condom<T> operator % (const T value){
			Condom<T> newObj;
			*(newObj.ptr) = *ptr % value;
			return newObj;
		}
	
		Condom<T>& operator ++(){
			++(*ptr);
			return *this;
		}
	
		Condom<T> operator ++(int){
			Condom<T> oldObj;
			*(oldObj.ptr) = *(ptr);
			(*ptr)++;
			return oldObj;
		}
	
		Condom<T>& operator --(){
			--(*ptr);
			return *this;
		}
	
		Condom<T> operator --(int){
			Condom<T> oldObj;
			*(oldObj.ptr) = *(ptr);
			(*ptr)--;
			return oldObj;
		}
	
		Condom<T>& operator = (const Condom<T> &rhs){
			RemoveReference();
			ptr = rhs.ptr;
			nodePTR = rhs.nodePTR;
			nodePTR->first++;
			return *this;
		}
	
		Condom<T>& operator = (const T &rhs){
			*(ptr) = rhs;
		}
	
		bool operator== (const Condom<T> &other) const {
			return *ptr == *(other.ptr);
		}
	
		bool operator== (const T &other) const {
			return *ptr == other;
		}
	
		bool operator> (const Condom<T> &other) const {
			return *ptr > *(other.ptr);
		}
	
		bool operator> (const T &other) const {
			return *ptr > other;
		}
	
		bool operator< (const Condom<T> &other) const {
			return *ptr < *(other.ptr);
		}
	
		bool operator< (const T &other) const {
			return *ptr < other;
		}
	
		bool operator!= (const Condom<T> &other) const {
			return *ptr != *(other.ptr);
		}
	
		bool operator!= (const T &other) const {
			return *ptr != other;
		}
	
		bool operator>= (const Condom<T> &other) const {
			return *ptr >= *(other.ptr);
		}
	
		bool operator>= (const T &other) const {
			return *ptr >= other;
		}
	
		bool operator<= (const Condom<T> &other) const {
			return *ptr <= *(other.ptr);
		}
	
		bool operator<= (const T &other) const {
			return *ptr <= other;
		}
	
		bool operator!() const {
			return !(*ptr);
		}
	
		bool operator &&(const Condom<T> &other) const {
			return *ptr && *(other.ptr);
		}
	
		bool operator &&(const T &other) const {
			return *ptr && other;
		}
	
		bool operator ||(const Condom<T> &other) const {
			return *ptr || *(other.ptr);
		}
	
		bool operator ||(const T &other) const {
			return *ptr || other;
		}
	
		Condom<T> operator ~() const {
			Condom<T> newObject;
			*(newObject.ptr) = ~(*ptr);
			return newObject;
		}
	
		Condom<T> operator &(const Condom<T> &other) const {
			Condom<T> newObject;
			*(newObject.ptr) = (*ptr) & *(other.ptr);
			return newObject;
		}
	
		Condom<T> operator &(const T &other) const {
			Condom<T> newObject;
			*(newObject.ptr) = (*ptr) & other;
			return newObject;
		}
	
		Condom<T> operator |(const Condom<T> &other) const {
			Condom<T> newObject;
			*(newObject.ptr) = (*ptr) | *(other.ptr);
			return newObject;
		}
	
		Condom<T> operator |(const T &other) const {
			Condom<T> newObject;
			*(newObject.ptr) = (*ptr) | other;
			return newObject;
		}
	
		Condom<T> operator ^(const Condom<T> &other) const {
			Condom<T> newObject;
			*(newObject.ptr) = (*ptr) ^ *(other.ptr);
			return newObject;
		}
	
		Condom<T> operator ^(const T &other) const {
			Condom<T> newObject;
			*(newObject.ptr) = (*ptr) ^ other;
			return newObject;
		}
	
		Condom<T> operator <<(const Condom<T> &other) const {
			Condom<T> newObject;
			*(newObject.ptr) = (*ptr) << *(other.ptr);
			return newObject;
		}
	
		Condom<T> operator <<(const T &other) const {
			Condom<T> newObject;
			*(newObject.ptr) = (*ptr) << other;
			return newObject;
		}
	
		Condom<T> operator >>(const Condom<T> &other) const {
			Condom<T> newObject;
			*(newObject.ptr) = (*ptr) >> *(other.ptr);
			return newObject;
		}
	
		Condom<T> operator >>(const T &other) const {
			Condom<T> newObject;
			*(newObject.ptr) = (*ptr) >> other;
			return newObject;
		}
	
		Condom<T>& operator +=(const Condom<T> &other) {
			(*ptr) += *(other.ptr);
			return *this;
		}
	
		Condom<T>& operator +=(const T &other){
			(*ptr) += other;
			return *this;
		}
	
		Condom<T>& operator -=(const Condom<T> &other){
			(*ptr) -= *(other.ptr);
			return *this;
		}
	
		Condom<T>& operator -=(const T &other){
			(*ptr) -= other;
			return *this;
		}
	
		Condom<T>& operator *=(const Condom<T> &other){
			(*ptr) *= *(other.ptr);
			return *this;
		}
	
		Condom<T>& operator *=(const T &other){
			(*ptr) *= other;
			return *this;
		}
	
		Condom<T>& operator /=(const Condom<T> &other){
			(*ptr) /= *(other.ptr);
			return *this;
		}
	
		Condom<T>& operator /=(const T &other){
			(*ptr) /= other;
			return *this;
		}
	
		Condom<T>& operator %=(const Condom<T> &other){
			(*ptr) %= *(other.ptr);
			return *this;
		}
	
		Condom<T>& operator %=(const T &other){
			(*ptr) %= other;
			return *this;
		}
	
		Condom<T>& operator &=(const Condom<T> &other){
			(*ptr) &= *(other.ptr);
			return *this;
		}
	
		Condom<T>& operator &=(const T &other){
			(*ptr) &= other;
			return *this;
		}
	
		Condom<T>& operator |=(const Condom<T> &other){
			(*ptr) |= *(other.ptr);
			return *this;
		}
	
		Condom<T>& operator |=(const T &other){
			(*ptr) |= other;
			return *this;
		}
	
		Condom<T>& operator ^=(const Condom<T> &other){
			(*ptr) ^= *(other.ptr);
			return *this;
		}
	
		Condom<T>& operator ^=(const T &other){
			(*ptr) ^= other;
			return *this;
		}
	
		Condom<T>& operator <<=(const Condom<T> &other){
			(*ptr) <<= *(other.ptr);
			return *this;
		}
	
		Condom<T>& operator <<=(const T &other){
			(*ptr) <<= other;
			return *this;
		}
	
		Condom<T>& operator >>=(const Condom<T> &other){
			(*ptr) >>= *(other.ptr);
			return *this;
		}
	
		Condom<T>& operator >>=(const T &other){
			(*ptr) >>= other;
			return *this;
		}
	
		void* operator new(size_t x) = delete;
		void* operator new[](size_t x) = delete;
	
		friend ostream& operator<<(ostream& stream, const Condom<T>& obj){
			stream << *(obj.ptr);
			return stream;
		}
	
		unsigned int GetReferenceCount() const{
			return nodePTR->first;
		}
	
		#ifdef DEBUG
		T* _getPTR(){
			//_memNode dummy;
			//dummy.ptr = ptr;
			//auto target = manager.find(dummy);
			//const _memNode &reff = *target;
	
			return ptr;
		}
		#endif
	
	};
};

#endif // _Condom__h
