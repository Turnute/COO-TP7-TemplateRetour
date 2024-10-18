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

		coopointer(const coopointer& other) {
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

		coopointer& operator=(const coopointer& other) {
			if (ptr != other.ptr)
			{
				// Cas sp�cial : l'�l�ment qui prend 
				// l'affectation �tait le dernier allou� � sa zone m�moire
				if (*cmpt == 1)
				{
					delete cmpt;
					delete ptr;
				}
				// Sinon, on d�cr�mente simplement son compteur
				else
					--(*cmpt);

				// Affectation en surface
				++(*other.cmpt);
				cmpt = other.cmpt;
				ptr = other.ptr;
			}

			return *this;
		}

	};

}


