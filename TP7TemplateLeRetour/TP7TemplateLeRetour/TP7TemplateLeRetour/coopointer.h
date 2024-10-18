#pragma once
#include <ostream>

namespace coo {
	template <typename T> 
	class coopointer
	{
		// Définition de la classe Compteur
		class coorefcounter
		{
			unsigned int cmpt;
		public:
			coorefcounter() {
				cmpt = 0;
			};


			unsigned int getCmpt() const {
				return cmpt;
			};

			coorefcounter& operator++() {
				++cmpt;
				return *this;
			};
			coorefcounter& operator--() {
				--cmpt;
				return *this;
			};

			coorefcounter& operator=(const coorefcounter& other) {
				this->cmpt = other->cmpt;
			};
		};

		// Attributs
		coorefcounter cmpt;
		T* ptr;

	public:
		// Constructeurs & Destructeurs
		coopointer() {
			ptr = nullptr;
		};
		coopointer(const T*& p) : ptr(p){
			++cmpt;
		};
		coopointer(const coopointer& other) : ptr(other->ptr) {
			++(other->cmpt);
			this->cmpt = other->cmpt;
		};
		~coopointer() {
			
			delete(ptr)
		};

		// Surcharge d'Opérateurs
		coopointer& operator=(const coopointer& other);
		T& operator*() const;
		T* operator->();


		//friend ostream& operator<<(ostream& out, const coopointer& other) const;
	};
}


