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
			coorefcounter();
			unsigned int getCmpt() const;

			coorefcounter& operator++();
			coorefcounter& operator--();
		};

		// Attributs
		coorefcounter cmpt;
		T* ptr;

	public:
		// Constructeurs & Destructeurs
		coopointer();
		coopointer(const T*& p);
		coopointer(const coopointer& other);
		~coopointer();

		// Surcharge d'Opérateurs
		coopointer& operator=(const coopointer& other);
		T& operator*() const;
		T* operator->();

		//friend ostream& operator<<(ostream& out, const coopointer& other) const;
	};
}


