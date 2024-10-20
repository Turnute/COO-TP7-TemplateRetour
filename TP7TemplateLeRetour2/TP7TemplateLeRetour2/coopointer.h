//  Tourenne    Audebert
//  Vincent     Dorine

#pragma once
#include <iostream>

namespace coo
{
	template <typename T>
	class coopointer
	{
		// Définition de la classe Compteur
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

			// Opérateurs	==================
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
		// Méthodes ================
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
				// Cas spécial : l'élément qui prend 
				// l'affectation était le dernier alloué à sa zone mémoire
				if (*cmpt == 0)
				{
					delete cmpt;
					delete ptr;
				}
				// Sinon, on décrémente simplement son compteur

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

		// Méthodes à interdire : définies en private
		coounique();
		coounique(const coounique&);

		// Operateurs à interdire
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


