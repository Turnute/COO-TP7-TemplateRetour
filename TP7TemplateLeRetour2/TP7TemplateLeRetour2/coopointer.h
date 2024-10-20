//  Tourenne    Audebert
//  Vincent     Dorine

#pragma once
#include <iostream>

namespace coo
{
	template <typename T>
	class coopointer
	{
		// D�finition de la classe Compteur
		class coorefcounter
		{
			unsigned int cmpt;

		public:
			// Constructeurs ==================
			coorefcounter() : cmpt(0) { }

			coorefcounter(const int& i) : cmpt(i) { }

			unsigned int get() const {
				return cmpt;
			}

			// Op�rateurs	==================
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
				return *this;
			}

			bool operator==(const int& i) const {
				return (this->cmpt == i);
			}
		};

		coorefcounter* cmpt;
		T* ptr;
	public:
		// Constructeurs & Destructeur ================
		coopointer() : cmpt(new coorefcounter), ptr(nullptr) {}

		coopointer(T* t) : cmpt(new coorefcounter(1)), ptr(t) {}

		coopointer(const coopointer<T>& other) {
			++(*other.cmpt);
			cmpt = other.cmpt;
			ptr = other.ptr;
		}
	
		~coopointer(){
			--(*cmpt);

			if (*cmpt == 0)
			{
				delete cmpt;
				delete ptr;
			}
		}
		// M�thodes ================
		unsigned int count() const {
			return (*cmpt).get();
		}

		// Operateurs ================
		T& operator*() const {
			return *ptr;
		}

		T* operator->() {
			return ptr;
		}

		coopointer<T>& operator=(const coopointer<T>& other) {
			if (ptr != other.ptr)
			{
				--(*cmpt);
				// Cas sp�cial : l'�l�ment qui prend 
				// l'affectation �tait le dernier allou� � sa zone m�moire
				if (*cmpt == 0)
				{
					delete cmpt;
					delete ptr;
				}
				// Sinon, on d�cr�mente simplement son compteur

				// Affectation en surface
				cmpt = other.cmpt;
				ptr = other.ptr;
				++(*cmpt);
			}

			return *this;
		}

	};

	template <typename T>
	class coounique
	{
		T* ptr;

		// M�thodes � interdire : d�finies en private
		coounique();
		coounique(const coounique&);

		// Operateurs � interdire
		coounique& operator=(const coounique&);
	
	public:
		// Constructeur & Destructeur ================
		coounique(T* t) : ptr(t) { }

		~coounique(){
			delete ptr;
		}

		// Operateurs ================
		T& operator*() const {
			return *ptr;
		}

		T* operator->() {
			return ptr;
		}

	};

}


