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
			coorefcounter() : cmpt(0) { }

			coorefcounter(const int& i) : cmpt(i) { }

			unsigned int get() const {
				return cmpt;
			}

			coorefcounter& operator++() {
				++cmpt;
				return *this;
			}

			coorefcounter& operator--() {
				--cmpt;
				return *this;
			}

			coorefcounter& operator=(const coorefcounter& other) {
				this->cmpt = other->cmpt;
			}
		};

		// Attributs
		coorefcounter* cmpt;
		T* ptr;

	public:
		// Constructeurs & Destructeurs
		coopointer() : cmpt(new coorefcounter), ptr(nullptr) { }

		coopointer(T* p) : cmpt(new coorefcounter(1)), ptr(p) { }

		coopointer(const coopointer<T>& other) : ptr(other.ptr) {
			++(*(other.cmpt));
			this->cmpt = other.cmpt;
		}

		~coopointer() {
			
			delete(ptr);
		}

		// Surcharge d'Opérateurs
		coopointer<T>& operator=(const coopointer<T>& other) {
			++(other.cmpt);
			this->cmpt = other.cmpt;
			this->ptr = other.ptr;
		}

		T& operator*() const;
		T* operator->();

		/*
		friend std::ostream& operator<<(std::ostream& out, const coopointer<T>& other) const
		{
			/*out << "Adresse : " << other.ptr << std::endl
				<< "Valeur : "  << *(other.ptr) << std::endl
				<< "Compteur : " << (*(other.cpmt)).get() << std::endl;

			return out;
		}*/
	};
}


